//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define N 9

int grid[N][N];

int main() {
    // Read the input grid from the user.
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    // Solve the grid.
    if (solve_grid(grid)) {
        // Print the solved grid.
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("No solution found.\n");
    }

    return 0;
}

int solve_grid(int grid[N][N]) {
    // Find the first empty cell.
    int row, col;
    if (!find_empty_cell(grid, &row, &col)) {
        return 1; // The grid is already solved.
    }

    // Try all possible values for the empty cell.
    for (int value = 1; value <= N; value++) {
        // Check if the value is valid for the empty cell.
        if (is_valid_value(grid, row, col, value)) {
            // Set the value in the empty cell.
            grid[row][col] = value;

            // Recursively solve the grid with the new value.
            if (solve_grid(grid)) {
                return 1; // The grid is solved.
            }

            // If the grid is not solved, reset the empty cell to 0.
            grid[row][col] = 0;
        }
    }

    // If we have tried all possible values and none of them worked, then the grid is not solvable.
    return 0;
}

int find_empty_cell(int grid[N][N], int *row, int *col) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 0) {
                *row = i;
                *col = j;
                return 1;
            }
        }
    }
    return 0;
}

int is_valid_value(int grid[N][N], int row, int col, int value) {
    // Check if the value is already present in the row.
    for (int i = 0; i < N; i++) {
        if (grid[row][i] == value) {
            return 0;
        }
    }

    // Check if the value is already present in the column.
    for (int i = 0; i < N; i++) {
        if (grid[i][col] == value) {
            return 0;
        }
    }

    // Check if the value is already present in the 3x3 box.
    int box_row = row / 3;
    int box_col = col / 3;
    for (int i = 3 * box_row; i < 3 * box_row + 3; i++) {
        for (int j = 3 * box_col; j < 3 * box_col + 3; j++) {
            if (grid[i][j] == value) {
                return 0;
            }
        }
    }

    return 1;
}