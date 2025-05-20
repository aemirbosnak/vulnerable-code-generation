//FormAI DATASET v1.0 Category: Sudoku solver ; Style: artistic
#include <stdio.h>
#include <stdbool.h>

#define N 9

bool findEmptyLocation(int sudoku[N][N], int *row, int *col);
bool isSafe(int sudoku[N][N], int row, int col, int num);
bool solveSudoku(int sudoku[N][N]);
void printSudoku(int sudoku[N][N]);

int main()
{
    int sudoku[N][N];
    printf("Enter the Sudoku puzzle (use 0 for empty cells):\n");
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            scanf("%d",&sudoku[i][j]);
        }
    }
    printf("\nInitial Sudoku Puzzle:\n");
    printSudoku(sudoku);
    if (solveSudoku(sudoku) == true)
    {
        printf("\nSolved Sudoku Puzzle:\n");
        printSudoku(sudoku);
    }
    else
    {
        printf("No solution exists! ");
    }
    return 0;
}

bool findEmptyLocation(int sudoku[N][N], int *row, int *col)
{
    for (*row = 0; *row < N; (*row)++)
    {
        for (*col = 0; *col < N; (*col)++)
        {
            if (sudoku[*row][*col] == 0)
            {
                return true;
            }
        }
    }
    return false;
}

bool isSafe(int sudoku[N][N], int row, int col, int num)
{
    for (int i = 0; i < N; i++)
    {
        if (sudoku[row][i] == num)
            return false;
        if (sudoku[i][col] == num)
            return false;
        if (sudoku[(row - row%3) + i/3][(col - col%3) + i%3] == num)
            return false;
    }
    return true;
}

bool solveSudoku(int sudoku[N][N])
{
    int row, col;
    if (!findEmptyLocation(sudoku, &row, &col))
       return true;
    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(sudoku, row, col, num))
        {
            sudoku[row][col] = num;
            if (solveSudoku(sudoku))
                return true;
            sudoku[row][col] = 0;
        }
    }
    return false;
}

void printSudoku(int sudoku[N][N])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            printf("%d ",sudoku[i][j]);
        }
        printf("\n");
    }
}