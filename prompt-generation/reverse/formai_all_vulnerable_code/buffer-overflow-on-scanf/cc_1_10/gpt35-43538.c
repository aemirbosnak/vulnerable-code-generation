//FormAI DATASET v1.0 Category: Table Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize variables
    int numPlayers, i, j, roll, currPlayerTurn = 0;
    printf("Welcome to C Table Game!\n");
    printf("How many players will there be (2-6): ");
    scanf("%d", &numPlayers);

    // Check if valid number of players
    while (numPlayers < 2 || numPlayers > 6) {
        printf("Invalid input. Please enter number of players between 2-6: ");
        scanf("%d", &numPlayers);
    }

    // Initialize player positions and win
    int positions[numPlayers];
    int win = 0;
    for (i = 0; i < numPlayers; i++) {
        positions[i] = 0;
    }

    // Game Loop
    while (!win) {
        // Player Roll
        printf("Player %d's turn.\n", currPlayerTurn + 1);
        printf("Press enter to roll the dice.", currPlayerTurn + 1);
        scanf("%*c"); // Cleans input buffer
        roll = rand() % 6 + 1; // Get random integer between 1-6
        printf("You rolled: %d\n", roll);

        // Update Player Position
        positions[currPlayerTurn] += roll;

        // Check if player won
        if (positions[currPlayerTurn] >= 50) {
            printf("Player %d wins!\n", currPlayerTurn + 1);
            win = 1;
            break;
        }

        // Display player positions
        printf("Player Positions:\n");
        for (i = 0; i < numPlayers; i++) {
            printf("Player %d: ", i + 1);
            for (j = 0; j < positions[i]; j++) {
                printf(" ");
            }
            printf("*\n");
        }

        // Increment player turn
        currPlayerTurn++;
        if (currPlayerTurn == numPlayers) {
            currPlayerTurn = 0; // Start over if it reaches the last player
        }
    }

    return 0;
}