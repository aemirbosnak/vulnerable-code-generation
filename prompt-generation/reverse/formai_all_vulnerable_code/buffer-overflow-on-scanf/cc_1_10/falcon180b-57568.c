//Falcon-180B DATASET v1.0 Category: Sudoku solver ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 9
#define MAX_COLS 9
#define MAX_VALUE 9

void print_sudoku(int board[MAX_ROWS][MAX_COLS]) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int is_valid_row(int board[MAX_ROWS][MAX_COLS], int row, int value) {
    for (int i = 0; i < MAX_COLS; i++) {
        if (board[row][i] == value) {
            return 0;
        }
    }
    return 1;
}

int is_valid_col(int board[MAX_ROWS][MAX_COLS], int col, int value) {
    for (int i = 0; i < MAX_ROWS; i++) {
        if (board[i][col] == value) {
            return 0;
        }
    }
    return 1;
}

int is_valid_box(int board[MAX_ROWS][MAX_COLS], int row, int col, int value) {
    int box_row = (row / 3) * 3;
    int box_col = (col / 3) * 3;
    for (int i = box_row; i < box_row + 3; i++) {
        for (int j = box_col; j < box_col + 3; j++) {
            if (board[i][j] == value) {
                return 0;
            }
        }
    }
    return 1;
}

int is_valid_move(int board[MAX_ROWS][MAX_COLS], int row, int col, int value) {
    return is_valid_row(board, row, value) && is_valid_col(board, col, value) && is_valid_box(board, row, col, value);
}

int solve_sudoku(int board[MAX_ROWS][MAX_COLS]) {
    int row = 0, col = 0;
    while (row < MAX_ROWS && col < MAX_COLS) {
        if (board[row][col] == 0) {
            for (int i = 1; i <= MAX_VALUE; i++) {
                if (is_valid_move(board, row, col, i)) {
                    board[row][col] = i;
                    if (solve_sudoku(board)) {
                        return 1;
                    } else {
                        board[row][col] = 0;
                    }
                }
            }
            return 0;
        }
        row++;
        if (row == MAX_ROWS) {
            row = 0;
            col++;
        }
    }
    return 1;
}

int main() {
    int board[MAX_ROWS][MAX_COLS];
    int row, col;

    // Read in the board
    for (row = 0; row < MAX_ROWS; row++) {
        for (col = 0; col < MAX_COLS; col++) {
            scanf("%d", &board[row][col]);
        }
    }

    // Solve the board
    if (solve_sudoku(board)) {
        print_sudoku(board);
    } else {
        printf("No solution found.\n");
    }

    return 0;
}