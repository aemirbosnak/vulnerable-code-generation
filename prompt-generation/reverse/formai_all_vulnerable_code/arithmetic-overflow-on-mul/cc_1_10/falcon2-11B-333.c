//Falcon2-11B DATASET v1.0 Category: Tic Tac Toe AI ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 3
#define MAX_COLS 3
#define EMPTY 0
#define X 1
#define O 2

typedef struct board {
    int rows[MAX_ROWS];
    int cols[MAX_COLS];
} Board;

void print_board(Board* board) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            printf("%d ", board->rows[i] * 3 + board->cols[j]);
        }
        printf("\n");
    }
}

void print_board_row(int row) {
    for (int i = 0; i < MAX_COLS; i++) {
        printf("%d ", row * 3 + i);
    }
    printf("\n");
}

void print_board_col(int col) {
    for (int i = 0; i < MAX_ROWS; i++) {
        printf("%d ", i * 3 + col);
    }
    printf("\n");
}

void make_move(Board* board, int row, int col, int player) {
    board->rows[row] = player;
    board->cols[col] = player;
}

int check_winner(Board* board, int player) {
    int row_winner = 0;
    int col_winner = 0;
    int diag_winner = 0;

    for (int i = 0; i < MAX_ROWS; i++) {
        if (board->rows[i] == player) {
            row_winner = 1;
        }
    }

    for (int j = 0; j < MAX_COLS; j++) {
        if (board->cols[j] == player) {
            col_winner = 1;
        }
    }

    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            if (board->rows[i] == player && board->cols[j] == player) {
                diag_winner = 1;
            }
        }
    }

    if (row_winner || col_winner || diag_winner) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    Board board;
    int player = 0;
    int turn = 0;
    int row, col;

    while (turn < 9) {
        print_board(&board);
        printf("Player %d's turn.\n", player == 0? 1 : 2);
        scanf("%d %d", &row, &col);
        make_move(&board, row - 1, col - 1, player);
        if (check_winner(&board, player) == 1) {
            printf("Player %d wins!\n", player);
            break;
        }
        player = player == 0? 1 : 0;
        turn++;
    }

    return 0;
}