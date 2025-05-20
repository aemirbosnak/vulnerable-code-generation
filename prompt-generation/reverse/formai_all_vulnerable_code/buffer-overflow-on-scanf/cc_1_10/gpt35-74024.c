//FormAI DATASET v1.0 Category: Sudoku solver ; Style: Sherlock Holmes
#include <stdio.h>

// Our problem-solving detective, Sherlock
int solveSudoku(int grid[9][9]);

// Our main function, Watson
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

    // Insert Sudoku puzzle here
    printf("Enter the Sudoku puzzle (Use 0 to represent blank cells):\n");
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    // Call on Sherlock to solve the puzzle
    if(solveSudoku(grid) == 1) {
        // Print out the solved puzzle
        printf("Solved Sudoku Puzzle:\n");
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("Invalid Sudoku Puzzle\n");
    }
    return 0;
}

int solveSudoku(int grid[9][9]) {
    int row, col;

    // Check if there is any remaining empty cell in the grid
    if(!findEmptyCell(grid, &row, &col)) {
        return 1;
    }

    // Test all numbers from 1-9 to see if they fit the empty cell
    for(int num=1; num<=9; num++) {
        // Check if the number is not already used in the same row, column, or 3x3 box
        if(isNumSafe(grid, row, col, num)) {
            // Fill the cell with the number
            grid[row][col] = num;

            // Recursively check if the rest of the cells can be filled with numbers
            if(solveSudoku(grid)) {
                return 1; // Success!
            }

            // If the number doesn't work, backtrack
            grid[row][col] = 0;
        }
    }
    return 0; // No solution
}

int findEmptyCell(int grid[9][9], int *row, int *col) {
    for(*row=0; *row<9; (*row)++) {
        for(*col=0; *col<9; (*col)++) {
            if(grid[*row][*col] == 0) {
                return 1; // There is an empty cell
            }
        }
    }
    return 0; // There is no empty cell
}

int isNumSafe(int grid[9][9], int row, int col, int num) {
    // Check if the same number is already used in the same row
    for(int i=0; i<9; i++) {
        if(grid[row][i] == num) {
            return 0; // Not safe
        }
    }

    // Check if the same number is already used in the same column
    for(int i=0; i<9; i++) {
        if(grid[i][col] == num) {
            return 0; // Not safe
        }
    }

    // Check if the same number is already used in the same 3x3 box
    int boxRow = row - row%3;
    int boxCol = col - col%3;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(grid[boxRow+i][boxCol+j] == num) {
                return 0; // Not safe
            }
        }
    }

    return 1; // Safe
}