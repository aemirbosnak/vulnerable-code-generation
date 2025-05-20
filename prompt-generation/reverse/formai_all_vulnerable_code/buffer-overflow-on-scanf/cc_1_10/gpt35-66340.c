//FormAI DATASET v1.0 Category: Memory Game ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4
#define NUM_PAIRS 8

// Function declarations
void initializeBoard(char board[SIZE][SIZE]);
void printBoard(char board[SIZE][SIZE]);
void updateBoard(char board[SIZE][SIZE], int row1, int col1, int row2, int col2);

// Main function
int main() {
    srand(time(NULL)); // Seed random number generator
    char board[SIZE][SIZE];
    initializeBoard(board);
    printBoard(board);
    int numGuesses = 0;
    int row1, col1, row2, col2;
    while (numGuesses < NUM_PAIRS) {
        printf("Player 1, please enter your first guess: ");
        scanf("%d %d", &row1, &col1);
        printf("Player 1, please enter your second guess: ");
        scanf("%d %d", &row2, &col2);
        updateBoard(board, row1, col1, row2, col2);
        printBoard(board);
        if (board[row1][col1] == board[row2][col2]) {
            printf("You found a match!\n");
            numGuesses++;
        } else {
            printf("Sorry, try again.\n");
        }
        printf("Player 2, please enter your first guess: ");
        scanf("%d %d", &row1, &col1);
        printf("Player 2, please enter your second guess: ");
        scanf("%d %d", &row2, &col2);
        updateBoard(board, row1, col1, row2, col2);
        printBoard(board);
        if (board[row1][col1] == board[row2][col2]) {
            printf("You found a match!\n");
            numGuesses++;
        } else {
            printf("Sorry, try again.\n");
        }
    }
    printf("Congratulations, you found all the pairs!\n");
    return 0;
}

// Function for initializing the board with random letters
void initializeBoard(char board[SIZE][SIZE]) {
    char letters[NUM_PAIRS * 2] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    int letterIndex = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = letters[letterIndex];
            letterIndex++;
            if (letterIndex == NUM_PAIRS * 2) {
                letterIndex = 0;
            }
        }
    }
    // Shuffle the letters
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int a = rand() % SIZE;
            int b = rand() % SIZE;
            char temp = board[i][j];
            board[i][j] = board[a][b];
            board[a][b] = temp;
        }
    }
}

// Function for printing the board
void printBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function for updating the board
void updateBoard(char board[SIZE][SIZE], int row1, int col1, int row2, int col2) {
    char temp = board[row1][col1];
    board[row1][col1] = board[row2][col2];
    board[row2][col2] = temp;
}