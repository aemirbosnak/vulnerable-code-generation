//FormAI DATASET v1.0 Category: Sudoku solver ; Style: invasive
#include <stdio.h>

// Function to check if the given number is present in the row
int isPresentInRow(int grid[9][9], int row, int num) {
    for (int col = 0; col < 9; col++) {
        if (grid[row][col] == num) {
            return 1;
        }
    }
    return 0;
}

// Function to check if the given number is present in the column
int isPresentInCol(int grid[9][9], int col, int num) {
    for (int row = 0; row < 9; row++) {
        if (grid[row][col] == num) {
            return 1;
        }
    }
    return 0;
}

// Function to check if the given number is present in the 3x3 grid
int isPresentInBox(int grid[9][9], int boxStartRow, int boxStartCol, int num) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (grid[row+boxStartRow][col+boxStartCol] == num) {
                return 1;
            }
        }
    }
    return 0;
}

// Function to check if it's safe to place a number in a cell
int isSafe(int grid[9][9], int row, int col, int num) {
    return !isPresentInRow(grid, row, num) && !isPresentInCol(grid, col, num) && !isPresentInBox(grid, row - row%3, col - col%3, num);
}

// Function to print the Sudoku grid
void printGrid(int grid[9][9]) {
    printf("\n");
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++)
            printf("%2d", grid[row][col]);
        printf("\n");
    }
}

// Function to solve the Sudoku puzzle using Backtracking
int solveSudoku(int grid[9][9], int row, int col) {
    if (row == 9 - 1 && col == 9) {
        return 1;
    }
    if (col == 9) {
        row++;
        col = 0;
    }
    if (grid[row][col] > 0) {
        return solveSudoku(grid, row, col + 1);
    }
    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid, row, col + 1)) {
                return 1;
            }
        }
        grid[row][col] = 0;
    }
    return 0; 
}

int main() {
    int grid[9][9] = {
                    {0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0}
                   };
    printf("Enter the Sudoku puzzle:\n");
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            scanf("%d", &grid[row][col]);
        }
    }
    
    printf("\nSudoku puzzle before solving:\n");
    printGrid(grid);
    
    if (solveSudoku(grid, 0, 0)) {
        printf("\nSudoku puzzle after solving:\n");
        printGrid(grid);
    } else {
        printf("\nNo solution exists");
    }
    return 0;
}