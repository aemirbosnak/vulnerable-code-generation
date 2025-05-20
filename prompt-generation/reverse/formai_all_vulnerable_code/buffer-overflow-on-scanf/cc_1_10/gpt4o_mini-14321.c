//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLANETS 5
#define MAX_NAME_LENGTH 20
#define MAX_RESOURCE_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    char resource[MAX_RESOURCE_LENGTH];
    int dangerLevel;
} Planet;

void initializePlanets(Planet planets[]);
void explorePlanet(Planet planet);
void displayPlanetInfo(Planet planet);
void printIntroduction();
void printMenu();
int getRandomNumber(int min, int max);

int main() {
    Planet planets[MAX_PLANETS];
    int choice;

    srand(time(0)); // Initialize random number generator
    initializePlanets(planets);
    printIntroduction();

    do {
        printMenu();
        printf("Enter your choice (0 to exit): ");
        scanf("%d", &choice);

        if (choice > 0 && choice <= MAX_PLANETS) {
            explorePlanet(planets[choice - 1]);
        } else if (choice != 0) {
            printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 0);

    printf("Thank you for playing the Space Adventure! Safe travels!\n");
    return 0;
}

void initializePlanets(Planet planets[]) {
    strcpy(planets[0].name, "Xenon");
    strcpy(planets[0].resource, "Rare Minerals");
    planets[0].dangerLevel = getRandomNumber(1, 10);

    strcpy(planets[1].name, "Zypher");
    strcpy(planets[1].resource, "Alien Technology");
    planets[1].dangerLevel = getRandomNumber(1, 10);

    strcpy(planets[2].name, "Vortis");
    strcpy(planets[2].resource, "Crystal Energy");
    planets[2].dangerLevel = getRandomNumber(1, 10);

    strcpy(planets[3].name, "Theris");
    strcpy(planets[3].resource, "Biohazard Components");
    planets[3].dangerLevel = getRandomNumber(1, 10);

    strcpy(planets[4].name, "Aquarion");
    strcpy(planets[4].resource, "Water Resources");
    planets[4].dangerLevel = getRandomNumber(1, 10);
}

void explorePlanet(Planet planet) {
    printf("You are exploring planet %s.\n", planet.name);
    displayPlanetInfo(planet);
    
    printf("You may encounter danger with a level of %d!\n", planet.dangerLevel);
    int encounter = getRandomNumber(1, 10);
    
    if (encounter <= planet.dangerLevel) {
        printf("Oh no! You encountered a danger on %s! You lost some resources!\n", planet.name);
    } else {
        printf("Success! You harvested %s from %s!\n", planet.resource, planet.name);
    }
}

void displayPlanetInfo(Planet planet) {
    printf("Planet Name: %s\n", planet.name);
    printf("Resource Type: %s\n", planet.resource);
    printf("Danger Level: %d\n\n", planet.dangerLevel);
}

void printIntroduction() {
    printf("Welcome to the Space Adventure!\n");
    printf("You will explore different planets and collect resources.\n");
    printf("Beware of dangers that may lurk on each planet!\n\n");
}

void printMenu() {
    printf("Available Planets:\n");
    printf("1. Xenon\n");
    printf("2. Zypher\n");
    printf("3. Vortis\n");
    printf("4. Theris\n");
    printf("5. Aquarion\n");
}

int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}