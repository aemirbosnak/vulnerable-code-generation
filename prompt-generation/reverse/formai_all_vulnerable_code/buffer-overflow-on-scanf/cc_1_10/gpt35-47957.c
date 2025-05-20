//FormAI DATASET v1.0 Category: Sudoku solver ; Style: paranoid
#include <stdio.h>

#define N 9

int grid[N][N];

int isSafe(int row, int col, int num)
{
    int i, j;

    // Check if num is already present in row
    for (i = 0; i < N; i++)
        if (grid[row][i] == num)
            return 0;

    // Check if num is already present in column
    for (i = 0; i < N; i++)
        if (grid[i][col] == num)
            return 0;

    // Check if num is already present in 3x3 subgrid
    int row_start = (row / 3) * 3;
    int col_start = (col / 3) * 3;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            if (grid[row_start + i][col_start + j] == num)
                return 0;

    return 1;
}

int solveSudoku()
{
    int row, col, num;

    // Find unassigned cell
    int unassigned = 0;
    for (row = 0; row < N && !unassigned; row++)
        for (col = 0; col < N && !unassigned; col++)
            if (grid[row][col] == 0)
                unassigned = 1;

    // If no unassigned cell left, puzzle is solved
    if (!unassigned)
        return 1;

    // Try values 1 to 9 for current cell
    for (num = 1; num <= 9; num++)
    {
        // Check if num is safe for current cell
        if (isSafe(row, col, num))
        {
            // Try num in current cell
            grid[row][col] = num;

            // Recursively solve remaining puzzle
            if (solveSudoku())
                return 1;

            // If solveSudoku() returns false, undo assigned value
            grid[row][col] = 0;
        }
    }
    return 0;
}

int main()
{
    int i, j;

    printf("Enter Sudoku puzzle:\n");
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            scanf("%d", &grid[i][j]);

    if (solveSudoku())
    {
        printf("Sudoku solution:\n");
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
                printf("%d ", grid[i][j]);
            printf("\n");
        }
    }
    else
        printf("Unable to solve Sudoku puzzle.\n");

    return 0;
}