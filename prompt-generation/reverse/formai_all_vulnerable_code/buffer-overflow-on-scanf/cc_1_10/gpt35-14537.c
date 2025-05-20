//FormAI DATASET v1.0 Category: Sudoku solver ; Style: introspective
#include <stdio.h>
#include <stdbool.h>

#define ROWS 9
#define COLS 9

int grid[ROWS][COLS]; // sudoku grid

// function to check if a number is safe to place in a particular cell
bool isSafe(int row, int col, int num) {
    // check if the same number is present in the row or column
    for (int i = 0; i < ROWS; i++) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return false;
        }
    }

    // check if the same number is present in the 3x3 sub-grid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = startRow; i < startRow + 3; i++) {
        for (int j = startCol; j < startCol + 3; j++) {
            if (grid[i][j] == num) {
                return false;
            }
        }
    }

    return true;
}

// function to print the sudoku grid
void printGrid() {
    printf("-------------------------\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", grid[i][j]);
            if (j == 2 || j == 5) {
                printf("| ");
            }
        }
        printf("\n");
        if (i == 2 || i == 5) {
            printf("-------------------------\n");
        }
    }
    printf("-------------------------\n");
}

// recursive function to solve the sudoku grid
bool solveSudoku(int row, int col) {
    // if all cells are filled, return true
    if (row == ROWS) {
        return true;
    }

    // check if the current cell is already filled, move to next cell
    if (grid[row][col] != 0) {
        if (col == COLS - 1) {
            return solveSudoku(row + 1, 0);
        } else {
            return solveSudoku(row, col + 1);
        }
    }

    // try placing numbers in the current cell
    for (int num = 1; num <= 9; num++) {
        if (isSafe(row, col, num)) {
            grid[row][col] = num;
            if (col == COLS - 1) {
                if (solveSudoku(row + 1, 0)) {
                    return true;
                }
            } else {
                if (solveSudoku(row, col + 1)) {
                    return true;
                }
            }
            grid[row][col] = 0; // backtrack
        }
    }

    return false;
}

int main() {
    // initialize the sudoku grid
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    // solve the sudoku grid
    if (solveSudoku(0, 0)) {
        printGrid();
    } else {
        printf("Could not solve the sudoku grid!\n");
    }

    return 0;
}