//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define SIZE 4
#define MAX_PAIRS (SIZE * SIZE) / 2

// Function declaration
void initializeBoard(char board[SIZE][SIZE]);
void fillBoard(char board[SIZE][SIZE]);
void printBoard(char board[SIZE][SIZE], int revealed[SIZE][SIZE]);
int makeMove(char board[SIZE][SIZE], int revealed[SIZE][SIZE]);
int checkMatch(char board[SIZE][SIZE], int firstRow, int firstCol, int secondRow, int secondCol);
int isGameFinished(int revealed[SIZE][SIZE]);
void shuffleArray(char *array, int n);

// Main function
int main() {
    char board[SIZE][SIZE];
    int revealed[SIZE][SIZE] = {0}; // 0 means unrevealed, 1 means revealed
    int moves = 0;

    printf("Welcome to the Grateful Memory Game!\n");
    printf("Try to match all the pairs. Good luck!\n\n");

    initializeBoard(board);
    fillBoard(board);

    while (!isGameFinished(revealed)) {
        printBoard(board, revealed);
        printf("Turns taken: %d\n", moves);
        moves += makeMove(board, revealed);
    }

    printf("\nCongratulations! You've matched all the pairs in %d turns!\n", moves);
    return 0;
}

// Function to initialize the board with '*'
void initializeBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            board[i][j] = '*';
}

// Function to fill the board with pairs of letters
void fillBoard(char board[SIZE][SIZE]) {
    char letters[MAX_PAIRS];
    for (int i = 0; i < MAX_PAIRS; i++) {
        letters[i] = 'A' + i; // Fill with letters A, B, C...
    }

    shuffleArray(letters, MAX_PAIRS);

    int k = 0;
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = letters[k / 2]; // Assign pairs
            k++;
        }
}

// Function to shuffle the array of letters
void shuffleArray(char *array, int n) {
    srand(time(NULL));
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

// Function to print the current state of the board
void printBoard(char board[SIZE][SIZE], int revealed[SIZE][SIZE]) {
    printf("Current Board:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (revealed[i][j] == 1)
                printf(" %c ", board[i][j]);
            else
                printf(" * ");
        }
        printf("\n");
    }
}

// Function to make a move and return the number of moves taken
int makeMove(char board[SIZE][SIZE], int revealed[SIZE][SIZE]) {
    int firstRow, firstCol, secondRow, secondCol;

    printf("Select the first card (row column): ");
    scanf("%d %d", &firstRow, &firstCol);
    revealed[firstRow][firstCol] = 1;

    printBoard(board, revealed);

    printf("Select the second card (row column): ");
    scanf("%d %d", &secondRow, &secondCol);
    revealed[secondRow][secondCol] = 1;

    printBoard(board, revealed);

    if (checkMatch(board, firstRow, firstCol, secondRow, secondCol)) {
        printf("It's a match!\n\n");
        return 1; // One move made
    } else {
        printf("Not a match. Try again!\n");
        sleep(2);
        revealed[firstRow][firstCol] = 0; // Hide the first card
        revealed[secondRow][secondCol] = 0; // Hide the second card
	return 1; // One move made
    }
}

int checkMatch(char board[SIZE][SIZE], int firstRow, int firstCol, int secondRow, int secondCol) {
    return board[firstRow][firstCol] == board[secondRow][secondCol];
}

// Check if the game is finished
int isGameFinished(int revealed[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (!revealed[i][j])
                return 0; // Not finished yet
    return 1; // Finished
}