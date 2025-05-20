//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: rigorous
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
    board[row][col] = '*';
}

int checkMatch(char board[ROWS][COLS], int row, int col) {
    int count = 0;
    if (row > 0 && board[row - 1][col] == board[row][col]) {
        count++;
    }
    if (row < ROWS - 1 && board[row + 1][col] == board[row][col]) {
        count++;
    }
    if (col > 0 && board[row][col - 1] == board[row][col]) {
        count++;
    }
    if (col < COLS - 1 && board[row][col + 1] == board[row][col]) {
        count++;
    }
    return count;
}

int main() {
    srand(time(NULL));
    char board[ROWS][COLS];
    initBoard(board);
    int player = 1;
    int moves = 0;
    while (moves < ROWS * COLS - 1) {
        int row, col;
        do {
            row = rand() % ROWS;
            col = rand() % COLS;
        } while (board[row][col]!= '-');
        placeCard(board, row, col);
        printBoard(board);
        printf("Player %d's turn.\n", player);
        int choiceRow, choiceCol;
        scanf("%d %d", &choiceRow, &choiceCol);
        if (board[choiceRow - 1][choiceCol - 1] == '*') {
            printf("Correct match!\n");
            moves++;
        } else {
            printf("Incorrect match.\n");
            player =!player;
        }
    }
    printf("Player %d wins!\n", player);
    return 0;
}