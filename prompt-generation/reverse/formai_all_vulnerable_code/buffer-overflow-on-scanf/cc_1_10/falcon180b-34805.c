//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: futuristic
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

int main() {
    srand(time(NULL));

    char board[ROWS][COLS];
    initBoard(board);

    int matches = 0;
    int turns = 0;

    while (matches < ROWS * COLS) {
        int row, col;
        do {
            row = rand() % ROWS;
            col = rand() % COLS;
        } while (board[row][col]!= '-');

        board[row][col] = '*';
        printBoard(board);

        char choice;
        printf("Enter your choice (row and column): ");
        scanf("%c%c", &choice, &choice);

        if (choice >= '0' && choice <= '9') {
            row = choice - '0';
            col = choice - '0';
        } else {
            printf("Invalid choice.\n");
            continue;
        }

        if (board[row][col] == '*') {
            matches++;
        } else {
            board[row][col] = '-';
        }

        turns++;
        if (turns == ROWS * COLS) {
            printf("Game over. You made %d matches in %d turns.\n", matches, turns);
            break;
        }
    }

    return 0;
}