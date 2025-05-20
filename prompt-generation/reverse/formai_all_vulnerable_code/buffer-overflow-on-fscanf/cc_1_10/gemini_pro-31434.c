//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: active
#include <stdio.h>
#include <stdlib.h>

// 9x9 Sudoku grid
int grid[9][9];

// Function to print the Sudoku grid
void print_grid() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the given value is safe to put in the given cell
int is_safe(int row, int col, int val) {
    // Check the row
    for (int i = 0; i < 9; i++) {
        if (grid[row][i] == val) {
            return 0;
        }
    }

    // Check the column
    for (int i = 0; i < 9; i++) {
        if (grid[i][col] == val) {
            return 0;
        }
    }

    // Check the 3x3 subgrid
    int box_row = row / 3;
    int box_col = col / 3;

    for (int i = 3 * box_row; i < 3 * box_row + 3; i++) {
        for (int j = 3 * box_col; j < 3 * box_col + 3; j++) {
            if (grid[i][j] == val) {
                return 0;
            }
        }
    }

    // If the value is safe to put, return 1
    return 1;
}

// Function to find an empty cell in the Sudoku grid
int find_empty_cell(int *row, int *col) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (grid[i][j] == 0) {
                *row = i;
                *col = j;
                return 1;
            }
        }
    }

    // If no empty cell is found, return 0
    return 0;
}

// Function to solve the Sudoku grid using backtracking
int solve_sudoku() {
    int row, col;

    // Find an empty cell
    if (!find_empty_cell(&row, &col)) {
        return 1;  // Sudoku is solved
    }

    // Try all possible values for the empty cell
    for (int val = 1; val <= 9; val++) {
        // Check if the value is safe to put
        if (is_safe(row, col, val)) {
            // Put the value in the cell
            grid[row][col] = val;

            // Recursively solve the Sudoku grid
            if (solve_sudoku()) {
                return 1;  // Sudoku is solved
            }

            // If the Sudoku grid is not solved, reset the cell to 0
            grid[row][col] = 0;
        }
    }

    // If no value is safe to put, return 0
    return 0;  // Sudoku is not solved
}

// Function to read the Sudoku grid from a file
int read_sudoku(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return 0;
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            fscanf(fp, "%d ", &grid[i][j]);
        }
    }

    fclose(fp);
    return 1;
}

// Main function
int main() {
    // Read the Sudoku grid from a file
    if (!read_sudoku("sudoku.txt")) {
        return 1;
    }

    // Print the unsolved Sudoku grid
    printf("Unsolved Sudoku grid:\n");
    print_grid();

    // Solve the Sudoku grid
    if (solve_sudoku()) {
        // Print the solved Sudoku grid
        printf("\nSolved Sudoku grid:\n");
        print_grid();
    } else {
        printf("\nSudoku grid cannot be solved\n");
    }

    return 0;
}