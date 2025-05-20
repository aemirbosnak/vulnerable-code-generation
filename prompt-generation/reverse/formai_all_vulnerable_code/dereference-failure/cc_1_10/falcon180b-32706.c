//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
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

int flipCard(char board[ROWS][COLS], int row, int col) {
    if (board[row][col] == '-') {
        board[row][col] = '*';
        return 1;
    } else if (board[row][col] == '*') {
        board[row][col] = '-';
        return 0;
    }
    return -1;
}

int checkMatch(char board[ROWS][COLS], int row, int col) {
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        return 0;
    }

    if (board[row][col] == '*') {
        return 0;
    }

    int match = 1;
    if (row > 0 && board[row - 1][col] == board[row][col]) {
        match = 0;
    } else if (col > 0 && board[row][col - 1] == board[row][col]) {
        match = 0;
    }

    return match;
}

int main() {
    srand(time(NULL));

    char board[ROWS][COLS];
    initBoard(board);

    int moves = 0;
    while (1) {
        printBoard(board);
        int row, col;
        printf("Enter the row and column of the card you want to flip: ");
        scanf("%d %d", &row, &col);

        int match = checkMatch(board, row, col);
        if (match) {
            printf("Match! Try again.\n");
        } else {
            int result = flipCard(board, row, col);
            if (result == 1) {
                moves++;
            }

            if (moves == 6) {
                printf("You win!\n");
                break;
            }
        }
    }

    return 0;
}