//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between 1 and 6
int rollDice() {
    return rand() % 6 + 1;
}

int main() {
    int player1Score = 0, player2Score = 0;
    int currentPlayer = 1;
    char playAgain;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Play the game until the user decides to quit
    do {
        // Roll the dice for each player
        int roll1 = rollDice();
        int roll2 = rollDice();

        // Print the results of each roll
        printf("Player 1 rolled: %d\n", roll1);
        printf("Player 2 rolled: %d\n", roll2);

        // Determine the winner of each round
        if (roll1 > roll2) {
            printf("Player 1 wins this round!\n");
            player1Score++;
        } else if (roll2 > roll1) {
            printf("Player 2 wins this round!\n");
            player2Score++;
        } else {
            printf("It's a tie!\n");
        }

        // Switch to the next player
        if (currentPlayer == 1) {
            currentPlayer = 2;
        } else {
            currentPlayer = 1;
        }

        // Ask the user if they want to play again
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);
    } while (playAgain == 'y' || playAgain == 'Y');

    // Print the final scores
    printf("Final scores:\n");
    printf("Player 1: %d\n", player1Score);
    printf("Player 2: %d\n", player2Score);

    return 0;
}