//MISTRAL-7B DATASET v1.0 Category: Sudoku solver ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define SIZE 9

void print_puzzle(int puzzle[SIZE][SIZE]);
bool is_valid(int puzzle[SIZE][SIZE], int row, int col, int num);
bool solve_sudoku(int puzzle[SIZE][SIZE], int row, int col);

int main() {
    int puzzle[SIZE][SIZE];

    printf("Enter a Sudoku puzzle (9x9 grid): \n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &puzzle[i][j]);
        }
    }

    if (solve_sudoku(puzzle, 0, 0)) {
        printf("\nSolution: \n");
        print_puzzle(puzzle);
    } else {
        printf("\nInvalid Sudoku puzzle. \n");
    }

    return 0;
}

void print_puzzle(int puzzle[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", puzzle[i][j]);
            if (j < SIZE - 1) {
                printf("|");
            }
        }
        printf("\n");
        if (i < SIZE - 1) {
            for (int k = 0; k < SIZE; k++) {
                printf("---+---");
            }
            printf("\n");
        }
    }
}

bool is_valid(int puzzle[SIZE][SIZE], int row, int col, int num) {
    for (int i = 0; i < SIZE; i++) {
        if (puzzle[row][i] == num || puzzle[i][col] == num) {
            return false;
        }
    }

    int box_row = row - row % 3;
    int box_col = col - col % 3;

    for (int i = box_row; i < box_row + 3; i++) {
        for (int j = box_col; j < box_col + 3; j++) {
            if (puzzle[i][j] == num) {
                return false;
            }
        }
    }

    return true;
}

bool solve_sudoku(int puzzle[SIZE][SIZE], int row, int col) {
    if (row >= SIZE) {
        return true;
    }

    if (col >= SIZE) {
        return solve_sudoku(puzzle, row + 1, 0);
    }

    if (puzzle[row][col] != 0) {
        return solve_sudoku(puzzle, row, col + 1);
    }

    for (int num = 1; num <= SIZE; num++) {
        if (is_valid(puzzle, row, col, num)) {
            puzzle[row][col] = num;
            if (solve_sudoku(puzzle, row, col + 1)) {
                return true;
            } else {
                puzzle[row][col] = 0;
            }
        }
    }

    return false;
}