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

int main() {
    char board[BOARD_SIZE][BOARD_SIZE] = {0};
    char playerName[256];
    int row, col;

    // Initialize board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 1) {
                board[i][j] = 'O';
            } else {
                board[i][j] = '.';
            }
        }
    }

    printf("Enter your name: ");
    gets(playerName);

    while (1) {
        printBoard(board);
        printf("%s's turn. Enter move (row col): ", playerName);
        scanf("%d %d", &row, &col);

        if (board[row][col] != 'O') {
            printf("Invalid move!\n");
            continue;
        }

        board[row][col] = 'X';

        // Check for win condition
        int win = 1;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == 'O') {
                    win = 0;
                    break;
                }
            }
            if (!win) break;
        }

        if (win) {
            printf("%s wins!\n", playerName);
            break;
        }
    }

    return 0;
}
