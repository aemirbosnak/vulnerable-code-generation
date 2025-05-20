//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLANETS 5
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int distance; // in light-years
    int resources; // resource abundance level
} Planet;

typedef struct {
    char playerName[MAX_NAME_LENGTH];
    int fuel;
    int currentPlanetIndex;
} SpaceTraveler;

void initPlanets(Planet planets[]) {
    snprintf(planets[0].name, MAX_NAME_LENGTH, "Zylox");
    planets[0].distance = 4;
    planets[0].resources = rand() % 100 + 1; // Random resources between 1 and 100

    snprintf(planets[1].name, MAX_NAME_LENGTH, "Tygran");
    planets[1].distance = 8;
    planets[1].resources = rand() % 100 + 1;

    snprintf(planets[2].name, MAX_NAME_LENGTH, "Hesperia");
    planets[2].distance = 10;
    planets[2].resources = rand() % 100 + 1;

    snprintf(planets[3].name, MAX_NAME_LENGTH, "Qlaztor");
    planets[3].distance = 15;
    planets[3].resources = rand() % 100 + 1;

    snprintf(planets[4].name, MAX_NAME_LENGTH, "Nexon");
    planets[4].distance = 20;
    planets[4].resources = rand() % 100 + 1;
}

void printPlanetDetails(Planet planet) {
    printf("Planet Name: %s\n", planet.name);
    printf("Distance: %d light-years\n", planet.distance);
    printf("Resources: %d\n", planet.resources);
}

void travelToPlanet(SpaceTraveler *traveler, Planet planets[], int planetIndex) {
    if (planetIndex < 0 || planetIndex >= MAX_PLANETS) {
        printf("Invalid planet selection.\n");
        return;
    }

    int fuelCost = planets[planetIndex].distance;
    
    if (traveler->fuel < fuelCost) {
        printf("Not enough fuel to travel to %s. Fuel available: %d, Fuel required: %d\n", planets[planetIndex].name, traveler->fuel, fuelCost);
    } else {
        traveler->fuel -= fuelCost;
        traveler->currentPlanetIndex = planetIndex;
        printf("Traveling to %s...\n", planets[planetIndex].name);
        printf("You arrived at %s. Resources on this planet: %d\n", planets[planetIndex].name, planets[planetIndex].resources);
    }
}

void gatherResources(SpaceTraveler *traveler, Planet planets[]) {
    int currentPlanetIndex = traveler->currentPlanetIndex;

    if (currentPlanetIndex == -1) {
        printf("You are not on any planet.\n");
        return;
    }

    int resourcesGathered = planets[currentPlanetIndex].resources;
    printf("Gathering resources from %s... You collected %d resources!\n", planets[currentPlanetIndex].name, resourcesGathered);
}

int main() {
    srand(time(NULL)); // Initialize random seed
    
    SpaceTraveler traveler;
    traveler.fuel = 30; // Starting fuel
    traveler.currentPlanetIndex = -1; // Not currently on any planet

    Planet planets[MAX_PLANETS];
    initPlanets(planets);

    printf("Welcome to the Cosmic Odyssey, Traveler!\n");
    printf("What is your name, brave explorer? ");
    fgets(traveler.playerName, MAX_NAME_LENGTH, stdin);
    traveler.playerName[strcspn(traveler.playerName, "\n")] = 0; // Remove newline

    int choice = -1;

    while (choice != 0) {
        printf("\n--- %s's Adventure ---\n", traveler.playerName);
        printf("1. View Planets\n");
        printf("2. Travel to a Planet\n");
        printf("3. Gather Resources\n");
        printf("0. Exit Game\n");
        printf("What would you like to do? ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Available Planets:\n");
                for (int i = 0; i < MAX_PLANETS; i++) {
                    printPlanetDetails(planets[i]);
                }
                break;
            case 2:
                printf("Enter planet index (0-%d) to travel to: ", MAX_PLANETS - 1);
                int planetIndex;
                scanf("%d", &planetIndex);
                travelToPlanet(&traveler, planets, planetIndex);
                break;
            case 3:
                gatherResources(&traveler, planets);
                break;
            case 0:
                printf("Exiting... Thank you for playing, %s!\n", traveler.playerName);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}