//FormAI DATASET v1.0 Category: Sudoku solver ; Style: medieval
#include <stdio.h>

#define UNASSIGNED 0
#define N 9

int safe(int sudoku[N][N], int row, int col, int num)
{
    // Check for same number in row, column and box
    for (int i = 0; i < N; i++)
    {
        if (sudoku[row][i] == num)
            return 0;

        if (sudoku[i][col] == num)
            return 0;

        if (sudoku[(row - row % 3) + i / 3][(col - col % 3) + i % 3] == num)
            return 0;
    }

    return 1;
}

void display(int sudoku[N][N])
{
    // Print out the solution
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%d ", sudoku[i][j]);
        printf("\n");
    }
}

int solve(int sudoku[N][N], int row, int col)
{
    if (row == N - 1 && col == N)
        return 1;

    if (col == N)
    {
        row++;
        col = 0;
    }

    if (sudoku[row][col] > 0)
        return solve(sudoku, row, col + 1);

    for (int num = 1; num <= N; num++)
    {
        if (safe(sudoku, row, col, num) == 1)
        {
            sudoku[row][col] = num;

            if (solve(sudoku, row, col + 1) == 1)
                return 1;
        }

        sudoku[row][col] = UNASSIGNED;
    }

    return 0;
}

int main()
{
    int sudoku[N][N];

    printf("Enter the initial configuration of the Sudoku puzzle:\n");

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &sudoku[i][j]);

    if (solve(sudoku, 0, 0) == 1)
        display(sudoku);
    else
        printf("\nNo solution exists!\n");

    return 0;
}