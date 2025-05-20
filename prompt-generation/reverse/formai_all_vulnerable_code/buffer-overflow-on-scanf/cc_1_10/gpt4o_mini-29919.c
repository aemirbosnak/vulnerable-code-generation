//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declarations
double calculateProbability(int aliens, int humans);
void displayProbability(double probability);
void simulateAlienAttack();

int main() {
    int aliens, humans;

    printf("Alien Invasion Probability Calculator\n");
    printf("=====================================\n");
    
    // User input for the number of aliens and humans
    printf("Enter the number of aliens (1-100): ");
    scanf("%d", &aliens);
    
    if (aliens < 1 || aliens > 100) {
        printf("Error: Number of aliens must be between 1 and 100.\n");
        return 1;
    }

    printf("Enter the number of humans (1-100): ");
    scanf("%d", &humans);
    
    if (humans < 1 || humans > 100) {
        printf("Error: Number of humans must be between 1 and 100.\n");
        return 1;
    }

    // Calculate and display the probability of an alien invasion
    double probability = calculateProbability(aliens, humans);
    displayProbability(probability);

    // Simulate multiple alien attacks based on user input
    char simulate;
    printf("Would you like to simulate an alien attack? (y/n): ");
    scanf(" %c", &simulate);
    
    if (simulate == 'y' || simulate == 'Y') {
        simulateAlienAttack();
    } else {
        printf("Thank you for using the Alien Invasion Probability Calculator.\n");
    }

    return 0;
}

// Function to calculate the probability of an alien invasion
double calculateProbability(int aliens, int humans) {
    if (humans == 0) return 0.0; // Prevent division by zero
    return (double)aliens / (aliens + humans) * 100.0; // percentage
}

// Function to display the calculated probability
void displayProbability(double probability) {
    printf("The probability of an alien invasion is: %.2f%%\n", probability);
}

// Function to simulate random alien attacks
void simulateAlienAttack() {
    int totalSimulations = 10; // Number of simulations
    int successCount = 0;

    srand((unsigned int)time(NULL)); // Seed the random number generator

    printf("Simulating %d alien attacks...\n", totalSimulations);
    
    for (int i = 0; i < totalSimulations; i++) {
        int outcome = rand() % 2; // Randomly determine success (1) or failure (0)
        
        if (outcome) {
            printf("Simulation %d: Alien attack successful!\n", i + 1);
            successCount++;
        } else {
            printf("Simulation %d: Alien attack failed.\n", i + 1);
        }
    }

    // Display simulation results
    printf("Total successful attacks: %d out of %d\n", successCount, totalSimulations);
    printf("Overall success rate: %.2f%%\n", (double)successCount / totalSimulations * 100.0);
}