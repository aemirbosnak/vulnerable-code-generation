//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 8
#define MAX_PLAYERS 2

void draw_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int check_winner(char board[BOARD_SIZE][BOARD_SIZE], char player) {
    int i, j;

    // Check horizontal lines
    for (i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return 1;
    }

    // Check vertical lines
    for (j = 0; j < BOARD_SIZE; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player)
            return 1;
    }

    // Check diagonal lines
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return 1;

    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return 1;

    return 0;
}

int main() {
    srand(time(NULL));
    char board[BOARD_SIZE][BOARD_SIZE];
    int player = 1;
    int moves = 0;

    // Initialize board with empty spaces
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '-';
        }
    }

    while (1) {
        system("clear");
        draw_board(board);
        printf("\nPlayer %d's turn. Enter your move (row and column): ", player);
        scanf("%d %d", &board[player - 1][0], &board[0][player - 1]);

        if (check_winner(board, player)) {
            printf("\nPlayer %d wins!\n", player);
            break;
        }

        player++;
        if (player > MAX_PLAYERS) {
            printf("\nIt's a tie.\n");
            break;
        }

        moves++;
        if (moves == 9) {
            printf("\nIt's a tie.\n");
            break;
        }
    }

    return 0;
}