//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3
#define PLAYER_X 1
#define PLAYER_O -1
#define EMPTY 0

void print_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int check_winner(int board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }

    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return board[0][j];
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }

    return EMPTY;
}

int get_empty_cell(int board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == EMPTY) {
                return i * BOARD_SIZE + j;
            }
        }
    }
    return -1;
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE] = {{EMPTY, EMPTY, EMPTY}, {EMPTY, EMPTY, EMPTY}, {EMPTY, EMPTY, EMPTY}};
    int player = PLAYER_X;
    int moves = 0;

    while (1) {
        print_board(board);
        int choice;
        scanf("%d", &choice);
        int cell = choice - 1;

        if (board[cell / BOARD_SIZE][cell % BOARD_SIZE] == EMPTY) {
            board[cell / BOARD_SIZE][cell % BOARD_SIZE] = player;
            moves++;

            if (check_winner(board)!= EMPTY) {
                printf("Player %d wins!\n", player);
                break;
            } else if (moves == BOARD_SIZE * BOARD_SIZE) {
                printf("It's a draw.\n");
                break;
            }

            player = -player;
        }
    }

    return 0;
}