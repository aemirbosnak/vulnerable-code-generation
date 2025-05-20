//FormAI DATASET v1.0 Category: Sudoku solver ; Style: decentralized
#include <stdio.h>
#include <stdbool.h>

// Check if the value is valid in a specific cell of the sudoku grid
bool is_valid(int grid[][9], int row, int col, int value) {
    // Check the row
    for (int i = 0; i < 9; i++) {
        if (grid[row][i] == value) {
            return false;
        }
    }
    // Check the column
    for (int i = 0; i < 9; i++) {
        if (grid[i][col] == value) {
            return false;
        }
    }
    // Check the small square
    int square_row = (row / 3) * 3;
    int square_col = (col / 3) * 3;
    for (int i = square_row; i < square_row + 3; i++) {
        for (int j = square_col; j < square_col + 3; j++) {
            if (grid[i][j] == value) {
                return false;
            }
        }
    }
    return true;
}

// Solve the sudoku grid recursively
bool solve_grid(int grid[][9], int row, int col) {
    // If we reached the end of the grid, return true
    if (row == 9) {
        return true;
    }
    // If we reached the end of the column, move to the next row
    if (col == 9) {
        return solve_grid(grid, row + 1, 0);
    }
    // If the cell is already filled, move to the next one
    if (grid[row][col] != 0) {
        return solve_grid(grid, row, col + 1);
    }
    // Try every possible value for the cell
    for (int i = 1; i <= 9; i++) {
        if (is_valid(grid, row, col, i)) {
            grid[row][col] = i;
            if (solve_grid(grid, row, col + 1)) {
                return true;
            }
            grid[row][col] = 0;
        }
    }
    return false;
}

// Print the sudoku grid
void print_grid(int grid[][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Initialize the sudoku grid
    int grid[9][9] = {
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
    // Prompt the user to input the sudoku grid
    printf("Enter the sudoku grid (use 0 for empty cells):\n");
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    // Solve the sudoku grid
    if (solve_grid(grid, 0, 0)) {
        printf("Solution:\n");
        print_grid(grid);
    } else {
        printf("No solution found.\n");
    }
    return 0;
}