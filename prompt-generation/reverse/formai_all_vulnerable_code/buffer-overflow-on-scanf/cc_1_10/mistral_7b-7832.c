//MISTRAL-7B DATASET v1.0 Category: Terminal Based Game ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 3

char board[SIZE][SIZE];

void drawBoard() {
    int i, j;

    printf("\n");
    for (i = 0; i < SIZE; i++) {
        printf("|");
        for (j = 0; j < SIZE; j++) {
            printf(" %c |", board[i][j]);
        }
        printf("\n");
        if (i < SIZE - 1) {
            printf("-----");
            for (j = 0; j < SIZE; j++) {
                printf("---");
            }
            printf("---\n");
        }
    }
}

int checkWin() {
    int i, j, k;

    for (i = 0; i < SIZE; i++) {
        if ((board[i][0] != '\0' && board[i][0] == board[i][1] && board[i][1] == board[i][2]))
            return 1;
        if ((board[0][i] != '\0' && board[0][i] == board[1][i] && board[1][i] == board[2][i]))
            return 1;
    }

    if (board[0][0] != '\0' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;

    if (board[0][2] != '\0' && board[0][2] == board[1][1] && board[1][1] == board[2][2])
        return 1;

    return 0;
}

void recursiveGame() {
    int row, col, win;

    do {
        system("clear");
        drawBoard();

        do {
            printf("Enter row and column: ");
            scanf("%d%d", &row, &col);
        } while (row < 1 || row > SIZE || col < 1 || col > SIZE || board[row - 1][col - 1] != '\0');

        board[row - 1][col - 1] = 'X';
        win = checkWin();

        if (win) {
            system("clear");
            drawBoard();
            printf("Player X wins!\n");
            return;
        }

    } while (win == 0);

    system("clear");
    drawBoard();

    do {
        printf("Enter row and column for Player O: ");
        scanf("%d%d", &row, &col);
    } while (row < 1 || row > SIZE || col < 1 || col > SIZE || board[row - 1][col - 1] != '\0');

    board[row - 1][col - 1] = 'O';

    if (checkWin()) {
        system("clear");
        drawBoard();
        printf("Player O wins!\n");
        return;
    }

    recursiveGame();
}

int main() {
    recursiveGame();

    return 0;
}