//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declarations
void showIntroduction();
void collectUserInput(int *numDays, int *numEncounters);
double calculateAlienInvasionProbability(int numDays, int numEncounters);
void displayResult(double probability);

int main() {
    // Seed random number generator
    srand(time(NULL));

    int numDays, numEncounters;
    double probability;

    // Show introduction
    showIntroduction();

    // Collect user input
    collectUserInput(&numDays, &numEncounters);

    // Calculate the probability of alien invasion
    probability = calculateAlienInvasionProbability(numDays, numEncounters);

    // Display the result
    displayResult(probability);

    return 0;
}

// Displays a brief introduction about the program
void showIntroduction() {
    printf("========================================\n");
    printf("   Alien Invasion Probability Calculator  \n");
    printf("========================================\n");
    printf("This program estimates the probability of an alien invasion\n");
    printf("based on the number of days you observe encounters with UFOs.\n");
    printf("Enter the total number of UFO encounters over the specified days.\n\n");
}

// Collects user input for the number of days and UFO encounters
void collectUserInput(int *numDays, int *numEncounters) {
    printf("Please enter the number of days you observed UFOs: ");
    scanf("%d", numDays);
    
    printf("Please enter the total number of UFO encounters in those days: ");
    scanf("%d", numEncounters);

    // Validate input
    if (*numDays <= 0 || *numEncounters < 0) {
        printf("Invalid input. Please enter positive values.\n");
        exit(1);
    }
}

// Calculates the probability of an alien invasion
double calculateAlienInvasionProbability(int numDays, int numEncounters) {
    // Base probabilities based on statistical evidence (hypothetical)
    double baseProbability = 0.001;  // Base invasion probability
    double encounterProbability = 0.05; // Probability of invasion per encounter

    // Estimate based on encounters and days observed
    double estimatedProbability = baseProbability + (numEncounters * encounterProbability / numDays);

    // Cap the probability to a maximum of 1.0
    if (estimatedProbability > 1.0) {
        estimatedProbability = 1.0;
    }

    return estimatedProbability;
}

// Displays the final probability result
void displayResult(double probability) {
    printf("------------------------------------------------\n");
    printf("Estimated Probability of Alien Invasion: %.2lf%%\n", probability * 100);
    printf("Based on your inputs, there is a %.2lf%% chance\n", probability * 100);
    printf("of an alien invasion occurring in the near future.\n");
    printf("------------------------------------------------\n");

    // Provide additional commentary based on probability
    if (probability <= 0.01) {
        printf("Chances are low; you can relax!\n");
    } else if (probability > 0.01 && probability <= 0.1) {
        printf("Moderate chances; stay vigilant!\n");
    } else {
        printf("High likelihood; make sure your emergency kit is ready!\n");
    }
}