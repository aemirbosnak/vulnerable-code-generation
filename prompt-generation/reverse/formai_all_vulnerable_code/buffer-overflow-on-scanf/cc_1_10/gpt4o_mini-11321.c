//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to calculate the probability of alien invasion based on various factors
double calculateProbability(int technologyLevel, int populationDensity, int environmentalFactors) {
    double baseProbability = 0.01; // Base invasion probability
    double techImpact = (technologyLevel / 100.0) * 0.2; // Impact of technology
    double densityImpact = (populationDensity / 100.0) * 0.3; // Impact of population density
    double environmentalImpact = (environmentalFactors / 100.0) * 0.5; // Impact of environmental factors

    double finalProbability = baseProbability + techImpact + densityImpact + environmentalImpact;
    return finalProbability < 1.0 ? finalProbability : 1.0; // Ensure probability does not exceed 1
}

// Function to simulate alien invasion decision based on randomized factor
int alienInvasionDecision(double probability) {
    double randomValue = (double)rand() / (double)RAND_MAX; // Random value between 0 and 1
    return randomValue < probability ? 1 : 0; // Return 1 if invasion occurs, 0 otherwise
}

// Function to collect user input
void collectUserInput(int *techLevel, int *popDensity, int *envFactors) {
    printf("Enter technology level (0-100): ");
    scanf("%d", techLevel);
    if (*techLevel < 0 || *techLevel > 100) {
        printf("Invalid technology level. Setting to default (50).\n");
        *techLevel = 50;
    }

    printf("Enter population density (0-100): ");
    scanf("%d", popDensity);
    if (*popDensity < 0 || *popDensity > 100) {
        printf("Invalid population density. Setting to default (50).\n");
        *popDensity = 50;
    }

    printf("Enter environmental factors (0-100): ");
    scanf("%d", envFactors);
    if (*envFactors < 0 || *envFactors > 100) {
        printf("Invalid environmental factors. Setting to default (50).\n");
        *envFactors = 50;
    }
}

// Main function
int main() {
    int technologyLevel = 0, populationDensity = 0, environmentalFactors = 0;

    // Seed random number generator
    srand(time(NULL));

    printf("Welcome to the Alien Invasion Probability Calculator\n");
    
    // Collect user input
    collectUserInput(&technologyLevel, &populationDensity, &environmentalFactors);

    // Calculate the probability of an alien invasion
    double invasionProbability = calculateProbability(technologyLevel, populationDensity, environmentalFactors);
    
    printf("Calculated probability of alien invasion: %.2f%%\n", invasionProbability * 100);

    // Make invasion decision based on calculated probability
    int decision = alienInvasionDecision(invasionProbability);
    
    if (decision) {
        printf("Alert! An alien invasion is likely to happen!\n");
    } else {
        printf("No imminent alien invasion detected. Relax!\n");
    }

    printf("Thank you for using the Alien Invasion Probability Calculator. Stay safe!\n");
    
    return 0;
}