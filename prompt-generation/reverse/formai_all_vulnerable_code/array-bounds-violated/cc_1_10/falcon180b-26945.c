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

int match(char board[ROWS][COLS], int row1, int col1, int row2, int col2) {
    if (board[row1][col1] == board[row2][col2]) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    srand(time(NULL));

    char board[ROWS][COLS];
    initBoard(board);

    int matches = 0;
    int attempts = 0;

    while (1) {
        printBoard(board);
        int row1, col1, row2, col2;
        scanf("%d %d %d %d", &row1, &col1, &row2, &col2);

        if (match(board, row1, col1, row2, col2)) {
            matches++;
        } else {
            attempts++;
        }

        if (attempts == 8) {
            break;
        }

        int value;
        scanf("%d", &value);
        board[row1][col1] = value + '0';
        board[row2][col2] = value + '0';
    }

    printf("Matches: %d\n", matches);

    return 0;
}