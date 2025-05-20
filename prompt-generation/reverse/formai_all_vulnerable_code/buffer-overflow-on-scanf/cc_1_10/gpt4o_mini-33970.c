//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_PLANETS 100
#define MAX_POPULATION 1000000
#define ALIEN_INVASION_THRESHOLD 0.05 // 5% threshold for invasion
#define ALIEN_TECH_LEVEL 10 // Scale from 1 to 10
#define PLAYER_TECH_LEVEL 5 // Scale from 1 to 10

typedef struct {
    char name[50];
    int population;
    float distanceFromEarth; // In light years
    int alienTechLevel; // Level of alien technology
} Planet;

void initializePlanets(Planet planets[], int count);
void calculateInvasionProbability(const Planet *planet, float *probability);
void displayInvasionProbabilities(const Planet planets[], int count);
void sortPlanetsByProbability(Planet planets[], float probabilities[], int count);
void displayPlanetDetails(const Planet *planet, float probability);

int main() {
    srand(time(0)); // Seed the random number generator

    int count;
    printf("Enter the number of planets to analyze (maximum %d): ", MAX_PLANETS);
    scanf("%d", &count);
    
    if (count < 1 || count > MAX_PLANETS) {
        printf("Invalid number of planets! Please enter a number between 1 and %d.\n", MAX_PLANETS);
        return EXIT_FAILURE;
    }

    Planet planets[MAX_PLANETS];
    initializePlanets(planets, count);
    
    displayInvasionProbabilities(planets, count);

    return EXIT_SUCCESS;
}

void initializePlanets(Planet planets[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Enter the name of planet %d: ", i + 1);
        scanf("%s", planets[i].name);
        
        planets[i].population = rand() % MAX_POPULATION + 1; // Random population from 1 to MAX_POPULATION
        planets[i].distanceFromEarth = (rand() % 100) + 1; // Random distance from 1 to 100 light years
        planets[i].alienTechLevel = rand() % ALIEN_TECH_LEVEL + 1; // Random tech level from 1 to ALIEN_TECH_LEVEL
    }
}

void calculateInvasionProbability(const Planet *planet, float *probability) {
    // Algorithm to calculate probability
    float baseProbability = (float)planet->population / MAX_POPULATION;
    float distanceFactor = 1.0 / (1.0 + planet->distanceFromEarth); // Closer planets have higher probability
    float techFactor = (float)planet->alienTechLevel / (PLAYER_TECH_LEVEL + planet->alienTechLevel);

    *probability = baseProbability * distanceFactor * techFactor;
}

void displayInvasionProbabilities(const Planet planets[], int count) {
    float probabilities[MAX_PLANETS];

    printf("\n--- Alien Invasion Probability ---\n");
    for (int i = 0; i < count; i++) {
        calculateInvasionProbability(&planets[i], &probabilities[i]);
        displayPlanetDetails(&planets[i], probabilities[i]);
    }

    sortPlanetsByProbability(planets, probabilities, count);
    printf("\n--- Sorted Invasion Probabilities ---\n");
    for (int i = 0; i < count; i++) {
        displayPlanetDetails(&planets[i], probabilities[i]);
    }
}

void sortPlanetsByProbability(Planet planets[], float probabilities[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (probabilities[j] < probabilities[j + 1]) { // Descending order
                float tempProb = probabilities[j];
                probabilities[j] = probabilities[j + 1];
                probabilities[j + 1] = tempProb;

                Planet tempPlanet = planets[j];
                planets[j] = planets[j + 1];
                planets[j + 1] = tempPlanet;
            }
        }
    }
}

void displayPlanetDetails(const Planet *planet, float probability) {
    printf("Planet Name: %s, Population: %d, Distance: %.2f light years, Alien Tech Level: %d, Invasion Probability: %.2f\n",
           planet->name, planet->population, planet->distanceFromEarth, planet->alienTechLevel, probability);
    if (probability > ALIEN_INVASION_THRESHOLD) {
        printf("Warning: High invasion risk detected!\n");
    }
}