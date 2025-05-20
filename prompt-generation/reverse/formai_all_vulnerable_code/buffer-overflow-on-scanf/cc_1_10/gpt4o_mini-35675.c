//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLANETS 5
#define MAX_SHIPS 3
#define MAX_NAME_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    int distance; // in light-years
    int resources; // resources available on the planet
} Planet;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int fuel; // in percentage
    int crew; // number of crew members
} Spaceship;

void initializePlanets(Planet planets[], int size) {
    const char *planetNames[] = {
        "Zephyria", "Crystalia", "Volcanis", "Aquaterra", "Aetheria"
    };
    
    for (int i = 0; i < size; i++) {
        strcpy(planets[i].name, planetNames[i]);
        planets[i].distance = rand() % 100 + 1; // Distance between 1 to 100 light-years
        planets[i].resources = rand() % 100 + 1; // Resources from 1 to 100
    }
}

void initializeSpaceships(Spaceship ships[], int size) {
    const char *shipNames[] = {
        "Star Voyager", "Galactic Explorer", "Cosmo Cruiser"
    };

    for (int i = 0; i < size; i++) {
        strcpy(ships[i].name, shipNames[i]);
        ships[i].fuel = rand() % 100 + 1; // Fuel between 1 to 100 percent
        ships[i].crew = (rand() % 5) + 1; // Crew members between 1 to 5
    }
}

void displayPlanets(Planet planets[], int size) {
    printf("Available Planets:\n");
    for (int i = 0; i < size; i++) {
        printf("Planet: %s | Distance: %d light-years | Resources: %d\n",
               planets[i].name, planets[i].distance, planets[i].resources);
    }
}

void displaySpaceships(Spaceship ships[], int size) {
    printf("\nAvailable Spaceships:\n");
    for (int i = 0; i < size; i++) {
        printf("Spaceship: %s | Fuel: %d%% | Crew: %d\n",
               ships[i].name, ships[i].fuel, ships[i].crew);
    }
}

int travelToPlanet(Spaceship *ship, Planet *planet) {
    if (ship->fuel < 10) {
        printf("Not enough fuel to travel to %s!\n", planet->name);
        return 0;
    }

    ship->fuel -= 10; // Decrease fuel by 10% for the journey
    printf("Traveling to %s... Arrived!\n", planet->name);
    return 1;
}

void gatherResources(Spaceship *ship, Planet *planet) {
    if (ship->crew < 2) {
        printf("Not enough crew to gather resources from %s!\n", planet->name);
        return;
    }

    printf("Gathering resources from %s...\n", planet->name);
    ship->crew--;
    printf("Resources gathered: %d\n", planet->resources);
}

int main() {
    srand(time(NULL)); // Seed for random number generation

    Planet planets[MAX_PLANETS];
    Spaceship ships[MAX_SHIPS];

    initializePlanets(planets, MAX_PLANETS);
    initializeSpaceships(ships, MAX_SHIPS);

    displayPlanets(planets, MAX_PLANETS);
    displaySpaceships(ships, MAX_SHIPS);

    int choice, planetIndex;
    printf("\nChoose your spaceship (1 to %d): ", MAX_SHIPS);
    scanf("%d", &choice);
    if (choice < 1 || choice > MAX_SHIPS) {
        printf("Invalid choice!\n");
        return 1;
    }

    Spaceship selectedShip = ships[choice - 1];
    printf("You selected %s.\n", selectedShip.name);
    
    printf("\nSelect a planet to travel to (1 to %d): ", MAX_PLANETS);
    scanf("%d", &planetIndex);
    
    if (planetIndex < 1 || planetIndex > MAX_PLANETS) {
        printf("Invalid planet selection!\n");
        return 1;
    }

    Planet selectedPlanet = planets[planetIndex - 1];

    if (travelToPlanet(&selectedShip, &selectedPlanet)) {
        gatherResources(&selectedShip, &selectedPlanet);
    }

    printf("\nReturning back to base...\n");
    printf("Fuel Remaining: %d%%\n", selectedShip.fuel);

    return 0;
}