//Falcon2-11B DATASET v1.0 Category: Bingo Simulator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max (inclusive)
int randomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    srand(time(0)); // Seed the random number generator with current time
    int bingo[5][5] = {{1, 2, 3, 4, 5}, // Pre-populate the bingo board
                       {6, 7, 8, 9, 10},
                       {11, 12, 13, 14, 15},
                       {16, 17, 18, 19, 20},
                       {21, 22, 23, 24, 25}}; // Initialize the board
    int playerScore = 0;
    int computerScore = 0;
    int playerNumber;

    printf("Welcome to the C Bingo Simulator!\n");
    printf("Here are your bingo numbers:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", bingo[i][j]);
        }
        printf("\n");
    }

    while (playerScore < 5 || computerScore < 5) { // Continue until both players have 5 numbers
        playerNumber = randomNumber(1, 25); // Generate a random number for the player
        if (playerScore < 5 && bingo[playerNumber - 1][0] == 0) { // Check if player has bingo
            printf("Player: %d\n", playerNumber);
            bingo[playerNumber - 1][0] = 1; // Mark the number on the board
            playerScore++; // Increase player score
        } else if (computerScore < 5 && bingo[playerNumber - 1][0] == 0) { // Check if computer has bingo
            printf("Computer: %d\n", playerNumber);
            bingo[playerNumber - 1][0] = 1; // Mark the number on the board
            computerScore++; // Increase computer score
        } else { // Player and computer already have 5 numbers
            printf("Player: %d | Computer: %d\n", playerScore, computerScore);
        }
    }

    printf("Game over!\n");
    printf("Player: %d\n", playerScore);
    printf("Computer: %d\n", computerScore);

    return 0;
}