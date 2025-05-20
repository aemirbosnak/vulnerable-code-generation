//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_DISTANCE 1000
#define FUEL_CAPACITY 500
#define PLANET_COUNT 5
#define COMMAND_COUNT 4

typedef struct {
    char name[20];
    int distance;
    int resources;
} Planet;

typedef struct {
    char shipName[20];
    int fuel;
    int supplies;
    char captain[20];
} Spaceship;

void initializePlanets(Planet planets[]) {
    strcpy(planets[0].name, "Celestia");
    planets[0].distance = 500;
    planets[0].resources = 150;

    strcpy(planets[1].name, "Luna");
    planets[1].distance = 300;
    planets[1].resources = 200;

    strcpy(planets[2].name, "Zyphor");
    planets[2].distance = 800;
    planets[2].resources = 100;

    strcpy(planets[3].name, "Aurelia");
    planets[3].distance = 400;
    planets[3].resources = 250;

    strcpy(planets[4].name, "Nebulon");
    planets[4].distance = 200;
    planets[4].resources = 300;
}

void displayPlanets(Planet planets[]) {
    printf("\nAvailable Planets:\n");
    for (int i = 0; i < PLANET_COUNT; i++) {
        printf("%d. %s - Distance: %d Light Years, Resources: %d\n", 
            i + 1, planets[i].name, planets[i].distance, planets[i].resources);
    }
}

int travel(Spaceship *ship, Planet *destination) {
    if (ship->fuel < destination->distance) {
        printf("Not enough fuel to reach %s. Current fuel: %d\n", destination->name, ship->fuel);
        return 0;
    } else {
        ship->fuel -= destination->distance;
        printf("Traveling to %s... Arrived!\n", destination->name);
        return 1;
    }
}

void gatherResources(Spaceship *ship, Planet *planet) {
    int gathered = planet->resources < ship->supplies ? planet->resources : ship->supplies;
    ship->supplies += gathered;
    planet->resources -= gathered;
    printf("Gathered %d resources from %s. Total supplies: %d\n", gathered, planet->name, ship->supplies);
}

void displayStatus(Spaceship ship) {
    printf("\n--- Spaceship Status ---\n");
    printf("Ship Name: %s\n", ship.shipName);
    printf("Captain: %s\n", ship.captain);
    printf("Fuel: %d\n", ship.fuel);
    printf("Supplies: %d\n", ship.supplies);
}

int main() {
    Spaceship ship = {"Starry Night", FUEL_CAPACITY, 0, "Luna"};
    Planet planets[PLANET_COUNT];
    initializePlanets(planets);

    displayStatus(ship);
    displayPlanets(planets);

    int choice;
    while (1) {
        printf("\nChoose a planet to travel to (1-%d), or 0 to exit: ", PLANET_COUNT);
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Preparing for departure...\n");
            break;
        } else if (choice < 1 || choice > PLANET_COUNT) {
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        Planet *selectedPlanet = &planets[choice - 1];

        if (travel(&ship, selectedPlanet)) {
            gatherResources(&ship, selectedPlanet);
            displayStatus(ship);
        }
    }

    printf("\nWishing you clear skies and joyous travels, brave captain!\n");
    return 0;
}