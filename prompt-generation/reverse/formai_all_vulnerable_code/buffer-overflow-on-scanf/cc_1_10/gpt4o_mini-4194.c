//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PLANET_COUNT 5
#define MAX_NAME_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    int lifeForms; // Number of friendly life forms on the planet
    int resources; // Amount of resources available
    int dangerLevel; // Danger level from 1 (safe) to 5 (very dangerous)
} Planet;

void initializePlanets(Planet planets[]) {
    const char *names[] = {"Zyphor", "Elyria", "Kravon", "Vortexia", "Helix"};
    for (int i = 0; i < PLANET_COUNT; i++) {
        strncpy(planets[i].name, names[i], MAX_NAME_LEN);
        planets[i].lifeForms = rand() % 100;
        planets[i].resources = rand() % 100;
        planets[i].dangerLevel = rand() % 5 + 1; // Danger level from 1 to 5
    }
}

void displayPlanets(Planet planets[]) {
    printf("🌌 Welcome to the Galactic Explorer! Here are the planets you can visit: 🌌\n");
    for (int i = 0; i < PLANET_COUNT; i++) {
        printf("Planet %d: %s\n", i + 1, planets[i].name);
        printf("  Life Forms: %d\n", planets[i].lifeForms);
        printf("  Resources: %d\n", planets[i].resources);
        printf("  Danger Level: %d\n\n", planets[i].dangerLevel);
    }
}

void explorePlanet(Planet planet) {
    printf("🚀 You are exploring the planet %s! 🚀\n", planet.name);
    printf("You encounter %d friendly life forms!\n", planet.lifeForms);
    
    if (planet.dangerLevel > 3) {
        printf("Warning: This planet has a high danger level!\n");
        printf("Do you want to search for resources? (1 for Yes, 0 for No): ");
        int choice;
        scanf("%d", &choice);
        
        if (choice == 1) {
            printf("You bravely search for resources!\n");
            if (rand() % 2) {
                printf("🔒 You found %d resources! 🔒\n", planet.resources);
            } else {
                printf("⚠️ Oh no! You were attacked! You barely escaped!\n");
            }
        } else {
            printf("🛑 You decide to leave the planet safely.\n");
        }
    } else {
        printf("🌟 The planet is safe! You can collect resources!\n");
        printf("You collected %d resources successfully!\n", planet.resources);
    }
}

int main() {
    srand(time(0)); // Seed for random number generation
    Planet planets[PLANET_COUNT];
    
    initializePlanets(planets);
    displayPlanets(planets);
    
    while (1) {
        printf("Choose a planet to explore (1-%d) or 0 to exit: ", PLANET_COUNT);
        int choice;
        scanf("%d", &choice);
        
        if (choice == 0) {
            printf("🛸 Thank you for exploring with us! Safe travels across the stars! 🛸\n");
            break;
        } else if (choice < 1 || choice > PLANET_COUNT) {
            printf("🚫 Invalid choice! Please pick a valid planet number.\n");
            continue;
        }
        
        explorePlanet(planets[choice - 1]);
    }
    
    return 0;
}