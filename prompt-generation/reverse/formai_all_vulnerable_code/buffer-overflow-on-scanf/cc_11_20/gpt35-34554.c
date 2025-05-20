//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLUMNS 10

int main() {
    srand(time(NULL)); // Seed the random number generator

    int board[ROWS][COLUMNS]; // Initialize the board
    int ships = 3; // Set the number of ships
    int hits = 0; // Initialize the hit counter

    printf("Welcome to Battleship!\n");
    printf("There are 3 ships hidden in the board.\n");
    printf("Can you find them all?\n");

    // Set all board positions to 0 (empty)
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLUMNS; j++) {
            board[i][j] = 0;
        }
    }

    // Randomly place the ships on the board
    for(int i = 0; i < ships; i++) {
        int row = rand() % ROWS;
        int column = rand() % COLUMNS;
        // Check if the position is already occupied by another ship
        if(board[row][column] == 0) {
            board[row][column] = 1;
        } else {
            // If the position is occupied, try again
            i--;
        }
    }

    // Main game loop
    while(hits < ships) {
        int rowGuess, columnGuess;
        printf("Enter row guess (0-9): ");
        scanf("%d", &rowGuess);
        printf("Enter column guess (0-9): ");
        scanf("%d", &columnGuess);

        // Check if the guess is out of bounds
        if(rowGuess < 0 || rowGuess > ROWS - 1 || columnGuess < 0 || columnGuess > COLUMNS - 1) {
            printf("Invalid guess. Please enter a number between 0 and 9.\n");
            continue;
        }

        // Check if the guess has already been made
        if(board[rowGuess][columnGuess] == -1 || board[rowGuess][columnGuess] == 1) {
            printf("You have already guessed that position.\n");
            continue;
        }

        // If the guess is incorrect, mark it as a miss (-1)
        if(board[rowGuess][columnGuess] == 0) {
            printf("Miss!\n");
            board[rowGuess][columnGuess] = -1;
        }

        // If the guess is correct, mark it as a hit (2)
        if(board[rowGuess][columnGuess] == 1) {
            printf("Hit!\n");
            board[rowGuess][columnGuess] = 2;
            hits++;
        }
    }

    printf("Congratulations! You found all the ships!\n");
    printf("Game over.");

    return 0;
}