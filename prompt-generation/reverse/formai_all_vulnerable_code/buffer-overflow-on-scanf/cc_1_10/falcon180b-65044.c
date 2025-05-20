//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void initBoard(char board[ROWS][COLS]) {
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

int isMatch(char a, char b) {
    return (a == b);
}

void flipCard(char board[ROWS][COLS], int row, int col) {
    if (board[row][col] == '-') {
        board[row][col] = '*';
    } else if (board[row][col] == '*') {
        board[row][col] = '-';
    }
}

int main() {
    srand(time(0));
    char board[ROWS][COLS];
    initBoard(board);
    int moves = 0;
    int matches = 0;
    int gameover = 0;

    while (!gameover) {
        printBoard(board);
        int row, col;
        scanf("%d %d", &row, &col);
        flipCard(board, row, col);
        moves++;

        if (isMatch(board[row][col], board[row][col + 1])) {
            flipCard(board, row, col);
            flipCard(board, row, col + 1);
            matches++;
        } else if (isMatch(board[row][col], board[row + 1][col])) {
            flipCard(board, row, col);
            flipCard(board, row + 1, col);
            matches++;
        }

        if (matches == 8) {
            gameover = 1;
        }
    }

    if (gameover) {
        printf("Congratulations! You won in %d moves.\n", moves);
    } else {
        printf("Sorry, you lost.\n");
    }

    return 0;
}