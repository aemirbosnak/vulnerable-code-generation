//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLANETS 100
#define PROBABILITY_SCALE 100

typedef struct {
    char name[30];
    float distance; // in light years
    float size;     // in Earth masses
    float probability; // alien invasion probability
} Planet;

void promptForPlanetData(Planet *planet);
void calculateInvasionProbability(Planet *planet);
void reportPlanetData(const Planet *planet);
void displayAllPlanets(Planet planets[], int count);
float randomProbability();

int main() {
    int planetCount = 0;
    Planet planets[MAX_PLANETS];
    char continueInput;

    printf("=== Alien Invasion Probability Calculator ===\n");

    do {
        if (planetCount >= MAX_PLANETS) {
            printf("Maximum number of planets reached. Cannot add more planets.\n");
            break;
        }

        promptForPlanetData(&planets[planetCount]);
        calculateInvasionProbability(&planets[planetCount]);
        reportPlanetData(&planets[planetCount]);

        planetCount++;

        printf("Do you want to enter data for another planet? (y/n): ");
        scanf(" %c", &continueInput);
        
    } while (continueInput == 'y' || continueInput == 'Y');

    printf("\n=== Summary of All Planets and Invasion Probabilities ===\n");
    displayAllPlanets(planets, planetCount);
    
    return 0;
}

void promptForPlanetData(Planet *planet) {
    printf("Enter the name of the planet: ");
    scanf("%s", planet->name);
    
    printf("Enter the distance from Earth (in light years): ");
    scanf("%f", &planet->distance);
    
    printf("Enter the size of the planet (in Earth masses): ");
    scanf("%f", &planet->size);
}

void calculateInvasionProbability(Planet *planet) {
    // A simple random probability calculation based on size and distance
    planet->probability = (randomProbability() + (planet->size / 10)) * (1 / (planet->distance / 10));
    if (planet->probability > 1.0) {
        planet->probability = 1.0; // cap at 100%
    }
}

void reportPlanetData(const Planet *planet) {
    printf("\nPlanet: %s\n", planet->name);
    printf("Distance from Earth: %.2f light years\n", planet->distance);
    printf("Planet size: %.2f Earth masses\n", planet->size);
    printf("Invasion Probability: %.2f%%\n", planet->probability * 100);
    printf("=============================================\n");
}

void displayAllPlanets(Planet planets[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Planet: %s, Distance: %.2f light years, Size: %.2f Earth masses, Invasion Probability: %.2f%%\n",
               planets[i].name, planets[i].distance, planets[i].size, planets[i].probability * 100);
    }
}

float randomProbability() {
    return (float)(rand() % PROBABILITY_SCALE) / PROBABILITY_SCALE; // generates a number between 0 and 1
}