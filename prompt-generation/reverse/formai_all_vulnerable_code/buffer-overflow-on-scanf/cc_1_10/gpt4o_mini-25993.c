//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLANETS 10
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int distance;   // in light years
    int alienActivity; // scale of 1-10
    int resources;      // scale of 1-10
    int historicalInvasions; // total number of invasions recorded
} Planet;

void calculateProbability(Planet planet) {
    float probability = 0.0;
    
    // Simple calculation based on distance and various factors
    if (planet.distance < 10) {
        probability += 30; // Closer planets have higher probability
    } else if (planet.distance < 50) {
        probability += 20; // Moderate distance
    } else {
        probability += 10; // Far away
    }

    // Add alien activity effect
    probability += planet.alienActivity * 5;
    
    // Add resources effect
    probability += planet.resources * 2;

    // Historical invasions factor
    if (planet.historicalInvasions > 0) {
        probability += planet.historicalInvasions * 10;
    }

    // Scale to a percentage
    if (probability > 100) {
        probability = 100;
    }

    printf("The probability of an alien invasion on planet %s is: %.2f%%\n", planet.name, probability);
}

void displayPlanets(Planet planets[], int count) {
    printf("\nList of Planets:\n");
    for (int i = 0; i < count; i++) {
        printf("%d: %s (Distance: %d light years, Alien Activity: %d, Resources: %d, Historical Invasions: %d)\n",
                i + 1, planets[i].name, planets[i].distance, planets[i].alienActivity, 
                planets[i].resources, planets[i].historicalInvasions);
    }
}

int main() {
    int numberOfPlanets;
    Planet planets[MAX_PLANETS];

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Enter the number of planets (max %d): ", MAX_PLANETS);
    
    scanf("%d", &numberOfPlanets);
    if (numberOfPlanets < 1 || numberOfPlanets > MAX_PLANETS) {
        printf("Invalid number of planets. Exiting...\n");
        return 1;
    }

    // Input planet data
    for (int i = 0; i < numberOfPlanets; i++) {
        printf("Enter details for planet %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", planets[i].name);
        
        printf("Distance from Earth (in light years): ");
        scanf("%d", &planets[i].distance);
        
        printf("Alien Activity Scale (1-10): ");
        scanf("%d", &planets[i].alienActivity);
        
        printf("Resources Scale (1-10): ");
        scanf("%d", &planets[i].resources);
        
        printf("Historical Invasions Recorded: ");
        scanf("%d", &planets[i].historicalInvasions);
    }

    displayPlanets(planets, numberOfPlanets);

    // Calculate probabilities for each planet
    printf("\nCalculating probabilities of invasion...\n");
    for (int i = 0; i < numberOfPlanets; i++) {
        calculateProbability(planets[i]);
    }

    // Conclusion statement
    printf("\nThank you for using the Alien Invasion Probability Calculator! Stay alert!\n");

    return 0;
}