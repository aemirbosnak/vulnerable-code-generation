//Falcon-180B DATASET v1.0 Category: Chess engine ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8
#define BLACK 'B'
#define WHITE 'W'
#define EMPTY '.'

char board[SIZE][SIZE];
int turn = 1;

void initBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }
    board[0][0] = WHITE;
    board[0][7] = BLACK;
    board[7][0] = BLACK;
    board[7][7] = WHITE;
}

void printBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int isLegalMove(int x, int y) {
    int dx = x - 4;
    int dy = y - 4;
    switch (board[x][y]) {
        case BLACK:
            if (dx < 0) {
                return 1;
            } else if (dx > 0) {
                return 2;
            } else if (dy < 0) {
                return 3;
            } else if (dy > 0) {
                return 4;
            }
            break;
        case WHITE:
            if (dx < 0) {
                return 5;
            } else if (dx > 0) {
                return 6;
            } else if (dy < 0) {
                return 7;
            } else if (dy > 0) {
                return 8;
            }
            break;
    }
    return 0;
}

int main() {
    initBoard();
    while (1) {
        printBoard();
        int x, y;
        scanf("%d%d", &x, &y);
        int move = isLegalMove(x, y);
        if (move == 0) {
            printf("Invalid move\n");
        } else {
            board[x][y] = turn == 1? BLACK : WHITE;
            turn =!turn;
        }
    }
    return 0;
}