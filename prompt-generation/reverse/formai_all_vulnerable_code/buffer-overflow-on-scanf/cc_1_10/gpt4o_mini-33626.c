//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIGHTINGS 100
#define MAX_POPULATION 1000000

// Function to calculate the probability of an alien invasion
double calculateProbability(int sightings, int population, double technologyFactor) {
    if (population <= 0) return 0.0;
    return (double)sightings / population * technologyFactor;
}

// Function to display the results
void displayResult(int sightings, int population, double techFactor, double probability) {
    printf("\n--- Alien Invasion Probability Report ---\n");
    printf("Number of Sightings: %d\n", sightings);
    printf("Population Size: %d\n", population);
    printf("Technology Factor: %.2f\n", techFactor);
    printf("Calculated Probability of Alien Invasion: %.6f\n", probability);
}

int main() {
    int sightings, population;
    double technologyFactor, probability;

    printf("Welcome to the Alien Invasion Probability Calculator\n");
    printf("---------------------------------------------------\n");

    // User Input for sightings
    printf("Enter the number of alien sightings reported (max %d): ", MAX_SIGHTINGS);
    scanf("%d", &sightings);
    
    // Input validation for sightings
    if (sightings < 0 || sightings > MAX_SIGHTINGS) {
        fprintf(stderr, "Invalid number of sightings. Please enter a value between 0 and %d.\n", MAX_SIGHTINGS);
        return EXIT_FAILURE;
    }

    // User Input for population size
    printf("Enter the size of the human population (max %d): ", MAX_POPULATION);
    scanf("%d", &population);
    
    // Input validation for population
    if (population <= 0 || population > MAX_POPULATION) {
        fprintf(stderr, "Invalid population size. Please enter a positive value up to %d.\n", MAX_POPULATION);
        return EXIT_FAILURE;
    }

    // User Input for technology factor
    printf("Enter the technology factor (e.g., 1.0 for normal, >1 for advanced technology): ");
    scanf("%lf", &technologyFactor);
    
    // Input validation for technology factor
    if (technologyFactor < 0) {
        fprintf(stderr, "Invalid technology factor. Please enter a non-negative value.\n");
        return EXIT_FAILURE;
    }

    // Calculate probability
    probability = calculateProbability(sightings, population, technologyFactor);

    // Display results
    displayResult(sightings, population, technologyFactor, probability);

    return EXIT_SUCCESS;
}