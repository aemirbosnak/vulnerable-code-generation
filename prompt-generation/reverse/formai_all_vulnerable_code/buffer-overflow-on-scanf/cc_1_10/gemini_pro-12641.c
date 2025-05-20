//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define SIZE 9

int grid[SIZE][SIZE];
int solved[SIZE][SIZE];
int count;

int is_safe(int row, int col, int num) {
    for (int i = 0; i < SIZE; i++) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return 0;
        }
    }
    int r = row / 3;
    int c = col / 3;
    for (int i = r * 3; i < (r + 1) * 3; i++) {
        for (int j = c * 3; j < (c + 1) * 3; j++) {
            if (grid[i][j] == num) {
                return 0;
            }
        }
    }
    return 1;
}

void solve_sudoku() {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            if (grid[row][col] == 0) {
                for (int num = 1; num <= SIZE; num++) {
                    if (is_safe(row, col, num)) {
                        grid[row][col] = num;
                        solve_sudoku();
                        if (count == 0) {
                            grid[row][col] = 0;
                        }
                    }
                }
                return;
            }
        }
    }
    count++;
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            solved[row][col] = grid[row][col];
        }
    }
}

int main() {
    printf("Enter the Sudoku puzzle (0 for empty cells):\n");
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            scanf("%d ", &grid[row][col]);
        }
    }
    solve_sudoku();
    if (count == 0) {
        printf("No solution found.\n");
    } else {
        printf("Solution:\n");
        for (int row = 0; row < SIZE; row++) {
            for (int col = 0; col < SIZE; col++) {
                printf("%d ", solved[row][col]);
            }
            printf("\n");
        }
    }
    return 0;
}