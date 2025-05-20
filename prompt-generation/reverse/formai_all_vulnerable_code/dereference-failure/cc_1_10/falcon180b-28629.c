//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 4

void initBoard(char board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = '*';
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

int matchCards(char board[ROWS][COLS], int row1, int col1, int row2, int col2) {
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
    int row1, col1, row2, col2;

    while (1) {
        printBoard(board);
        printf("Matches: %d\n", matches);
        printf("Attempts: %d\n", attempts);

        int choice;
        scanf("%d", &choice);

        row1 = choice / COLS;
        col1 = choice % COLS;

        if (board[row1][col1]!= '*') {
            continue;
        }

        attempts++;

        int foundMatch = 0;
        while (!foundMatch) {
            row2 = rand() % ROWS;
            col2 = rand() % COLS;

            if (matchCards(board, row1, col1, row2, col2)) {
                board[row1][col1] = '*';
                board[row2][col2] = '*';
                foundMatch = 1;
                matches++;
            }
        }

        if (matches == (ROWS * COLS) / 2) {
            printf("Congratulations! You won!\n");
            break;
        }
    }

    return 0;
}