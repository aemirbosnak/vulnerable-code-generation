//Falcon-180B DATASET v1.0 Category: Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

void initBoard(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = '-';
        }
    }
}

int checkWin(char board[ROWS][COLS]) {
    // Check rows
    for (int i = 0; i < ROWS; i++) {
        if (board[i][0]!= '-' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < COLS; j++) {
        if (board[0][j]!= '-' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0]!= '-' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }

    if (board[0][2]!= '-' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }

    return 0;
}

void printBoard(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    char board[ROWS][COLS];
    initBoard(board);

    int players = 2;
    int currentPlayer = 1;

    while (players > 0) {
        int row, col;
        printf("Player %d's turn:\n", currentPlayer);
        printf("Enter row and column: ");
        scanf("%d %d", &row, &col);

        if (board[row - 1][col - 1] == '-') {
            board[row - 1][col - 1] = (currentPlayer == 1)? 'X' : 'O';
            currentPlayer = (currentPlayer == 1)? 2 : 1;
            players--;
        } else {
            printf("Invalid move. Try again.\n");
        }

        printBoard(board);

        if (checkWin(board)) {
            printf("Player %d wins!\n", currentPlayer);
            break;
        }
    }

    return 0;
}