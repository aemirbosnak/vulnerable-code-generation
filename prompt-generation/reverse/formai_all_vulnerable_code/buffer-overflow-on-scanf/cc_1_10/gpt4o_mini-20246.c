//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLANETS 10
#define MAX_GALAXIES 5
#define PLAYER_NAME_LENGTH 30

typedef struct {
    char name[20];
    int distance; // Distance from the player's current location
    char resource[20]; // Resource available on the planet
} Planet;

typedef struct {
    char name[20];
    int numberOfPlanets;
    Planet planets[MAX_PLANETS];
} Galaxy;

typedef struct {
    char playerName[PLAYER_NAME_LENGTH];
    int currentGalaxy;
    int resourcesCollected;
} Player;

void initializePlanets(Galaxy *galaxy) {
    const char *planetNames[] = {"Zoltar", "Aquara", "Firaxis", "Jupitera", "Xenon"};
    const char *resources[] = {"Water", "Gold", "Silver", "Gems", "Alien Technology"};

    for (int i = 0; i < galaxy->numberOfPlanets; i++) {
        snprintf(galaxy->planets[i].name, sizeof(galaxy->planets[i].name), "%s", planetNames[i % 5]);
        galaxy->planets[i].distance = rand() % 100 + 1; // Random distance between 1 to 100
        snprintf(galaxy->planets[i].resource, sizeof(galaxy->planets[i].resource), "%s", resources[i % 5]);
    }
}

void initializeGalaxies(Galaxy galaxies[], int numberOfGalaxies) {
    for (int i = 0; i < numberOfGalaxies; i++) {
        snprintf(galaxies[i].name, sizeof(galaxies[i].name), "Galaxy %d", i + 1);
        galaxies[i].numberOfPlanets = rand() % MAX_PLANETS + 1; // Random number of planets
        initializePlanets(&galaxies[i]);
    }
}

void displayGalaxies(Galaxy galaxies[], int numberOfGalaxies) {
    printf("Welcome to the Cosmic Journey!\n");
    printf("Here's a list of galaxies:\n");
    for (int i = 0; i < numberOfGalaxies; i++) {
        printf("%d. %s (Number of Planets: %d)\n", i + 1, galaxies[i].name, galaxies[i].numberOfPlanets);
    }
}

void visitPlanet(Player *player, Galaxy *galaxy, int planetIndex) {
    Planet *planet = &galaxy->planets[planetIndex];

    printf("Visiting %s...\n", planet->name);
    printf("Found resource: %s\n", planet->resource);
    player->resourcesCollected++;
    printf("Resources collected: %d\n", player->resourcesCollected);

    printf("Would you like to travel to another planet in the same galaxy? (1 for Yes, 0 for No): ");
    int option;
    scanf("%d", &option);
    if (option == 1) {
        int nextPlanetIndex;
        printf("Enter the planet index to visit (0 to %d): ", galaxy->numberOfPlanets - 1);
        scanf("%d", &nextPlanetIndex);
        if (nextPlanetIndex >= 0 && nextPlanetIndex < galaxy->numberOfPlanets) {
            visitPlanet(player, galaxy, nextPlanetIndex);
        } else {
            printf("Invalid planet index!\n");
        }
    } else {
        printf("Leaving %s. Goodbye!\n", planet->name);
    }
}

int main() {
    srand(time(0));

    Galaxy galaxies[MAX_GALAXIES];
    initializeGalaxies(galaxies, MAX_GALAXIES);

    Player player;
    printf("Enter your name, brave traveler: ");
    scanf("%s", player.playerName);
    player.currentGalaxy = 0;
    player.resourcesCollected = 0;

    displayGalaxies(galaxies, MAX_GALAXIES);
    
    int galaxyChoice;
    printf("Select a galaxy to explore (1 to %d): ", MAX_GALAXIES);
    scanf("%d", &galaxyChoice);
    if (galaxyChoice > 0 && galaxyChoice <= MAX_GALAXIES) {
        Galaxy *selectedGalaxy = &galaxies[galaxyChoice - 1];
        printf("You have chosen to explore %s!\n", selectedGalaxy->name);
        
        int planetIndex;
        printf("Enter a planet index to visit (0 to %d): ", selectedGalaxy->numberOfPlanets - 1);
        scanf("%d", &planetIndex);
        
        if (planetIndex >= 0 && planetIndex < selectedGalaxy->numberOfPlanets) {
            visitPlanet(&player, selectedGalaxy, planetIndex);
        } else {
            printf("Invalid planet index! Adventure cancelled.\n");
        }
    } else {
        printf("Invalid galaxy choice! Please try again later.\n");
    }

    printf("Thank you for playing, %s! You've collected a total of %d resources.\n", player.playerName, player.resourcesCollected);
    
    return 0;
}