//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define PLAYERS 2

void initializeBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '-';
        }
    }
}

void printBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(char board[BOARD_SIZE][BOARD_SIZE], int player) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[i][2] == player && board[i][1] == player && board[i][0] == player)) {
            return player;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if ((board[0][j] == player && board[1][j] == player && board[2][j] == player) ||
            (board[2][j] == player && board[1][j] == player && board[0][j] == player)) {
            return player;
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[2][0] == player && board[1][1] == player && board[0][2] == player)) {
        return player;
    }

    return 0;
}

int main() {
    srand(time(NULL));
    char board[BOARD_SIZE][BOARD_SIZE];
    int player = 1; // X starts first

    initializeBoard(board);

    while (1) {
        printBoard(board);
        int x, y;
        if (player == 1) {
            printf("Player 1's turn. Enter your move (row and column): ");
            scanf("%d %d", &x, &y);
            if (board[x][y]!= '-') {
                printf("Invalid move. Try again.\n");
                continue;
            }
            board[x][y] = 'X';
            player = 2;
            if (checkWin(board, player) == player) {
                printf("Player %d wins!\n", player);
                break;
            }
        } else {
            printf("Player 2's turn. Enter your move (row and column): ");
            scanf("%d %d", &x, &y);
            if (board[x][y]!= '-') {
                printf("Invalid move. Try again.\n");
                continue;
            }
            board[x][y] = 'O';
            player = 1;
            if (checkWin(board, player) == player) {
                printf("Player %d wins!\n", player);
                break;
            }
        }
    }

    return 0;
}