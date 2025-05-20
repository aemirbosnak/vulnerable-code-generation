//FormAI DATASET v1.0 Category: Sudoku solver ; Style: creative
#include <stdio.h>

// Function that checks if the value is valid for that cell
int is_valid(int grid[9][9], int row, int col, int num) {
    // Check if the value is already present in the same row
    for(int i = 0; i < 9; i++) {
        if(grid[row][i] == num) return 0;
    }

    // Check if the value is already present in the same column
    for(int i = 0; i < 9; i++) {
        if(grid[i][col] == num) return 0;
    }

    // Check if the value is already present in the same 3x3 box
    int box_row = row - row % 3;
    int box_col = col - col % 3;
    for(int i = box_row; i < box_row + 3; i++) {
        for(int j = box_col; j < box_col + 3; j++) {
            if(grid[i][j] == num) return 0;
        }
    }

    // If the value is valid, return 1
    return 1;
}

// Function that recursively solves the sudoku puzzle
int solve_sudoku(int grid[9][9], int row, int col) {
    // Check if we have reached the end of the puzzle
    if(row == 8 && col == 9) {
        return 1;
    }

    // Check if we have reached the end of a row
    if(col == 9) {
        row++;
        col = 0;
    }

    // Check if we have already filled this cell
    if(grid[row][col] != 0) {
        return solve_sudoku(grid, row, col + 1);
    }

    // Try each possible value for this cell
    for(int num = 1; num <= 9; num++) {
        if(is_valid(grid, row, col, num)) {
            grid[row][col] = num;

            // Recursively solve the rest of the puzzle
            if(solve_sudoku(grid, row, col + 1)) {
                return 1;
            }
        }

        // Set the cell to 0 if the value is not valid
        grid[row][col] = 0;
    }

    // Return 0 if the puzzle could not be solved
    return 0;
}

int main() {
    // Initialize the sudoku puzzle
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

    // Prompt the user to enter the values of the puzzle
    printf("Enter the Sudoku puzzle (enter 0 for unknown cells):\n");
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    // Solve the puzzle
    if(solve_sudoku(grid, 0, 0)) {
        // Print the solution
        printf("\nSolution:\n");
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
    }
    else {
        printf("Could not solve the puzzle :(\n");
    }

    return 0;
}