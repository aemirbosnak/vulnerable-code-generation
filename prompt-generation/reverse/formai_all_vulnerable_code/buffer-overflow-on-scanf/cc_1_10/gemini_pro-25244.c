//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 9
#define EMPTY 0

int grid[SIZE][SIZE];
int solved[SIZE][SIZE];

void print_grid() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int is_valid(int row, int col, int num) {
    for (int i = 0; i < SIZE; i++) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return 0;
        }
    }

    int box_row = row / 3;
    int box_col = col / 3;

    for (int i = box_row * 3; i < box_row * 3 + 3; i++) {
        for (int j = box_col * 3; j < box_col * 3 + 3; j++) {
            if (grid[i][j] == num) {
                return 0;
            }
        }
    }

    return 1;
}

int solve_sudoku(int row, int col) {
    if (row == SIZE) {
        return 1;
    }

    if (col == SIZE) {
        return solve_sudoku(row + 1, 0);
    }

    if (grid[row][col] != EMPTY) {
        return solve_sudoku(row, col + 1);
    }

    for (int num = 1; num <= SIZE; num++) {
        if (is_valid(row, col, num)) {
            grid[row][col] = num;
            if (solve_sudoku(row, col + 1)) {
                return 1;
            }
            grid[row][col] = EMPTY;
        }
    }

    return 0;
}

int main() {
    char line[SIZE + 1];

    for (int i = 0; i < SIZE; i++) {
        scanf("%s", line);
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = line[j] - '0';
        }
    }

    if (solve_sudoku(0, 0)) {
        print_grid();
    } else {
        printf("No solution exists");
    }

    return 0;
}