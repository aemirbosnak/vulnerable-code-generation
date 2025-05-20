//Falcon-180B DATASET v1.0 Category: Chess engine ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8
#define EMPTY 0
#define WHITE 1
#define BLACK 2

int board[SIZE][SIZE];

void initBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }
}

void printBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == EMPTY) {
                printf(" ");
            } else if (board[i][j] == WHITE) {
                printf("W");
            } else {
                printf("B");
            }
        }
        printf("\n");
    }
}

int checkWin(int player) {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }
    return 0;
}

int main() {
    initBoard();
    int player = WHITE;
    int x, y;
    while (1) {
        printBoard();
        printf("Player %d's turn\n", player);
        scanf("%d%d", &x, &y);
        if (board[x][y] == EMPTY) {
            board[x][y] = player;
            if (checkWin(player)) {
                printf("Player %d wins!\n", player);
                break;
            } else {
                player = (player == WHITE)? BLACK : WHITE;
            }
        } else {
            printf("Invalid move\n");
        }
    }
    return 0;
}