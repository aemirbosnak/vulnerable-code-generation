//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 9

// Function to print the sudoku grid
void print_grid(int grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a number is safe to place in a particular cell
int is_safe(int grid[SIZE][SIZE], int row, int col, int num) {
    // Check row
    for (int i = 0; i < SIZE; i++) {
        if (grid[row][i] == num) {
            return 0;
        }
    }

    // Check column
    for (int i = 0; i < SIZE; i++) {
        if (grid[i][col] == num) {
            return 0;
        }
    }

    // Check 3x3 box
    int box_row = row / 3;
    int box_col = col / 3;
    for (int i = box_row * 3; i < box_row * 3 + 3; i++) {
        for (int j = box_col * 3; j < box_col * 3 + 3; j++) {
            if (grid[i][j] == num) {
                return 0;
            }
        }
    }

    // If all checks pass, return 1
    return 1;
}

// Function to find an empty cell in the grid
int find_empty_cell(int grid[SIZE][SIZE], int *row, int *col) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] == 0) {
                *row = i;
                *col = j;
                return 1;
            }
        }
    }
    return 0;
}

// Function to solve the sudoku grid
int solve_sudoku(int grid[SIZE][SIZE]) {
    int row, col;

    // If no empty cell found, the sudoku is solved
    if (!find_empty_cell(grid, &row, &col)) {
        return 1;
    }

    // Try all possible numbers for the empty cell
    for (int num = 1; num <= SIZE; num++) {
        // If the number is safe to place, place it and recursively solve the rest of the grid
        if (is_safe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solve_sudoku(grid)) {
                return 1;
            }
            // If the recursion fails, reset the cell to 0 and try the next number
            grid[row][col] = 0;
        }
    }

    // If no number is safe to place, return 0
    return 0;
}

int main() {
    // Input the sudoku grid
    int grid[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d ", &grid[i][j]);
        }
    }

    // Solve the sudoku grid
    if (solve_sudoku(grid)) {
        // Print the solved sudoku grid
        print_grid(grid);
    } else {
        printf("No solution exists for this sudoku grid.\n");
    }

    return 0;
}