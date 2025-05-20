//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Player struct to keep track of player information
typedef struct {
    char name[20];
    int score;
    int level;
} Player;

// Helper function to read a player's information from the console
Player read_player_info() {
    Player p;
    printf("Enter player name: ");
    scanf("%s", p.name);
    printf("Enter player score: ");
    scanf("%d", &p.score);
    printf("Enter player level: ");
    scanf("%d", &p.level);
    return p;
}

int main() {
    // Initialize empty player array with space for 4 players
    Player players[4];
    int num_players = 0;

    // Loop to continuously prompt for input until player array is full
    while (num_players < 4) {
        printf("Enter player information:\n");
        Player p = read_player_info();

        // Check if player with same name already exists in array
        int exists = 0;
        for (int i = 0; i < num_players; i++) {
            if (strcmp(players[i].name, p.name) == 0) {
                printf("Player with name %s already exists! Please enter a unique name.\n", p.name);
                exists = 1;
                break;
            }
        }

        // Add player to array if no player with same name exists
        if (!exists) {
            players[num_players] = p;
            num_players++;
        }
    }

    // Print out player information
    printf("\nPlayer information:\n");
    for (int i = 0; i < 4; i++) {
        printf("Name: %s\n", players[i].name);
        printf("Score: %d\n", players[i].score);
        printf("Level: %d\n", players[i].level);
    }

    return 0;
}