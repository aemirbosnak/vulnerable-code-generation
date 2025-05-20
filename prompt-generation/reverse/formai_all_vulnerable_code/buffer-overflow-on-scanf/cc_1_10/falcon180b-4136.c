//Falcon-180B DATASET v1.0 Category: Table Game ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3
#define EMPTY '.'
#define PLAYER1 'X'
#define PLAYER2 'O'

char board[ROWS][COLS];
char currentPlayer = PLAYER1;

void initBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = EMPTY;
        }
    }
}

void printBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin() {
    for (int i = 0; i < ROWS; i++) {
        // Check rows
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) {
            return 1;
        }
    }

    for (int j = 0; j < COLS; j++) {
        // Check columns
        if (board[0][j] == currentPlayer && board[1][j] == currentPlayer && board[2][j] == currentPlayer) {
            return 1;
        }
    }

    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) {
        // Check diagonals
        return 1;
    }

    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) {
        return 1;
    }

    return 0;
}

int main() {
    srand(time(NULL));
    initBoard();

    while (1) {
        printBoard();
        int row, col;
        printf("Player %c, enter your move (row and column): ", currentPlayer);
        scanf("%d%d", &row, &col);

        if (row < 0 || row >= ROWS || col < 0 || col >= COLS || board[row][col]!= EMPTY) {
            printf("Invalid move, try again.\n");
            continue;
        }

        board[row][col] = currentPlayer;

        if (checkWin()) {
            printf("Player %c wins!\n", currentPlayer);
            break;
        }

        currentPlayer = (currentPlayer == PLAYER1)? PLAYER2 : PLAYER1;
    }

    return 0;
}