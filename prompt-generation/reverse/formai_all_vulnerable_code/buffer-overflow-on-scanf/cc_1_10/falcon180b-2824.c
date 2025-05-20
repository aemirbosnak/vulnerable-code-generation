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

void placeCard(char board[ROWS][COLS], int row, int col, char card) {
    board[row][col] = card;
}

int checkMatch(char board[ROWS][COLS], int row, int col) {
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        return 0;
    }

    if (board[row][col] == '-') {
        return 0;
    }

    return 1;
}

int checkWin(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == '-') {
                return 0;
            }
        }
    }

    return 1;
}

void flipCard(char board[ROWS][COLS], int row, int col) {
    if (checkMatch(board, row, col)) {
        board[row][col] = '-';
    } else {
        board[row][col] = (board[row][col] == '1'? '2' : '1');
    }
}

int main() {
    srand(time(NULL));

    char board[ROWS][COLS];
    initBoard(board);

    int moves = 0;
    while (1) {
        printBoard(board);
        printf("Moves: %d\n", moves);

        int row, col;
        scanf("%d %d", &row, &col);

        if (!checkMatch(board, row, col)) {
            printf("Invalid move.\n");
            continue;
        }

        flipCard(board, row, col);
        moves++;

        if (checkWin(board)) {
            printf("You win!\n");
            break;
        }
    }

    return 0;
}