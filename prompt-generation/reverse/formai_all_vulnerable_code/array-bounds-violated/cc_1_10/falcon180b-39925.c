//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define MATCH 1
#define MISS 0

int board[ROWS][COLS] = {
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
};

void shuffleBoard(int board[ROWS][COLS]) {
    int i, j, temp;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            srand(time(NULL));
            temp = rand() % 2;
            board[i][j] = temp;
        }
    }
}

void printBoard(int board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (board[i][j] == 0) {
                printf("_ ");
            } else if (board[i][j] == 1) {
                printf("X ");
            } else {
                printf("O ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int player = 1;
    int choice, matchCount = 0;

    shuffleBoard(board);

    while (matchCount < ROWS * COLS / 2) {
        printf("Player %d's turn\n", player);
        printBoard(board);
        printf("Enter your choice (row col): ");
        scanf("%d %d", &choice, &choice);
        if (board[choice][choice] == 0) {
            board[choice][choice] = player;
            if (player == 1) {
                player = 2;
            } else {
                player = 1;
            }
            matchCount++;
        } else {
            printf("Miss! Try again.\n");
        }
    }

    if (player == 1) {
        printf("Player 1 wins!\n");
    } else {
        printf("Player 2 wins!\n");
    }

    return 0;
}