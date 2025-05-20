//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to simulate the probability of an alien invasion
double simulateAlienInvasion(int population, int technologyLevel) {
    // Assuming a basic model where population and technology influence invasion probability
    // For simplicity, influence factor ranges from 0.0 to 1.0
    double baseProbability = (double) rand() / RAND_MAX;
    double populationFactor = (double)population / 1000000; // Normalize to a million
    double techFactor = (double)technologyLevel / 10; // Normalize to a max level of 10

    // Calculate final probability with weights
    double invasionProbability = baseProbability * (populationFactor * 0.5 + techFactor * 0.5);
    
    // Clamp the probability between 0.0 and 1.0
    if (invasionProbability > 1.0) {
        invasionProbability = 1.0;
    } else if (invasionProbability < 0.0) {
        invasionProbability = 0.0;
    }

    return invasionProbability;
}

// Function to display invasion probability
void displayInvasionProbability(double probability) {
    printf("---------------------------------------------------\n");
    printf("Invasion Probability: %.2f%%\n", probability * 100);
    if (probability < 0.1) {
        printf("You're safe! The aliens are not interested in Earth!\n");
    } else if (probability < 0.5) {
        printf("Caution! Alien interest is building up!\n");
    } else {
        printf("Alert! Strengthen your defenses, aliens are coming!\n");
    }
    printf("---------------------------------------------------\n");
}

int main() {
    srand(time(0)); // Seed the random number generator

    int population;
    int technologyLevel;

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    
    // User input for population
    printf("Enter the Earth population (in millions, e.g., 7 for 7 million): ");
    scanf("%d", &population);
    
    // User input for technology level
    printf("On a scale of 0 to 10, how advanced is your technology? ");
    scanf("%d", &technologyLevel);

    // Validate user input
    if (population < 0 || technologyLevel < 0 || technologyLevel > 10) {
        printf("Invalid input! Population must be non-negative and technology level must be between 0 and 10.\n");
        return 1; // Exit with error
    }

    // Calculate the probability of an alien invasion
    double invasionProbability = simulateAlienInvasion(population, technologyLevel);

    // Display the result
    displayInvasionProbability(invasionProbability);

    // Add a feature to simulate multiple scenarios
    char continueSimulation;
    do {
        printf("Would you like to simulate another scenario? (y/n): ");
        scanf(" %c", &continueSimulation);

        if (continueSimulation == 'y' || continueSimulation == 'Y') {
            printf("Enter the Earth population (in millions): ");
            scanf("%d", &population);

            printf("Technology level (0 to 10): ");
            scanf("%d", &technologyLevel);

            if (population < 0 || technologyLevel < 0 || technologyLevel > 10) {
                printf("Invalid input! Population must be non-negative and technology level must be between 0 and 10.\n");
                continue; // Skip loop iteration
            }

            invasionProbability = simulateAlienInvasion(population, technologyLevel);
            displayInvasionProbability(invasionProbability);
        }
    } while (continueSimulation == 'y' || continueSimulation == 'Y');

    printf("Thank you for using the Alien Invasion Probability Calculator! Stay safe!\n");
    
    return 0; // Successful termination
}