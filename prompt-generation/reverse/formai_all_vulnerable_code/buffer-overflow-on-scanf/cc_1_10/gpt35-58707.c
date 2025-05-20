//FormAI DATASET v1.0 Category: Sudoku solver ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>

#define UNASSIGNED 0
#define N 9

int solveSudoku(int grid[N][N]);

int checkrow(int grid[N][N], int row, int num)
{
    for(int col=0; col<N; col++)
        if(grid[row][col] == num)
            return 1;
    return 0;
}

int checkcol(int grid[N][N], int col, int num)
{
    for(int row=0; row<N; row++)
        if(grid[row][col] == num)
            return 1;
    return 0;
}

int checkBox(int grid[N][N], int rowStart, int colStart, int num)
{
    for(int row=0; row<3; row++)
        for(int col=0; col<3; col++)
            if(grid[rowStart+row][colStart+col] == num)
                return 1;
    return 0;
}

int isSafe(int grid[N][N], int row, int col, int num)
{
    return !checkrow(grid, row, num) &&
           !checkcol(grid, col, num) &&
           !checkBox(grid, row - row%3, col - col%3, num) &&
            grid[row][col] == UNASSIGNED;
}

void print(int grid[N][N])
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
            printf("%d ", grid[i][j]);
        printf("\n");
    }
}

int findUnassigned(int grid[N][N], int *row, int *col)
{
    for(*row=0; *row<N; (*row)++)
        for(*col=0; *col<N; (*col)++)
            if(grid[*row][*col] == UNASSIGNED)
                return 1;
    return 0;
}

int solveSudoku(int grid[N][N])
{
    int row, col;
    if(!findUnassigned(grid, &row, &col))
        return 1;
    for(int num = 1; num <= 9; num++)
    {
        if (isSafe(grid, row, col, num))
        {
            grid[row][col] = num;
            if(solveSudoku(grid))
                return 1;
            grid[row][col] = UNASSIGNED;
        }
    }
    return 0;
}

int main()
{
    int grid[N][N];
    printf("Enter the Sudoku grid (0 for unassigned cell): \n");
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            scanf("%d", &grid[i][j]);
    if(solveSudoku(grid))
        print(grid);
    else
        printf("No solution exists");
    return 0;
}