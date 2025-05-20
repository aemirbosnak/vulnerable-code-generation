//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLANETS 5
#define MAX_SHIPS 5
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int distance;
    int resources;
} Planet;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int fuel;
    int cargo;
} Spaceship;

void initPlanets(Planet planets[]);
void initSpaceships(Spaceship ships[]);
void displayPlanets(Planet planets[]);
void displaySpaceships(Spaceship ships[]);
void travelToPlanet(Spaceship *ship, Planet *planet);
void collectResources(Spaceship *ship, Planet *planet);

int main() {
    srand(time(NULL)); // Seed the random number generator

    Planet planets[MAX_PLANETS];
    Spaceship ships[MAX_SHIPS];
    
    initPlanets(planets);
    initSpaceships(ships);

    int choice, shipIndex;
    while (1) {
        printf("\n=== Space Adventure ===\n");
        displaySpaceships(ships);
        printf("Choose your spaceship (1-%d) or 0 to exit: ", MAX_SHIPS);
        scanf("%d", &shipIndex);

        if (shipIndex == 0) {
            printf("Thanks for playing!\n");
            break;
        }

        if (shipIndex < 1 || shipIndex > MAX_SHIPS) {
            printf("Invalid choice, try again.\n");
            continue;
        }

        Spaceship *selectedShip = &ships[shipIndex - 1];
        
        displayPlanets(planets);
        printf("Choose a planet to travel to (1-%d): ", MAX_PLANETS);
        scanf("%d", &choice);

        if (choice < 1 || choice > MAX_PLANETS) {
            printf("Invalid choice, try again.\n");
            continue;
        }

        Planet *selectedPlanet = &planets[choice - 1];
        travelToPlanet(selectedShip, selectedPlanet);
        collectResources(selectedShip, selectedPlanet);
    }
    
    return 0;
}

void initPlanets(Planet planets[]) {
    for (int i = 0; i < MAX_PLANETS; i++) {
        snprintf(planets[i].name, MAX_NAME_LENGTH, "Planet %d", i + 1);
        planets[i].distance = rand() % 100 + 1; // Distance between 1 to 100
        planets[i].resources = rand() % 50 + 1; // Resources between 1 to 50
    }
}

void initSpaceships(Spaceship ships[]) {
    for (int i = 0; i < MAX_SHIPS; i++) {
        snprintf(ships[i].name, MAX_NAME_LENGTH, "Ship %d", i + 1);
        ships[i].fuel = rand() % 100 + 1; // Fuel between 1 to 100
        ships[i].cargo = 0; // Initial cargo is 0
    }
}

void displayPlanets(Planet planets[]) {
    printf("\nAvailable Planets:\n");
    for (int i = 0; i < MAX_PLANETS; i++) {
        printf("%d. %s | Distance: %d | Resources: %d\n", i + 1, planets[i].name, planets[i].distance, planets[i].resources);
    }
}

void displaySpaceships(Spaceship ships[]) {
    printf("\nAvailable Spaceships:\n");
    for (int i = 0; i < MAX_SHIPS; i++) {
        printf("%d. %s | Fuel: %d | Cargo: %d\n", i + 1, ships[i].name, ships[i].fuel, ships[i].cargo);
    }
}

void travelToPlanet(Spaceship *ship, Planet *planet) {
    if (ship->fuel >= planet->distance) {
        ship->fuel -= planet->distance;
        printf("Traveling to %s... Arrival successful! Fuel left: %d\n", planet->name, ship->fuel);
    } else {
        printf("Not enough fuel to travel to %s. Please refuel!\n", planet->name);
    }
}

void collectResources(Spaceship *ship, Planet *planet) {
    if (ship->cargo + planet->resources <= 100) { // Assume max cargo capacity is 100
        ship->cargo += planet->resources;
        planet->resources = 0; // Resources collected
        printf("Collected resources from %s. Current cargo: %d\n", planet->name, ship->cargo);
    } else {
        printf("Cargo full! Cannot collect more resources from %s.\n", planet->name);
    }
}