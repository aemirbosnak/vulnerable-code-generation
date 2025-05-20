//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
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
    char board[ROWS][COLS];
    int matches = 0;

    initBoard(board);

    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = rand() % 2 == 0? '*' : '-';
        }
    }

    printf("Welcome to the surrealist memory game!\n");
    printf("There are %d stars hidden in the grid.\n", ROWS * COLS / 2);

    while (matches < ROWS * COLS / 2) {
        int row, col;
        printf("Enter the row and column of the card you want to flip: ");
        scanf("%d %d", &row, &col);

        if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
            char card = board[row][col];
            board[row][col] = '-';

            if (card == '*') {
                matches++;
                printf("You found a star!\n");
            } else {
                printf("Sorry, there is no star here.\n");
            }
        } else {
            printf("Invalid input.\n");
        }

        printBoard(board);
    }

    printf("Congratulations! You found all %d stars!\n", matches);

    return 0;
}