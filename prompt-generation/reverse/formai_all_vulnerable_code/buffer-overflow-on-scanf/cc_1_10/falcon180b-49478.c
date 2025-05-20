//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void initBoard(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = '-';
        }
    }
}

void printBoard(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void placeCard(char board[ROWS][COLS], int row, int col) {
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
        board[row][col] = '*';
    }
}

int checkMatch(char board[ROWS][COLS], int row, int col) {
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
        if (board[row][col] == '*') {
            return 1;
        }
    }
    return 0;
}

int checkWin(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j]!= '-') {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    srand(time(NULL));
    char board[ROWS][COLS];
    initBoard(board);
    int player = 1;
    while (1) {
        printBoard(board);
        int row, col;
        scanf("%d %d", &row, &col);
        if (checkMatch(board, row, col)) {
            printf("Player %d wins!\n", player);
            break;
        } else {
            placeCard(board, row, col);
            player++;
        }
        if (player > 2) {
            player = 1;
        }
    }
    return 0;
}