//Falcon-180B DATASET v1.0 Category: Checkers Game ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 8
#define EMPTY '.'
#define PLAYER1 'X'
#define PLAYER2 'O'

char board[SIZE][SIZE];
int turn = 1;

void initBoard() {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }
}

void printBoard() {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin() {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        if ((board[i][0] == PLAYER1 && board[i][1] == PLAYER1 && board[i][2] == PLAYER1) ||
            (board[0][i] == PLAYER1 && board[1][i] == PLAYER1 && board[2][i] == PLAYER1)) {
            return 1;
        }
    }
    for (i = 0; i < SIZE; i++) {
        if ((board[i][SIZE - 1] == PLAYER1 && board[i][SIZE - 2] == PLAYER1 && board[i][SIZE - 3] == PLAYER1) ||
            (board[SIZE - 1][i] == PLAYER1 && board[SIZE - 2][i] == PLAYER1 && board[SIZE - 3][i] == PLAYER1)) {
            return 1;
        }
    }
    for (j = 0; j < SIZE; j++) {
        if ((board[0][j] == PLAYER1 && board[1][j] == PLAYER1 && board[2][j] == PLAYER1) ||
            (board[SIZE - 1][j] == PLAYER1 && board[SIZE - 2][j] == PLAYER1 && board[SIZE - 3][j] == PLAYER1)) {
            return 1;
        }
    }
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (board[i][j]!= EMPTY) {
                return 0;
            }
        }
    }
    return 0;
}

void switchTurn() {
    if (turn == 1) {
        turn = 2;
    } else {
        turn = 1;
    }
}

int main() {
    srand(time(NULL));
    initBoard();
    printBoard();

    int x, y;
    while (1) {
        printf("Player %d, enter your move (row, col): ", turn);
        scanf("%d %d", &x, &y);
        if (board[x - 1][y - 1] == EMPTY) {
            board[x - 1][y - 1] = (turn == 1)? PLAYER1 : PLAYER2;
            switchTurn();
            printBoard();
            if (checkWin()) {
                printf("Player %d wins!\n", turn);
                break;
            }
        } else {
            printf("Invalid move.\n");
        }
    }
    return 0;
}