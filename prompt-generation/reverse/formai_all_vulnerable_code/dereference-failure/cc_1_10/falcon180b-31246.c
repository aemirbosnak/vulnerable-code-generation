//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

// Function to initialize the game board with random numbers
void initBoard(int board[][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = rand() % 10;
        }
    }
}

// Function to print the game board
void printBoard(int board[][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if two numbers are equal
int checkMatch(int board[][COLS], int row1, int col1, int row2, int col2) {
    return board[row1][col1] == board[row2][col2];
}

// Function to check if all numbers have been matched
int checkWin(int board[][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (board[i][j]!= -1) {
                return 0;
            }
        }
    }
    return 1;
}

// Function to flip two cards and check for a match
void playGame(int board[][COLS]) {
    int row1, col1, row2, col2;
    printf("Choose two cards:\n");
    scanf("%d %d", &row1, &col1);
    scanf("%d %d", &row2, &col2);

    if (checkMatch(board, row1, col1, row2, col2)) {
        printf("Match!\n");
        board[row1][col1] = board[row2][col2] = -1;
    } else {
        printf("No match.\n");
        board[row1][col1] = board[row2][col2] = -1;
    }
}

int main() {
    srand(time(NULL));
    int board[ROWS][COLS];
    initBoard(board);
    int gameWon = 0;

    while (!gameWon) {
        printBoard(board);
        playGame(board);

        if (checkWin(board)) {
            printf("Congratulations! You won!\n");
            gameWon = 1;
        }
    }

    return 0;
}