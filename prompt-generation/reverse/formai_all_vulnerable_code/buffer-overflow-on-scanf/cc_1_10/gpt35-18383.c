//FormAI DATASET v1.0 Category: Sudoku solver ; Style: Sherlock Holmes
#include <stdio.h>

#define N 9

int grid[N][N];

int find_empty(int *row, int *col)
{
    for (*row = 0; *row < N; (*row)++)
    {
        for (*col = 0; *col < N; (*col)++)
        {
            if (grid[*row][*col] == 0)
            {
                return 1;
            }
        }
    }
    return 0;
}

int is_valid(int row, int col, int num)
{
    for (int i = 0; i < N; i++)
    {
        if (grid[row][i] == num || grid[i][col] == num)
        {
            return 0;
        }
    }
    int box_row = row - row % 3;
    int box_col = col - col % 3;
    for (int i = box_row; i < box_row + 3; i++)
    {
        for (int j = box_col; j < box_col + 3; j++)
        {
            if (grid[i][j] == num)
            {
                return 0;
            }
        }
    }
    return 1;
}

int solve_sudoku()
{
    int row, col;
    if (!find_empty(&row, &col))
    {
        return 1;
    }
    for (int num = 1; num <= N; num++)
    {
        if (is_valid(row, col, num))
        {
            grid[row][col] = num;
            if (solve_sudoku())
            {
                return 1;
            }
            grid[row][col] = 0;
        }
    }
    return 0;
}

int main()
{
    printf("Enter the Sudoku grid:\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &grid[i][j]);
        }
    }
    if (solve_sudoku())
    {
        printf("The solution to the Sudoku puzzle is:\n");
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("The given Sudoku puzzle is unsolvable!\n");
    }
    return 0;
}