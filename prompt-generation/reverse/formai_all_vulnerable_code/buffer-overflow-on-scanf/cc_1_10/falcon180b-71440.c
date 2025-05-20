//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 5

void initBoard(char board[][SIZE]);
void printBoard(char board[][SIZE]);
int checkWin(char board[][SIZE]);
void flipCard(char board[][SIZE], int row, int col);

int main() {
    char board[SIZE][SIZE];
    int choice, row, col, matches = 0;

    initBoard(board);

    while (matches < SIZE * SIZE) {
        printBoard(board);
        printf("\nSelect a card: ");
        scanf("%d %d", &row, &col);
        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == '*') {
            flipCard(board, row, col);
            if (checkWin(board)) {
                printf("\nCongratulations! You win!\n");
                matches = SIZE * SIZE;
            } else {
                matches++;
            }
        } else {
            printf("\nInvalid selection!\n");
        }
    }

    return 0;
}

void initBoard(char board[][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            board[i][j] = '*';
        }
    }
}

void printBoard(char board[][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(char board[][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (board[i][j]!= '*') {
                return 0;
            }
        }
    }
    return 1;
}

void flipCard(char board[][SIZE], int row, int col) {
    if (row == col) {
        board[row][col] = 'X';
    } else if (row + col == SIZE - 1) {
        board[row][col] = 'O';
    } else {
        board[row][col] = '*';
    }
}