#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

#define BOARD_SIZE 6

void printBoard(int board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE] = {0};
    int currentPlayer = 1;
    int row, col;

    while (1) {
        printBoard(board);
        printf("Player %d, enter your move (row col): ", currentPlayer);
        scanf("%d %d", &row, &col);

        if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == 0) {
            board[row][col] = currentPlayer;
            if (currentPlayer == 1) {
                currentPlayer = 2;
            } else {
                currentPlayer = 1;
            }
        } else {
            printf("Invalid move. Try again.\n");
        }
    }

    return 0;
}
