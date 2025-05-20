//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants
#define MAX_PLANETS 5
#define MAX_RESOURCES 3
#define MAX_ENERGY 100

// Define planet structure
typedef struct {
    char name[30];
    int resourceValue[MAX_RESOURCES]; // Resource values on the planet
    int difficulty; // Difficulty of collecting resources
} Planet;

// Function prototypes
void initializePlanets(Planet planets[]);
void printPlanetInfo(Planet planet);
int explorePlanet(Planet planet, int energy);
void showStatus(int energy, int resourcesCollected);

int main() {
    srand(time(NULL)); // Seed for random number generation
    Planet planets[MAX_PLANETS];
    int energy = MAX_ENERGY;
    int totalResourcesCollected = 0;
    char choice;

    initializePlanets(planets);

    printf("Welcome to the Galactic Explorer Adventure!\n");
    printf("You have %.0f energy units to start your journey. Good luck!\n\n", energy);

    while (energy > 0) {
        printf("Choose a planet to explore:\n");
        for (int i = 0; i < MAX_PLANETS; i++) {
            printf("%d. %s (Difficulty: %d)\n", i + 1, planets[i].name, planets[i].difficulty);
        }

        int planetChoice;
        printf("Enter your choice (1-%d): ", MAX_PLANETS);
        scanf("%d", &planetChoice);

        if (planetChoice < 1 || planetChoice > MAX_PLANETS) {
            printf("Invalid choice! Please choose a valid planet.\n");
            continue;
        }

        int resourcesCollected = explorePlanet(planets[planetChoice - 1], energy);
        totalResourcesCollected += resourcesCollected;
        energy -= planets[planetChoice - 1].difficulty;

        showStatus(energy, totalResourcesCollected);

        if (energy > 0) {
            printf("Do you want to explore another planet? (y/n): ");
            getchar(); // Clear newline character from buffer
            scanf("%c", &choice);
            if (choice == 'n') {
                break;
            }
        } else {
            printf("You've run out of energy! Game Over.\n");
        }
    }

    printf("Thank you for playing Galactic Explorer Adventure! You collected %d resources.\n", totalResourcesCollected);
    return 0;
}

void initializePlanets(Planet planets[]) {
    sprintf(planets[0].name, "Zorath");
    planets[0].resourceValue[0] = rand() % 20 + 10; // Random resource values
    planets[0].resourceValue[1] = rand() % 20 + 10;
    planets[0].resourceValue[2] = rand() % 20 + 10;
    planets[0].difficulty = rand() % 25 + 5;

    sprintf(planets[1].name, "Quasar IV");
    planets[1].resourceValue[0] = rand() % 20 + 10;
    planets[1].resourceValue[1] = rand() % 20 + 10;
    planets[1].resourceValue[2] = rand() % 20 + 10;
    planets[1].difficulty = rand() % 25 + 5;

    sprintf(planets[2].name, "Krypton Delta");
    planets[2].resourceValue[0] = rand() % 20 + 10;
    planets[2].resourceValue[1] = rand() % 20 + 10;
    planets[2].resourceValue[2] = rand() % 20 + 10;
    planets[2].difficulty = rand() % 25 + 5;

    sprintf(planets[3].name, "Nebula 7");
    planets[3].resourceValue[0] = rand() % 20 + 10;
    planets[3].resourceValue[1] = rand() % 20 + 10;
    planets[3].resourceValue[2] = rand() % 20 + 10;
    planets[3].difficulty = rand() % 25 + 5;

    sprintf(planets[4].name, "Triton V");
    planets[4].resourceValue[0] = rand() % 20 + 10;
    planets[4].resourceValue[1] = rand() % 20 + 10;
    planets[4].resourceValue[2] = rand() % 20 + 10;
    planets[4].difficulty = rand() % 25 + 5;
}

void printPlanetInfo(Planet planet) {
    printf("Planet: %s\n", planet.name);
    printf("Resource Values: [");
    for (int i = 0; i < MAX_RESOURCES; i++) {
        printf("%d", planet.resourceValue[i]);
        if (i != MAX_RESOURCES - 1) printf(", ");
    }
    printf("]\n");
    printf("Difficulty: %d\n", planet.difficulty);
}

int explorePlanet(Planet planet, int energy) {
    printf("\nExploring %s...\n", planet.name);
    printPlanetInfo(planet);

    if (energy >= planet.difficulty) {
        int resourcesCollected = rand() % (MAX_RESOURCES + 1); // Random number of resources collected
        printf("You successfully collected %d resources from %s!\n", resourcesCollected, planet.name);
        return resourcesCollected;
    } else {
        printf("You didn't have enough energy to explore %s! You lost 10 energy.\n", planet.name);
        return 0;
    }
}

void showStatus(int energy, int resourcesCollected) {
    printf("\nCurrent Status:\n");
    printf("Energy: %.0f\n", energy);
    printf("Total Resources Collected: %d\n\n", resourcesCollected);
}