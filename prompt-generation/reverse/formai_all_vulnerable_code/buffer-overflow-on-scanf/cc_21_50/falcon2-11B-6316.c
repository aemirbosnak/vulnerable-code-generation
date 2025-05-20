//Falcon2-11B DATASET v1.0 Category: Tic Tac Toe AI ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct board_t {
    char board[BOARD_SIZE][BOARD_SIZE];
} board_t;

int main() {
    // initialize board
    board_t board;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board.board[i][j] = '-';
        }
    }

    // ask player for move
    char player_input[BOARD_SIZE][BOARD_SIZE];
    int i, j;
    printf("Player 1, enter your move (row, column): ");
    for (i = 0; i < BOARD_SIZE; i++) {
        scanf("%s", player_input[i]);
        for (j = 0; j < BOARD_SIZE; j++) {
            if (player_input[i][j]!= '-') {
                board.board[i][j] = 'X';
                break;
            }
        }
    }
    printf("Player 2, enter your move (row, column): ");
    for (i = 0; i < BOARD_SIZE; i++) {
        scanf("%s", player_input[i]);
        for (j = 0; j < BOARD_SIZE; j++) {
            if (player_input[i][j]!= '-') {
                board.board[i][j] = 'O';
                break;
            }
        }
    }

    int x_wins, o_wins, tie;
    int score[BOARD_SIZE][BOARD_SIZE];
    memset(score, 0, sizeof(score));

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board.board[i][j] == 'X') {
                score[i][j] = 1;
            } else if (board.board[i][j] == 'O') {
                score[i][j] = -1;
            }
        }
    }

    // check for win
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (score[i][j] == 3) {
                x_wins++;
            } else if (score[i][j] == -3) {
                o_wins++;
            }
        }
    }
    if (x_wins == 1 || o_wins == 1) {
        if (x_wins == 1) {
            printf("Player X wins!");
        } else {
            printf("Player O wins!");
        }
    } else if (x_wins == o_wins == 0) {
        printf("It's a tie!");
    }

    // ask player if they want to play again
    char play_again;
    printf("Do you want to play again? (y/n): ");
    scanf("%c", &play_again);
    if (play_again!= 'y') {
        printf("Thanks for playing!\n");
    }

    return 0;
}