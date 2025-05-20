//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to simulate the presence of aliens on Earth
int isAlienInvasion() {
    return rand() % 100 < 7; // 7% chance of an invasion
}

// Function to calculate the probability 
void calculateAlienProbability(int simulations, double *result) {
    int invasionCount = 0;

    for (int i = 0; i < simulations; i++) {
        if (isAlienInvasion()) {
            invasionCount++;
        }
    }
    *result = (double)invasionCount / simulations * 100;
}

// Function to display the result
void displayProbability(double probability) {
    printf("After running simulations, the probability of an alien invasion is: %.2f%%\n", probability);
}

// Function to get user input for the number of simulations
int getUserInput() {
    int simCount;
    printf("Enter the number of simulations to run (suggested at least 1000): ");
    scanf("%d", &simCount);
    return simCount;
}

// Function to log results to a file
void logResults(double probability) {
    FILE *file = fopen("alien_invasion_log.txt", "a+");
    if (file == NULL) {
        perror("Unable to open log file");
        exit(EXIT_FAILURE);
    }
    fprintf(file, "Alien Invasion Probability: %.2f%%\n", probability);
    fclose(file);
}

// Main function
int main() {
    int simulations;
    double probability;

    // Seed the random number generator for different results each time
    srand(time(NULL));

    simulations = getUserInput();

    if (simulations <= 0) {
        printf("Simulation count must be positive! Please try again.\n");
        return 1; // Exit if the input is invalid
    }

    calculateAlienProbability(simulations, &probability);
    
    displayProbability(probability);
    logResults(probability);

    // Additional fun message to engage the user
    printf("Let's hope they don't land in your backyard!\n");

    return 0;
}