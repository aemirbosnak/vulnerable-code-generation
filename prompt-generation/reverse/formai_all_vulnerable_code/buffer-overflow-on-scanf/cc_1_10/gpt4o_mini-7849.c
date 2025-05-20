//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants for the alien invasion probability calculator
#define BASE_PROBABILITY 0.1
#define MAX_EXTRA_PROBABILITY 0.9
#define UNIVERSE_SIZE 1000000
#define ALIEN_TECH_LEVEL 5

// Function to calculate probability of alien invasion based on various parameters
double calculateAlienInvasionProbability(int techLevel, int solarFlareActivity, int recentEncounters) {
    double invasionProbability = BASE_PROBABILITY;
    
    // Modify probability based on alien technology level
    invasionProbability += (techLevel / 10.0) * 0.1; // Add increment based on tech level
    
    // Modify probability based on solar flare activity
    invasionProbability += (solarFlareActivity / 5.0) * 0.05; // Add increment based on solar flare activity
    
    // Modify probability based on recent encounters with unidentified flying objects
    invasionProbability += (recentEncounters / 10.0) * 0.2; // Add increment based on encounters
    
    // Ensure the probability does not exceed 1.0
    if (invasionProbability > 1.0) {
        invasionProbability = 1.0;
    }
    
    return invasionProbability;
}

// Function to display the future prediction of alien invasion
void displayInvasionPrediction(double probability) {
    if (probability < 0.2) {
        printf("The chance of an alien invasion is low (%.2f%%).\n", probability * 100);
    } else if (probability < 0.5) {
        printf("The chance of an alien invasion is moderate (%.2f%%).\n", probability * 100);
    } else {
        printf("Warning! The chance of an alien invasion is high (%.2f%%).\n", probability * 100);
    }
}

// Function to simulate solar flare activity
int simulateSolarFlareActivity() {
    return rand() % 10; // Randomly generate from 0 to 9
}

// Function to simulate recent alien encounters
int simulateRecentEncounters() {
    return rand() % 20; // Randomly generate from 0 to 19
}

// Main function - the entry point of the program
int main() {
    srand(time(NULL)); // Seed for random number generation

    int techLevel, solarFlareActivity, recentEncounters;
    
    // User input for alien technology level
    printf("Enter the current alien technology level (1-10): ");
    scanf("%d", &techLevel);
    if (techLevel < 1 || techLevel > 10) {
        printf("Invalid technology level. Please restart the program.\n");
        exit(1);
    }
    
    // Simulating solar flare activity and recent encounters
    solarFlareActivity = simulateSolarFlareActivity();
    recentEncounters = simulateRecentEncounters();
    
    // Calculate the probability of alien invasion
    double invasionProbability = calculateAlienInvasionProbability(techLevel, solarFlareActivity, recentEncounters);
    
    // Display the prediction
    displayInvasionPrediction(invasionProbability);
    
    // Ask if the user wants to simulate again
    char choice;
    printf("Do you want to run another simulation? (y/n): ");
    scanf(" %c", &choice);
    
    while (choice == 'y' || choice == 'Y') {
        // Re-enter technology level
        printf("Enter the current alien technology level (1-10): ");
        scanf("%d", &techLevel);
        if (techLevel < 1 || techLevel > 10) {
            printf("Invalid technology level. Exiting simulation.\n");
            exit(1);
        }
        
        solarFlareActivity = simulateSolarFlareActivity();
        recentEncounters = simulateRecentEncounters();
        
        invasionProbability = calculateAlienInvasionProbability(techLevel, solarFlareActivity, recentEncounters);
        
        displayInvasionPrediction(invasionProbability);
        
        printf("Do you want to run another simulation? (y/n): ");
        scanf(" %c", &choice);
    }
    
    // End of simulation
    printf("Thank you for using the Alien Invasion Probability Calculator. Stay safe!\n");
    
    return 0;
}