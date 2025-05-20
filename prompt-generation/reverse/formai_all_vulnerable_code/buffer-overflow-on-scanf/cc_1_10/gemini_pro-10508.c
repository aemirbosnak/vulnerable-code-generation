//GEMINI-pro DATASET v1.0 Category: Pattern printing ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 4
#define MAX_NAME_LEN 20
#define MAX_PATTERN_LEN 100

typedef struct {
    char name[MAX_NAME_LEN + 1];
    char pattern[MAX_PATTERN_LEN + 1];
    int score;
} player_t;

player_t players[MAX_PLAYERS];
int num_players;

int main() {
    // Get the number of players
    printf("Enter the number of players (1-%d): ", MAX_PLAYERS);
    scanf("%d", &num_players);
    if (num_players < 1 || num_players > MAX_PLAYERS) {
        printf("Invalid number of players\n");
        return EXIT_FAILURE;
    }

    // Get the player information
    for (int i = 0; i < num_players; i++) {
        printf("Enter player %d's name: ", i + 1);
        scanf("%s", players[i].name);
        printf("Enter player %d's pattern: ", i + 1);
        scanf("%s", players[i].pattern);
        players[i].score = 0;
    }

    // Play the game
    int round = 1;
    while (round <= 10) {
        printf("Round %d\n", round);
        for (int i = 0; i < num_players; i++) {
            printf("%s's turn\n", players[i].name);
            printf("Guess the pattern: ");
            char guess[MAX_PATTERN_LEN + 1];
            scanf("%s", guess);
            if (strcmp(guess, players[i].pattern) == 0) {
                printf("Correct!\n");
                players[i].score++;
            } else {
                printf("Incorrect\n");
            }
        }
        round++;
    }

    // Display the results
    printf("Final scores:\n");
    for (int i = 0; i < num_players; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }

    return EXIT_SUCCESS;
}