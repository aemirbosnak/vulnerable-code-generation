#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

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
        printf("Enter your move (row col): ");
        gets(&board[row][col]); // Intentional buffer overflow vulnerability
    }

    return 0;
}
