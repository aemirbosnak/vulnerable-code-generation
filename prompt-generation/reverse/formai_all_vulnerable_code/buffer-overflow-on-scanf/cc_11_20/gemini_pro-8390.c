//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROWS 5
#define NUM_COLS 5

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create a 2D array to represent the game board
    int board[NUM_ROWS][NUM_COLS];

    // Fill the board with random numbers
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            board[i][j] = rand() % 10;
        }
    }

    // Print the game board
    printf("The game board:\n");
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    // Get the player's move
    int row, col;
    printf("Enter the row and column of your move (e.g. 1 3): ");
    scanf("%d %d", &row, &col);

    // Check if the move is valid
    if (row < 0 || row >= NUM_ROWS || col < 0 || col >= NUM_COLS) {
        printf("Invalid move. Please try again.\n");
        return EXIT_FAILURE;
    }

    // Make the move
    board[row][col] = -1;

    // Print the updated game board
    printf("The updated game board:\n");
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    // Check if the player has won
    int won = 1;
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            if (board[i][j] >= 0) {
                won = 0;
            }
        }
    }

    // Print the result
    if (won) {
        printf("You win!\n");
    } else {
        printf("You lose!\n");
    }

    return EXIT_SUCCESS;
}