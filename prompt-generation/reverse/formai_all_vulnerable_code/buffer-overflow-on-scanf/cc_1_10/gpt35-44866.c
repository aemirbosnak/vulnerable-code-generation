//FormAI DATASET v1.0 Category: Sudoku solver ; Style: accurate
#include <stdio.h>

#define UNASSIGNED 0
#define N 9

int grid[N][N];

int find_unassigned(int* row, int* col)
{
    for (*row = 0; *row < N; (*row)++)
        for (*col = 0; *col < N; (*col)++)
            if (grid[*row][*col] == UNASSIGNED)
                return 1;
    return 0;
}

int row_used(int row, int num)
{
    for (int col = 0; col < N; col++)
        if (grid[row][col] == num)
            return 1;
    return 0;
}

int col_used(int col, int num)
{
    for (int row = 0; row < N; row++)
        if (grid[row][col] == num)
            return 1;
    return 0;
}

int box_used(int row_start, int col_start, int num)
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row + row_start][col + col_start] == num)
                return 1;
    return 0;
}

int is_safe(int row, int col, int num)
{
    return !row_used(row, num) &&
           !col_used(col, num) &&
           !box_used(row - row % 3, col - col % 3, num);
}

int solve_sudoku()
{
    int row, col;
    if (!find_unassigned(&row, &col))
        return 1;
    for (int num = 1; num <= 9; num++)
    {
        if (is_safe(row, col, num))
        {
            grid[row][col] = num;

            if (solve_sudoku())
                return 1;

            grid[row][col] = UNASSIGNED;
        }
    }
    return 0;
}

int main()
{
    printf("Enter the Sudoku grid (0 for empty cell):\n");

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &grid[i][j]);

    if (solve_sudoku())
    {
        printf("\nSudoku solution:\n");
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                printf("%d ", grid[i][j]);
            printf("\n");
        }
    }
    else
    {
        printf("No solution exists.");
    }

    return 0;
}