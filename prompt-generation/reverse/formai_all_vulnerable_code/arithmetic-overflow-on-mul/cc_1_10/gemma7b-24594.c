//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BOARD_SIZE 3

typedef struct GameBoard {
    int board[BOARD_SIZE][BOARD_SIZE];
    int currentPlayer;
    pthread_mutex_t mutex;
} GameBoard;

void placeMark(GameBoard *board, int row, int col) {
    pthread_mutex_lock(&board->mutex);
    if (board->board[row][col] == 0) {
        board->board[row][col] = board->currentPlayer;
    }
    pthread_mutex_unlock(&board->mutex);
}

int checkWin(GameBoard *board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board->board[0][i] == board->board[1][i] && board->board[0][i] == board->board[2][i] && board->board[0][i] != 0) {
            return board->board[0][i] * 2;
        }
    }

    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board->board[j][0] == board->board[j][1] && board->board[j][0] == board->board[j][2] && board->board[j][0] != 0) {
            return board->board[j][0] * 2;
        }
    }

    if (board->board[0][0] == board->board[1][1] && board->board[0][0] == board->board[2][2] && board->board[0][0] != 0) {
        return board->board[0][0] * 2;
    }

    return 0;
}

int main() {
    GameBoard board;
    board.currentPlayer = 1;

    pthread_mutex_init(&board.mutex, NULL);

    placeMark(&board, 1, 1);
    placeMark(&board, 2, 0);
    placeMark(&board, 0, 0);
    placeMark(&board, 1, 0);
    placeMark(&board, 2, 1);

    int winner = checkWin(&board);

    if (winner) {
        printf("The winner is player %d\n", winner);
    } else {
        printf("It's a draw\n");
    }

    return 0;
}