//FormAI DATASET v1.0 Category: Sudoku solver ; Style: satisfied
#include <stdio.h>
#include <stdbool.h>

#define N 9

// Function declarations
bool check_row(int grid[N][N], int row, int num);
bool check_col(int grid[N][N], int col, int num);
bool check_box(int grid[N][N], int row, int col, int num);
bool find_unassigned(int grid[N][N], int *row, int *col);
bool solve_sudoku(int grid[N][N]);
void print_grid(int grid[N][N]);

// Check if number num is present in given row
bool check_row(int grid[N][N], int row, int num) {
    for (int col = 0; col < N; col++) {
        if (grid[row][col] == num) {
            return true;
        }
    }
    return false;
}

// Check if number num is present in given column
bool check_col(int grid[N][N], int col, int num) {
    for (int row = 0; row < N; row++) {
        if (grid[row][col] == num) {
            return true;
        }
    }
    return false;
}

// Check if number num is present in given box
bool check_box(int grid[N][N], int box_start_row, int box_start_col, int num) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (grid[row+box_start_row][col+box_start_col] == num) {
                return true;
            }
        }
    }
    return false;
}

// Find an unassigned location in the grid
bool find_unassigned(int grid[N][N], int *row, int *col) {
    for (*row = 0; *row < N; (*row)++) {
        for (*col = 0; *col < N; (*col)++) {
            if (grid[*row][*col] == 0) {
                return true;
            }
        }
    }
    return false;
}

// Solve the sudoku recursively
bool solve_sudoku(int grid[N][N]) {
    int row;
    int col;

    // Find an unassigned cell
    if (!find_unassigned(grid, &row, &col)) {
        return true;
    }

    // Try different numbers
    for (int num = 1; num <= 9; num++) {
        if (!check_row(grid, row, num) &&
            !check_col(grid, col, num) &&
            !check_box(grid, row - row%3, col - col%3, num)) {
            // If the number is valid, set it
            grid[row][col] = num;

            // Recursively solve the rest of the grid
            if (solve_sudoku(grid)) {
                return true;
            }

            // If the remaining grid cannot be solved with this number, unset it and try again
            grid[row][col] = 0;
        }
    }

    // If no number works in this cell, backtrack
    return false;
}

// Print the solved grid
void print_grid(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

// Driver function
int main() {
    int grid[N][N] = {
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

    // Get input grid
    printf("Enter the %d x %d Sudoku grid (0 for unknown cells):\n", N, N);
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            scanf("%d", &grid[row][col]);
        }
    }

    if (solve_sudoku(grid)) {
        printf("Solved Sudoku:\n");
        print_grid(grid);
    } else {
        printf("No solution exists.");
    }

    return 0;
}