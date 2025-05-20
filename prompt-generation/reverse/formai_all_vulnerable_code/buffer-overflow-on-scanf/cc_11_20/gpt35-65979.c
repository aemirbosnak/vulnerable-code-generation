//FormAI DATASET v1.0 Category: Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void printBoard(char board[][COLS]) {
    int i, j;
    printf("\n\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf(" %c ", board[i][j]);
        }
        printf("\n\n");
    }
}

int main() {
    char board[ROWS][COLS];
    int i, j, turn = 0, row, col, validMove;
    char player;

    srand(time(NULL));

    // generate random board values
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (rand() % 2 == 0) {
                board[i][j] = 'X';
            } else {
                board[i][j] = 'O';
            }
        }
    }

    printBoard(board);

    // game loop
    while (turn < ROWS * COLS) {
        validMove = 0;
        if (turn % 2 == 0) {
            player = 'X';
        } else {
            player = 'O';
        }

        // prompt for move
        while (!validMove) {
            printf("Player %c: Enter row and column: ", player);
            scanf("%d %d", &row, &col);
            if (row >= 0 && row < ROWS && col >= 0 && col < COLS && board[row][col] != '-') {
                validMove = 1;
            } else {
                printf("Invalid move. Please try again.\n");
            }
        }

        // mark move on board
        board[row][col] = '-';
        printBoard(board);

        // check for win
        for (i = 0; i < ROWS; i++) {
            if (board[i][0] == '-' && board[i][1] == '-' && board[i][2] == '-') {
                printf("Player %c wins!\n", player);
                return 0;
            }
            if (board[0][i] == '-' && board[1][i] == '-' && board[2][i] == '-') {
                printf("Player %c wins!\n", player);
                return 0;
            }
        }
        if (board[0][0] == '-' && board[1][1] == '-' && board[2][2] == '-') {
            printf("Player %c wins!\n", player);
            return 0;
        }
        if (board[0][2] == '-' && board[1][1] == '-' && board[2][0] == '-') {
            printf("Player %c wins!\n", player);
            return 0;
        }

        turn++;
    }

    printf("Game over. It's a draw.\n");

    return 0;
}