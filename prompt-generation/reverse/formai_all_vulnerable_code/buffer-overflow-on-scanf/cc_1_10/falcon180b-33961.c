//Falcon-180B DATASET v1.0 Category: Table Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

void initializeBoard(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = '-';
        }
    }
}

void drawBoard(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkForWinner(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }

    for (int j = 0; j < COLS; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return 1;
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }

    return 0;
}

int main() {
    srand(time(NULL));

    char board[ROWS][COLS];
    initializeBoard(board);

    int players = 2;
    int currentPlayer = 1;

    while (players > 0) {
        drawBoard(board);
        printf("Player %d's turn\n", currentPlayer);

        int row, col;
        scanf("%d %d", &row, &col);

        if (board[row - 1][col - 1] == '-') {
            board[row - 1][col - 1] = (currentPlayer == 1)? 'X' : 'O';
            currentPlayer = (currentPlayer == 1)? 2 : 1;
            players--;
        } else {
            printf("Invalid move\n");
        }
    }

    if (checkForWinner(board)) {
        printf("Player %d wins!\n", (players == 1)? 1 : 2);
    } else {
        printf("It's a tie!\n");
    }

    return 0;
}