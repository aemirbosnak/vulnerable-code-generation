//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLANETS 10
#define MAX_OBJECTS 5

typedef struct {
    char name[50];
    int x, y;
    int resources;
    int population;
} Planet;

typedef struct {
    char name[50];
    int x, y;
    int speed;
    int cargo;
} Spaceship;

void generatePlanets(Planet planets[], int numPlanets) {
    for (int i = 0; i < numPlanets; i++) {
        planets[i].population = rand() % 1000 + 1;
        planets[i].resources = rand() % 1000 + 1;
        planets[i].x = rand() % 1000;
        planets[i].y = rand() % 1000;
    }
}

void generateSpaceships(Spaceship spaceships[], int numSpaceships) {
    for (int i = 0; i < numSpaceships; i++) {
        spaceships[i].cargo = rand() % 1000 + 1;
        spaceships[i].speed = rand() % 100 + 1;
        spaceships[i].x = rand() % 1000;
        spaceships[i].y = rand() % 1000;
    }
}

void printPlanet(Planet planet) {
    printf("Planet: %s\n", planet.name);
    printf("Population: %d\n", planet.population);
    printf("Resources: %d\n", planet.resources);
    printf("Location: (%d, %d)\n\n", planet.x, planet.y);
}

void printSpaceship(Spaceship spaceship) {
    printf("Spaceship: %s\n", spaceship.name);
    printf("Cargo: %d\n", spaceship.cargo);
    printf("Speed: %d\n", spaceship.speed);
    printf("Location: (%d, %d)\n\n", spaceship.x, spaceship.y);
}

int main() {
    srand(time(NULL));

    Planet planets[MAX_PLANETS];
    Spaceship spaceships[MAX_OBJECTS];

    int numPlanets, numSpaceships;

    printf("Enter the number of planets: ");
    scanf("%d", &numPlanets);

    printf("Enter the number of spaceships: ");
    scanf("%d", &numSpaceships);

    generatePlanets(planets, numPlanets);
    generateSpaceships(spaceships, numSpaceships);

    printf("Planets:\n");
    for (int i = 0; i < numPlanets; i++) {
        printPlanet(planets[i]);
    }

    printf("Spaceships:\n");
    for (int i = 0; i < numSpaceships; i++) {
        printSpaceship(spaceships[i]);
    }

    return 0;
}