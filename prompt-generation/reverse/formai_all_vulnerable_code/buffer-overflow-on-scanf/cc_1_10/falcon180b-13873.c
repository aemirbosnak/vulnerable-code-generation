//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 4

// Struct to hold player information
typedef struct {
    char name[20];
    int score;
} Player;

// Function prototypes
void initializePlayers(Player* players);
int getPlayerIndex(char* name, Player* players);
void displayScores(Player* players);

int main() {
    Player players[MAX_PLAYERS]; // Array to hold player information
    initializePlayers(players); // Initialize player information

    while(1) {
        printf("Enter name: ");
        char name[20];
        scanf("%s", name);

        int playerIndex = getPlayerIndex(name, players); // Get player index

        if(playerIndex == -1) {
            printf("Player not found.\n");
            continue;
        }

        printf("Enter score: ");
        int score;
        scanf("%d", &score);

        players[playerIndex].score += score; // Add score to player's score
    }

    return 0;
}

// Function to initialize player information
void initializePlayers(Player* players) {
    for(int i=0; i<MAX_PLAYERS; i++) {
        strcpy(players[i].name, "Player");
        players[i].score = 0;
    }
}

// Function to get player index based on name
int getPlayerIndex(char* name, Player* players) {
    for(int i=0; i<MAX_PLAYERS; i++) {
        if(strcmp(players[i].name, name) == 0) {
            return i;
        }
    }

    return -1; // Player not found
}

// Function to display player scores
void displayScores(Player* players) {
    printf("Player Scores:\n");
    for(int i=0; i<MAX_PLAYERS; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
}