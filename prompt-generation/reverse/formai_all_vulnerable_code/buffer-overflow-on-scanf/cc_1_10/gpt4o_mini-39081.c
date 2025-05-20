//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLANETS 5
#define PLANET_NAME_LENGTH 20

typedef struct {
    char name[PLANET_NAME_LENGTH];
    int resources;
    int difficulty;
} Planet;

typedef struct {
    char captain[PLANET_NAME_LENGTH];
    int shipFuel;
    int totalPlanetsExplored;
    int credits;
} Spacecraft;

void initializePlanet(Planet* planet, const char* name, int resources, int difficulty) {
    strncpy(planet->name, name, PLANET_NAME_LENGTH);
    planet->resources = resources;
    planet->difficulty = difficulty;
}

void explorePlanet(Planet* planet, Spacecraft* ship) {
    printf("Exploring planet %s...\n", planet->name);
    
    if (ship->shipFuel <= 0) {
        printf("Not enough fuel to explore!\n");
        return;
    }

    ship->shipFuel -= 1;

    int chance = rand() % 100;
    if (chance < planet->difficulty) {
        printf("Encountered difficulties on %s!\n", planet->name);
        printf("Exploration failed.\n");
    } else {
        printf("Successfully explored %s and gathered %d resources.\n", planet->name, planet->resources);
        ship->credits += planet->resources;
        ship->totalPlanetsExplored += 1;
    }
}

void displayStatus(Spacecraft* ship) {
    printf("\n=== Spacecraft Status ===\n");
    printf("Captain: %s\n", ship->captain);
    printf("Fuel: %d\n", ship->shipFuel);
    printf("Total Planets Explored: %d\n", ship->totalPlanetsExplored);
    printf("Credits: %d\n", ship->credits);
    printf("=========================\n");
}

int main() {
    srand(time(NULL));

    Spacecraft ship;
    strncpy(ship.captain, "Captain Nova", PLANET_NAME_LENGTH);
    ship.shipFuel = 5;
    ship.totalPlanetsExplored = 0;
    ship.credits = 0;

    Planet planets[MAX_PLANETS];

    initializePlanet(&planets[0], "Zarcon", 50, 30);
    initializePlanet(&planets[1], "Vulcan", 30, 70);
    initializePlanet(&planets[2], "Jupiteria", 70, 20);
    initializePlanet(&planets[3], "Xantha", 40, 40);
    initializePlanet(&planets[4], "Elysium", 100, 50);

    int choice;

    while (1) {
        displayStatus(&ship);

        printf("\nChoose a planet to explore (0-4) or -1 to exit:\n");
        for (int i = 0; i < MAX_PLANETS; i++) {
            printf("%d: %s\n", i, planets[i].name);
        }

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == -1) {
            printf("Exiting the adventure. Safe travels, Captain %s!\n", ship.captain);
            break;
        } else if (choice < 0 || choice >= MAX_PLANETS) {
            printf("Invalid choice. Try again!\n");
            continue;
        }

        explorePlanet(&planets[choice], &ship);
    }

    return 0;
}