//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_POPULATION 1000000
#define ALIEN_PROBABILITY 0.0001

// Function to simulate alien invasion
int simulateAlienInvasion(int humanPopulation) {
    // Generate a random number
    double randValue = (double)rand() / RAND_MAX;

    // Conditional check for alien invasion
    if (randValue < ALIEN_PROBABILITY) {
        return 1; // Alien invasion occurs
    }
    return 0; // No alien invasion
}

// Function to calculate total alien invasion probability
double calculateInvasionProbability(int numberOfSimulations, int humanPopulation) {
    int invasionCount = 0;

    for (int i = 0; i < numberOfSimulations; i++) {
        if (simulateAlienInvasion(humanPopulation)) {
            invasionCount++;
        }
    }
    
    // Probability is the ratio of invasions to simulations
    return (double)invasionCount / numberOfSimulations;
}

// Fun function for user input
int getHumanPopulation() {
    int population;
    printf("Hello, Earthling! 👽 How many humans are we considering today (up to %d)? ", MAX_POPULATION);
    scanf("%d", &population);

    while (population <= 0 || population > MAX_POPULATION) {
        printf("Oops! Please enter a number between 1 and %d. Let's try again! ✅\n", MAX_POPULATION);
        scanf("%d", &population);
    }

    return population;
}

// Fun function for simulation count
int getSimulationCount() {
    int simulations;
    printf("How many simulations would you like to run? 🌌 Please enter a positive number: ");
    scanf("%d", &simulations);

    while (simulations <= 0) {
        printf("Oh no! Please enter a positive number for simulations. Let's try that again! 🔁\n");
        scanf("%d", &simulations);
    }

    return simulations;
}

// Main function to run the probability calculator
int main() {
    srand(time(NULL)); // Seed the random number generator

    printf("🌟 Welcome to the Alien Invasion Probability Calculator! 🌠\n");
    
    // Get human population from user
    int humanPopulation = getHumanPopulation();
    
    // Get number of simulations from user
    int numberOfSimulations = getSimulationCount();

    // Calculate the invasion probability
    double invasionProbability = calculateInvasionProbability(numberOfSimulations, humanPopulation);

    // Display results
    printf("🌍 Given a human population of %d and running %d simulations... 🎉\n", humanPopulation, numberOfSimulations);
    printf("The probability of an alien invasion is: %.6f %%\n", invasionProbability * 100);
    
    printf("Thank you for using the Alien Invasion Probability Calculator! 🛸👽✨\n");
    return 0;
}