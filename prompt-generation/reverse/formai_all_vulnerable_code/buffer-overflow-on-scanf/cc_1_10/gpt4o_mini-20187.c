//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Structure to hold the alien invasion data
struct InvasionData {
    int population;         // Population of Earth
    double technologyLevel; // Earth technology level on a scale from 0.0 to 1.0
    double alienIntelligence; // Alien intelligence level on a scale from 0.0 to 1.0
    int historicalInvasions; // Historical data on previous invasions
};

// Function to calculate the probability of an alien invasion
double calculateInvasionProbability(struct InvasionData data) {
    // Base probability computation using arbitrary constants and the invasion data attributes
    double baseProbability = 0.25; // Base probability factor
    double populationFactor = (double)data.population / 7e9;  // Normalize population against world population
    double technologyFactor = data.technologyLevel * 0.25; // Assume higher tech decreases probability
    double intelligenceFactor = data.alienIntelligence * 0.5; // Assume smarter aliens increase probability
    double invasionHistoryFactor = (double)data.historicalInvasions * 0.1; // Previously recorded invasions

    // Total computed probability
    double probability = baseProbability +
                         populationFactor -
                         technologyFactor +
                         intelligenceFactor +
                         invasionHistoryFactor;

    // Cap the probability between 0 and 1
    if (probability < 0) {
        return 0.0;
    } else if (probability > 1) {
        return 1.0;
    }

    return probability;
}

// Entry point of the program
int main() {
    struct InvasionData data;
    char choice;

    printf("Welcome to the Alien Invasion Probability Calculator!\n");

    // Gathering user information
    do {
        printf("\nPlease enter Earth's Population (in billions): ");
        scanf("%d", &data.population);
        
        printf("Enter Earth's Technology Level (0.0 - 1.0): ");
        scanf("%lf", &data.technologyLevel);
        
        printf("Enter Alien Intelligence Level (0.0 - 1.0): ");
        scanf("%lf", &data.alienIntelligence);
        
        printf("Enter the number of Historical Invasions: ");
        scanf("%d", &data.historicalInvasions);
        
        // Calculate probability
        double invasionProbability = calculateInvasionProbability(data);
        
        // Display the results
        printf("\nThe calculated probability of an alien invasion is: %.2f%%\n", invasionProbability * 100);
        if (invasionProbability < 0.1) {
            printf("Chances are low! Enjoy your day!\n");
        } else if (invasionProbability < 0.5) {
            printf("Alert level: Moderate, keep an eye on the skies!\n");
        } else {
            printf("Warning: High probability of invasion! Prepare accordingly!\n");
        }

        printf("\nWould you like to calculate again? (y/n): ");
        scanf(" %c", &choice);
        
    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using the Alien Invasion Probability Calculator. Stay safe!\n");
    return 0;
}