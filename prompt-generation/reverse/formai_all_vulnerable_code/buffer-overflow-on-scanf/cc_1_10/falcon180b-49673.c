//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_TRIALS 1000000
#define MAX_ALIENS 1000
#define MIN_ALIENS 1

// Function to generate a random number
int randInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to simulate an alien invasion
int simulateInvasion(int numAliens) {
    int numSurvivors = 0;

    // Loop through each alien
    for (int i = 0; i < numAliens; i++) {
        // Generate a random number between 0 and 100
        int attackSuccess = randInt(0, 100);

        // If the attack is successful, the alien survives
        if (attackSuccess >= 50) {
            numSurvivors++;
        }
    }

    // Return the number of survivors
    return numSurvivors;
}

// Function to calculate the probability of an alien invasion succeeding
double calculateInvasionProbability(int numAliens) {
    int numSurvivors = 0;
    int numTrials = 0;

    // Loop through each trial
    for (int i = 0; i < NUM_TRIALS; i++) {
        // Simulate an alien invasion
        numSurvivors += simulateInvasion(numAliens);
        numTrials++;
    }

    // Calculate the probability of success
    double probability = (double)numSurvivors / (double)numTrials;

    // Return the probability
    return probability;
}

int main() {
    int numAliens;

    // Prompt the user for the number of aliens
    printf("Enter the number of aliens (between %d and %d): ", MIN_ALIENS, MAX_ALIENS);
    scanf("%d", &numAliens);

    // Calculate the invasion probability
    double probability = calculateInvasionProbability(numAliens);

    // Print the results
    printf("For an invasion of %d aliens, the probability of success is %.2f%%\n", numAliens, probability * 100);

    return 0;
}