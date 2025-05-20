//Falcon-180B DATASET v1.0 Category: Checkers Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 8
#define BLACK 'B'
#define WHITE 'W'
#define EMPTY '.'

char board[SIZE][SIZE];

void initBoard() {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }
}

int validMove(int row, int col) {
    int dx, dy;
    if (row >= 0 && row < SIZE && col >= 0 && col < SIZE) {
        if (board[row][col] == EMPTY) {
            return 1;
        } else if (board[row][col] == BLACK && row - col == 0) {
            return 2;
        } else if (board[row][col] == WHITE && row - col == 0) {
            return 3;
        }
    }
    return 0;
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

int main() {
    int player = 1;
    int row, col;
    int choice;
    char piece;
    initBoard();
    while (1) {
        printBoard();
        printf("Player %d's turn\n", player);
        printf("Enter your move (row col): ");
        scanf("%d %d", &row, &col);
        if (!validMove(row, col)) {
            printf("Invalid move\n");
            continue;
        }
        if (board[row][col] == EMPTY) {
            if (player == 1) {
                piece = BLACK;
            } else {
                piece = WHITE;
            }
            board[row][col] = piece;
            player++;
        } else if (board[row][col] == BLACK && player == 1) {
            board[row][col] = WHITE;
            player++;
        } else if (board[row][col] == WHITE && player == 2) {
            board[row][col] = BLACK;
            player++;
        }
        if (checkWin(player)) {
            printf("Player %d wins!\n", player);
            break;
        }
    }
    return 0;
}

int checkWin(int player) {
    int i, j;
    int count = 0;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (board[i][j] == player) {
                count++;
            }
        }
    }
    if (count == 12) {
        return 1;
    }
    return 0;
}