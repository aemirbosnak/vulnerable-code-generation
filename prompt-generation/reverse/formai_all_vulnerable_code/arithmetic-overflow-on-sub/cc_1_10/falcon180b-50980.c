//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: random
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
        if (board[row][col] == '-') {
            board[row][col] = 'X';
        }
    }
}

int checkWin(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == board[i][3]) {
            return 1;
        }
    }
    for (int j = 0; j < COLS; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[2][j] == board[3][j]) {
            return 1;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == board[3][3]) {
        return 1;
    }
    if (board[0][3] == board[1][2] && board[1][2] == board[2][1] && board[2][1] == board[3][0]) {
        return 1;
    }
    return 0;
}

int main() {
    srand(time(NULL));
    char board[ROWS][COLS];
    initBoard(board);
    int player = 1;
    while (1) {
        printf("Player %d's turn.\n", player);
        int row, col;
        scanf("%d %d", &row, &col);
        row--; col--;
        if (board[row][col] == '-') {
            placeCard(board, row, col);
            if (checkWin(board)) {
                printf("Player %d wins!\n", player);
                break;
            }
            player++;
            if (player > 2) {
                player = 1;
            }
        } else {
            printf("Invalid move.\n");
        }
        printBoard(board);
    }
    return 0;
}