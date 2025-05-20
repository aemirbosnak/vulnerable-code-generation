//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_PLANETS 100
#define LOVE_FACTOR 1.618  // Golden Ratio for romantic touch

// Structure to hold information about each planet
typedef struct {
    char name[50];
    double distance;      // Distance from Earth in light-years
    double technology;    // Technology level
    double romance;       // Romantic capability (from 0.0 to 1.0)
} Planet;

// Function to calculate invasion probability
double calculateInvasionProbability(Planet planet) {
    // A romantic formula to determine how likely an invasion would happen
    return (planet.technology * (1.0 - planet.romance) * LOVE_FACTOR) / (planet.distance + 1.0);
}

// Function to generate a random planet
Planet generateRandomPlanet() {
    Planet planet;
    sprintf(planet.name, "Planet_%d", rand() % 100 + 1);
    planet.distance = (rand() % 1000 + 1) / 10.0; // Random distance between 0.1 and 100 light-years
    planet.technology = (rand() % 100) / 100.0;   // Technology from 0.0 to 1.0
    planet.romance = (rand() % 100) / 100.0;      // Romance capability from 0.0 to 1.0
    return planet;
}

// Function to display planet information sweetly
void displayPlanetInfo(Planet planet) {
    printf("Oh, dear traveler! Allow me to introduce you to...\n");
    printf("Planet Name: %s\n", planet.name);
    printf("Distance from Earth: %.2f light-years\n", planet.distance);
    printf("Technology Level: %.2f/1.0\n", planet.technology);
    printf("Romantic Capability: %.2f/1.0\n", planet.romance);
    printf("\n");
}

// Main function
int main() {
    srand(time(NULL)); // Seed for random number generator
    printf("Welcome to the Cosmic Romance: Alien Invasion Probability Calculator!\n\n");

    int numPlanets;
    printf("How many planets shall we ponder upon? (1 to %d): ", MAX_PLANETS);
    scanf("%d", &numPlanets);

    if (numPlanets < 1 || numPlanets > MAX_PLANETS) {
        printf("A love for the cosmos asks for a number between 1 and %d!\n", MAX_PLANETS);
        return 1;
    }

    printf("\nLet us gaze upon the stars...\n");

    for (int i = 0; i < numPlanets; ++i) {
        Planet planet = generateRandomPlanet();
        displayPlanetInfo(planet);
        
        double invasionProbability = calculateInvasionProbability(planet);
        printf("The probability of invasion from %s is: %.2f%%\n", planet.name, invasionProbability * 100);
        printf("Oh my! We must guard our hearts and our Earth!\n\n");
    }

    printf("As our journey comes to an end, remember, love conquers all, even cosmic threats!\n");
    
    return 0;
}