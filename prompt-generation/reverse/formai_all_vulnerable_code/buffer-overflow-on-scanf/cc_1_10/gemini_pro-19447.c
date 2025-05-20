//GEMINI-pro DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Declare global variables
double alienProbability;
int numStars;
int numPlanets;
int numHabitablePlanets;
int numIntelligentLifeforms;
int numSpacefaringCivilizations;

// Declare functions
double calculateAlienProbability(void);
void printResults(void);

// Define main function
int main(void) {
    // Set global variables
    alienProbability = 0.0;
    numStars = 0;
    numPlanets = 0;
    numHabitablePlanets = 0;
    numIntelligentLifeforms = 0;
    numSpacefaringCivilizations = 0;

    // Get user input
    printf("Enter the number of stars in the universe: ");
    scanf("%d", &numStars);

    printf("Enter the average number of planets per star: ");
    scanf("%d", &numPlanets);

    printf("Enter the percentage of planets that are habitable: ");
    scanf("%d", &numHabitablePlanets);

    printf("Enter the percentage of habitable planets that develop intelligent life: ");
    scanf("%d", &numIntelligentLifeforms);

    printf("Enter the percentage of intelligent lifeforms that develop spacefaring civilizations: ");
    scanf("%d", &numSpacefaringCivilizations);

    // Calculate the alien probability
    alienProbability = calculateAlienProbability();

    // Print the results
    printResults();

    return 0;
}

// Define calculateAlienProbability function
double calculateAlienProbability(void) {
    double probability = 0.0;

    // Calculate the probability of a star having a planet
    probability = (double)numPlanets / (double)numStars;

    // Calculate the probability of a planet being habitable
    probability *= (double)numHabitablePlanets / 100.0;

    // Calculate the probability of a habitable planet developing intelligent life
    probability *= (double)numIntelligentLifeforms / 100.0;

    // Calculate the probability of intelligent life developing spacefaring civilizations
    probability *= (double)numSpacefaringCivilizations / 100.0;

    return probability;
}

// Define printResults function
void printResults(void) {
    printf("The probability of alien life in the universe is: %.2f%%\n", alienProbability * 100.0);
}