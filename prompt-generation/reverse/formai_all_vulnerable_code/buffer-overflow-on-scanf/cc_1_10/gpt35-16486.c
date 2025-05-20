//FormAI DATASET v1.0 Category: Sudoku solver ; Style: curious
#include <stdio.h>

// function to print the sudoku grid
void printGrid(int grid[9][9])
{
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

// function to check if a number is already present in a row
int isPresentInRow(int grid[9][9], int row, int num)
{
    for (int col = 0; col < 9; col++) {
        if (grid[row][col] == num) {
            return 1;
        }
    }
    return 0;
}

// function to check if a number is already present in a column
int isPresentInCol(int grid[9][9], int col, int num)
{
    for (int row = 0; row < 9; row++) {
        if (grid[row][col] == num) {
            return 1;
        }
    }
    return 0;
}

// function to check if a number is already present in a 3x3 subgrid
int isPresentInSubgrid(int grid[9][9], int startRow, int startCol, int num)
{
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (grid[row + startRow][col + startCol] == num) {
                return 1;
            }
        }
    }
    return 0;
}

// function to check if a number is valid to be placed at the given position in the sudoku grid
int isValid(int grid[9][9], int row, int col, int num)
{
    // check if number is already present in the row or column or subgrid
    return !isPresentInRow(grid, row, num) &&
           !isPresentInCol(grid, col, num) &&
           !isPresentInSubgrid(grid, row - row % 3, col - col % 3, num);
}

// function to solve the sudoku grid
int solveSudoku(int grid[9][9])
{
    int row, col;

    // find the first unassigned position in the grid
    int found = 0;
    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            if (grid[row][col] == 0) {
                found = 1;
                break;
            }
        }
        if (found) {
            break;
        }
    }

    // if all positions have been filled, the sudoku is solved
    if (!found) {
        return 1;
    }

    // try placing numbers from 1 to 9 in the current position and recursively solve the remaining grid
    for (int num = 1; num <= 9; num++) {
        if (isValid(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid)) {
                return 1;
            }
            grid[row][col] = 0;
        }
    }

    // backtrack if no valid number can be placed in the current position
    return 0;
}

int main()
{
    int grid[9][9] = {{0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
	                  {0, 0, 0, 0, 0, 0, 0, 0, 0},
	                  {0, 0, 0, 0, 0, 0, 0, 0, 0},
	                  {0, 0, 0, 0, 0, 0, 0, 0, 0},
	                  {0, 0, 0, 0, 0, 0, 0, 0, 0},
	                  {0, 0, 0, 0, 0, 0, 0, 0, 0},
	                  {0, 0, 0, 0, 0, 0, 0, 0, 0},
	                  {0, 0, 0, 0, 0, 0, 0, 0, 0}};

    // enter the values in the grid that are already known
    printf("Enter the values in the sudoku grid one by one (in row-wise order).\nUse 0 for unknown positions.\n");
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            scanf("%d", &grid[row][col]);
        }
    }

    printf("Sudoku grid before solving:\n");
    printGrid(grid);

    // solve the sudoku grid
    if (solveSudoku(grid)) {
        printf("Sudoku grid after solving:\n");
        printGrid(grid);
    } else {
        printf("No solution found.\n");
    }

    return 0;
}