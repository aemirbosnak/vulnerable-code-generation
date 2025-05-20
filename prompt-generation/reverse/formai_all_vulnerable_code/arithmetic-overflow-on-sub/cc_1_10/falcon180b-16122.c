//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3

enum player_t {
    PLAYER_X = 1,
    PLAYER_O = 2,
    PLAYER_EMPTY = 0
};

void print_board(enum player_t board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int check_winner(enum player_t board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i])) {
            return board[i][i];
        }
    }

    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        return board[0][0];
    }

    return PLAYER_EMPTY;
}

int check_tie(enum player_t board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == PLAYER_EMPTY) {
                return 0;
            }
        }
    }
    return 1;
}

void make_move(enum player_t board[BOARD_SIZE][BOARD_SIZE], int row, int col) {
    if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE &&
        board[row][col] == PLAYER_EMPTY) {
        board[row][col] = PLAYER_X;
    }
}

int main() {
    enum player_t board[BOARD_SIZE][BOARD_SIZE] = {{PLAYER_EMPTY}};
    int current_player = PLAYER_X;

    while (1) {
        system("clear");
        print_board(board);

        int row, col;
        printf("Player %d's turn. Enter row and column: ", current_player);
        scanf("%d%d", &row, &col);

        --row;
        --col;

        make_move(board, row, col);

        if (check_winner(board)!= PLAYER_EMPTY) {
            printf("Player %d wins!\n", check_winner(board));
            break;
        } else if (check_tie(board)) {
            printf("Tie game.\n");
            break;
        }

        current_player = (current_player == PLAYER_X)? PLAYER_O : PLAYER_X;
    }

    return 0;
}