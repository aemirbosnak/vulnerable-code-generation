//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROBABILITY 100

// Function prototypes
double calculateAlienInvasionProbability(int year, int population, double technologyAdvancement);
void displayProbability(double probability);

int main() {
    int year, population;
    double technologyAdvancement;
    char continueProgram;

    // Seed random number generator
    srand(time(NULL));

    printf("Welcome to the Alien Invasion Probability Calculator!\n");

    do {
        // Getting input from the user
        printf("Enter the year of interest (e.g., 2025): ");
        scanf("%d", &year);

        printf("Enter the current world population (in billions): ");
        scanf("%d", &population);

        if (population < 1 || population > 10) {
            printf("Population out of range. Please enter a value between 1 and 10 billion.\n");
            continue;
        }

        printf("Enter technology advancement level (1 - 10, where 10 is highest): ");
        scanf("%lf", &technologyAdvancement);

        if (technologyAdvancement < 1 || technologyAdvancement > 10) {
            printf("Technology advancement out of range. Please enter a value between 1 and 10.\n");
            continue;
        }

        // Calculate the alien invasion probability
        double probability = calculateAlienInvasionProbability(year, population, technologyAdvancement);

        // Display the result
        displayProbability(probability);

        // Ask user if they want to calculate again
        printf("Would you like to calculate again? (y/n): ");
        scanf(" %c", &continueProgram);
        
    } while (continueProgram == 'y' || continueProgram == 'Y');

    printf("Thank you for using the Alien Invasion Probability Calculator! Goodbye!\n");
    return 0;
}

// Function to calculate the probability of an alien invasion based on inputs
double calculateAlienInvasionProbability(int year, int population, double technologyAdvancement) {
    // A simple formula to calculate the probability, this could be made complex with more factors
    double baseProbability = (year % 100) / (double)MAX_PROBABILITY; // Year factor
    double populationFactor = population * 10; // Convert billions to millions
    double technologyFactor = (technologyAdvancement / 10) * 50; // Adjust technology influence

    // Combine factors to form probability
    double probability = baseProbability + (populationFactor + technologyFactor) / 200.0;

    // Ensure the probability is within valid bounds
    if (probability > 1.0) {
        probability = 1.0;
    }
    return probability * 100; // Convert to percentage
}

// Function to display the invasion probability
void displayProbability(double probability) {
    printf("The probability of an alien invasion in this year is: %.2f%%\n", probability);
    if (probability > 75) {
        printf("Warning: High probability! Prepare your defenses!\n");
    } else if (probability > 50) {
        printf("Caution: Moderate probability. Stay alert!\n");
    } else {
        printf("Low probability. You can relax for now!\n");
    }
}