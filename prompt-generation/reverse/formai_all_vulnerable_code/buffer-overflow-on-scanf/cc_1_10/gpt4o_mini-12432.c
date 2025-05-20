//GPT-4o-mini DATASET v1.0 Category: System boot optimizer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_PLAYERS 4
#define MAX_NAME_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    int speed;
    int boostPoints;
} Player;

void initializePlayers(Player players[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Enter name for Player %d: ", i + 1);
        fgets(players[i].name, MAX_NAME_LEN, stdin);
        players[i].name[strcspn(players[i].name, "\n")] = 0; // Remove newline
        players[i].speed = rand() % 5 + 1; // Initial speed between 1 and 5
        players[i].boostPoints = 0; // Initial boost points
    }
}

void displayPlayerStats(Player players[], int count) {
    printf("\nCurrent Player Stats:\n");
    for (int i = 0; i < count; i++) {
        printf("Player %s - Speed: %d, Boost Points: %d\n",
               players[i].name, players[i].speed, players[i].boostPoints);
    }
}

int applyBoost(Player* player) {
    if (player->boostPoints > 0) {
        player->boostPoints--;
        player->speed += 2; // Temporary boost
        printf("%s used a boost! New Speed: %d\n", player->name, player->speed);
        return 1;
    } else {
        printf("%s has no boost points left!\n", player->name);
        return 0;
    }
}

void collectBoostPoints(Player* player) {
    player->boostPoints += 1; // Randomly collect a boost point
    printf("%s collected a boost point! Total Boost Points: %d\n",
           player->name, player->boostPoints);
}

void simulateBootProcess(Player players[], int count) {
    int raceLength = 30; // Simulated race length
    int playerPositions[MAX_PLAYERS] = {0};

    srand(time(0)); // For random values

    while (1) {
        for (int i = 0; i < count; i++) {
            int action = rand() % 3; // Random action: 0 = collect point, 1 = boost, 2 = nothing
            if (action == 0) {
                collectBoostPoints(&players[i]);
            } else if (action == 1) {
                applyBoost(&players[i]);
            }
            playerPositions[i] += players[i].speed; // Update positions
            // Reset speed after boost
            players[i].speed = players[i].speed > 3 ? players[i].speed - 1 : players[i].speed; 
        }

        // Display current positions
        printf("\nCurrent Race Positions:\n");
        for (int i = 0; i < count; i++) {
            printf("%s is at position %d\n", players[i].name, playerPositions[i]);
        }

        // Check for race completion
        for (int i = 0; i < count; i++) {
            if (playerPositions[i] >= raceLength) {
                printf("\n%s wins the boot race!\n", players[i].name);
                return;
            }
        }
        
        // Delay for the next round
        sleep(1);
    }
}

int main() {
    Player players[MAX_PLAYERS];
    int numPlayers;

    printf("Welcome to the Multiplayer Boot Optimizer!\n");
    printf("How many players (1 - %d): ", MAX_PLAYERS);
    scanf("%d", &numPlayers);
    getchar(); // Consume newline

    if (numPlayers < 1 || numPlayers > MAX_PLAYERS) {
        printf("Invalid number of players. Exiting...\n");
        return 1;
    }

    initializePlayers(players, numPlayers);
    displayPlayerStats(players, numPlayers);

    simulateBootProcess(players, numPlayers);

    return 0;
}