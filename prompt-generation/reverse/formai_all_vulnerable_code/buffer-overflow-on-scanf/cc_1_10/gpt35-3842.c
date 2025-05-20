//FormAI DATASET v1.0 Category: Sudoku solver ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

// Changing the size of the Sudoku dynamically
#define ROW 9
#define COLUMN 9

int sudoku[ROW][COLUMN];

// Function to print the Sudoku
void printSudoku()
{
    printf("+-----+-----+-----+\n");
    for (int i = 0; i < ROW; i++)
    {
        printf("| ");
        for (int j = 0; j < COLUMN; j++)
        {
            printf("%d ", sudoku[i][j]);
            if ((j + 1) % 3 == 0)
            {
                printf("| ");
            }
        }
        printf("\n");
        if ((i + 1) % 3 == 0)
        {
            printf("+-----+-----+-----+\n");
        }
    }
}

// Function to check if the value 'num' is already placed in the given row
int usedInRow(int row, int num)
{
    for (int i = 0; i < COLUMN; i++)
    {
        if (sudoku[row][i] == num)
        {
            return 1;
        }
    }
    return 0;
}

// Function to check if the value 'num' is already placed in the given column
int usedInColumn(int col, int num)
{
    for (int i = 0; i < ROW; i++)
    {
        if (sudoku[i][col] == num)
        {
            return 1;
        }
    }
    return 0;
}

// Function to check if the value 'num' is already placed in the given 3x3 box
int usedInBox(int row, int col, int num)
{
    int boxRowStart = row - row % 3;
    int boxColStart = col - col % 3;

    for (int i = boxRowStart; i < boxRowStart + 3; i++)
    {
        for (int j = boxColStart; j < boxColStart + 3; j++)
        {
            if (sudoku[i][j] == num)
            {
                return 1;
            }
        }
    }
    return 0;
}

// Function to check if it is safe to place 'num' at the given cell
int isSafe(int row, int col, int num)
{
    return !usedInRow(row, num) && !usedInColumn(col, num) && !usedInBox(row, col, num);
}

// Function to solve the Sudoku
int solveSudoku()
{
    int row, col;

    // Check if there is any unassigned cell
    if (!findUnassignedCell(&row, &col))
    {
        return 1;
    }

    // Try all possible values in the unassigned cell
    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(row, col, num))
        {
            sudoku[row][col] = num;

            // Recursively solve the Sudoku
            if (solveSudoku())
            {
                return 1;
            }

            // Undo the assigned cell if the recursion ends up being wrong
            sudoku[row][col] = 0;
        }
    }

    // If none of the values work, backtrack
    return 0;
}

// Function to find the unassigned cell in the Sudoku
int findUnassignedCell(int *row, int *col)
{
    for (*row = 0; *row < ROW; (*row)++)
    {
        for (*col = 0; *col < COLUMN; (*col)++)
        {
            if (sudoku[*row][*col] == 0)
            {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    // User input: Enter the Sudoku row by row, replace blank spaces with 0
    printf("Enter the Sudoku:\n");
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            scanf("%d", &sudoku[i][j]);
        }
    }

    printf("\n======================================\n");
    printf("               Sudoku                 \n");
    printf("======================================\n");
    printSudoku();

    // Solve the Sudoku
    if (solveSudoku())
    {
        printf("\n======================================\n");
        printf("            Solution Found            \n");
        printf("======================================\n");
        printSudoku();
    }
    else
    {
        printf("\n======================================\n");
        printf("            Solution Not Found        \n");
        printf("======================================\n");
    }

    return 0;
}