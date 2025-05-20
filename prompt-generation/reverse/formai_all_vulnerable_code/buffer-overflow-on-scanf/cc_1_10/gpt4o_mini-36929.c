//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define MAX_PLAYERS 10
#define MAX_GEMS 10

typedef struct {
    int id;
    int gems[MAX_GEMS];
    int num_gems;
} Player;

void assign_gems(Player players[], int num_players, int total_gems) {
    // Simple greedy algorithm to distribute gems among players
    int gems_remaining = total_gems;
    while (gems_remaining > 0) {
        for (int i = 0; i < num_players; i++) {
            if (gems_remaining <= 0) break;

            // Give one gem to the current player
            players[i].gems[players[i].num_gems] = 1; 
            players[i].num_gems++;
            gems_remaining--;
        }
    }
}

void display_gems(Player players[], int num_players) {
    for (int i = 0; i < num_players; i++) {
        printf("Player %d has received: ", players[i].id);
        for (int j = 0; j < players[i].num_gems; j++) {
            printf("%d ", players[i].gems[j]);
        }
        printf(" (Total: %d)\n", players[i].num_gems);
    }
}

int main() {
    Player players[MAX_PLAYERS];
    int num_players, total_gems;

    printf("Welcome to the Gem Collector Game!\n");
    printf("Enter the number of players (1-%d): ", MAX_PLAYERS);
    scanf("%d", &num_players);

    if (num_players < 1 || num_players > MAX_PLAYERS) {
        printf("Invalid number of players! Exiting...\n");
        return 1;
    }

    printf("Enter the total number of gems to distribute: ");
    scanf("%d", &total_gems);

    // Initialize players
    for (int i = 0; i < num_players; i++) {
        players[i].id = i + 1; // Player IDs start from 1
        players[i].num_gems = 0; // No gems initially
    }

    // Assign the gems using a greedy algorithm
    assign_gems(players, num_players, total_gems);

    // Display the result
    display_gems(players, num_players);

    return 0;
}