//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to initialize random number generation
void initRandom() {
    srand(time(NULL));
}

// Function to simulate alien invasion probabilities
double calculateInvasionRisk(int population, int alienTechnologyLevel) {
    double baseProbability = 0.01; // Base 1% chance of invasion
    double populationImpact = population / 1000000.0; // Impact of population
    double technologyImpact = alienTechnologyLevel / 10.0; // Max tech level 10

    // Final probability calculation
    double invasionProbability = baseProbability * (1 + populationImpact) * (1 + technologyImpact);
    return invasionProbability > 1.0 ? 1.0 : invasionProbability; // Cap at 100%
}

// Function to display the invasion risk to the user
void displayInvasionRisk(int population, int alienTechnologyLevel) {
    double invasionProbability = calculateInvasionRisk(population, alienTechnologyLevel);
    printf("Calculated Invasion Probability:\n");
    printf("Population: %d\n", population);
    printf("Alien Technology Level: %d\n", alienTechnologyLevel);
    printf("Risk of alien invasion: %.2f%%\n", invasionProbability * 100);
}

// Function to display a message based on the invasion risk level
void displayRiskMessage(double invasionProbability) {
    if (invasionProbability < 0.1) {
        printf("The risk is low. Enjoy your day!\n");
    } else if (invasionProbability < 0.5) {
        printf("The risk is moderate. Stay alert!\n");
    } else {
        printf("The risk is high! Prepare for the worst!\n");
    }
}

// Function to get user input safely
int getUserInput(const char* prompt) {
    int value;
    printf("%s", prompt);
    while (scanf("%d", &value) != 1 || value < 0) {
        printf("Invalid input. Please enter a non-negative integer: ");
        while (getchar() != '\n'); // Clear input buffer
    }
    return value;
}

int main() {
    initRandom(); // Initialize random seed for simulations

    printf("Welcome to the Alien Invasion Probability Calculator\n");
    
    // Get user input for population and alien technology level
    int population = getUserInput("Enter the Earth's population (in millions): ") * 1000000;
    int alienTechnologyLevel = getUserInput("Enter alien technology level (1-10): ");

    // Check if alien technology level is within acceptable bounds
    while (alienTechnologyLevel < 1 || alienTechnologyLevel > 10) {
        printf("Alien technology level must be between 1 and 10. Please enter again:\n");
        alienTechnologyLevel = getUserInput("Enter alien technology level (1-10): ");
    }

    // Display invasion risk
    displayInvasionRisk(population, alienTechnologyLevel);

    // Calculate and display risk message
    double invasionProbability = calculateInvasionRisk(population, alienTechnologyLevel);
    displayRiskMessage(invasionProbability);

    printf("\nThank you for using the Alien Invasion Probability Calculator!\n");
    return 0;
}