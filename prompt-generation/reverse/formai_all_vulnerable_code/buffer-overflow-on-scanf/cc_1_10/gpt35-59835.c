//FormAI DATASET v1.0 Category: Sudoku solver ; Style: immersive
#include <stdio.h>
#include <stdbool.h>

#define N 9

int grid[N][N];

bool findEmpty(int *row, int *col) {
    for (*row = 0; *row < N; ++(*row)) {
        for (*col = 0; *col < N; ++(*col)) {
            if (grid[*row][*col] == 0) {
                return true;
            }
        }
    }
    return false;
}

bool usedInRow(int row, int num) {
    for (int col = 0; col < N; ++col) {
        if (grid[row][col] == num) {
            return true;
        }
    }
    return false;
}

bool usedInCol(int col, int num) {
    for (int row = 0; row < N; ++row) {
        if (grid[row][col] == num) {
            return true;
        }
    }
    return false;
}

bool usedInBox(int boxStartRow, int boxStartCol, int num) {
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            if (grid[row + boxStartRow][col + boxStartCol] == num) {
                return true;
            }
        }
    }
    return false;
}

bool isSafe(int row, int col, int num) {
    return !usedInRow(row, num) && !usedInCol(col, num) && !usedInBox(row - row % 3, col - col % 3, num);
}

bool solve() {
    int row, col;
    if (!findEmpty(&row, &col)) {
        return true;
    }
    for (int num = 1; num <= 9; ++num) {
        if (isSafe(row, col, num)) {
            grid[row][col] = num;
            if (solve()) {
                return true;
            }
            grid[row][col] = 0;
        }
    }
    return false;
}

void printGrid() {
    for (int row = 0; row < N; ++row) {
        for (int col = 0; col < N; ++col) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

int main() {
    printf("Enter the Sudoku grid (0 for empty cells):\n");
    for (int row = 0; row < N; ++row) {
        for (int col = 0; col < N; ++col) {
            scanf("%d", &grid[row][col]);
        }
    }
    if (solve()) {
        printf("Sudoku solved:\n");
        printGrid();
    } else {
        printf("No solution exists.\n");
    }
    return 0;
}