//GPT-4o-mini DATASET v1.0 Category: Sudoku solver ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 16  // Maximum size for sudoku (4x4, 9x9, 16x16...)

int gridSize; // Size of the Sudoku grid
int subGridSize; // Size of the smaller squares in the grid
int sudoku[MAX_SIZE][MAX_SIZE]; // Sudoku grid

// Function prototypes
bool isSafe(int row, int col, int num);
bool solveSudoku();
void printGrid();
void initializeGrid(int size);
void configSudoku(int size);

int main() {
    int size;

    printf("Enter the size of the Sudoku grid (4 for 4x4, 9 for 9x9, 16 for 16x16): ");
    scanf("%d", &size);

    configSudoku(size);
    initializeGrid(size);

    printf("Sudoku Puzzle:\n");
    printGrid();

    if (solveSudoku()) {
        printf("\nSolved Sudoku Puzzle:\n");
        printGrid();
    } else {
        printf("\nNo solution exists!\n");
    }

    return 0;
}

// Function to check if num can be placed at (row, col)
bool isSafe(int row, int col, int num) {
    for (int x = 0; x < gridSize; x++) {
        if (sudoku[row][x] == num || sudoku[x][col] == num) // Check row and column
            return false;
    }

    int startRow = row - row % subGridSize;
    int startCol = col - col % subGridSize;

    for (int i = 0; i < subGridSize; i++) {
        for (int j = 0; j < subGridSize; j++) {
            if (sudoku[i + startRow][j + startCol] == num) // Check subgrid
                return false;
        }
    }
    return true;
}

// Function to solve the Sudoku puzzle using Backtracking
bool solveSudoku() {
    for (int row = 0; row < gridSize; row++) {
        for (int col = 0; col < gridSize; col++) {
            if (sudoku[row][col] == 0) { // Empty cell found
                for (int num = 1; num <= gridSize; num++) {
                    if (isSafe(row, col, num)) {
                        sudoku[row][col] = num; // Assign number

                        if (solveSudoku()) // Recursively attempt further
                            return true;

                        sudoku[row][col] = 0; // Backtrack
                    }
                }
                return false; // No valid number found
            }
        }
    }
    return true; // Solved
}

// Function to print the grid
void printGrid() {
    for (int row = 0; row < gridSize; row++) {
        for (int col = 0; col < gridSize; col++) {
            printf("%2d ", sudoku[row][col]);
        }
        printf("\n");
    }
}

// Function to initialize the grid with given size
void initializeGrid(int size) {
    gridSize = size;
    subGridSize = (int)sqrt(size);
    
    printf("Enter the Sudoku puzzle (0 for empty cells):\n");
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            scanf("%d", &sudoku[i][j]);
        }
    }
}

// Function to configure Sudoku settings
void configSudoku(int size) {
    if (size != 4 && size != 9 && size != 16) {
        printf("Invalid size! Please enter 4, 9 or 16.\n");
        exit(EXIT_FAILURE);
    }
}