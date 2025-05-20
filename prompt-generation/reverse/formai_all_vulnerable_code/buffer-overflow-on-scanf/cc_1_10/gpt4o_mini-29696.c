//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLANETS 10
#define MAX_RESOURCES 5

typedef struct {
    char name[20];
    int resourceAmount[MAX_RESOURCES];
} Planet;

void generatePlanet(Planet *planet) {
    const char *planetNames[] = {"Zyphron", "Lunarus", "Galactica", "Nebulon", "Xyloar"};
    strcpy(planet->name, planetNames[rand() % 5]);
    
    for (int i = 0; i < MAX_RESOURCES; i++) {
        planet->resourceAmount[i] = rand() % 100; // Random resource amount
    }
}

void displayPlanetInfo(Planet planet) {
    printf("Welcome to planet %s!\n", planet.name);
    printf("Resources available:\n");
    for (int i = 0; i < MAX_RESOURCES; i++) {
        printf("Resource %d: %d\n", i + 1, planet.resourceAmount[i]);
    }
}

void exploreGalaxy() {
    Planet planets[MAX_PLANETS];
    for (int i = 0; i < MAX_PLANETS; i++) {
        generatePlanet(&planets[i]);
    }

    char choice;
    int currentPlanet = 0;

    while (1) {
        displayPlanetInfo(planets[currentPlanet]);

        printf("What would you like to do?\n");
        printf("1. Collect resources\n");
        printf("2. Jump to next planet\n");
        printf("3. Exit the game\n");
        printf("Enter your choice (1/2/3): ");
        scanf(" %c", &choice);

        if (choice == '1') {
            printf("Collecting resources from %s...\n", planets[currentPlanet].name);
            for (int i = 0; i < MAX_RESOURCES; i++) {
                if (planets[currentPlanet].resourceAmount[i] > 0) {
                    printf("Collected %d of resource %d!\n", planets[currentPlanet].resourceAmount[i], i + 1);
                    planets[currentPlanet].resourceAmount[i] = 0; // Resource collected
                }
            }
        } else if (choice == '2') {
            currentPlanet = (currentPlanet + 1) % MAX_PLANETS;
            printf("Jumping to next planet...\n");
        } else if (choice == '3') {
            printf("Exiting the game... Safe travels!\n");
            break;
        } else {
            printf("Invalid choice! Please choose again.\n");
        }
    }
}

int main() {
    srand(time(0)); // Seed for randomness
    printf("Welcome to the Space Adventure Game!\n");
    exploreGalaxy();
    return 0;
}