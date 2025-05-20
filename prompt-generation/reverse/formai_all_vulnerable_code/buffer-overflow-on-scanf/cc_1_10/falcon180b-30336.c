//Falcon-180B DATASET v1.0 Category: Sudoku solver ; Style: Alan Turing
#include <stdio.h>

#define SIZE 9

void print_board(int board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

void initialize_board(int board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = 0;
        }
    }
}

int is_valid(int board[SIZE][SIZE], int row, int col, int num) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        if (board[row][i] == num)
            return 0;
    }
    for (j = 0; j < SIZE; j++) {
        if (board[j][col] == num)
            return 0;
    }
    int box_row = row - row % 3;
    int box_col = col - col % 3;
    for (i = box_row; i < box_row + 3; i++) {
        for (j = box_col; j < box_col + 3; j++) {
            if (board[i][j] == num)
                return 0;
        }
    }
    return 1;
}

int search_empty(int board[SIZE][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (board[i][j] == 0)
                return 1;
        }
    }
    return 0;
}

int solve_sudoku(int board[SIZE][SIZE]) {
    int i, j;
    while (search_empty(board)) {
        for (i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++) {
                if (board[i][j] == 0) {
                    int num = 1;
                    while (!is_valid(board, i, j, num)) {
                        num++;
                    }
                    board[i][j] = num;
                }
            }
        }
    }
    print_board(board);
    return 1;
}

int main() {
    int board[SIZE][SIZE];
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            scanf("%d", &board[i][j]);
        }
    }
    solve_sudoku(board);
    return 0;
}