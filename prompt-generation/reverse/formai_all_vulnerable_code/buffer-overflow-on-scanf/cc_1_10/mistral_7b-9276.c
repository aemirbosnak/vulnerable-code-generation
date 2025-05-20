//MISTRAL-7B DATASET v1.0 Category: Sudoku solver ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 9

bool is_valid(int grid[SIZE][SIZE], int row, int col, int num) {
    for (int i = 0; i < SIZE; i++) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return false;
        }
    }

    int box_row = row - row % 3, box_col = col - col % 3;
    for (int i = box_row; i < box_row + 3; i++) {
        for (int j = box_col; j < box_col + 3; j++) {
            if (grid[i][j] == num) {
                return false;
            }
        }
    }

    return true;
}

bool solve_sudoku(int grid[SIZE][SIZE], int row, int col) {
    if (row >= SIZE) {
        return true;
    }

    if (col >= SIZE) {
        row++;
        col = 0;
    }

    if (grid[row][col] != 0) {
        return solve_sudoku(grid, row, col + 1);
    }

    for (int num = 1; num <= SIZE; num++) {
        if (is_valid(grid, row, col, num)) {
            grid[row][col] = num;
            if (solve_sudoku(grid, row, col + 1)) {
                return true;
            }
            grid[row][col] = 0;
        }
    }

    return false;
}

void print_sudoku(int grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", grid[i][j]);
            if (j < SIZE - 1) {
                printf("|");
            }
        }
        printf("\n");
        if (i < SIZE - 1) {
            for (int j = 0; j < SIZE; j++) {
                printf("---+---");
                if (j < SIZE - 1) {
                    printf("---");
                }
            }
            printf("\n");
        }
    }
}

int main() {
    int grid[SIZE][SIZE] = {0};
    int row = 0, col = 0;

    printf("Enter a Sudoku puzzle (use 0 for empty cells):\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            char str[SIZE];
            scanf("%s", str);
            if (strlen(str) > 1) {
                sscanf(str, "%d", &grid[i][j]);
            }
            if (grid[i][j] == 0) {
                row = i;
                col = j;
            }
        }
    }

    if (solve_sudoku(grid, row, col)) {
        print_sudoku(grid);
    } else {
        printf("No solution found.\n");
    }

    return 0;
}