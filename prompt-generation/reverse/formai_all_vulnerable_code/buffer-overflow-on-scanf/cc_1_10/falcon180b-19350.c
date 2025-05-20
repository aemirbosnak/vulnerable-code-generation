//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define PLAYER_1 1
#define PLAYER_2 2
#define EMPTY 0

void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int check_winner(char board[BOARD_SIZE][BOARD_SIZE]) {
    int i;

    // Check rows
    for (i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }

    // Check columns
    for (i = 0; i < BOARD_SIZE; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i];
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }

    return EMPTY;
}

int make_move(char board[BOARD_SIZE][BOARD_SIZE], int player) {
    int row, col;
    char mark;

    if (player == PLAYER_1) {
        mark = 'X';
    } else {
        mark = 'O';
    }

    printf("Player %d's turn:\n", player);
    printf("Enter row and column: ");
    scanf("%d %d", &row, &col);

    if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == EMPTY) {
        board[row][col] = mark;
        return 1;
    }

    return 0;
}

int main() {
    srand(time(NULL));
    char board[BOARD_SIZE][BOARD_SIZE] = {{EMPTY, EMPTY, EMPTY}, {EMPTY, EMPTY, EMPTY}, {EMPTY, EMPTY, EMPTY}};
    int current_player = PLAYER_1;

    while (1) {
        system("clear");
        print_board(board);
        printf("\nCurrent player: %d\n", current_player);

        if (make_move(board, current_player)) {
            int winner = check_winner(board);

            if (winner!= EMPTY) {
                printf("\nPlayer %d wins!\n", winner);
                break;
            }

            current_player = (current_player == PLAYER_1)? PLAYER_2 : PLAYER_1;
        } else {
            printf("\nInvalid move. Try again.\n");
        }
    }

    return 0;
}