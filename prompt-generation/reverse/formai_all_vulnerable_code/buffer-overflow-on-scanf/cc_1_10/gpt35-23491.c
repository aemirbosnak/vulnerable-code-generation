//FormAI DATASET v1.0 Category: Sudoku solver ; Style: Cyberpunk
#include <stdio.h>

#define N 9
#define UNASSIGNED 0

int grid[N][N];

int findUnassigned(int *row, int *col);
int isSafe(int row, int col, int num);
int solveSudoku();

int main() {
    printf("Enter the Sudoku grid:\n");
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    if(solveSudoku()) {
        printf("Solved Sudoku grid:\n");
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
    }
    else {
        printf("Invalid Sudoku grid\n");
    }

    return 0;
}

int findUnassigned(int *row, int *col) {
    for(*row = 0; *row < N; (*row)++) {
        for(*col = 0; *col < N; (*col)++) {
            if(grid[*row][*col] == UNASSIGNED) {
                return 1;
            }
        }
    }
    return 0;
}

int isSafe(int row, int col, int num) {
    int i, j;

    // Check row and column
    for(i = 0; i < N; i++) {
        if(grid[row][i] == num || grid[i][col] == num) {
            return 0;
        }
    }

    // Check sub-grid
    int start_row = row - row%3;
    int start_col = col - col%3;

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            if(grid[start_row+i][start_col+j] == num) {
                return 0;
            }
        }
    }

    // If safe
    return 1;
}

int solveSudoku() {
    int row, col;

    if(!findUnassigned(&row, &col)) {
        return 1;
    }

    for(int num = 1; num <= N; num++) {
        if(isSafe(row, col, num)) {
            grid[row][col] = num;

            if(solveSudoku()) {
                return 1;
            }

            grid[row][col] = UNASSIGNED;
        }
    }

    return 0;
}