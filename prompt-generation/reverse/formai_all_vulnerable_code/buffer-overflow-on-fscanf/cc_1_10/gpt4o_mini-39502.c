//GPT-4o-mini DATASET v1.0 Category: Sudoku solver ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

#define SIZE 9

// Function to print the Sudoku grid
void printGrid(int grid[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

// Check if a number can be placed in the specified position
int isSafe(int grid[SIZE][SIZE], int row, int col, int num) {
    // Check the current row and column
    for (int x = 0; x < SIZE; x++) {
        if (grid[row][x] == num || grid[x][col] == num) {
            return 0;
        }
    }

    // Check the 3x3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) {
                return 0;
            }
        }
    }
    return 1;
}

// Solve the Sudoku using backtracking
int solveSudoku(int grid[SIZE][SIZE]) {
    int row, col;
    int isEmpty = 1;

    // Find an empty space in the grid
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (grid[row][col] == 0) {
                isEmpty = 0; // There is an empty space
                break;
            }
        }
        if (!isEmpty) break;
    }

    // If there is no empty space, we are done
    if (isEmpty) return 1;

    // Try placing numbers 1 to 9 in the empty space
    for (int num = 1; num <= SIZE; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num; // Place the number

            // Recur to see if this leads to a solution
            if (solveSudoku(grid)) {
                return 1;
            }

            // If this doesn't lead to a solution, reset the cell
            grid[row][col] = 0;
        }
    }
    return 0; // Trigger backtracking
}

// Load a Sudoku puzzle from a file
int loadPuzzle(const char *filename, int grid[SIZE][SIZE]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file %s for reading\n", filename);
        return 0;
    }
    
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            fscanf(file, "%d", &grid[row][col]);
        }
    }
    
    fclose(file);
    return 1;
}

// Main function to run the Sudoku solver
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <puzzle_file>\n", argv[0]);
        return 1;
    }
    
    int grid[SIZE][SIZE] = {0};

    // Load the Sudoku puzzle from the specified file
    if (!loadPuzzle(argv[1], grid)) {
        return 1;
    }

    printf("Original Sudoku Grid:\n");
    printGrid(grid);

    if (solveSudoku(grid)) {
        printf("Solved Sudoku Grid:\n");
        printGrid(grid);
    } else {
        printf("No solution exists for the given Sudoku puzzle.\n");
    }

    return 0;
}