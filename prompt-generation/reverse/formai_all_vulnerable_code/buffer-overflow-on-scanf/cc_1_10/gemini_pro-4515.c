//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define SUDOKU_SIZE 9

int main() {
    int sudoku[SUDOKU_SIZE][SUDOKU_SIZE];
    int solved = 0;
    int num_solutions = 0;

    // Read the sudoku puzzle from the user.
    printf("Enter the sudoku puzzle:\n");
    for (int i = 0; i < SUDOKU_SIZE; i++) {
        for (int j = 0; j < SUDOKU_SIZE; j++) {
            scanf("%d", &sudoku[i][j]);
        }
    }

    // Print the original sudoku puzzle.
    printf("Original sudoku puzzle:\n");
    for (int i = 0; i < SUDOKU_SIZE; i++) {
        for (int j = 0; j < SUDOKU_SIZE; j++) {
            printf("%d ", sudoku[i][j]);
        }
        printf("\n");
    }

    // Solve the sudoku puzzle.
    if (solve_sudoku(sudoku)) {
        solved = 1;
    }

    // Print the solved sudoku puzzle.
    if (solved) {
        printf("Solved sudoku puzzle:\n");
        for (int i = 0; i < SUDOKU_SIZE; i++) {
            for (int j = 0; j < SUDOKU_SIZE; j++) {
                printf("%d ", sudoku[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("Could not solve the sudoku puzzle.\n");
    }

    return 0;
}

int solve_sudoku(int sudoku[SUDOKU_SIZE][SUDOKU_SIZE]) {
    int row, col;
    int num_empty_cells = 0;

    // Find an empty cell.
    for (row = 0; row < SUDOKU_SIZE; row++) {
        for (col = 0; col < SUDOKU_SIZE; col++) {
            if (sudoku[row][col] == 0) {
                num_empty_cells++;
            }
        }
    }

    // If there are no empty cells, then the sudoku puzzle is solved.
    if (num_empty_cells == 0) {
        return 1;
    }

    // Try all possible values for the empty cell.
    for (int value = 1; value <= SUDOKU_SIZE; value++) {
        // Check if the value is valid for the empty cell.
        if (is_valid_value(sudoku, row, col, value)) {
            // Set the value for the empty cell.
            sudoku[row][col] = value;

            // Recursively solve the sudoku puzzle.
            if (solve_sudoku(sudoku)) {
                return 1;
            } else {
                // If the recursive call fails, then the value is not valid for the empty cell.
                sudoku[row][col] = 0;
            }
        }
    }

    // If none of the possible values are valid for the empty cell, then the sudoku puzzle cannot be solved.
    return 0;
}

int is_valid_value(int sudoku[SUDOKU_SIZE][SUDOKU_SIZE], int row, int col, int value) {
    // Check if the value is already in the row.
    for (int i = 0; i < SUDOKU_SIZE; i++) {
        if (sudoku[row][i] == value) {
            return 0;
        }
    }

    // Check if the value is already in the column.
    for (int i = 0; i < SUDOKU_SIZE; i++) {
        if (sudoku[i][col] == value) {
            return 0;
        }
    }

    // Check if the value is already in the 3x3 subgrid.
    int subgrid_row = row / 3;
    int subgrid_col = col / 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (sudoku[subgrid_row * 3 + i][subgrid_col * 3 + j] == value) {
                return 0;
            }
        }
    }

    // If the value is not already in the row, column, or 3x3 subgrid, then it is a valid value for the empty cell.
    return 1;
}