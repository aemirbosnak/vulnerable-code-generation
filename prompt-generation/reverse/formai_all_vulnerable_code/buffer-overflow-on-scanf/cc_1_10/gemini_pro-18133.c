//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 9

// Check if the puzzle is valid
int is_valid(int grid[N][N]) {
    // Check each row for duplicates
    for (int i = 0; i < N; i++) {
        int row[N] = {0};
        for (int j = 0; j < N; j++) {
            if (grid[i][j] != 0 && row[grid[i][j] - 1] == 1) {
                return 0;
            }
            row[grid[i][j] - 1] = 1;
        }
    }

    // Check each column for duplicates
    for (int j = 0; j < N; j++) {
        int col[N] = {0};
        for (int i = 0; i < N; i++) {
            if (grid[i][j] != 0 && col[grid[i][j] - 1] == 1) {
                return 0;
            }
            col[grid[i][j] - 1] = 1;
        }
    }

    // Check each 3x3 box for duplicates
    for (int i = 0; i < N; i += 3) {
        for (int j = 0; j < N; j += 3) {
            int box[N] = {0};
            for (int k = i; k < i + 3; k++) {
                for (int l = j; l < j + 3; l++) {
                    if (grid[k][l] != 0 && box[grid[k][l] - 1] == 1) {
                        return 0;
                    }
                    box[grid[k][l] - 1] = 1;
                }
            }
        }
    }

    return 1;
}

// Solve the puzzle using backtracking
int solve(int grid[N][N]) {
    // Find an empty cell
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (grid[i][j] == 0) {
                goto found;
            }
        }
    }

    // If no empty cell found, the puzzle is solved
    return 1;

found:
    // Try all possible values for the empty cell
    for (int k = 1; k <= N; k++) {
        grid[i][j] = k;

        // Check if the puzzle is still valid
        if (is_valid(grid)) {
            // If the puzzle is valid, try to solve the rest of it
            if (solve(grid)) {
                return 1;
            }
        }

        // If the puzzle is not valid, reset the empty cell
        grid[i][j] = 0;
    }

    // If no valid value found for the empty cell, the puzzle cannot be solved
    return 0;
}

// Print the puzzle
void print_grid(int grid[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Read the puzzle from the user
    int grid[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    // Check if the puzzle is valid
    if (!is_valid(grid)) {
        printf("The puzzle is not valid.\n");
        return 0;
    }

    // Solve the puzzle
    if (solve(grid)) {
        printf("The puzzle is solved:\n");
        print_grid(grid);
    } else {
        printf("The puzzle cannot be solved.\n");
    }

    return 0;
}