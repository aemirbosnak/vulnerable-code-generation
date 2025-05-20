//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to calculate the probability of an alien invasion
float calculateProbability(float baseChance, float humanTechLevel, float alienTechLevel) {
    float invasionChance = baseChance;
    invasionChance += (humanTechLevel * 0.1);    // Increase chance based on human technology
    invasionChance -= (alienTechLevel * 0.1);    // Decrease chance based on alien technology

    // Ensure the probability is between 0 and 100
    if (invasionChance < 0) return 0;
    if (invasionChance > 100) return 100;

    return invasionChance;
}

// Function to simulate the alien invasion based on probability
void simulateInvasion(float probability) {
    float randomValue = (float)rand() / (float)RAND_MAX * 100; // Generate a random value between 0 and 100

    if (randomValue < probability) {
        printf("ALERT: Alien Invasion Detected! Probability was %.2f%%.\n", probability);
    } else {
        printf("Status: No Invasion. Probability was %.2f%%.\n", probability);
    }
}

int main() {
    srand(time(NULL));  // Seed the random number generator

    float baseChance;
    float humanTechLevel;
    float alienTechLevel;
    char continueSimulation;

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    
    do {
        // Get user input for base chance, human tech level, and alien tech level
        printf("Enter the base chance of alien invasion (0 - 100): ");
        scanf("%f", &baseChance);
        
        printf("Enter the human technology level (0 - 100): ");
        scanf("%f", &humanTechLevel);
        
        printf("Enter the alien technology level (0 - 100): ");
        scanf("%f", &alienTechLevel);

        // Validate input
        if (baseChance < 0 || baseChance > 100 || 
            humanTechLevel < 0 || humanTechLevel > 100 || 
            alienTechLevel < 0 || alienTechLevel > 100) {
            printf("Error: Please enter values between 0 and 100.\n");
            continue;
        }

        // Calculate invasion probability
        float probability = calculateProbability(baseChance, humanTechLevel, alienTechLevel);
        printf("Calculated Probability of Alien Invasion: %.2f%%\n", probability);
        
        // Simulate the invasion
        simulateInvasion(probability);

        // Ask the user if they want to continue
        printf("Do you want to run another simulation? (y/n): ");
        scanf(" %c", &continueSimulation);

    } while (continueSimulation == 'y' || continueSimulation == 'Y');
    
    printf("Thank you for using the Alien Invasion Probability Calculator!\n");
    return 0;
}