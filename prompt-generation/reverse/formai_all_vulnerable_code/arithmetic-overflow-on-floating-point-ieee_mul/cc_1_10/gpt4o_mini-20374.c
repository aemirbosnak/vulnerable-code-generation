//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to hold alien characteristics
typedef struct {
    int population;
    float technologyLevel; // Scale of 0.0 to 1.0
} AlienSpecies;

// Structure to hold Earth characteristics
typedef struct {
    int population;
    float defenseLevel; // Scale of 0.0 to 1.0
    float resources; // Scale of 0.0 to 1.0
} Earth;

// Function to calculate the probability of an alien invasion
float calculateInvasionProbability(AlienSpecies aliens, Earth earth) {
    float invasionChance = 0.0;

    // Basic parameters
    float alienFactor = (float)aliens.population / 1000000.0; // Scaling for population
    float techFactor = aliens.technologyLevel * 0.5; // Technology can help or hinder
    float defenseFactor = (1 - earth.defenseLevel) * 0.3; // Lower defense increases chance
    float resourceFactor = earth.resources * 0.2; // More resources may attract attention

    // Calculate the probability
    invasionChance = (alienFactor + techFactor + defenseFactor + resourceFactor) * 100; // Final chance in percentage
    
    if (invasionChance > 100) {
        invasionChance = 100; // Max chance is 100%
    }

    return invasionChance;
}

// Function to collect user input for alien and Earth characteristics
void getUserInputs(AlienSpecies *aliens, Earth *earth) {
    printf("Enter alien population: ");
    scanf("%d", &aliens->population);
    printf("Enter alien technology level (0.0 to 1.0): ");
    scanf("%f", &aliens->technologyLevel);

    printf("\nEnter Earth population: ");
    scanf("%d", &earth->population);
    printf("Enter Earth defense level (0.0 to 1.0): ");
    scanf("%f", &earth->defenseLevel);
    printf("Enter Earth resources level (0.0 to 1.0): ");
    scanf("%f", &earth->resources);
}

// Function to display the invasion report
void displayInvasionReport(float invasionProbability) {
    printf("\n--- Invasion Probability Report ---\n");
    printf("The calculated probability of an alien invasion is: %.2f%%\n", invasionProbability);
    
    if (invasionProbability > 75) {
        printf("Warning: You should prepare for an invasion!\n");
    } else if (invasionProbability > 50) {
        printf("Caution: An invasion is possible, stay alert!\n");
    } else {
        printf("Low risk: The aliens are unlikely to invade anytime soon.\n");
    }

    printf("-----------------------------------\n");
}

int main() {
    AlienSpecies aliens;
    Earth earth;
    float invasionProbability;

    srand(time(NULL)); // For random events, not used here to keep the example simple

    // Get inputs from user
    getUserInputs(&aliens, &earth);

    // Calculate invasion probability
    invasionProbability = calculateInvasionProbability(aliens, earth);

    // Display the results
    displayInvasionReport(invasionProbability);

    return 0;
}