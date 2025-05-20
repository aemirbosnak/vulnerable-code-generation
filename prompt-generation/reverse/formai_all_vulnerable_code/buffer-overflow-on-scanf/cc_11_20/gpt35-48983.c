//FormAI DATASET v1.0 Category: Table Game ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int players, maxScore, i, j, playerScore, turnScore, playerIndex, diceRoll, turnCount;
    printf("Welcome to Mind-Bending C Table Game\n\n");

    // Get number of players
    printf("Enter number of players (2-6): ");
    scanf("%d", &players);
    while (players < 2 || players > 6) {
        printf("Invalid input, please enter a number between 2 and 6: ");
        scanf("%d", &players);
    }

    // Get max score to win
    printf("Enter maximum score to win (50-1000): ");
    scanf("%d", &maxScore);
    while (maxScore < 50 || maxScore > 1000) {
        printf("Invalid input, please enter a number between 50 and 1000: ");
        scanf("%d", &maxScore);
    }

    // Initialize random number generator
    srand(time(NULL));

    // Initialize player scores to 0
    int playerScores[players];
    for (i = 0; i < players; i++) {
        playerScores[i] = 0;
    }

    // Begin game loop
    playerIndex = 0; // Start with first player
    turnCount = 0;
    while (1) {
        printf("\nTurn %d - Player %d's turn\n", turnCount+1, playerIndex+1);
        printf("Current scores:");
        for (i = 0; i < players; i++) {
            printf(" Player %d: %d", i+1, playerScores[i]);
        }
        printf("\n");

        playerScore = playerScores[playerIndex];
        turnScore = 0;

        // Roll the dice
        diceRoll = rand() % 6 + 1;
        printf("You rolled a %d\n", diceRoll);

        if (diceRoll == 1) {
            printf("Oh no! You rolled a 1 and lost all your turn points.\n");
            turnScore = 0;
            playerIndex = (playerIndex + 1) % players; // Move to next player
        } else {
            turnScore += diceRoll;
            printf("Turn score is now %d\n", turnScore);

            printf("Do you want to roll again? (Y/N)\n");
            char choice;
            scanf(" %c", &choice);

            while (choice == 'Y' || choice == 'y') {
                // Roll again
                diceRoll = rand() % 6 + 1;
                printf("You rolled a %d\n", diceRoll);

                if (diceRoll == 1) {
                    printf("Oh no! You rolled a 1 and lost all your turn points.\n");
                    turnScore = 0;
                    break;
                } else {
                    turnScore += diceRoll;
                    printf("Turn score is now %d\n", turnScore);
                    printf("Do you want to roll again? (Y/N)\n");
                    scanf(" %c", &choice);
                }
            }

            // Add turnScore to playerScore and check if player wins
            playerScore += turnScore;
            if (playerScore >= maxScore) {
                printf("Congratulations, player %d wins with a score of %d!\n", playerIndex+1, playerScore);
                return 0; // End game
            }

            printf("End of turn, player %d's score is now %d\n", playerIndex+1, playerScore);
            playerScores[playerIndex] = playerScore;
            playerIndex = (playerIndex + 1) % players; // Move to next player
        }

        turnCount++;
    }
}