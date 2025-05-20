//FormAI DATASET v1.0 Category: Sudoku solver ; Style: complex
#include <stdio.h>
#include <stdbool.h>

#define N 9

int grid[N][N];

bool isSafe(int row, int col, int num)
{
    for (int i = 0; i < N; i++) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return false;
        }
    }
    int sRow = (row / 3) * 3;
    int sCol = (col / 3) * 3;
    for (int i = sRow; i < sRow + 3; i++) {
        for (int j = sCol; j < sCol + 3; j++) {
            if (grid[i][j] == num) {
                return false;
            }
        }
    }
    return true;
}

bool findEmpty(int *row, int *col)
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 0) {
                *row = i;
                *col = j;
                return true;
            }
        }
    }
    return false;
}

bool solve()
{
    int row, col;
    if (!findEmpty(&row, &col)) {
        return true;
    }
    for (int i = 1; i <= 9; i++) {
        if (isSafe(row, col, i)) {
            grid[row][col] = i;
            if (solve()) {
                return true;
            }
            grid[row][col] = 0;
        }
    }
    return false;
}

void printGrid()
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    // Input your grid
    printf("Enter 9x9 Sudoku grid (0 for empty cells):\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    if (solve()) {
        printf("Solution:\n");
        printGrid();
    } else {
        printf("Failed to solve\n");
    }

    return 0;
}