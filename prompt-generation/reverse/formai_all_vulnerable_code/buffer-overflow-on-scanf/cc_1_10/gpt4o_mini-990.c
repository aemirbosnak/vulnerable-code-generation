//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLANETS 10
#define MAX_DIST 1000  // Max distance from Earth in light years
#define MAX_POPULATION 1000000000  // Max population on a planet

typedef struct {
    char name[50];
    float distanceFromEarth;  // in light years
    long population;           // number of inhabitants
    float invasionProbability; // calculated invasion probability
} Planet;

// Function prototypes
void initializePlanets(Planet planets[], int size);
void calculateInvasionProbabilities(Planet planets[], int size);
void displayPlanets(const Planet planets[], int size);
void sortPlanetsByProbability(Planet planets[], int size);
void simulateInvasion(const Planet planets[], int size);

int main() {
    srand(time(NULL)); // Seed for randomness
    Planet planets[MAX_PLANETS];
    int numberOfPlanets;

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("How many planets do you want to analyze? (Max %d): ", MAX_PLANETS);
    scanf("%d", &numberOfPlanets);

    if (numberOfPlanets > MAX_PLANETS || numberOfPlanets < 1) {
        printf("Invalid number of planets. Exiting.\n");
        return -1;
    }

    initializePlanets(planets, numberOfPlanets);
    calculateInvasionProbabilities(planets, numberOfPlanets);
    sortPlanetsByProbability(planets, numberOfPlanets);
    displayPlanets(planets, numberOfPlanets);
    simulateInvasion(planets, numberOfPlanets);

    return 0;
}

// Function to initialize planets
void initializePlanets(Planet planets[], int size) {
    for (int i = 0; i < size; i++) {
        printf("\nEnter the name of planet %d: ", i + 1);
        scanf("%s", planets[i].name);
        planets[i].distanceFromEarth = (float)(rand() % MAX_DIST + 1); // Random distance
        planets[i].population = (long)(rand() % MAX_POPULATION + 1);  // Random population
        planets[i].invasionProbability = 0;
    }
}

// Calculate the invasion probabilities based on distance and population
void calculateInvasionProbabilities(Planet planets[], int size) {
    for (int i = 0; i < size; i++) {
        // A hypothetical formula: Probability inversely proportional to distance
        // and directly proportional to population
        planets[i].invasionProbability = (float)planets[i].population / (planets[i].distanceFromEarth * 100);
    }
}

// Function to sort planets based on their invasion probability
void sortPlanetsByProbability(Planet planets[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (planets[j].invasionProbability < planets[j + 1].invasionProbability) {
                Planet temp = planets[j];
                planets[j] = planets[j + 1];
                planets[j + 1] = temp;
            }
        }
    }
}

// Function to display planet information
void displayPlanets(const Planet planets[], int size) {
    printf("\nPlanet Information:\n");
    printf("------------------------------------------------------------------\n");
    printf("%-20s %-15s %-12s %-20s\n", "Planet Name", "Distance", "Population", "Invasion Probability");
    printf("------------------------------------------------------------------\n");
    for (int i = 0; i < size; i++) {
        printf("%-20s %-15.2f %-12ld %-20.2f\n", 
               planets[i].name, planets[i].distanceFromEarth, planets[i].population, planets[i].invasionProbability);
    }
}

// Simulate a possible invasion event
void simulateInvasion(const Planet planets[], int size) {
    printf("\nSimulating possible invasion...\n");
    for (int i = 0; i < size; i++) {
        float randomChance = (float)rand() / RAND_MAX; // random float between 0 and 1
        if (randomChance < (planets[i].invasionProbability / 100)) {
            printf("Invasion detected from %s! Prepare for contact!\n", planets[i].name);
        } else {
            printf("No invasion from %s. All clear.\n", planets[i].name);
        }
    }
}