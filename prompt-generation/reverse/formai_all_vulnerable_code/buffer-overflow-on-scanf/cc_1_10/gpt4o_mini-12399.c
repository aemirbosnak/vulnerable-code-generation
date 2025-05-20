//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLANETS 5
#define MAX_NAME_LENGTH 30
#define MAX_DISTANCE 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    int distance; // Distance from Earth in light years
    int resources; // Resources available on the planet
} Planet;

void initializePlanets(Planet planets[], int count) {
    const char *planetNames[] = {"Aquila", "Cygnus", "Draco", "Phoenix", "Orion"};
    for (int i = 0; i < count; i++) {
        strcpy(planets[i].name, planetNames[i]);
        planets[i].distance = rand() % MAX_DISTANCE + 1; // Random distance between 1 and MAX_DISTANCE
        planets[i].resources = rand() % 100 + 1; // Random resources between 1 and 100
    }
}

void displayPlanets(Planet planets[], int count) {
    printf("\nAvailable planets:\n");
    for (int i = 0; i < count; i++) {
        printf("Planet: %s, Distance: %d light years, Resources: %d\n",
               planets[i].name, planets[i].distance, planets[i].resources);
    }
}

void explorePlanet(Planet planet) {
    printf("\nExploring %s...\n", planet.name);
    printf("You have discovered %d resources!\n", planet.resources);
    printf("You gather the resources successfully!\n");
}

int main() {
    srand(time(NULL));
    Planet planets[MAX_PLANETS];
    int choice;

    initializePlanets(planets, MAX_PLANETS);

    do {
        displayPlanets(planets, MAX_PLANETS);
        printf("\nEnter the number of the planet you want to explore (1-%d) or 0 to exit: ", MAX_PLANETS);
        scanf("%d", &choice);

        if (choice > 0 && choice <= MAX_PLANETS) {
            explorePlanet(planets[choice - 1]);
        } else if (choice != 0) {
            printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 0);

    printf("Thanks for exploring! Safe travels!\n");
    return 0;
}