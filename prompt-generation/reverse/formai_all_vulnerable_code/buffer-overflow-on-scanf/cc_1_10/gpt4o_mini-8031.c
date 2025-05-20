//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLANETS 10
#define PLANET_NAME_LENGTH 20
#define MAX_ASTRONAUTS 5

typedef struct {
    char name[PLANET_NAME_LENGTH];
    int resources;
    int dangerLevel;
} Planet;

typedef struct {
    char name[PLANET_NAME_LENGTH];
    int experience;
} Astronaut;

void initializePlanets(Planet planets[], int count) {
    const char* planetNames[] = {
        "Zarox", "Felenor", "Quorax", "Trekon", "Glimmer",
        "Abyssia", "Voltara", "Hexon", "Xerithon", "Lunaris"
    };
    
    srand(time(NULL));
    
    for (int i = 0; i < count; i++) {
        strncpy(planets[i].name, planetNames[i], PLANET_NAME_LENGTH);
        planets[i].resources = rand() % 100 + 1; // Resources between 1 - 100
        planets[i].dangerLevel = rand() % 10;     // Danger Level between 0 - 9
    }
}

void initializeAstronauts(Astronaut astronauts[], int count) {
    const char* astronautNames[] = {
        "Captain Nova", "Commander Ray", "Lieutenant Star",
        "Dr. Cosmo", "Navigator Z"
    };

    for (int i = 0; i < count; i++) {
        strncpy(astronauts[i].name, astronautNames[i], PLANET_NAME_LENGTH);
        astronauts[i].experience = rand() % 100 + 1; // Experience between 1 - 100
    }
}

void displayPlanets(Planet planets[], int count) {
    printf("Planets available for exploration:\n");
    for (int i = 0; i < count; i++) {
        printf("%s - Resources: %d, Danger Level: %d\n",
               planets[i].name,
               planets[i].resources,
               planets[i].dangerLevel);
    }
}

void displayAstronauts(Astronaut astronauts[], int count) {
    printf("Astronauts ready for mission:\n");
    for (int i = 0; i < count; i++) {
        printf("%s - Experience Level: %d\n",
               astronauts[i].name,
               astronauts[i].experience);
    }
}

int selectPlanet(Planet planets[], int count) {
    int choice;
    printf("Select the planet to explore (0-%d): ", count - 1);
    scanf("%d", &choice);
    return (choice >= 0 && choice < count) ? choice : -1;
}

void explorePlanet(Planet *planet, Astronaut astronauts[]) {
    printf("Exploring %s...\n", planet->name);
    
    if (planet->dangerLevel > 5) {
        printf("Danger is high! Astronauts need to be cautious!\n");
    }
    
    int successChance = rand() % 100 + 1;
    
    if (successChance <= (10 + astronauts[0].experience / 10 - planet->dangerLevel * 3)) {
        printf("Mission Successful! Found Resources: %d\n", planet->resources);
    } else {
        printf("Mission Failed! Danger was too high!\n");
    }
}

int main() {
    Planet planets[MAX_PLANETS];
    Astronaut astronauts[MAX_ASTRONAUTS];
    int numOfPlanets = 5; // for simplicity, limiting the number of planets
    int numOfAstronauts = 3; // same for astronauts

    initializePlanets(planets, numOfPlanets);
    initializeAstronauts(astronauts, numOfAstronauts);

    displayPlanets(planets, numOfPlanets);
    displayAstronauts(astronauts, numOfAstronauts);

    int planetIndex = selectPlanet(planets, numOfPlanets);
    if (planetIndex != -1) {
        explorePlanet(&planets[planetIndex], astronauts);
    } else {
        printf("Invalid planet selection.\n");
    }
    
    return 0;
}