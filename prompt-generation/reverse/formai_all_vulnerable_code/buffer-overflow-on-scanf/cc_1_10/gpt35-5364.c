//FormAI DATASET v1.0 Category: Table Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3 // Define number of rows
#define COLS 3 // Define number of columns

// Function prototypes
void displayGameboard(char board[][COLS]);
int checkWinner(char board[][COLS], char player);

int main() {
    char board[ROWS][COLS]; // Create 3x3 game board 
    char player1 = 'X'; // Initialize player 1 marker
    char player2 = 'O'; // Initialize player 2 marker
    int turnNumber = 0; // Initialize turn number to 0

    // Seed random number generator
    srand((unsigned) time(NULL));

    // Initialize game board to empty spaces
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            board[i][j] = ' '; 
        }
    }

    printf("Let's play C Table Game!\n");
    printf("Player 1 will be %.1c and Player 2 will be %.1c\n\n", player1, player2);
    displayGameboard(board); // Display empty game board

    while (turnNumber < ROWS * COLS) { // While there are still moves to be played
        printf("Player %d, please enter your move. (Row Column): ", turnNumber % 2 + 1); // Prompt player

        int row, col; // Variables to hold player move
        scanf(" %d %d", &row, &col); // Get move from player

        // Make sure move is valid
        if(row < 0 || row > ROWS-1 || col < 0 || col > COLS-1 || board[row][col] != ' ') {
            printf("Invalid move. Please try again.\n");
            continue;
        }

        // Make move
        if (turnNumber % 2 == 0) {
            board[row][col] = player1;
        } else {
            board[row][col] = player2;
        }

        turnNumber++; // Increment turn counter
        displayGameboard(board); // Display updated game board

        // Check if there is a winner
        if (checkWinner(board, player1)) {
            printf("Player 1 is the winner!\n");
            return 0;
        } else if (checkWinner(board, player2)) {
            printf("Player 2 is the winner!\n");
            return 0;
        }
    }

    printf("It's a tie!\n"); // If no winner after all moves played
    return 0;
}

// Function to display game board
void displayGameboard(char board[][COLS]) {
    printf("\n");
    for(int i = 0; i < ROWS; i++) {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if (i != ROWS - 1) {
            printf("\n-----------\n");
        }
    }
    printf("\n\n");
}

// Function to check if there is a winner
int checkWinner(char board[][COLS], char player) {
    // Check rows
    for(int i = 0; i < ROWS; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }
    // Check columns
    for(int j = 0; j < COLS; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return 1;
        }
    }
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }
    return 0; // If no winner found
}