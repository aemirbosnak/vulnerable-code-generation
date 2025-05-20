//FormAI DATASET v1.0 Category: Sudoku solver ; Style: Dennis Ritchie
#include <stdio.h>

#define SIZE 9
#define NO_VALUE 0

int grid[SIZE][SIZE];

int findEmpty(int *row, int *col) {
    for (*row = 0; *row < SIZE; (*row)++) {
        for (*col = 0; *col < SIZE; (*col)++) {
            if (grid[*row][*col] == NO_VALUE) {
                return 1;
            }
        }
    }
    return 0;
}

int isValid(int row, int col, int num) {
    // Check row
    for (int i = 0; i < SIZE; i++) {
        if (grid[row][i] == num) {
            return 0;
        }
    }
    // Check column
    for (int i = 0; i < SIZE; i++) {
        if (grid[i][col] == num) {
            return 0;
        }
    }
    // Check sub-grid
    int subGridRow = row - row % 3;
    int subGridCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[subGridRow + i][subGridCol + j] == num) {
                return 0;
            }
        }
    }
    return 1;
}

int solve() {
    int row, col;
    if (!findEmpty(&row, &col)) {
        return 1;
    }
    for (int num = 1; num <= SIZE; num++) {
        if (isValid(row, col, num)) {
            grid[row][col] = num;
            if (solve()) {
                return 1;
            }
            grid[row][col] = NO_VALUE;
        }
    }
    return 0;
}

void printGrid() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Populate the grid with values
    printf("Enter Sudoku Grid (0 to indicate empty cells): \n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    // Solve the Sudoku
    if (solve()) {
        printf("Solved Sudoku Grid: \n");
        printGrid();
        return 0;
    } else {
        printf("Invalid Sudoku Grid. Please try again.\n");
        return 1;
    }
}