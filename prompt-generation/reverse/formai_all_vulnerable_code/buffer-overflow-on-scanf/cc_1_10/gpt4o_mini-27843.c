//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLANETS 5
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int breathable;
    int resources;
} Planet;

void initializePlanets(Planet planets[]) {
    const char *names[MAX_PLANETS] = {"Zenon", "Aurelia", "Krypton", "Nebula", "Triton"};
    for (int i = 0; i < MAX_PLANETS; i++) {
        strncpy(planets[i].name, names[i], MAX_NAME_LENGTH);
        planets[i].breathable = rand() % 2; // 0 or 1
        planets[i].resources = rand() % 100; // Resources from 0 to 99
    }
}

void displayPlanets(Planet planets[]) {
    printf("Available Planets:\n");
    for (int i = 0; i < MAX_PLANETS; i++) {
        printf("%d: %s - Breathable: %s, Resources: %d\n", 
                i + 1, 
                planets[i].name, 
                planets[i].breathable ? "Yes" : "No", 
                planets[i].resources);
    }
}

void explorePlanet(Planet planet) {
    printf("Exploring planet %s...\n", planet.name);
    if (planet.breathable) {
        printf("You can breathe here! Resources found: %d\n", planet.resources);
        if (planet.resources > 50) {
            printf("This planet has plentiful resources!\n");
        } else {
            printf("Resources are limited on this planet.\n");
        }
    } else {
        printf("WARNING: This planet is not breathable! Return to the ship!\n");
    }
}

void spaceAdventure() {
    Planet planets[MAX_PLANETS];
    srand(time(NULL));
    initializePlanets(planets);
    displayPlanets(planets);

    int choice;
    printf("Choose a planet to explore (1-%d): ", MAX_PLANETS);
    scanf("%d", &choice);
    if (choice < 1 || choice > MAX_PLANETS) {
        printf("Invalid choice! Exiting the adventure.\n");
        return;
    }

    explorePlanet(planets[choice - 1]);
}

int main() {
    printf("Welcome to the Space Adventure!\n");
    spaceAdventure();
    printf("Thank you for playing! Safe travels.\n");
    return 0;
}