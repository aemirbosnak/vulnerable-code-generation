//Gemma-7B DATASET v1.0 Category: Table Game ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM_PLAYER 2

typedef struct Player {
    char name[20];
    int score;
    int hand[MAX_NUM_PLAYER];
} Player;

int main() {
    Player players[MAX_NUM_PLAYER];
    int i, numPlayers, round, totalScore, currentPlayer;

    // Initialize players
    for (i = 0; i < MAX_NUM_PLAYER; i++) {
        players[i].name[0] = '\0';
        players[i].score = 0;
        players[i].hand[0] = '\0';
    }

    // Get number of players
    printf("Enter the number of players (2-4): ");
    scanf("%d", &numPlayers);

    // Set number of players
    if (numPlayers < 2 || numPlayers > MAX_NUM_PLAYER) {
        printf("Invalid number of players.\n");
        exit(1);
    }

    // Start the game
    round = 1;
    totalScore = 0;
    currentPlayer = 0;

    // Game loop
    while (totalScore < 1000) {
        // Get the current player's turn
        currentPlayer = (currentPlayer + 1) % numPlayers;

        // Roll the dice
        int roll = rand() % 6 + 1;

        // Add the roll to the current player's hand
        players[currentPlayer].hand[round] = roll;

        // Calculate the current player's score
        int score = players[currentPlayer].hand[round] + players[currentPlayer].score;

        // Update the current player's score
        players[currentPlayer].score = score;

        // Update the total score
        totalScore = score;

        // Print the results of the turn
        printf("%s rolled a %d and has a total score of %d.\n", players[currentPlayer].name, roll, score);

        // Increment the round
        round++;
    }

    // End the game
    printf("Game over! The winner is: %s.\n", players[currentPlayer].name);

    return 0;
}