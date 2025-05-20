//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 6
#define MAX_HEALTH 10
#define MAX_DIFFICULTY 5

typedef struct {
    char name[20];
    int health;
    int difficulty;
} player;

int main() {
    player players[MAX_PLAYERS];
    int num_players;
    int round = 0;

    srand(time(NULL));

    printf("Welcome to Procedural Space Adventure!\n");
    printf("How many players will embark on this adventure?\n");
    scanf("%d", &num_players);

    if (num_players <= 0 || num_players > MAX_PLAYERS) {
        printf("Invalid number of players!\n");
        return 1;
    }

    // Initialize players
    for (int i = 0; i < num_players; i++) {
        printf("Enter name for player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].health = MAX_HEALTH;
        players[i].difficulty = rand() % MAX_DIFFICULTY + 1;
    }

    // Game loop
    while (1) {
        printf("\nRound %d\n", ++round);

        // Random event
        int event = rand() % 3;
        if (event == 0) {
            printf("Nothing happened...\n");
        } else if (event == 1) {
            printf("An asteroid field! Difficulty increased by 1 for all players\n");
            for (int i = 0; i < num_players; i++) {
                players[i].difficulty++;
            }
        } else {
            printf("A space pirate attack! One player's health decreased by 3\n");
            int victim = rand() % num_players;
            players[victim].health -= 3;
            if (players[victim].health <= 0) {
                printf("%s has been defeated!\n", players[victim].name);
                num_players--;
                for (int i = victim; i < num_players; i++) {
                    players[i] = players[i+1];
                }
            }
        }

        // Print player stats
        printf("\n");
        for (int i = 0; i < num_players; i++) {
            printf("%s: Health %d, Difficulty %d\n", players[i].name, players[i].health, players[i].difficulty);
        }

        if (num_players == 1) {
            printf("%s is the last player standing!\n", players[0].name);
            break;
        }

        // End of round
        printf("\nPress ENTER to continue...\n");
        getchar();
        getchar();
    }

    return 0;
}