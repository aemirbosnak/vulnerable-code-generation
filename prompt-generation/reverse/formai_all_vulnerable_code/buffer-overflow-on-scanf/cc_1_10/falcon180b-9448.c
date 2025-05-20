//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ALIENS 1000
#define MAX_PLANETS 1000
#define MAX_INVASIONS 1000

typedef struct {
    char name[50];
    int population;
    int defense;
} Planet;

typedef struct {
    char name[50];
    int strength;
} Alien;

void generatePlanets(Planet planets[], int numPlanets) {
    for (int i = 0; i < numPlanets; i++) {
        sprintf(planets[i].name, "Planet %d", i + 1);
        planets[i].population = rand() % 10000 + 1;
        planets[i].defense = rand() % 10000 + 1;
    }
}

void generateAliens(Alien aliens[], int numAliens) {
    for (int i = 0; i < numAliens; i++) {
        sprintf(aliens[i].name, "Alien %d", i + 1);
        aliens[i].strength = rand() % 10000 + 1;
    }
}

int invadePlanet(Planet planet, Alien alien) {
    if (alien.strength > planet.defense) {
        printf("Planet %s has been invaded by Alien %s!\n", planet.name, alien.name);
        return 1;
    } else {
        printf("Alien %s failed to invade Planet %s.\n", alien.name, planet.name);
        return 0;
    }
}

int main() {
    srand(time(NULL));
    Planet planets[MAX_PLANETS];
    Alien aliens[MAX_ALIENS];
    int numPlanets, numAliens, invasions;

    printf("Enter the number of planets: ");
    scanf("%d", &numPlanets);

    printf("Enter the number of aliens: ");
    scanf("%d", &numAliens);

    generatePlanets(planets, numPlanets);
    generateAliens(aliens, numAliens);

    printf("Enter the number of invasions: ");
    scanf("%d", &invasions);

    for (int i = 0; i < invasions; i++) {
        int planetIndex = rand() % numPlanets;
        int alienIndex = rand() % numAliens;

        if (invadePlanet(planets[planetIndex], aliens[alienIndex])) {
            planets[planetIndex].population -= 1000;
        }
    }

    return 0;
}