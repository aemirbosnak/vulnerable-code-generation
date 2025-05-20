//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declarations
int randomInRange(int, int);
int calculateProbability(int, int, int);
void displayResults(int, int, int, int);

int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));
    
    // Define variables
    int numPlanets, numAliens, technologyLevel, invasionProbability;
    
    // Get input from user
    printf("Enter the number of planets in the galaxy: ");
    scanf("%d", &numPlanets);
    
    printf("Enter the average number of aliens per planet: ");
    scanf("%d", &numAliens);
    
    printf("Enter the technology level of the aliens (1-10): ");
    scanf("%d", &technologyLevel);
    
    // Calculate invasion probability
    invasionProbability = calculateProbability(numPlanets, numAliens, technologyLevel);
    
    // Display results
    displayResults(numPlanets, numAliens, technologyLevel, invasionProbability);
    
    return 0;
}

// Function to generate a random number within a range
int randomInRange(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to calculate invasion probability
int calculateProbability(int numPlanets, int numAliens, int technologyLevel) {
    int baseProbability = (numAliens * numPlanets) / 10;
    int techModifier = randomInRange(technologyLevel, technologyLevel * 2);
    int invasionProbability = baseProbability + techModifier;
    return invasionProbability;
}

// Function to display the results
void displayResults(int numPlanets, int numAliens, int technologyLevel, int invasionProbability) {
    printf("\nAlien Invasion Probability Calculator Results:\n");
    printf("Number of planets in the galaxy: %d\n", numPlanets);
    printf("Average number of aliens per planet: %d\n", numAliens);
    printf("Technology level of the aliens: %d\n", technologyLevel);
    printf("Invasion probability: %d%%\n\n", invasionProbability);
}