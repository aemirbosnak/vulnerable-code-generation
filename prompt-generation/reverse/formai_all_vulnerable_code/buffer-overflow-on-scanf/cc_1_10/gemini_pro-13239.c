//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 9

typedef struct {
    int val;
    bool solved;
} Cell;

typedef Cell Grid[SIZE][SIZE];

void print_grid(Grid grid) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", grid[i][j].val);
        }
        printf("\n");
    }
}

bool is_valid(Grid grid, int row, int col, int val) {
    // Check row
    for (int i = 0; i < SIZE; i++) {
        if (grid[row][i].val == val) {
            return false;
        }
    }
    
    // Check column
    for (int j = 0; j < SIZE; j++) {
        if (grid[j][col].val == val) {
            return false;
        }
    }
    
    // Check 3x3 box
    int box_row = row / 3 * 3;
    int box_col = col / 3 * 3;
    for (int i = box_row; i < box_row + 3; i++) {
        for (int j = box_col; j < box_col + 3; j++) {
            if (grid[i][j].val == val) {
                return false;
            }
        }
    }
    
    return true;
}

bool solve_sudoku(Grid grid) {
    // Find an empty cell
    int row, col;
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (!grid[row][col].solved) {
                break;
            }
        }
        if (col != SIZE) {
            break;
        }
    }

    // Base case: no empty cells left
    if (row == SIZE) {
        return true;
    }
    
    // Try all possible values for the empty cell
    for (int val = 1; val <= SIZE; val++) {
        // Check if the value is valid
        if (is_valid(grid, row, col, val)) {
            // Set the value and mark the cell as solved
            grid[row][col].val = val;
            grid[row][col].solved = true;
            
            // Recursively solve the rest of the grid
            if (solve_sudoku(grid)) {
                return true;
            }
            
            // If the recursive call failed, reset the cell
            grid[row][col].val = 0;
            grid[row][col].solved = false;
        }
    }
    
    // If no valid value was found for the empty cell, return false
    return false;
}

int main() {
    // Initialize the grid
    Grid grid;
    memset(grid, 0, sizeof(grid));
    
    // Get the input grid from the user
    printf("Enter the Sudoku grid (0 for empty cells):\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &grid[i][j].val);
            grid[i][j].solved = (grid[i][j].val != 0);
        }
    }
    
    // Solve the Sudoku grid
    if (solve_sudoku(grid)) {
        printf("Solved Sudoku grid:\n");
        print_grid(grid);
    } else {
        printf("Could not solve the Sudoku grid.\n");
    }
    
    return 0;
}