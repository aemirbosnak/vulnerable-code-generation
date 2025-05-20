//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLANETS 5
#define MAX_NAME_LENGTH 30
#define MAX_RESOURCE_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char resource[MAX_RESOURCE_LENGTH];
    int dangerLevel;
} Planet;

typedef struct {
    int health;
    int resources;
} Spacecraft;

void initializePlanets(Planet planets[]) {
    strcpy(planets[0].name, "Zyron");
    strcpy(planets[0].resource, "Crystals");
    planets[0].dangerLevel = 1;

    strcpy(planets[1].name, "Xylon");
    strcpy(planets[1].resource, "Gases");
    planets[1].dangerLevel = 2;

    strcpy(planets[2].name, "Taron");
    strcpy(planets[2].resource, "Metals");
    planets[2].dangerLevel = 3;

    strcpy(planets[3].name, "Viron");
    strcpy(planets[3].resource, "Energy");
    planets[3].dangerLevel = 4;

    strcpy(planets[4].name, "Alyth");
    strcpy(planets[4].resource, "Water");
    planets[4].dangerLevel = 5;
}

void printPlanets(Planet planets[], int count) {
    printf("Available Planets:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - Resource: %s (Danger Level: %d)\n", 
                i + 1, planets[i].name, planets[i].resource, planets[i].dangerLevel);
    }
}

int explorePlanet(Spacecraft *ship, Planet *planet) {
    printf("Exploring planet: %s\n", planet->name);
    int encounter = rand() % 10;

    if (encounter < planet->dangerLevel) {
        printf("You encountered hostile aliens!\n");
        int battleOutcome = rand() % 2;
        if (battleOutcome == 0) {
            printf("You fought bravely but lost.\n");
            ship->health -= 20;
            if (ship->health <= 0) {
                printf("You have perished in battle. Game Over!\n");
                return 0;
            }
        } else {
            printf("You defeated the aliens and gathered resources!\n");
            ship->resources += 10;
        }
    } else {
        printf("You safely gathered resources from the planet.\n");
        ship->resources += 5;
    }
    return 1;
}

void showStatus(Spacecraft ship) {
    printf("\nShip Status:\n");
    printf("Health: %d\n", ship.health);
    printf("Resources: %d\n", ship.resources);
}

int main() {
    srand(time(NULL));
    
    Planet planets[MAX_PLANETS];
    initializePlanets(planets);

    Spacecraft ship;
    ship.health = 100;
    ship.resources = 0;

    int playing = 1;
    while (playing && ship.health > 0) {
        printPlanets(planets, MAX_PLANETS);
        int choice;
        printf("Select a planet to explore (1-%d) or 0 to quit: ", MAX_PLANETS);
        scanf("%d", &choice);

        if (choice == 0) {
            playing = 0;
            printf("Thank you for playing! Your journey ends here.\n");
        } else if (choice >= 1 && choice <= MAX_PLANETS) {
            if (!explorePlanet(&ship, &planets[choice - 1])) {
                playing = 0;
            }
        } else {
            printf("Invalid choice! Please try again.\n");
        }

        showStatus(ship);
        if (ship.resources >= 50) {
            printf("Congratulations! You have gathered enough resources to build a new spaceship!\n");
            playing = 0;
        }
    }

    return 0;
}