//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PLAYERS 4
#define GUESSES 5

typedef struct {
    int num;
    char name[20];
} player_t;

player_t players[PLAYERS] = {
    {.num = 1, .name = "Player 1"},
    {.num = 2, .name = "Player 2"},
    {.num = 3, .name = "Player 3"},
    {.num = 4, .name = "Player 4"}
};

int main() {
    int i, j, k, guesses = 0;
    int correct = 0;
    int points = 0;

    // Initialize the game
    for (i = 0; i < PLAYERS; i++) {
        players[i].num = 0;
    }

    // Start the game loop
    while (1) {
        // Display the current scores
        printf("Scores:\n");
        for (i = 0; i < PLAYERS; i++) {
            printf("Player %d: %d\n", i + 1, players[i].num);
        }

        // Ask players to make their guesses
        printf("Enter your guess (1-100): ");
        scanf("%d", &guesses);

        // Check if the player has won
        for (i = 0; i < PLAYERS; i++) {
            if (players[i].num == guesses) {
                correct++;
                break;
            }
        }

        // Update the scores
        for (i = 0; i < PLAYERS; i++) {
            if (i == correct) {
                points++;
            }
            players[i].num = 0;
        }

        // Check if the game is over
        if (correct == PLAYERS) {
            break;
        }
    }

    // Display the final scores
    printf("Final Scores:\n");
    for (i = 0; i < PLAYERS; i++) {
        printf("Player %d: %d\n", i + 1, points);
    }

    return 0;
}