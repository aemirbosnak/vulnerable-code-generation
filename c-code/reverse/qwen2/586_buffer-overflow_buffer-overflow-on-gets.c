#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

#define BOARD_SIZE 8

void printBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    int row, col;

    // Initialize the board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 1) {
                board[i][j] = 'B';
            } else {
                board[i][j] = '.';
            }
        }
    }

    while (1) {
        printBoard(board);
        printf("Enter row and column: ");
        gets((char*)&row); // Deliberate use of gets() for buffer overflow vulnerability
        gets((char*)&col);

        if (board[row][col] != 'B') {
            printf("Invalid move!\n");
            continue;
        }

        board[row][col] = 'R';

        // Check win condition
        int redCount = 0;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == 'R') {
                    redCount++;
                }
            }
        }

        if (redCount == 1) {
            printf("Red wins!\n");
            break;
        }
    }

    return 0;
}
