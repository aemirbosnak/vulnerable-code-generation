//GPT-4o-mini DATASET v1.0 Category: Sudoku solver ; Style: immersive
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define SIZE 9

void printGrid(int grid[SIZE][SIZE]) {
    printf("Sudoku Grid:\n");
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

bool isSafe(int grid[SIZE][SIZE], int row, int col, int num) {
    for (int x = 0; x < SIZE; x++) {
        if (grid[row][x] == num || grid[x][col] == num ||
            grid[row - row % 3 + x / 3][col - col % 3 + x % 3] == num) {
            return false;
        }
    }
    return true;
}

bool solveSudoku(int grid[SIZE][SIZE]) {
    int row, col;
    bool isEmpty = true;
    
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (grid[row][col] == 0) {
                isEmpty = false;
                break;
            }
        }
        if (!isEmpty) {
            break;
        }
    }

    if (isEmpty) return true; // Sudoku is solved

    for (int num = 1; num <= SIZE; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;

            if (solveSudoku(grid)) {
                return true;
            }

            grid[row][col] = 0; // Backtrack
        }
    }
    return false;
}

void fillGrid(int grid[SIZE][SIZE]) {
    printf("Enter your Sudoku puzzle (0 for empty cells):\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
}

int main() {
    int grid[SIZE][SIZE] = {0};
    
    fillGrid(grid);
    printf("\nInitial Sudoku Puzzle:\n");
    printGrid(grid);
    
    if (solveSudoku(grid)) {
        printf("\nSolved Sudoku Puzzle:\n");
        printGrid(grid);
    } else {
        printf("\nNo solution exists for the given Sudoku puzzle.\n");
    }
    
    return 0;
}