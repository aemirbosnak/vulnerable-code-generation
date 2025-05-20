//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_PLANETS 5
#define INITIAL_RESOURCES 100

typedef struct {
    char name[20];
    int minerals;
    int energy;
} Planet;

void initializePlanets(Planet planets[]) {
    const char *planetNames[MAX_PLANETS] = {"Zyxon", "Qalaxy", "Vortax", "Nerbos", "Ferra"};
    
    for (int i = 0; i < MAX_PLANETS; i++) {
        snprintf(planets[i].name, sizeof(planets[i].name), "%s", planetNames[i]);
        planets[i].minerals = rand() % 50 + 1; // Random minerals between 1 and 50
        planets[i].energy = rand() % 50 + 1;   // Random energy between 1 and 50
    }
}

void displayStatus(int resources, int planetsVisited) {
    printf("\nYour current resources: %d\n", resources);
    printf("Planets visited: %d\n", planetsVisited);
}

void explorePlanet(Planet *planet, int *resources) {
    printf("You have arrived at %s!\n", planet->name);
    printf("Minerals found: %d\n", planet->minerals);
    printf("Energy found: %d\n", planet->energy);
    
    *resources += planet->minerals + planet->energy; // Collecting resources
    printf("You collected resources! Total resources: %d\n", *resources);
}

int main() {
    srand(time(NULL));
    Planet planets[MAX_PLANETS];
    initializePlanets(planets);
    
    int resources = INITIAL_RESOURCES;
    int planetsVisited = 0;
    int gameOver = 0;

    printf("Welcome to Galactic Explorer!\n");
    printf("Your mission: Explore the galaxy and gather resources!\n");
    
    while (!gameOver) {
        displayStatus(resources, planetsVisited);
        
        printf("\nChoose a planet to explore (0 - Zyxon, 1 - Qalaxy, 2 - Vortax, 3 - Nerbos, 4 - Ferra, 5 - Exit): ");
        int choice;
        scanf("%d", &choice);
        
        if (choice == 5) {
            printf("Exiting the game... Thank you for playing Galactic Explorer!\n");
            break;
        } else if (choice < 0 || choice >= MAX_PLANETS) {
            printf("Invalid choice! Please select a valid planet.\n");
            continue;
        }

        explorePlanet(&planets[choice], &resources);
        planetsVisited++;

        // Simulating chance of space anomaly
        if (rand() % 2 == 0) {
            printf("Oh no! You encountered a space anomaly!\n");
            int lostResources = rand() % 30 + 1; // Losing between 1 and 30 resources
            resources -= lostResources;
            printf("You lost %d resources! Current resources: %d\n", lostResources, resources);
            if (resources <= 0) {
                printf("You've run out of resources! Game Over!\n");
                gameOver = 1;
            }
        }
    }

    return 0;
}