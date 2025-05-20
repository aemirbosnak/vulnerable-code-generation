//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
double calculateProbability(int alienTechnology, int humanDefense);
void printResults(int alienTechnology, int humanDefense, double probability);

int main() {
    int alienTechnology, humanDefense;
    
    // Seed random number generator
    srand(time(NULL));
    
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Let's evaluate the threat based on alien technology and human defense capabilities.\n");
    
    // Input alien technology level
    printf("Enter the alien technology level (1-100): ");
    scanf("%d", &alienTechnology);
    
    // Validate input
    while (alienTechnology < 1 || alienTechnology > 100) {
        printf("Invalid input. Please enter a technology level between 1 and 100: ");
        scanf("%d", &alienTechnology);
    }
    
    // Input human defense capability
    printf("Enter the human defense capability level (1-100): ");
    scanf("%d", &humanDefense);
    
    // Validate input
    while (humanDefense < 1 || humanDefense > 100) {
        printf("Invalid input. Please enter a defense capability between 1 and 100: ");
        scanf("%d", &humanDefense);
    }
    
    // Calculate invasion probability
    double probability = calculateProbability(alienTechnology, humanDefense);
    
    // Print results
    printResults(alienTechnology, humanDefense, probability);
    
    return 0;
}

// Function to calculate the probability of an alien invasion
double calculateProbability(int alienTechnology, int humanDefense) {
    // Adjust probabilities based on technology and defense levels
    double invasionProbability = (alienTechnology - humanDefense) * 1.0; // Basic formula
    invasionProbability = invasionProbability > 0 ? invasionProbability : 0; // Clear negative probabilities
    invasionProbability = invasionProbability < 100 ? invasionProbability : 100; // Cap at 100
    
    return invasionProbability;
}

// Function to print the results of the invasion probability
void printResults(int alienTechnology, int humanDefense, double probability) {
    printf("\n--- Invasion Probability Report ---\n");
    printf("Alien Technology Level: %d\n", alienTechnology);
    printf("Human Defense Capability: %d\n", humanDefense);
    printf("Calculated Invasion Probability: %.2f%%\n", probability);
    
    if (probability > 75) {
        printf("Danger Level: Critical! Prepare for imminent invasion!\n");
    } else if (probability > 50) {
        printf("Danger Level: High! Strengthen defenses immediately!\n");
    } else if (probability > 25) {
        printf("Danger Level: Moderate! Stay vigilant and ready!\n");
    } else {
        printf("Danger Level: Low! Enjoy your day, humanity is safe for now!\n");
    }
    
    printf("-------------------------------------\n");
}