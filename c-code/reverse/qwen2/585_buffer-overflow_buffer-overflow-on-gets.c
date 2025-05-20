#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BOARD_SIZE 8

void printBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void initializeBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    memset(board, ' ', sizeof(board));
    board[3][3] = 'B';
    board[3][4] = 'W';
    board[4][3] = 'W';
    board[4][4] = 'B';
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    initializeBoard(board);
    printBoard(board);

    // Vulnerability: Buffer Overflow
    char input[10];
    printf("Enter your move (e.g., A1 B2): ");
    fgets(input, sizeof(input), stdin);
    int row = input[0] - 'A';
    int col = input[1] - '1';

    if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE) {
        board[row][col] = 'X'; // Place a marker on the board
    } else {
        printf("Invalid move!\n");
    }

    printBoard(board);
    return 0;
}
