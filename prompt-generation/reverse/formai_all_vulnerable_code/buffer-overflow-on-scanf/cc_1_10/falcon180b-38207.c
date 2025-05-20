//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void init_board(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = '-';
        }
    }
}

void print_board(char board[ROWS][COLS]) {
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
    init_board(board);

    int num_matches = 0;
    int num_turns = 0;

    while (num_matches < ROWS * COLS / 2) {
        int row, col;
        do {
            row = rand() % ROWS;
            col = rand() % COLS;
        } while (board[row][col]!= '-');

        board[row][col] = '*';
        num_turns++;

        if (row == 0 && col == 0) {
            printf("Game started!\n");
        }

        print_board(board);

        int choice;
        printf("Enter your choice (row, col): ");
        scanf("%d %d", &row, &col);

        if (row < 0 || row >= ROWS || col < 0 || col >= COLS || board[row][col]!= '*') {
            printf("Invalid choice.\n");
        } else if (board[row][col] == '*') {
            num_matches++;
            printf("Match found!\n");
        } else {
            printf("Missed.\n");
        }

        board[row][col] = '-';
    }

    printf("You found all the matches in %d turns.\n", num_turns);

    return 0;
}