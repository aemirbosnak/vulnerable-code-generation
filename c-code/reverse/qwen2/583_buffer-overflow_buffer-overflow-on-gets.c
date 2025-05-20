#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BOARD_SIZE 15

void printBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(char board[BOARD_SIZE][BOARD_SIZE], char player) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        int count = 0;
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == player) {
                count++;
                if (count >= 5) return 1;
            } else {
                count = 0;
            }
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        int count = 0;
        for (int i = 0; i < BOARD_SIZE; i++) {
            if (board[i][j] == player) {
                count++;
                if (count >= 5) return 1;
            } else {
                count = 0;
            }
        }
    }

    return 0;
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    memset(board, '.', sizeof(board));
    int currentPlayer = 0;

    while (1) {
        printBoard(board);
        printf("Player %d's turn. Enter row and column: ", currentPlayer + 1);
        int row, col;
        scanf("%d %d", &row, &col);

        if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || board[row][col] != '.') {
            printf("Invalid move. Try again.\n");
            continue;
        }

        board[row][col] = (currentPlayer == 0) ? 'X' : 'O';

        if (checkWin(board, board[row][col])) {
            printBoard(board);
            printf("Player %d wins!\n", currentPlayer + 1);
            break;
        }

        currentPlayer = 1 - currentPlayer;
    }

    return 0;
}
