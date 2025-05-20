//FormAI DATASET v1.0 Category: Sudoku solver ; Style: ephemeral
#include <stdio.h>
#include <stdbool.h>

int grid[9][9];

// Check if a value is already in the same row
bool inRow(int row, int value) {
    for (int col = 0; col < 9; col++) {
        if (grid[row][col] == value) {
            return true;
        }
    }
    return false;
}

// Check if a value is already in the same column
bool inColumn(int col, int value) {
    for (int row = 0; row < 9; row++) {
        if (grid[row][col] == value) {
            return true;
        }
    }
    return false;
}

// Check if a value is already in the same 3x3 box
bool inBox(int startRow, int startCol, int value) {
    for (int row = startRow; row < startRow + 3; row++) {
        for (int col = startCol; col < startCol + 3; col++) {
            if (grid[row][col] == value) {
                return true;
            }
        }
    }
    return false;
}

// Check if a value is valid to be placed in a particular cell
bool isValid(int row, int col, int value) {
    return !inRow(row, value) && !inColumn(col, value) && !inBox(row - row % 3, col - col % 3, value);
}

// Solve the sudoku puzzle using a recursive backtracking algorithm
bool solveSudoku() {
    int row, col;
    bool isFreeCell = false;

    // Find an empty cell
    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            if (grid[row][col] == 0) {
                isFreeCell = true;
                break;
            }
        }
        if (isFreeCell) {
            break;
        }
    }

    // Base case - the entire puzzle is filled
    if (row == 9 && col == 9) {
        return true;
    }

    // Try different numbers in the empty cell
    for (int value = 1; value <= 9; value++) {
        if (isValid(row, col, value)) {
            grid[row][col] = value;

            // Recursively try to solve the rest of the puzzle
            if (solveSudoku()) {
                return true;
            }

            // Backtrack if the current value did not lead to a solution
            grid[row][col] = 0;
        }
    }

    // If none of the values worked, backtrack to the previous cell
    return false;
}

// Print the solved puzzle
void printGrid() {
    printf("The solved Sudoku puzzle:\n");
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

// Driver code to test the solver function
int main() {
    printf("Enter the unsolved Sudoku puzzle (use 0 for empty cells):\n");

    // Read in the unsolved puzzle
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            scanf("%d", &grid[row][col]);
        }
    }

    // Solve the puzzle
    if (solveSudoku()) {
        printGrid();
    } else {
        printf("No solution exists for the given puzzle.");
    }
    return 0;
}