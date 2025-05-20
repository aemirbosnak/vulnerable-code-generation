//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void init_board(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            board[i][j] = '-';
        }
    }
}

void print_board(const char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    char board[ROWS][COLS];
    init_board(board);

    int matches = 0;
    while (matches < ROWS * COLS / 2) {
        int row, col;
        do {
            row = rand() % ROWS;
            col = rand() % COLS;
        } while (board[row][col]!= '-');

        board[row][col] = '*';

        print_board(board);

        char choice;
        printf("Enter your choice (row and column): ");
        scanf("%c%c", &choice, &choice);

        int r = choice - '0';
        int c = choice - 'A';

        if (board[r][c] == '*') {
            ++matches;
        } else {
            printf("Invalid choice.\n");
        }
    }

    printf("Congratulations! You won with %d matches.\n", matches);

    return 0;
}