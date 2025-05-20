//Falcon-180B DATASET v1.0 Category: Chess engine ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 8
#define EMPTY -1
#define BLACK -2
#define WHITE 2

int board[SIZE][SIZE];
int turn;

void initBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }
    turn = 1;
}

void drawBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == EMPTY) {
                printf(" %d ", i * SIZE + j);
            } else if (board[i][j] == BLACK) {
                printf("B ");
            } else if (board[i][j] == WHITE) {
                printf("W ");
            }
        }
        printf("\n");
    }
}

int isLegal(int row, int col) {
    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
        return 0;
    }
    if (board[row][col]!= EMPTY) {
        return 0;
    }
    return 1;
}

int checkWinCondition() {
    int count = 0;
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == BLACK && board[i][1] == BLACK && board[i][2] == BLACK) {
            count++;
        }
        if (board[0][i] == BLACK && board[1][i] == BLACK && board[2][i] == BLACK) {
            count++;
        }
    }
    if (count == 8) {
        printf("Black wins!\n");
        exit(0);
    }
    count = 0;
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == WHITE && board[i][1] == WHITE && board[i][2] == WHITE) {
            count++;
        }
        if (board[0][i] == WHITE && board[1][i] == WHITE && board[2][i] == WHITE) {
            count++;
        }
    }
    if (count == 8) {
        printf("White wins!\n");
        exit(0);
    }
    return 0;
}

int main() {
    srand(time(NULL));
    initBoard();
    drawBoard();
    while (1) {
        int x, y;
        printf("Enter your move (row col): ");
        scanf("%d %d", &x, &y);
        if (!isLegal(x, y)) {
            printf("Invalid move!\n");
            continue;
        }
        board[x][y] = turn == 1? BLACK : WHITE;
        turn = turn == 1? 2 : 1;
        drawBoard();
        if (checkWinCondition()) {
            break;
        }
    }
    return 0;
}