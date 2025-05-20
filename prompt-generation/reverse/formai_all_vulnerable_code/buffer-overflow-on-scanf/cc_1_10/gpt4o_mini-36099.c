//GPT-4o-mini DATASET v1.0 Category: Game ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_PLANETS 10
#define MAX_NAME_LENGTH 20
#define MAX_PLAYERS 5
#define MAX_COMMAND_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int resources;
    int technology_level;
} Planet;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int ships;
    int energy;
    int score;
} Player;

Planet planets[MAX_PLANETS];
Player players[MAX_PLAYERS];
int numPlanets = 0;
int numPlayers = 0;

void initializePlanets() {
    for (int i = 0; i < MAX_PLANETS; i++) {
        snprintf(planets[i].name, MAX_NAME_LENGTH, "Planet-%d", i + 1);
        planets[i].resources = rand() % 1000;
        planets[i].technology_level = rand() % 10 + 1;
    }
    numPlanets = MAX_PLANETS;
}

void initializePlayers() {
    for (int i = 0; i < MAX_PLAYERS; i++) {
        snprintf(players[i].name, MAX_NAME_LENGTH, "Player-%d", i + 1);
        players[i].ships = 5; // Starting ships
        players[i].energy = 100; // Starting energy
        players[i].score = 0; // Starting score
    }
    numPlayers = MAX_PLAYERS;
}

void displayPlanets() {
    printf("Available Planets:\n");
    for (int i = 0; i < numPlanets; i++) {
        printf("%s - Resources: %d, Tech Level: %d\n", 
               planets[i].name, 
               planets[i].resources, 
               planets[i].technology_level);
    }
}

void displayPlayers() {
    printf("Players:\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("%s - Ships: %d, Energy: %d, Score: %d\n", 
               players[i].name, 
               players[i].ships,
               players[i].energy,
               players[i].score);
    }
}

void gatherResources(int playerIndex, int planetIndex) {
    if (players[playerIndex].energy >= 10) {
        players[playerIndex].energy -= 10;
        players[playerIndex].score += planets[planetIndex].resources / 10;
        printf("%s gathered resources from %s!\n", players[playerIndex].name, planets[planetIndex].name);
        planets[planetIndex].resources = 0; // Resources depleted
    } else {
        printf("%s does not have enough energy to gather resources!\n", players[playerIndex].name);
    }
}

void upgradeTechnology(int playerIndex) {
    if (players[playerIndex].energy >= 20) {
        players[playerIndex].energy -= 20;
        players[playerIndex].score += 5;
        printf("%s upgraded technology!\n", players[playerIndex].name);
    } else {
        printf("%s does not have enough energy to upgrade technology!\n", players[playerIndex].name);
    }
}

void commandLoop() {
    char command[MAX_COMMAND_LENGTH];
    int playerIndex;

    while (1) {
        printf("\nEnter player index (0-%d): ", numPlayers - 1);
        scanf("%d", &playerIndex);
        if (playerIndex < 0 || playerIndex >= numPlayers) {
            printf("Invalid player index!\n");
            continue;
        }
        printf("Available Commands: gather, upgrade, status, quit\n");
        printf("Enter command: ");
        scanf("%s", command);

        if (strcmp(command, "gather") == 0) {
            int planetIndex;
            printf("Choose planet index (0-%d): ", numPlanets - 1);
            scanf("%d", &planetIndex);
            if (planetIndex < 0 || planetIndex >= numPlanets) {
                printf("Invalid planet index!\n");
                continue;
            }
            gatherResources(playerIndex, planetIndex);
        } else if (strcmp(command, "upgrade") == 0) {
            upgradeTechnology(playerIndex);
        } else if (strcmp(command, "status") == 0) {
            displayPlayers();
        } else if (strcmp(command, "quit") == 0) {
            printf("Exiting game...\n");
            break;
        } else {
            printf("Unknown command: %s\n", command);
        }
    }
}

int main() {
    srand(time(NULL));
    initializePlanets();
    initializePlayers();
    
    printf("Welcome to the Galactic Conquest!\n");
    displayPlanets();
    displayPlayers();
    
    commandLoop();
    
    return 0;
}