//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLANETS 10
#define MAX_NAME_LENGTH 30
#define MAX_MESSAGE_LENGTH 100
#define MAX_SYSTEMS 5

typedef struct {
    char name[MAX_NAME_LENGTH];
    int resources;
    int distance;
    int hasLife;
} Planet;

typedef struct {
    char name[MAX_NAME_LENGTH];
    Planet planets[MAX_PLANETS];
    int numPlanets;
} StarSystem;

StarSystem starSystems[MAX_SYSTEMS];

void initializeStarSystems() {
    for (int i = 0; i < MAX_SYSTEMS; i++) {
        sprintf(starSystems[i].name, "System %d", i + 1);
        starSystems[i].numPlanets = rand() % MAX_PLANETS + 1; // Random number of planets

        for (int j = 0; j < starSystems[i].numPlanets; j++) {
            sprintf(starSystems[i].planets[j].name, "Planet %d.%d", i + 1, j + 1);
            starSystems[i].planets[j].resources = rand() % 100;
            starSystems[i].planets[j].distance = rand() % 1000;
            starSystems[i].planets[j].hasLife = rand() % 2; // 0 or 1
        }
    }
}

void displayStarSystems() {
    for (int i = 0; i < MAX_SYSTEMS; i++) {
        printf("Star System: %s\n", starSystems[i].name);
        for (int j = 0; j < starSystems[i].numPlanets; j++) {
            printf("  - %s: Resources %d, Distance %d light-years, %s\n",
                   starSystems[i].planets[j].name,
                   starSystems[i].planets[j].resources,
                   starSystems[i].planets[j].distance,
                   starSystems[i].planets[j].hasLife ? "Supports Life" : "No Life");
        }
    }
}

void explorePlanet(int systemIndex, int planetIndex) {
    printf("Exploring %s in %s...\n", starSystems[systemIndex].planets[planetIndex].name, starSystems[systemIndex].name);
    int discoveredResources = rand() % 50;
    starSystems[systemIndex].planets[planetIndex].resources += discoveredResources;
    printf("You have discovered additional resources: %d\n", discoveredResources);
    printf("Total resources now: %d\n", starSystems[systemIndex].planets[planetIndex].resources);
}

void reportStatus() {
    printf("Spacecraft Status Report:\n");
    printf("Hull Integrity: 100%%\n");
    printf("Power Levels: 75%%\n");
    printf("Fuel Levels: 50%%\n");
}

void interactWithLifeform() {
    // Simple interaction with found lifeform
    if (rand() % 2) {
        printf("You have encountered a friendly alien lifeform!\n");
        printf("They share advanced technology with you.\n");
    } else {
        printf("You encountered hostile alien lifeforms! They attack!\n");
        printf("You need to retreat!\n");
    }
}

void displayMainMenu() {
    printf("Welcome to the Galactic Explorer!\n");
    printf("1. View Star Systems\n");
    printf("2. Explore a Planet\n");
    printf("3. Check Craft Status\n");
    printf("4. Interact with Lifeforms\n");
    printf("5. Exit\n");
}

int main() {
    srand(time(NULL));
    initializeStarSystems();
    
    int choice, systemIndex, planetIndex;
    while (1) {
        displayMainMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayStarSystems();
                break;
            case 2:
                printf("Enter the star system index (1 - %d): ", MAX_SYSTEMS);
                scanf("%d", &systemIndex);
                systemIndex--; // Convert to 0-based index
                if (systemIndex < 0 || systemIndex >= MAX_SYSTEMS) {
                    printf("Invalid system index!\n");
                    break;
                }
                printf("Enter the planet index (1 - %d): ", starSystems[systemIndex].numPlanets);
                scanf("%d", &planetIndex);
                planetIndex--; // Convert to 0-based index
                if (planetIndex < 0 || planetIndex >= starSystems[systemIndex].numPlanets) {
                    printf("Invalid planet index!\n");
                    break;
                }
                explorePlanet(systemIndex, planetIndex);
                break;
            case 3:
                reportStatus();
                break;
            case 4:
                interactWithLifeform();
                break;
            case 5:
                printf("Ending the adventure. Safe travels!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}