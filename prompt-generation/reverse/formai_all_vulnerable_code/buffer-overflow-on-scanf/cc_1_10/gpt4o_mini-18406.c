//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_PERCENTAGE 100
#define HUMANS 7800000000 // Estimated world population
#define BASE_PROBABILITY 0.0001 // Base probability of abduction

/* Function Prototype */
double calculateAlienAbductionProbability(int alienStrength, int humanResistance, int technologyLevel);
void displayResults(int alienStrength, int humanResistance, int technologyLevel, double probability);

/* Main Program */
int main() {
    int alienStrength = 0;
    int humanResistance = 0;
    int technologyLevel = 0;
    
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("This program evaluates the likelihood of alien abductions based on various parameters.\n\n");
    
    // Get user input for alien strength
    printf("Enter alien strength (1 to 10): ");
    scanf("%d", &alienStrength);
    while (alienStrength < 1 || alienStrength > 10) {
        printf("Invalid input. Please enter a value between 1 and 10: ");
        scanf("%d", &alienStrength);
    }
    
    // Get user input for human resistance
    printf("Enter human resistance (1 to 10): ");
    scanf("%d", &humanResistance);
    while (humanResistance < 1 || humanResistance > 10) {
        printf("Invalid input. Please enter a value between 1 and 10: ");
        scanf("%d", &humanResistance);
    }
    
    // Get user input for technology level
    printf("Enter technology level (1 to 10): ");
    scanf("%d", &technologyLevel);
    while (technologyLevel < 1 || technologyLevel > 10) {
        printf("Invalid input. Please enter a value between 1 and 10: ");
        scanf("%d", &technologyLevel);
    }
    
    // Calculate the probability of abduction
    double probability = calculateAlienAbductionProbability(alienStrength, humanResistance, technologyLevel);
    
    // Display results
    displayResults(alienStrength, humanResistance, technologyLevel, probability);
    
    return 0;
}

/* Calculate the Probability of Abduction */
double calculateAlienAbductionProbability(int alienStrength, int humanResistance, int technologyLevel) {
    double effectiveStrength = (double)alienStrength * technologyLevel;
    double effectiveResistance = (double)humanResistance;

    // Logarithmic formula to prevent overflow/underflow
    double probability = BASE_PROBABILITY * (effectiveStrength / (effectiveStrength + effectiveResistance));
    
    // Scale probability to percentage
    return probability * MAX_PERCENTAGE; 
}

/* Display the Results */
void displayResults(int alienStrength, int humanResistance, int technologyLevel, double probability) {
    printf("\n==============================\n");
    printf("Alien Invasion Simulation Results:\n");
    printf("==============================\n");
    printf("Alien Strength: %d\n", alienStrength);
    printf("Human Resistance: %d\n", humanResistance);
    printf("Technology Level: %d\n", technologyLevel);
    
    if (probability < 0.01) {
        printf("Probability of Alien Abduction: < 0.01%% (Virtually Impossible)\n");
    } else if (probability > MAX_PERCENTAGE) {
        printf("Probability of Alien Abduction: 100%% (Worst Case Scenario!)\n");
    } else {
        printf("Probability of Alien Abduction: %.2f%%\n", probability);
    }
    
    printf("==============================\n");
}