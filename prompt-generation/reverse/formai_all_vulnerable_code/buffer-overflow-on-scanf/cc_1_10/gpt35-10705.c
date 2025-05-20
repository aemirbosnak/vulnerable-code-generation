//FormAI DATASET v1.0 Category: Sudoku solver ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#define MAX 9

int grid[MAX][MAX];

void print_grid() {
    for (int i=0; i<MAX; i++) {
        for (int j=0; j<MAX; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int can_place(int row, int col, int num) {
    // check row
    for (int i=0; i<MAX; i++) {
        if (grid[row][i] == num) {
            return 0;
        }
    }
    // check column
    for (int i=0; i<MAX; i++) {
        if (grid[i][col] == num) {
            return 0;
        }
    }
    // check subgrid
    int sub_row = row / 3 * 3;
    int sub_col = col / 3 * 3;
    for (int i=sub_row; i<sub_row+3; i++) {
        for (int j=sub_col; j<sub_col+3; j++) {
            if (grid[i][j] == num) {
                return 0;
            }
        }
    }
    return 1;
}

int solve(int row, int col) {
    if (row == MAX) {
        return 1;
    }
    if (grid[row][col] != 0) {
        if (col == MAX-1) {
            if (solve(row+1, 0)) {
                return 1;
            }
        } else {
            if (solve(row, col+1)) {
                return 1;
            }
        }
    } else {
        for (int i=1; i<=MAX; i++) {
            if (can_place(row, col, i)) {
                grid[row][col] = i;
                if (col == MAX-1) {
                    if (solve(row+1, 0)) {
                        return 1;
                    }
                } else {
                    if (solve(row, col+1)) {
                        return 1;
                    }
                }
                grid[row][col] = 0;
            }
        }
    }
    return 0;
}

int main() {
    // read input grid
    for (int i=0; i<MAX; i++) {
        for (int j=0; j<MAX; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    // solve sudoku
    if (solve(0, 0)) {
        printf("Solution:\n");
        print_grid();
    } else {
        printf("No solution found\n");
    }
    return 0;
}