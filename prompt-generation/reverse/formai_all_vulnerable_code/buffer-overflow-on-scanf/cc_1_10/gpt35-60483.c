//FormAI DATASET v1.0 Category: Sudoku solver ; Style: funny
#include <stdio.h>

// Function to print the Sudoku grid
void printGrid(int grid[9][9])
{
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

// Function to check whether a num value is already
// present in the given row or not
int usedInRow(int grid[9][9], int row, int num)
{
    for (int col = 0; col < 9; col++)
    {
        if (grid[row][col] == num)
        {
            return 1;
        }
    }
    return 0;
}

// Function to check whether a num value is already
// present in the given column or not
int usedInCol(int grid[9][9], int col, int num)
{
    for (int row = 0; row < 9; row++)
    {
        if (grid[row][col] == num)
        {
            return 1;
        }
    }
    return 0;
}

// Function to check whether a num value is already
// present in the given box or not
int usedInBox(int grid[9][9], int startRow, int startCol, int num)
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (grid[row+startRow][col+startCol] == num)
            {
                return 1;
            }
        }
    }
    return 0;
}

// Function to check whether it will be
// legal to assign num to the given row,col location
int isSafe(int grid[9][9], int row, int col, int num)
{
    return !usedInRow(grid, row, num) &&
           !usedInCol(grid, col, num) &&
           !usedInBox(grid, row - row % 3 , col - col % 3, num);
}

// Function to find the unassigned location in the grid
int findUnassignedLocation(int grid[9][9], int *row, int *col)
{
    for (*row = 0; *row < 9; (*row)++)
    {
        for (*col = 0; *col < 9; (*col)++)
        {
            if (grid[*row][*col] == 0)
            {
                return 1;
            }
        }
    }
    return 0;
}

// Function to solve the Sudoku grid using backtracking
int solveSudoku(int grid[9][9])
{
    int row, col;
    if (!findUnassignedLocation(grid, &row, &col))
    {
        return 1;
    }
    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(grid, row, col, num))
        {
            grid[row][col] = num;
            if (solveSudoku(grid))
            {
                return 1;
            }
            grid[row][col] = 0;
        }
    }
    return 0;
}

// Driver code
int main()
{
    // Welcome message
    printf("Welcome to Schizo the Sudoku-solving bot!\n");
    printf("I can solve a Sudoku puzzle for you. Just enter the numbers and let me do the magic!\n");

    // Sudoku puzzle input
    int grid[9][9];
    printf("\nEnter the Sudoku puzzle (0 for empty cell):\n");
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            scanf("%d", &grid[row][col]);
        }
    }

    // Solving the Sudoku puzzle
    if (solveSudoku(grid))
    {
        // Printing the solved Sudoku grid
        printf("\nYay! I have solved the puzzle. Here is the solution:\n");
        printGrid(grid);
    }
    else
    {
        // Oops! Unable to solve the Sudoku puzzle
        printf("\nSorry, I am not able to solve the puzzle. Looks like you have given me an unsolvable puzzle!\n");
    }

    // Goodbye message
    printf("\nThank you for playing with me. Have a nice day :)\n");

    return 0;
}