//GPT-4o-mini DATASET v1.0 Category: Sudoku solver ; Style: Donald Knuth
#include <stdio.h>
#include <stdbool.h>

#define N 9

// Function to print the Sudoku grid
void printGrid(int grid[N][N]) {
    for (int r = 0; r < N; r++) {
        for (int d = 0; d < N; d++) {
            printf("%d ", grid[r][d]);
        }
        printf("\n");
    }
}

// Check if a number can be placed in the given position
bool isSafe(int grid[N][N], int row, int col, int num) {
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num || grid[x][col] == num ||
            grid[row - row % 3 + x / 3][col - col % 3 + x % 3] == num) {
            return false;
        }
    }
    return true;
}

// Solve the Sudoku using backtracking
bool solveSudoku(int grid[N][N]) {
    int row, col;
    bool isEmpty = true;

    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                isEmpty = false;
                break;
            }
        }
        if (!isEmpty) break;
    }

    // If no empty space is left, the Sudoku is solved
    if (isEmpty) return true;

    // Try numbers 1 to 9
    for (int num = 1; num <= N; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;

            if (solveSudoku(grid)) return true;

            // Reset the position if num doesn't lead to a solution
            grid[row][col] = 0;
        }
    }
    return false;
}

// Read the Sudoku grid from user input
void readGrid(int grid[N][N]) {
    printf("Enter the Sudoku grid (0 for empty cells):\n");
    for (int r = 0; r < N; r++) {
        for (int d = 0; d < N; d++) {
            scanf("%d", &grid[r][d]);
        }
    }
}

int main() {
    int grid[N][N];

    readGrid(grid);

    if (solveSudoku(grid)) {
        printf("Solved Sudoku:\n");
        printGrid(grid);
    } else {
        printf("No solution exists!\n");
    }

    return 0;
}