//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLANETS 10
#define MAX_SPECIES 5
#define MAX_TRAVEL_TIME 100

// Function to simulate aliens arriving
int simulateAlienInvasion(int planetCount, int speciesCount) {
    return rand() % (planetCount * speciesCount);
}

// Function to determine the probability of invasion
double calculateInvasionProbability(int invasions, int totalSimulations) {
    if (totalSimulations == 0) return 0.0;
    return (double)invasions / totalSimulations * 100;
}

// Function to generate a friendly message about the invasion
void printFriendlyMessage(int planetCount, int speciesCount, double probability) {
    printf("\n🤖🔭 Alien Invasion Simulator! 🔭🤖\n");
    printf("On a universe with %d planets and %d alien species...\n", planetCount, speciesCount);
    printf("The calculated probability of an alien invasion is: %.2f%%\n", probability);
    printf("Stay calm, humans! The universe is a vast place, and aliens could be friendly! ☀️🤝\n");
}

// Main function
int main() {
    srand(time(NULL));  // Set seed for random generator

    int planetCount, speciesCount, totalSimulations;
    printf("Welcome to the Cosmic Alien Invasion Probability Calculator! 🌌\n");
    
    // Asking user for inputs
    printf("Please enter the number of planets to simulate (1 - %d): ", MAX_PLANETS);
    scanf("%d", &planetCount);
    if (planetCount < 1 || planetCount > MAX_PLANETS) {
        printf("Oops! Please enter a valid number of planets (1 - %d).\n", MAX_PLANETS);
        return 1;
    }

    printf("Please enter the number of alien species to consider (1 - %d): ", MAX_SPECIES);
    scanf("%d", &speciesCount);
    if (speciesCount < 1 || speciesCount > MAX_SPECIES) {
        printf("Oops! Please enter a valid number of alien species (1 - %d).\n", MAX_SPECIES);
        return 1;
    }

    printf("How many simulations do you want to run? (Choose a number, e.g., 1000): ");
    scanf("%d", &totalSimulations);
    if (totalSimulations < 1) {
        printf("Oops! You need to run at least one simulation.\n");
        return 1;
    }

    int totalInvasions = 0;

    // Run the simulations
    for (int i = 0; i < totalSimulations; i++) {
        if (simulateAlienInvasion(planetCount, speciesCount) % 2 == 0) { // Simple condition for an invasion
            totalInvasions++;
        }
    }

    // Calculate probability
    double invasionProbability = calculateInvasionProbability(totalInvasions, totalSimulations);

    // Display friendly message
    printFriendlyMessage(planetCount, speciesCount, invasionProbability);

    printf("\nThank you for using the Cosmic Alien Invasion Simulator! 🌟\n");
    printf("Remember: The odds are ever in your favor! May the universe be peaceful! ☮️🤗\n");

    return 0;
}