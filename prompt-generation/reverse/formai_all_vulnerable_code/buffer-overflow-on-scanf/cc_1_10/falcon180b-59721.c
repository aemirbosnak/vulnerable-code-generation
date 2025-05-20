//Falcon-180B DATASET v1.0 Category: Sudoku solver ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 9

bool isValid(int grid[SIZE][SIZE], int row, int col, int num) {
    int i, j;

    for (i = 0; i < SIZE; i++) {
        if (grid[row][i] == num)
            return false;
    }

    for (i = 0; i < SIZE; i++) {
        if (grid[i][col] == num)
            return false;
    }

    int startRow = row - row % SIZE;
    int startCol = col - col % SIZE;

    for (i = startRow; i < startRow + SIZE; i++) {
        for (j = startCol; j < startCol + SIZE; j++) {
            if (grid[i][j] == num)
                return false;
        }
    }

    return true;
}

bool fillGrid(int grid[SIZE][SIZE]) {
    int i, j;

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (grid[i][j] == 0) {
                return false;
            }
        }
    }

    return true;
}

void printGrid(int grid[SIZE][SIZE]) {
    int i, j;

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

void solveSudoku(int grid[SIZE][SIZE]) {
    int i, j, num;

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (grid[i][j] == 0) {
                for (num = 1; num <= SIZE; num++) {
                    if (isValid(grid, i, j, num)) {
                        grid[i][j] = num;

                        if (fillGrid(grid)) {
                            return;
                        } else {
                            grid[i][j] = 0;
                        }
                    }
                }

                printf("Solution not found.\n");
                exit(0);
            }
        }
    }
}

int main() {
    int grid[SIZE][SIZE];
    int i, j;

    printf("Enter the Sudoku grid:\n");

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    solveSudoku(grid);

    printf("The solution is:\n");
    printGrid(grid);

    return 0;
}