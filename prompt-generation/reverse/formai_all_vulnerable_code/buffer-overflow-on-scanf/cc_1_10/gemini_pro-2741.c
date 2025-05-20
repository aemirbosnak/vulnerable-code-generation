//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 9
#define UNSET 0

int grid[SIZE][SIZE];
int solved = 0;

int is_safe(int row, int col, int num) {
    int i, j;

    // Check row
    for (i = 0; i < SIZE; i++) {
        if (grid[row][i] == num) {
            return 0;
        }
    }

    // Check column
    for (j = 0; j < SIZE; j++) {
        if (grid[j][col] == num) {
            return 0;
        }
    }

    // Check box
    int box_row = row / 3;
    int box_col = col / 3;
    for (i = 3 * box_row; i < 3 * box_row + 3; i++) {
        for (j = 3 * box_col; j < 3 * box_col + 3; j++) {
            if (grid[i][j] == num) {
                return 0;
            }
        }
    }

    return 1;
}

void print_grid() {
    int i, j;

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

void solve_sudoku() {
    int row, col;

    // Find an empty cell
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (grid[row][col] == UNSET) {
                goto found;
            }
        }
    }

    // No empty cells, sudoku is solved
    solved = 1;
    return;

found:
    // Try all possible numbers for the empty cell
    for (int num = 1; num <= SIZE; num++) {
        if (is_safe(row, col, num)) {
            // Set the empty cell to the number
            grid[row][col] = num;

            // Recursively solve the sudoku
            solve_sudoku();

            // If the sudoku is not solved, reset the empty cell
            if (!solved) {
                grid[row][col] = UNSET;
            }
        }
    }
}

int main() {
    // Read the sudoku grid from the user
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    // Solve the sudoku
    solve_sudoku();

    // Print the solved sudoku
    if (solved) {
        printf("Solved sudoku:\n");
        print_grid();
    } else {
        printf("Sudoku could not be solved.\n");
    }

    return 0;
}