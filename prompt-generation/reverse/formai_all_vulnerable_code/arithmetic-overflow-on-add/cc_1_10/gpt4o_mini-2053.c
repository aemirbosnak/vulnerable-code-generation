//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PLAYERS 10
#define MAX_PLANETS 5
#define PLANET_NAME_LENGTH 30
#define PLAYER_NAME_LENGTH 20

typedef struct {
    char name[PLAYER_NAME_LENGTH];
    int health;
    int score;
} Player;

typedef struct {
    char name[PLANET_NAME_LENGTH];
    int loot;
} Planet;

Player players[MAX_PLAYERS];
Planet planets[MAX_PLANETS];
int playerCount = 0;

void initializePlanets() {
    strcpy(planets[0].name, "Zorax");
    planets[0].loot = 50;

    strcpy(planets[1].name, "Vulcanus");
    planets[1].loot = 70;

    strcpy(planets[2].name, "Aetheria");
    planets[2].loot = 40;

    strcpy(planets[3].name, "Nexulis");
    planets[3].loot = 60;

    strcpy(planets[4].name, "Orbis");
    planets[4].loot = 80;
}

void registerPlayer() {
    if (playerCount >= MAX_PLAYERS) {
        printf("Maximum player limit reached!\n");
        return;
    }
    printf("Enter player name: ");
    scanf("%s", players[playerCount].name);
    players[playerCount].health = 100;
    players[playerCount].score = 0;
    playerCount++;
    printf("Player %s registered successfully!\n", players[playerCount - 1].name);
}

void explorePlanet(int playerIndex) {
    printf("%s is exploring...\n", players[playerIndex].name);
    sleep(1); // Simulates time taken to explore.

    int chosenPlanet = rand() % MAX_PLANETS;
    int lootFound = planets[chosenPlanet].loot;
    players[playerIndex].score += lootFound;

    printf("%s discovered planet %s and found %d loot!\n", players[playerIndex].name, planets[chosenPlanet].name, lootFound);
}

void displayScores() {
    printf("\n--- Player Scores ---\n");
    for (int i = 0; i < playerCount; i++) {
        printf("%s: Health: %d, Score: %d\n", players[i].name, players[i].health, players[i].score);
    }
}

int main() {
    char choice;
    srand(time(NULL));
    initializePlanets();

    while (1) {
        printf("\nWelcome to the Space Adventure Game!\n");
        printf("1. Register Player\n");
        printf("2. Explore Planet\n");
        printf("3. Show Scores\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                registerPlayer();
                break;
            case '2':
                if (playerCount == 0) {
                    printf("No players registered yet! Please register first.\n");
                } else {
                    for (int i = 0; i < playerCount; i++) {
                        explorePlanet(i);
                    }
                }
                break;
            case '3':
                displayScores();
                break;
            case '4':
                printf("Exiting game...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}