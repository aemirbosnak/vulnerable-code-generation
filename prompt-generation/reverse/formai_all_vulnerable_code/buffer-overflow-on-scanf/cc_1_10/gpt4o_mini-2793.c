//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_TURNS 10
#define MAP_SIZE 10

typedef struct {
    char name[20];
    int position;
} Player;

void initializePlayers(Player players[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Enter the name for Player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].position = 0;
    }
}

void displayPlayerPositions(Player players[], int count) {
    printf("\nCurrent positions:\n");
    for (int i = 0; i < count; i++) {
        printf("%s is at position %d\n", players[i].name, players[i].position);
    }
}

void movePlayer(Player *player) {
    int move;
    move = rand() % 6 + 1; // Random move between 1 and 6
    player->position += move;

    if (player->position >= MAP_SIZE) {
        printf("%s has reached the end of the map!\n", player->name);
        player->position = MAP_SIZE; // Clamp to MAP_SIZE
    } else {
        printf("%s moves %d spaces to position %d\n", player->name, move, player->position);
    }
}

int main() {
    Player players[MAX_PLAYERS];
    int numberOfPlayers;
    
    srand(time(NULL)); // Seed the random number generator

    printf("Welcome to the Decentralized Race Game!\n");
    printf("How many players (1 - %d): ", MAX_PLAYERS);
    scanf("%d", &numberOfPlayers);
    
    if (numberOfPlayers < 1 || numberOfPlayers > MAX_PLAYERS) {
        printf("Invalid number of players. Please restart the game.\n");
        return 1;
    }

    initializePlayers(players, numberOfPlayers);
    
    for (int turn = 0; turn < MAX_TURNS; turn++) {
        printf("\n--- Turn %d ---\n", turn + 1);
        
        for (int i = 0; i < numberOfPlayers; i++) {
            movePlayer(&players[i]);
            displayPlayerPositions(players, numberOfPlayers);
            
            if (players[i].position == MAP_SIZE) {
                printf("\nCongratulations %s! You are the winner!\n", players[i].name);
                return 0;
            }
        }
    }
    
    printf("\nGame Over! No one reached the end of the map.\n");
    return 0;
}