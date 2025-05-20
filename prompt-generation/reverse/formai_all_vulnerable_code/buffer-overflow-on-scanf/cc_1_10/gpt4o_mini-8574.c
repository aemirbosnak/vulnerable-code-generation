//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLANETS 10
#define MAX_LIFEFORMS 100
#define ALIEN_THRESHOLD 50

typedef struct {
    char name[30];
    int lifeForms;
    int alienProbability; // in percentage
} Planet;

void initializePlanets(Planet *planets, int numberOfPlanets) {
    const char *planetNames[MAX_PLANETS] = {
        "Mars", "Venus", "Jupiter", "Saturn", "Mercury",
        "Neptune", "Uranus", "Pluto", "Earth", "Kepler-186f"
    };
    
    for (int i = 0; i < numberOfPlanets; i++) {
        snprintf(planets[i].name, sizeof(planets[i].name), "%s", planetNames[i]);
        planets[i].lifeForms = rand() % MAX_LIFEFORMS;
        planets[i].alienProbability = rand() % 101; // Probability between 0 and 100
    }
}

void displayPlanetInfo(Planet *planets, int numberOfPlanets) {
    printf("Planet Information:\n");
    printf("%-15s %-15s %-15s\n", "Planet Name", "Life Forms", "Alien Probability");
    
    for (int i = 0; i < numberOfPlanets; i++) {
        printf("%-15s %-15d %-15d\n", planets[i].name, planets[i].lifeForms, planets[i].alienProbability);
    }
}

void calculateInvasionChance(Planet *planets, int numberOfPlanets) {
    for (int i = 0; i < numberOfPlanets; i++) {
        int chance = planets[i].lifeForms * planets[i].alienProbability / 100;
        
        if (chance > ALIEN_THRESHOLD) {
            printf("Warning! Potential Alien Invasion detected on %s with chance: %d%%\n", planets[i].name, chance);
        }
    }
}

void collectUserInput(Planet *planets, int *numberOfPlanets) {
    printf("Enter the number of planets to analyze (Max %d): ", MAX_PLANETS);
    scanf("%d", numberOfPlanets);
    
    if (*numberOfPlanets > MAX_PLANETS) {
        printf("Exceeded maximum limit of %d planets. Setting to %d.\n", MAX_PLANETS, MAX_PLANETS);
        *numberOfPlanets = MAX_PLANETS;
    }
}

int main() {
    srand(time(NULL)); // Seed for random number generation

    Planet planets[MAX_PLANETS];
    int numberOfPlanets;

    collectUserInput(planets, &numberOfPlanets);
    initializePlanets(planets, numberOfPlanets);
    displayPlanetInfo(planets, numberOfPlanets);
    calculateInvasionChance(planets, numberOfPlanets);

    return 0;
}