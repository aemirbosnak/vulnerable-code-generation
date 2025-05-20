//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLANETS 10
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int resources;
    int dangerLevel;
} Planet;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int fuel;
    int resources;
} Spaceship;

void initializePlanets(Planet planets[]) {
    const char *planetNames[] = {"Zephyr", "Xandar", "Qatari", "Nnara", "Klyto", "Marzara", "Trinox", "Vortex", "Astoria", "Delta"};
    for (int i = 0; i < MAX_PLANETS; i++) {
        strcpy(planets[i].name, planetNames[i]);
        planets[i].resources = rand() % 100 + 1;
        planets[i].dangerLevel = rand() % 10 + 1;
    }
}

void travelToPlanet(Spaceship *ship, Planet *planet) {
    printf("Traveling to %s...\n", planet->name);
    ship->fuel -= planet->dangerLevel;
    
    if (ship->fuel < 0) {
        printf("Not enough fuel to reach %s! Game Over.\n", planet->name);
        exit(0);
    }

    printf("You have arrived at %s! Resources available: %d, Danger Level: %d\n", planet->name, planet->resources, planet->dangerLevel);
    
    printf("Do you want to collect resources? (1: Yes, 0: No): ");
    int choice;
    scanf("%d", &choice);
    
    if (choice == 1) {
        if (planet->resources > 0) {
            ship->resources += planet->resources;
            printf("You collected %d resources! Current resources: %d\n", planet->resources, ship->resources);
            planet->resources = 0; // resources depleted
        } else {
            printf("Resources already depleted at %s!\n", planet->name);
        }
    }
}

void displayStatus(Spaceship *ship) {
    printf("\n--- Spaceship Status ---\n");
    printf("Name: %s\n", ship->name);
    printf("Fuel: %d\n", ship->fuel);
    printf("Resources: %d\n", ship->resources);
    printf("-------------------------\n\n");
}

int main() {
    srand(time(NULL));

    Spaceship ship;
    printf("Enter your spaceship name: ");
    scanf("%s", ship.name);
    ship.fuel = 50; // starting fuel
    ship.resources = 0; // starting resources

    Planet planets[MAX_PLANETS];
    initializePlanets(planets);

    int gameRunning = 1;
    while (gameRunning) {
        displayStatus(&ship);
        printf("Choose a planet to travel to (0-%d) or -1 to exit: \n", MAX_PLANETS - 1);
        for (int i = 0; i < MAX_PLANETS; i++) {
            printf("%d: %s\n", i, planets[i].name);
        }

        int planetChoice;
        scanf("%d", &planetChoice);
        if (planetChoice == -1) {
            gameRunning = 0;
            printf("Exiting the game. Thank you for playing!\n");
            break;
        }

        if (planetChoice < 0 || planetChoice >= MAX_PLANETS) {
            printf("Invalid choice. Please select a valid planet.\n");
            continue;
        }

        travelToPlanet(&ship, &planets[planetChoice]);

        if (ship.fuel <= 0) {
            printf("You ran out of fuel! Game Over.\n");
            break;
        }
    }

    return 0;
}