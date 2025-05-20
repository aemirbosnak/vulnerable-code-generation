//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BOARD_SIZE 3
#define MOVE_SIZE 9

int board[BOARD_SIZE][BOARD_SIZE] = {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
};

int is_board_full() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 0) {
                return 0;
            }
        }
    }

    return 1;
}

int check_win(int player) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[j][0] == player && board[j][1] == player && board[j][2] == player) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }

    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }

    return 0;
}

void make_move(int move) {
    board[move / MOVE_SIZE][move % MOVE_SIZE] = 2;
}

int main() {
    int player = 1;
    int move = 0;

    srand(time(NULL));

    while (!is_board_full() && !check_win(player)) {
        move = rand() % MOVE_SIZE;

        if (board[move / MOVE_SIZE][move % MOVE_SIZE] == 0) {
            make_move(move);
            player = (player == 1) ? 2 : 1;
        }
    }

    if (check_win(player)) {
        printf("Player %d won!", player);
    } else {
        printf("It's a draw!");
    }

    return 0;
}