//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLANETS 20

// Function to display instructions
void displayInstructions() {
    printf("===============================================\n");
    printf("  Welcome to the Alien Invasion Probability\n");
    printf("             Calculator 3000!\n");
    printf("===============================================\n");
    printf("Here you can calculate the probability of alien\n");
    printf("invasions based on the number of habitable\n");
    printf("planets and the probability of them being\n");
    printf("inhabited by aliens!\n");
    printf("===============================================\n");
}

// Function to calculate the total probability of an alien invasion
double calculateTotalProbability(int numberOfPlanets, double planetProbability) {
    double totalProbability = 1.0;

    for (int i = 0; i < numberOfPlanets; i++) {
        totalProbability *= (1 - planetProbability); // Probability of no aliens
    }
    
    return 1 - totalProbability; // Total probability of at least one alien
}

// Function to get a valid input for the number of planets
int getNumberOfPlanets() {
    int planets;
    do {
        printf("Enter the number of planets (1 to %d): ", MAX_PLANETS);
        scanf("%d", &planets);
        if (planets < 1 || planets > MAX_PLANETS) {
            printf("Invalid input! Please enter a number between 1 and %d.\n", MAX_PLANETS);
        }
    } while (planets < 1 || planets > MAX_PLANETS);
    
    return planets;
}

// Function to get a valid input for the probability of existence
double getPlanetProbability() {
    double probability;
    do {
        printf("Enter the probability of existence of aliens on each planet (0.0 to 1.0): ");
        scanf("%lf", &probability);
        if (probability < 0.0 || probability > 1.0) {
            printf("Invalid input! Please enter a valid probability between 0.0 and 1.0.\n");
        }
    } while (probability < 0.0 || probability > 1.0);
    
    return probability;
}

int main() {
    displayInstructions();

    // Seed random number generator
    srand(time(NULL));

    // Get user inputs
    int numberOfPlanets = getNumberOfPlanets();
    double planetProbability = getPlanetProbability();

    // Calculate the invasion probability
    double invasionProbability = calculateTotalProbability(numberOfPlanets, planetProbability);

    // Display the results
    printf("===============================================\n");
    printf("  Results from the Alien Invasion Calculator!  \n");
    printf("===============================================\n");
    printf("Number of planets: %d\n", numberOfPlanets);
    printf("Probability of existence of aliens on each planet: %.2f\n", planetProbability);
    printf("Calculated probability of alien invasion: %.2f\n", invasionProbability);
    printf("===============================================\n");

    // Create a fun interactive element
    printf("Would you like to experience a simulated alien invasion? (y/n): ");
    char choice;
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        // Simulate a chance of invasion
        double simulationChance = ((double)rand() / (double)RAND_MAX);
        printf("Simulating invasion...\n");
        if (simulationChance < invasionProbability) {
            printf("🚀 Alien invasion successful!!! 🌌\n");
        } else {
            printf("🙌 No alien invasion this time... for now! 🌍\n");
        }
    } else {
        printf("Thank you for using the Alien Invasion Probability Calculator! 👽\n");
    }

    return 0;
}