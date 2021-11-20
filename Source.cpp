#include <iostream>
#include <iomanip>
#include <time.h>


using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low,
    const int High);
void Print(int** a, const int rowCount, const int colCount);
void Sort(int** a, const int rowCount, const int colCount);
void Change(int** a, const int row1, const int row2, const int colCount);
void Calc(int** a, const int rowCount, const int colCount, int& S, int& k);

int main()
{
    srand((unsigned)time(NULL));

    int Low = 11;
    int High = 64;

    int rowCount = 8;//8x5
    int colCount = 5;

    int** Y = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        Y[i] = new int[colCount];

    Create(Y, rowCount, colCount, Low, High);
    Print(Y, rowCount, colCount);
    Sort(Y, rowCount, colCount);
    Print(Y, rowCount, colCount);

    int S = 0;
    int k = 0;
    Calc(Y, rowCount, colCount, S, k);
    cout << "S = " << S << endl;
    cout << "k = " << k << endl;
    Print(Y, rowCount, colCount);

    for (int i = 0; i < rowCount; i++)
        delete[] Y[i];
    delete[] Y;

    return 0;
}
////////////////////////////////////
void Create(int** Y, const int rowCount, const int colCount, const int Low,
    const int High)
{
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            Y[i][j] = High + rand() % (Low-High + 1);
}
////////////////////////////////////
void Print(int** Y, const int rowCount, const int colCount)
{
    cout << endl;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << Y[i][j];
        cout << endl;
    }
    cout << endl;
}
/////////////////////////////////
void Sort(int** Y, const int rowCount, const int colCount)
{
    for (int i0 = 0; i0 < rowCount - 1; i0++)
        for (int i1 = 0; i1 < rowCount - i0 - 1; i1++)
            if ((Y[i1][0] > Y[i1 + 1][0])
                ||
                (Y[i1][0] == Y[i1 + 1][0] &&
                    Y[i1][1] > Y[i1 + 1][1])
                ||
                (Y[i1][0] == Y[i1 + 1][0] &&
                    Y[i1][1] == Y[i1 + 1][1] &&
                    Y[i1][3] > Y[i1 + 1][3]))
                Change(Y, i1, i1 + 1, colCount);
}
////////////////
void Change(int** Y, const int row1, const int row2, const int colCount)
{
    int tmp;
    for (int j = 0; j < colCount; j++)
    {
        tmp = Y[row1][j];
        Y[row1][j] = Y[row2][j];
        Y[row2][j] = tmp;
    }
}
//////////////////
void Calc(int** Y, const int rowCount, const int colCount, int& S, int& k)
{
    S = 0;
    k = 0;
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            if (Y[i][j] % 2 != 0 || !(Y[i][j] % 3 == 0))// всі непарні, або крім кратних 3.
            {
                S += Y[i][j];
                k++;
                Y[i][j] = 0;
            }
}
