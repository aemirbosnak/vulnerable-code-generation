#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 10

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
    char player1[50], player2[50];
    int row, col;

    printf("Enter Player 1's name: ");
    gets(player1);
    printf("Enter Player 2's name: ");
    gets(player2);

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

    while (1) {
        printBoard(board);
        printf("%s's turn. Enter row and column: ", player1);
        scanf("%d %d", &row, &col);
        board[row][col] = 'X';

        printBoard(board);
        printf("%s's turn. Enter row and column: ", player2);
        scanf("%d %d", &row, &col);
        board[row][col] = 'O';
    }

    return 0;
}
