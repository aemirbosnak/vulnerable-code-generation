//FormAI DATASET v1.0 Category: Memory Game ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

// Function to print the game board
void printBoard(int board[][COLS], int rows) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < COLS; j++) {
            if(board[i][j] < 0) {
                printf("   ");
            } else {
                printf("%2d ", board[i][j]);
            }
        }
        printf("\n");
    }
}

// Function to initialize board with random pairs of numbers
void initBoard(int board[][COLS], int rows) {
    int numPairs = (rows * COLS) / 2;
    int pairs[numPairs];
    for(int i = 0; i < numPairs; i++) {
        pairs[i] = i + 1;
    }
    srand(time(NULL));
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < COLS; j++) {
            int index = rand() % numPairs;
            board[i][j] = pairs[index];
            numPairs--;
            pairs[index] = pairs[numPairs];
            if(board[i][j] == 1) {
                board[i][j] = -1;
            }
        }
    }
}

// Function to check if player has won the game
int hasWon(int board[][COLS], int rows) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < COLS; j++) {
            if(board[i][j] > 0) {
                return 0;
            }
        }
    }
    return 1;
}

// Main function to run the game
int main() {
    printf("Welcome to the Memory Game!\n\n");
    int board[ROWS][COLS];
    initBoard(board, ROWS);
    int numGuesses = 0;
    while(!hasWon(board, ROWS)) {
        printf("Guess a row and column (e.g. 1 2): ");
        int row1, col1, row2, col2;
        scanf("%d %d %d %d", &row1, &col1, &row2, &col2);
        if(board[row1][col1] == board[row2][col2]) {
            printf("You found a match!\n");
            board[row1][col1] = -1;
            board[row2][col2] = -1;
        } else {
            printf("No match. Try again.\n");
        }
        numGuesses++;
        printf("\n");
        printBoard(board, ROWS);
        printf("\n");
    }
    printf("Congratulations! You won in %d guesses!\n", numGuesses);
    return 0;
}