//FormAI DATASET v1.0 Category: Sudoku solver ; Style: optimized
#include <stdio.h>

#define SIZE 9

int sudoku[SIZE][SIZE];

int empty_cells();

int check_row(int row, int value);

int check_col(int col, int value);

int check_square(int row, int col, int value);

int solve_sudoku();

void print_sudoku();

int main() {
    printf("Enter 81 numbers ('0' for empty cells) to represent the Sudoku puzzle:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &sudoku[i][j]);
        }
    }

    if (solve_sudoku()) {
        printf("Solved Sudoku puzzle:\n");
        print_sudoku();
    } else {
        printf("No solution found!\n");
    }

    return 0;
}

int empty_cells() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (sudoku[i][j] == 0) {
                return 1;
            }
        }
    }
    return 0;
}

int check_row(int row, int value) {
    for (int i = 0; i < SIZE; i++) {
        if (sudoku[row][i] == value) {
            return 1;
        }
    }
    return 0;
}

int check_col(int col, int value) {
    for (int i = 0; i < SIZE; i++) {
        if (sudoku[i][col] == value) {
            return 1;
        }
    }
    return 0;
}

int check_square(int row, int col, int value) {
    int start_row = row - row % 3;
    int start_col = col - col % 3;
    for (int i = start_row; i < start_row + 3; i++) {
        for (int j = start_col; j < start_col + 3; j++) {
            if (sudoku[i][j] == value) {
                return 1;
            }
        }
    }
    return 0;
}

int solve_sudoku() {
    int row, col;
    if (!empty_cells()) {
        return 1;
    }
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (sudoku[row][col] == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (!check_row(row, num) && !check_col(col, num) && !check_square(row, col, num)) {
                        sudoku[row][col] = num;
                        if (solve_sudoku()) {
                            return 1;
                        } else {
                            sudoku[row][col] = 0;
                        }
                    }
                }
                return 0;
            }
        }
    }
    return 1;
}

void print_sudoku() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", sudoku[i][j]);
        }
        printf("\n");
    }
}