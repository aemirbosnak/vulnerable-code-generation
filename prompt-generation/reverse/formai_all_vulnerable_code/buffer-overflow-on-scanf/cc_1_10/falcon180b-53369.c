//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: minimalist
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
            board[row][col] = '*';
        }
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

int main() {
    srand(time(NULL));
    char board[ROWS][COLS];
    initBoard(board);
    int player = 1;
    int moves = 0;

    while (1) {
        system("clear");
        printBoard(board);
        int row, col;
        printf("Player %d's turn. Enter row and column: ", player);
        scanf("%d %d", &row, &col);

        if (checkMatch(board, row, col)) {
            printf("Match found!\n");
            placeCard(board, row, col);
            if (player == 1) {
                player = 2;
            } else {
                player = 1;
            }
            moves++;
        } else {
            printf("No match.\n");
            if (moves % 2 == 0) {
                placeCard(board, row, col);
            }
            if (player == 1) {
                player = 2;
            } else {
                player = 1;
            }
            moves++;
        }

        if (moves == 8) {
            break;
        }
    }

    return 0;
}