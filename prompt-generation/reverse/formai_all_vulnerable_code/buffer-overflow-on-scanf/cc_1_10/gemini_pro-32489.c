//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 9
#define EMPTY 0

// Cyberpunk-style variables
int grid[SIZE][SIZE];
int matrix[SIZE][SIZE];
int backtrackCounter = 0;
int solutionsCounter = 0;
char *matrixDisplay[SIZE][SIZE];

// Cyberpunk-style functions
void printMatrix() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%s", matrixDisplay[i][j]);
        }
        printf("\n");
    }
}

void setMatrixDisplay() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (matrix[i][j] == EMPTY) {
                matrixDisplay[i][j] = "░░";
            } else {
                matrixDisplay[i][j] = malloc(10 * sizeof(char));
                snprintf(matrixDisplay[i][j], 10, "%d", matrix[i][j]);
            }
        }
    }
}

int isSafe(int row, int col, int num) {
    // Check row
    for (int i = 0; i < SIZE; i++) {
        if (matrix[row][i] == num) {
            return 0;
        }
    }

    // Check column
    for (int i = 0; i < SIZE; i++) {
        if (matrix[i][col] == num) {
            return 0;
        }
    }

    // Check 3x3 box
    int boxRow = row / 3;
    int boxCol = col / 3;
    for (int i = boxRow * 3; i < boxRow * 3 + 3; i++) {
        for (int j = boxCol * 3; j < boxCol * 3 + 3; j++) {
            if (matrix[i][j] == num) {
                return 0;
            }
        }
    }

    return 1;
}

int solveSudoku() {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            if (matrix[row][col] == EMPTY) {
                for (int num = 1; num <= SIZE; num++) {
                    if (isSafe(row, col, num)) {
                        matrix[row][col] = num;
                        if (solveSudoku()) {
                            solutionsCounter++;
                            return 1;
                        }
                        matrix[row][col] = EMPTY;
                        backtrackCounter++;
                    }
                }
                return 0;
            }
        }
    }

    return 1;
}

int main() {
    // Initialize grid
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = EMPTY;
        }
    }

    // Get input
    printf("Enter the Sudoku puzzle (row by row):\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    // Copy grid to matrix
    memcpy(matrix, grid, sizeof(grid));

    // Set matrix display
    setMatrixDisplay();

    // Solve Sudoku
    if (solveSudoku()) {
        printf("Solution found:\n");
        printMatrix();
        printf("Solutions counter: %d\n", solutionsCounter);
        printf("Backtrack counter: %d\n", backtrackCounter);
    } else {
        printf("No solution found.\n");
    }

    return 0;
}