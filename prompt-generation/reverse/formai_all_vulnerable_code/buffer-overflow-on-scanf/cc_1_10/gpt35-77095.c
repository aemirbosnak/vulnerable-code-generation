//FormAI DATASET v1.0 Category: Sudoku solver ; Style: visionary
#include<stdio.h>

int grid[9][9];

void inputGrid() {
    printf("Please enter the grid:\n");
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
}

void printGrid() {
    printf("Solved Grid:\n");
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int validEntry(int num, int row, int col) {
    for (int i = 0; i < 9; i++) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return 0;
        }
    }
    int boxRow = row - (row % 3);
    int boxCol = col - (col % 3);
    for (int i = boxRow; i < boxRow + 3; i++) {
        for (int j = boxCol; j < boxCol + 3; j++) {
            if (grid[i][j] == num) {
                return 0;
            }
        }
    }
    return 1;
}

int solveSudoku(int row, int col) {
    if (row == 9) {
        return 1;
    }
    if (col == 9) {
        return solveSudoku(row + 1, 0);
    }
    if (grid[row][col] > 0) {
        return solveSudoku(row, col + 1);
    }
    for (int num = 1; num <= 9; num++) {
        if (validEntry(num, row, col)) {
            grid[row][col] = num;
            if (solveSudoku(row, col + 1)) {
                return 1;
            }
            grid[row][col] = 0;
        }
    }
    return 0;
}

int main() {
    inputGrid();
    if (solveSudoku(0, 0)) {
        printGrid();
    } else {
        printf("Invalid input grid or no solution found.");
    }
    return 0;
}