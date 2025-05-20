#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#define SIZE 15

void printBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char board[SIZE][SIZE] = {0};
    int turn = 0;
    char player1[50], player2[50];
    printf("Enter Player 1 name: ");
    gets(player1);
    printf("Enter Player 2 name: ");
    gets(player2);

    while (turn < 225) {
        printBoard(board);
        if (turn % 2 == 0) {
            printf("%s's turn\n", player1);
        } else {
            printf("%s's turn\n", player2);
        }

        // Simplified move input handling
        int row, col;
        printf("Enter row and column: ");
        scanf("%d %d", &row, &col);

        if (board[row][col] != ' ') continue;

        if (turn % 2 == 0) {
            board[row][col] = 'X';
        } else {
            board[row][col] = 'O';
        }

        turn++;
    }

    printBoard(board);
    printf("Game ended after 225 turns.\n");

    return 0;
}
