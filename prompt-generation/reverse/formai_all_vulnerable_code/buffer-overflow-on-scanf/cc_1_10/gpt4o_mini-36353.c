//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLANETS 5
#define MAX_ALIENS 3
#define MAX_TREASURES 5

typedef struct {
    char name[30];
    int treasures;
} Planet;

typedef struct {
    char name[30];
    int threatLevel;
} Alien;

typedef struct {
    char name[30];
} Treasure;

Planet planets[MAX_PLANETS];
Alien aliens[MAX_ALIENS];
Treasure treasures[MAX_TREASURES];
int currentPlanetIndex = 0;

void initializePlanets() {
    strcpy(planets[0].name, "Zorgon");
    planets[0].treasures = 10;
    
    strcpy(planets[1].name, "Novus");
    planets[1].treasures = 5;

    strcpy(planets[2].name, "Xandar");
    planets[2].treasures = 2;

    strcpy(planets[3].name, "Galactis");
    planets[3].treasures = 15;

    strcpy(planets[4].name, "Verdoon");
    planets[4].treasures = 8;
}

void initializeAliens() {
    strcpy(aliens[0].name, "Zylox");
    aliens[0].threatLevel = 7;

    strcpy(aliens[1].name, "Blarg");
    aliens[1].threatLevel = 5;

    strcpy(aliens[2].name, "Grix");
    aliens[2].threatLevel = 9;
}

void initializeTreasures() {
    strcpy(treasures[0].name, "Stellar Crystal");
    strcpy(treasures[1].name, "Cosmic Relic");
    strcpy(treasures[2].name, "Galactic Key");
    strcpy(treasures[3].name, "Nebula Gem");
    strcpy(treasures[4].name, "Black Hole Amulet");
}

void visitPlanet() {
    Planet planet = planets[currentPlanetIndex];
    printf("You arrived at planet %s!\n", planet.name);
    printf("You found %d treasures here!\n", planet.treasures);
    
    // Simulate alien encounter
    int alienEncounter = rand() % 2; // 50% chance of encountering an alien
    if (alienEncounter) {
        int alienIndex = rand() % MAX_ALIENS;
        Alien alien = aliens[alienIndex];
        printf("Watch out! You've encountered a hostile alien: %s (Threat Level: %d)\n", alien.name, alien.threatLevel);
        printf("You need to escape quickly!\n");
    } else {
        printf("No aliens in sight. You can collect treasures!\n");
        printf("Collecting treasures...\n");
        planet.treasures = 0; // All treasures collected
    }
}

void travelToNextPlanet() {
    currentPlanetIndex++;
    if (currentPlanetIndex >= MAX_PLANETS) {
        printf("You have explored all the planets! Adventure complete!\n");
        exit(0);
    }
}

void displayMenu() {
    printf("\n--- Space Adventure ---\n");
    printf("1. Visit Planet\n");
    printf("2. Travel to Next Planet\n");
    printf("3. Exit Game\n");
    printf("Choose your action: ");
}

int main() {
    srand(time(0));
    initializePlanets();
    initializeAliens();
    initializeTreasures();

    while (1) {
        displayMenu();
        
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                visitPlanet();
                break;
            case 2:
                travelToNextPlanet();
                break;
            case 3:
                printf("Exiting the game. Safe travels, space explorer!\n");
                return 0;
            default:
                printf("Invalid choice! Please select again.\n");
        }
    }
    
    return 0;
}