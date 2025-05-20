//GPT-4o-mini DATASET v1.0 Category: Sudoku solver ; Style: relaxed
#include <stdio.h>
#include <stdbool.h>

#define N 9

void print_grid(int grid[N][N]) {
    for (int r = 0; r < N; r++) {
        for (int d = 0; d < N; d++) {
            printf("%d ", grid[r][d]);
        }
        printf("\n");
    }
}

bool find_empty_position(int grid[N][N], int *row, int *col) {
    for (*row = 0; *row < N; (*row)++) {
        for (*col = 0; *col < N; (*col)++) {
            if (grid[*row][*col] == 0) {
                return true; // Found an empty position
            }
        }
    }
    return false; // No empty position found
}

bool is_safe(int grid[N][N], int row, int col, int num) {
    // Check if the number is not in the current row
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num) {
            return false;
        }
    }

    // Check if the number is not in the current column
    for (int x = 0; x < N; x++) {
        if (grid[x][col] == num) {
            return false;
        }
    }

    // Check if the number is not in the current 3x3 box
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }
    return true;
}

bool solve_sudoku(int grid[N][N]) {
    int row, col;

    // If there is no empty space, we are done
    if (!find_empty_position(grid, &row, &col)) {
        return true; // Puzzle solved
    }

    // Try numbers 1 to 9
    for (int num = 1; num <= 9; num++) {
        if (is_safe(grid, row, col, num)) {
            // Assigning a number to the empty cell
            grid[row][col] = num;

            // Recur to see if this leads to a solution
            if (solve_sudoku(grid)) {
                return true;
            }

            // If no number was valid, backtrack
            grid[row][col] = 0; // Reset the cell
        }
    }
    return false; // Trigger backtracking
}

int main() {
    int grid[N][N] = {0}; // Initialize grid with zeros (empty cells)

    printf("Enter the Sudoku puzzle (use 0 for empty cells):\n");
    for (int r = 0; r < N; r++) {
        for (int d = 0; d < N; d++) {
            scanf("%d", &grid[r][d]);
        }
    }

    if (solve_sudoku(grid)) {
        printf("\nSolved Sudoku:\n");
        print_grid(grid);
    } else {
        printf("No solution exists for the given Sudoku puzzle.\n");
    }

    return 0;
}