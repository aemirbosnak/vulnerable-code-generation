//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLANETS 10
#define MAX_NAME_LENGTH 20
#define MAX_SHIPS 5

typedef struct {
    char name[MAX_NAME_LENGTH];
    int distance; // Distance from Earth in light years
} Planet;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int speed; // Speed in light years per year
    int fuel; // Fuel capacity
} Spaceship;

void initializePlanets(Planet planets[], int count) {
    const char *planetNames[] = {"Zyphor", "Xenon", "Galdor", "Mylos", "Quarim",
                                  "Penthara", "Raxor", "Vortex", "Thronis", "Oberon"};

    for (int i = 0; i < count; i++) {
        snprintf(planets[i].name, MAX_NAME_LENGTH, "%s", planetNames[i]);
        planets[i].distance = rand() % 100 + 1; // Random distance between 1 and 100 light years
    }
}

void initializeSpaceships(Spaceship ships[], int count) {
    const char *shipNames[] = {"Falcon", "Spectre", "Voyager", "Stinger", "Nighthawk"};

    for (int i = 0; i < count; i++) {
        snprintf(ships[i].name, MAX_NAME_LENGTH, "%s", shipNames[i]);
        ships[i].speed = (rand() % 10) + 1; // Speed between 1 and 10 light years per year
        ships[i].fuel = (rand() % 50) + 50; // Fuel between 50 and 100 units
    }
}

void displayPlanets(Planet planets[], int count) {
    printf("\nPlanets in your galaxy:\n");
    for (int i = 0; i < count; i++) {
        printf("  %d. %s - %d light years away\n", i + 1, planets[i].name, planets[i].distance);
    }
}

void displaySpaceships(Spaceship ships[], int count) {
    printf("\nAvailable Spaceships:\n");
    for (int i = 0; i < count; i++) {
        printf("  %d. %s - Speed: %d light years/year, Fuel: %d units\n", i + 1, ships[i].name, ships[i].speed, ships[i].fuel);
    }
}

int calculateTravelTime(int distance, int speed) {
    return (distance + speed - 1) / speed; // Travel time in years
}

void travel(Spaceship ship, Planet destination) {
    if (ship.fuel <= 0) {
        printf("Your spaceship is out of fuel! Can't travel!\n");
        return;
    }

    int travelTime = calculateTravelTime(destination.distance, ship.speed);
    printf("Traveling to %s...\n", destination.name);
    printf("Estimated travel time: %d year(s)\n", travelTime);

    // Simulate travel
    for (int year = 1; year <= travelTime; year++) {
        ship.fuel -= 10; // Using fuel
        printf("  Year %d: %s is now %d light years away, Fuel left: %d units\n", year, ship.name, destination.distance - ship.speed * year, ship.fuel);
        if (ship.fuel < 0) {
            printf("Fuel exhausted! You are stranded in space!\n");
            return;
        }
    }

    printf("You have arrived at %s! Welcome to the new world!\n", destination.name);
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    Planet planets[MAX_PLANETS];
    Spaceship ships[MAX_SHIPS];

    initializePlanets(planets, MAX_PLANETS);
    initializeSpaceships(ships, MAX_SHIPS);

    displayPlanets(planets, MAX_PLANETS);
    displaySpaceships(ships, MAX_SHIPS);

    int shipChoice, planetChoice;

    printf("\nSelect a spaceship by choosing its number (1-%d): ", MAX_SHIPS);
    scanf("%d", &shipChoice);
    printf("Select a planet to travel to by choosing its number (1-%d): ", MAX_PLANETS);
    scanf("%d", &planetChoice);

    if (shipChoice < 1 || shipChoice > MAX_SHIPS || planetChoice < 1 || planetChoice > MAX_PLANETS) {
        printf("Invalid selection. Exiting adventure.\n");
        return 1;
    }

    travel(ships[shipChoice - 1], planets[planetChoice - 1]);

    return 0;
}