//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: scalable
// C Dice Roller Program

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll dice
int rollDice() {
    int roll = rand() % 6 + 1; // Generates a random number between 1 and 6
    return roll;
}

// Function to play game
void playGame() {
    int player1Score = 0;
    int player2Score = 0;
    int rounds = 5;
    int currentRound = 1;
    int choice;

    // Loop for each round
    while (currentRound <= rounds) {
        printf("Round %d:\n", currentRound);

        // Player 1's turn
        printf("Player 1's turn. Press 1 to roll the dice or any other key to pass the turn.\n");
        scanf("%d", &choice);
        if (choice == 1) {
            int roll = rollDice();
            printf("Player 1 rolled %d.\n", roll);
            player1Score += roll;
        } else {
            printf("Player 1 passed the turn.\n");
        }

        // Player 2's turn
        printf("Player 2's turn. Press 1 to roll the dice or any other key to pass the turn.\n");
        scanf("%d", &choice);
        if (choice == 1) {
            int roll = rollDice();
            printf("Player 2 rolled %d.\n", roll);
            player2Score += roll;
        } else {
            printf("Player 2 passed the turn.\n");
        }

        // Check for winner
        if (player1Score >= 21) {
            printf("Player 1 wins the game!\n");
            break;
        } else if (player2Score >= 21) {
            printf("Player 2 wins the game!\n");
            break;
        }

        // Increment round
        currentRound++;
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator with current time

    playGame();

    return 0;
}