//FormAI DATASET v1.0 Category: Table Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to simulate a dice roll
int diceRoll() {
    return rand() % 6 + 1;
}

// Main function
int main() {
    // Initialize random seed
    srand(time(NULL));

    // Declare and initialize variables
    int numPlayers = 0;
    int playerScores[10] = {0};
    int playerTurn = 0;
    int gameOver = 0;

    // Prompt user for number of players
    printf("Enter the number of players (2-10): ");
    scanf("%d", &numPlayers);

    // Create an array to store player names
    char playerNames[10][20];

    // Prompt user for player names
    for (int i = 0; i < numPlayers; i++) {
        printf("Enter player %d's name: ", i+1);
        scanf("%s", playerNames[i]);
    }

    // Loop through turns until game over
    while (!gameOver) {
        // Display current player name and score
        printf("\n%s's turn. Score: %d\n", playerNames[playerTurn], playerScores[playerTurn]);

        // Roll the dice
        int roll = diceRoll();
        printf("You rolled a %d\n", roll);

        // Update player score
        playerScores[playerTurn] += roll;

        // Check if player has won
        if (playerScores[playerTurn] >= 50) {
            printf("\n%s has won!\n", playerNames[playerTurn]);
            gameOver = 1;
        }

        // Switch turns to next player
        playerTurn = (playerTurn + 1) % numPlayers;
    }

    return 0;
}