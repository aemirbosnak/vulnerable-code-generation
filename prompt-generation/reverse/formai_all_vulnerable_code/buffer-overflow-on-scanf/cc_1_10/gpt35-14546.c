//FormAI DATASET v1.0 Category: Memory Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define ROWS 4
#define COLS 4

void init_board(int board[ROWS][COLS]) {
    int count = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = count++ + 1;
        }
    }
}

void print_board(int board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%4d", board[i][j]);
        }
        printf("\n");
    }
}

void shuffle_board(int board[ROWS][COLS]) {
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int k = rand() % ROWS;
            int l = rand() % COLS;
            int temp = board[i][j];
            board[i][j] = board[k][l];
            board[k][l] = temp;
        }
    }
}

bool is_valid_move(int board[ROWS][COLS], int row1, int col1, int row2, int col2) {
    if (row1 == row2 && col1 == col2) {
        return false;
    }
    if (board[row1][col1] == board[row2][col2]) {
        return true;
    }
    return false;
}

int main() {
    int board[ROWS][COLS];
    init_board(board);
    shuffle_board(board);
    print_board(board);

    int row1, col1, row2, col2;
    printf("Enter first move (row col): ");
    scanf("%d %d", &row1, &col1);
    printf("Enter second move (row col): ");
    scanf("%d %d", &row2, &col2);

    if (is_valid_move(board, row1, col1, row2, col2)) {
        printf("Valid move!\n");
    } else {
        printf("Invalid move!\n");
    }

    return 0;
}