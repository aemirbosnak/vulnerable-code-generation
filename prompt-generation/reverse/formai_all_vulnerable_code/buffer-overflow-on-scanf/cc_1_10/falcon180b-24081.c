//Falcon-180B DATASET v1.0 Category: Sudoku solver ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to print a 9x9 Sudoku grid
void print_grid(int grid[9][9]) {
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a number is valid in a given row
bool is_valid_row(int grid[9][9], int row, int num) {
    for(int i=0; i<9; i++) {
        if(grid[row][i] == num) {
            return false;
        }
    }
    return true;
}

// Function to check if a number is valid in a given column
bool is_valid_col(int grid[9][9], int col, int num) {
    for(int i=0; i<9; i++) {
        if(grid[i][col] == num) {
            return false;
        }
    }
    return true;
}

// Function to check if a number is valid in a given 3x3 box
bool is_valid_box(int grid[9][9], int row, int col, int num) {
    int box_row = row - row%3;
    int box_col = col - col%3;
    for(int i=box_row; i<box_row+3; i++) {
        for(int j=box_col; j<box_col+3; j++) {
            if(grid[i][j] == num) {
                return false;
            }
        }
    }
    return true;
}

// Function to solve a Sudoku puzzle using backtracking
bool solve_sudoku(int grid[9][9]) {
    int row, col;
    for(row=0; row<9; row++) {
        for(col=0; col<9; col++) {
            if(grid[row][col] == 0) {
                // Try each number from 1 to 9
                for(int num=1; num<=9; num++) {
                    if(is_valid_row(grid, row, num) && is_valid_col(grid, col, num) && is_valid_box(grid, row, col, num)) {
                        grid[row][col] = num;
                        // Recursively try to solve the rest of the puzzle
                        if(solve_sudoku(grid)) {
                            return true;
                        } else {
                            // If we reach here, the current choice was invalid, so try the next number
                            grid[row][col] = 0;
                        }
                    }
                }
                // If we reach here, the puzzle is unsolvable
                return false;
            }
        }
    }
    // If we reach here, the puzzle is complete
    return true;
}

// Main function to read a Sudoku puzzle from the user and solve it
int main() {
    int grid[9][9];
    printf("Enter a Sudoku puzzle (0 for empty cells):\n");
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    if(solve_sudoku(grid)) {
        printf("Solution:\n");
        print_grid(grid);
    } else {
        printf("No solution found.\n");
    }
    return 0;
}