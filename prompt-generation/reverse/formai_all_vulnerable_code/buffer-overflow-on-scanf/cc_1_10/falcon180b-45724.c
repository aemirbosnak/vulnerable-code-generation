//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROWS 4
#define COLS 4

void createBoard(char board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = '-';
        }
    }
}

void printBoard(char board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void placeCard(char board[ROWS][COLS], int row, int col) {
    if (board[row][col] == '-') {
        board[row][col] = '*';
    } else {
        printf("Invalid move\n");
    }
}

int checkMatch(char board[ROWS][COLS], int row, int col) {
    if (board[row][col]!= '-' && board[row][col]!= '*') {
        return 1;
    } else if (board[row][col] == '-') {
        return 0;
    }
}

int checkWin(char board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (board[i][j] == '-') {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    srand(time(NULL));
    char board[ROWS][COLS];
    createBoard(board);
    int player = 1;
    int moves = 0;
    while (!checkWin(board)) {
        printBoard(board);
        int row, col;
        printf("Player %d's turn\n", player);
        scanf("%d %d", &row, &col);
        row--;
        col--;
        if (checkMatch(board, row, col)) {
            placeCard(board, row, col);
            if (checkWin(board)) {
                printf("Player %d wins!\n", player);
                break;
            } else {
                player++;
            }
        } else {
            printf("Invalid move\n");
        }
        moves++;
        if (moves == 10) {
            printf("It's a draw.\n");
            break;
        }
    }
    return 0;
}