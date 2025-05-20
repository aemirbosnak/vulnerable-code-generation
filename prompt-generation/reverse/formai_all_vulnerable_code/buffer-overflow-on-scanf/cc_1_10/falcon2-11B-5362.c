//Falcon2-11B DATASET v1.0 Category: Math exercise ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 10

int main(int argc, char **argv) {
    srand(time(NULL)); // Initialize random seed

    int numPlayers = MAX_PLAYERS; // Maximum number of players
    int numGames = 100; // Number of games to play

    printf("Welcome to the Multiplayer Math Game!\n");
    printf("-------------------------------\n");

    int players[MAX_PLAYERS]; // Array to store player information
    int scores[MAX_PLAYERS]; // Array to store player scores

    // Create players
    for (int i = 0; i < numPlayers; i++) {
        players[i] = i + 1; // Player number
        scores[i] = 0; // Initial score
    }

    // Play games
    for (int i = 0; i < numGames; i++) {
        printf("Game %d:\n", i + 1);

        // Select random player
        int randomPlayer = rand() % numPlayers;
        printf("Player %d starts!\n", randomPlayer + 1);

        // Ask a math question
        int question = rand() % 10 + 1; // Random question between 1 and 10
        printf("Question: %d + %d =?", question, question);
        int answer = scanf("%d", &scores[randomPlayer]);

        // Check answer
        if (answer == (question + question)) {
            printf("Correct!\n");
            scores[randomPlayer]++; // Increment score
        } else {
            printf("Incorrect!\n");
            printf("The correct answer is %d.\n", question + question);
        }
    }

    // Print final scores
    printf("\nFinal Scores:\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("%d: %d\n", i + 1, scores[i]);
    }

    return 0;
}