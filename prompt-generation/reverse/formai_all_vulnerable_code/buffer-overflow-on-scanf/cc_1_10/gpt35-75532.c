//FormAI DATASET v1.0 Category: Sudoku solver ; Style: futuristic
#include <stdio.h>

#define N 9

int grid[N][N];

int findUnassigned(int *row, int *col) {
    for (*row = 0; *row < N; (*row)++) {
        for (*col = 0; *col < N; (*col)++) {
            if (grid[*row][*col] == 0) {
                return 1;
            }
        }
    }
    return 0;
}

int usedInRow(int row, int num) {
    for (int col = 0; col < N; col++) {
        if (grid[row][col] == num) {
            return 1;
        }
    }
    return 0;
}

int usedInCol(int col, int num) {
    for (int row = 0; row < N; row++) {
        if (grid[row][col] == num) {
            return 1;
        }
    }
    return 0;
}

int usedInBox(int boxStartRow, int boxStartCol, int num) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (grid[row + boxStartRow][col + boxStartCol] == num) {
                return 1;
            }
        }
    }
    return 0;
}

int isSafe(int row, int col, int num) {
    return !usedInRow(row, num) && !usedInCol(col, num) && !usedInBox(row - row % 3, col - col % 3, num);
}

int solveSudoku() {
    int row, col;
    if (!findUnassigned(&row, &col)) {
        return 1;
    }
    for (int num = 1; num <= 9; num++) {
        if (isSafe(row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku()) {
                return 1;
            }
            grid[row][col] = 0;
        }
    }
    return 0;
}

void printGrid() {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

int main() {
    printf("Enter the Sudoku puzzle (0 for empty spaces):\n");
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            scanf("%d", &grid[row][col]);
        }
    }
    if (solveSudoku()) {
        printf("\nSolution:\n");
        printGrid();
    } else {
        printf("\nNo solution exists.\n");
    }
    return 0;
}