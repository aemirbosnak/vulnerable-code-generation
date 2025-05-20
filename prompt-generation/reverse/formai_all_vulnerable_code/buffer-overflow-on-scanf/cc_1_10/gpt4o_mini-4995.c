//GPT-4o-mini DATASET v1.0 Category: Sudoku solver ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define SIZE 9

void printSudoku(int grid[SIZE][SIZE]) {
    printf("\n");
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
    printf("\n");
}

int isSafe(int grid[SIZE][SIZE], int row, int col, int num) {
    for (int x = 0; x < SIZE; x++) {
        if (grid[row][x] == num || grid[x][col] == num || 
            grid[row - row % 3 + x / 3][col - col % 3 + x % 3] == num) {
            return 0; // Not safe
        }
    }
    return 1; // Safe
}

int solveSudoku(int grid[SIZE][SIZE]) {
    int row, col;
    int isEmpty = 1;

    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (grid[row][col] == 0) {
                isEmpty = 0;
                break;
            }
        }
        if (!isEmpty) {
            break;
        }
    }

    if (isEmpty) {
        return 1; // Puzzle solved
    }

    for (int num = 1; num <= SIZE; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid)) {
                return 1;
            }
            grid[row][col] = 0; // Backtrack
        }
    }

    return 0; // Trigger backtracking
}

void fillSudoku(int grid[SIZE][SIZE]) {
    printf("Enter the Sudoku puzzle (0 for empty cells):\n");
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            scanf("%d", &grid[row][col]);
        }
    }
}

int main() {
    int grid[SIZE][SIZE] = {0};

    fillSudoku(grid);
    printf("Original Sudoku Puzzle:\n");
    printSudoku(grid);

    if (solveSudoku(grid)) {
        printf("Solved Sudoku Puzzle:\n");
        printSudoku(grid);
    } else {
        printf("No solution exists for the given Sudoku puzzle.\n");
    }

    return 0;
}