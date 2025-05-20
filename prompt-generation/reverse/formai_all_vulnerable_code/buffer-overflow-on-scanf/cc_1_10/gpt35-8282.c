//FormAI DATASET v1.0 Category: Sudoku solver ; Style: accurate
#include <stdio.h>

// Function to check if a number is safe to be placed
int isSafe(int sudoku[9][9], int row, int col, int num)
{
    // Check if the number already exists in row or column
    for (int i = 0; i < 9; i++)
    {
        if (sudoku[row][i] == num || sudoku[i][col] == num)
        {
            return 0;
        }
    }

    // Check if the number already exists in the 3x3 grid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = startRow; i < startRow + 3; i++)
    {
        for (int j = startCol; j < startCol + 3; j++)
        {
            if (sudoku[i][j] == num)
            {
                return 0;
            }
        }
    }

    return 1;
}

// Function to solve the Sudoku
int solveSudoku(int sudoku[9][9])
{
    int row = -1;
    int col = -1;
    int isFull = 1;

    // Search for an empty cell
    for (int i = 0; i < 9 && isFull; i++)
    {
        for (int j = 0; j < 9 && isFull; j++)
        {
            if (sudoku[i][j] == 0)
            {
                row = i;
                col = j;
                isFull = 0;
            }
        }
    }

    // If no empty cell is found, we are done!
    if (isFull)
    {
        return 1;
    }

    // Try all possible numbers to fill the cell
    for (int i = 1; i <= 9; i++)
    {
        if (isSafe(sudoku, row, col, i))
        {
            sudoku[row][col] = i;

            if (solveSudoku(sudoku))
            {
                return 1;
            }

            // Backtrack
            sudoku[row][col] = 0;
        }
    }

    return 0;
}

int main()
{
    int sudoku[9][9] = { {0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0} };

    printf("Enter the Sudoku puzzle (0 for empty cells):\n");
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            scanf("%d", &sudoku[i][j]);
        }
    }

    if (solveSudoku(sudoku))
    {
        printf("The solution to the Sudoku puzzle is:\n");
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                printf("%d ", sudoku[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("The Sudoku puzzle cannot be solved.\n");
    }

    return 0;
}