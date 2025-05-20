//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void printWelcomeMessage();
double calculateProbability(int techLevel, int populationDensity, double defenseBudget);
void displayProbability(double probability);

int main() {
    int techLevel, populationDensity;
    double defenseBudget, invasionProbability;

    printWelcomeMessage();

    // Gather inputs from the user
    printf("Enter the technological level of your civilization (1-10): ");
    scanf("%d", &techLevel);
    printf("Enter the population density (persons per square kilometer): ");
    scanf("%d", &populationDensity);
    printf("Enter your annual defense budget in billions (USD): ");
    scanf("%lf", &defenseBudget);

    // Calculate the invasion probability
    invasionProbability = calculateProbability(techLevel, populationDensity, defenseBudget);
    
    // Display the results
    displayProbability(invasionProbability);

    return 0;
}

// Function to print a welcome message
void printWelcomeMessage() {
    printf("***********************************************\n");
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("We'll help you determine your chances of an alien invasion.\n");
    printf("***********************************************\n");
}

// Function to calculate the invasion probability
double calculateProbability(int techLevel, int populationDensity, double defenseBudget) {
    double invasionRisk;

    // Simple hypothetical formula for invasion probability
    invasionRisk = (10 - techLevel) * 0.2 + (populationDensity / 1000.0) * 0.5 - (defenseBudget / 50.0);

    // Clamp the value between 0 and 1
    if (invasionRisk < 0) {
        invasionRisk = 0;
    } else if (invasionRisk > 1) {
        invasionRisk = 1;
    }

    return invasionRisk;
}

// Function to display the invasion probability
void displayProbability(double probability) {
    printf("***********************************************\n");
    printf("Based on your inputs, the estimated probability of an alien invasion is:\n");
    
    if (probability > 0.5) {
        printf("** HIGH PROBABILITY! Prepare the defenses! **\n");
    } else if (probability > 0.2) {
        printf("** Moderate Probability. Stay vigilant! **\n");
    } else {
        printf("** LOW PROBABILITY. Enjoy your day! **\n");
    }
    
    printf("Probability score: %.2f\n", probability * 100);
    printf("***********************************************\n");
}