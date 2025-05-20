//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIMULATIONS 100000

// Function prototypes
double calculateProbability(int totalPlanets, int alienPlanets);
void simulateAlienInvasion(int totalPlanets, int alienPlanets);
void displayResults(double probability);

int main() {
    int totalPlanets, alienPlanets;

    // Seed the random number generator
    srand(time(NULL));

    // User input for total number of planets and number of alien planets
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Please enter the total number of planets in the galaxy: ");
    scanf("%d", &totalPlanets);

    printf("Please enter the number of planets that have aliens: ");
    scanf("%d", &alienPlanets);

    // Validate the user inputs
    if (totalPlanets <= 0 || alienPlanets < 0 || alienPlanets > totalPlanets) {
        printf("Invalid input. The total planets must be greater than zero, and alien planets must be between 0 and total planets.\n");
        return 1;
    }

    // Calculate the possibility of an alien invasion
    simulateAlienInvasion(totalPlanets, alienPlanets);

    return 0;
}

// Function to simulate the alien invasion and calculate probability
void simulateAlienInvasion(int totalPlanets, int alienPlanets) {
    int invasionCount = 0;

    for (int i = 0; i < SIMULATIONS; i++) {
        int randomPlanet = rand() % totalPlanets; // Select a random planet

        // Check if the randomly selected planet has aliens
        if (randomPlanet < alienPlanets) {
            invasionCount++;
        }
    }

    double probability = calculateProbability(totalPlanets, alienPlanets);
    displayResults(probability);
}

// Function to calculate probability based on total planets and alien planets
double calculateProbability(int totalPlanets, int alienPlanets) {
    return (double)alienPlanets / totalPlanets; 
}

// Function to display the results of the simulation
void displayResults(double probability) {
    printf("===================================\n");
    printf("Results of the Alien Invasion Simulation\n");
    printf("===================================\n");
    printf("Probability of encountering an alien planet: %.4f (%.2f%%)\n", probability, probability * 100);
    printf("Simulated invasions in %d iterations.\n", SIMULATIONS);
    printf("Thank you for using the Alien Invasion Probability Calculator!\n");
}