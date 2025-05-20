//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void initBoard(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = 'X';
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
    int correctGuesses = 0;
    int totalGuesses = 0;
    int gameWon = 0;
    int playerChoice;
    int choice;
    int matchFound = 0;
    int matchRow;
    int matchCol;

    while (!gameWon) {
        printBoard(board);
        printf("\nEnter your choice (1-%d): ", ROWS * COLS - 1);
        scanf("%d", &playerChoice);
        totalGuesses++;

        if (playerChoice < 1 || playerChoice > ROWS * COLS - 1) {
            printf("Invalid choice.\n");
            continue;
        }

        matchFound = 0;
        matchRow = (playerChoice - 1) / COLS;
        matchCol = (playerChoice - 1) % COLS;

        if (board[matchRow][matchCol] == 'X') {
            printf("You found a match!\n");
            correctGuesses++;
        } else {
            printf("No match found.\n");
        }

        if (correctGuesses == ROWS * COLS / 2) {
            gameWon = 1;
            printf("Congratulations! You won the game!\n");
        } else if (totalGuesses == ROWS * COLS - 1) {
            gameWon = 1;
            printf("Game over. You lose.\n");
        }
    }

    return 0;
}