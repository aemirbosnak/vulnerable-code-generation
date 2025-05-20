//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: standalone
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
    int choice;
    int correctGuesses = 0;
    int wrongGuesses = 0;
    int numMoves = 0;
    int maxMoves = 10;
    int gameOver = 0;

    while (!gameOver) {
        printf("Enter your choice (0-9): ");
        scanf("%d", &choice);
        if (choice < 0 || choice > 9) {
            printf("Invalid choice.\n");
            continue;
        }
        if (board[choice / 3][choice % 3] == '-') {
            board[choice / 3][choice % 3] = 'X';
            if (choice == (rand() % 10)) {
                printf("Correct guess!\n");
                correctGuesses++;
            } else {
                printf("Incorrect guess.\n");
                wrongGuesses++;
            }
            numMoves++;
        } else if (board[choice / 3][choice % 3] == 'X') {
            printf("You already chose this tile.\n");
        } else {
            printf("This tile has already been revealed.\n");
        }
        printBoard(board);
        if (correctGuesses == 10) {
            printf("Congratulations, you win!\n");
            gameOver = 1;
        } else if (wrongGuesses == maxMoves) {
            printf("Sorry, you lose.\n");
            gameOver = 1;
        }
    }

    return 0;
}