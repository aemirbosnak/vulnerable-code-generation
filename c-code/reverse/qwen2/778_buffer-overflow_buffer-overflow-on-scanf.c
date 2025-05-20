#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

#define SIZE 6

void printBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(char board[SIZE][SIZE], char player) {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return 1;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return 1;
    }
    return 0;
}

int main() {
    char board[SIZE][SIZE] = {0};
    int x, y;
    char currentPlayer = 'X';

    while (1) {
        printBoard(board);
        printf("Player %c, enter your move (row col): ", currentPlayer);
        scanf("%d %d", &x, &y);

        if (x >= 0 && x < SIZE && y >= 0 && y < SIZE && board[x][y] == 0) {
            board[x][y] = currentPlayer;
            if (checkWin(board, currentPlayer)) {
                printBoard(board);
                printf("Player %c wins!\n", currentPlayer);
                break;
            }
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            printf("Invalid move. Try again.\n");
        }
    }

    return 0;
}
