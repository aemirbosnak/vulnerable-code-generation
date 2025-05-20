//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int randInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to print the probability of an alien invasion
void printProbability(int numPlanets, int numInhabited, int numInvaded) {
    float probability = (float)numInvaded / numInhabited;
    printf("The probability of an alien invasion is %.2f%%\n", probability * 100);
}

// Main function to run the program
int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Get the number of planets from the user
    int numPlanets;
    printf("Enter the number of planets: ");
    scanf("%d", &numPlanets);

    // Initialize the number of inhabited and invaded planets
    int numInhabited = 0;
    int numInvaded = 0;

    // Loop through each planet
    for (int i = 0; i < numPlanets; i++) {
        // Generate a random number between 0 and 1 to determine if the planet is inhabited
        float randNum = (float)randInt(0, 1000) / 1000;
        if (randNum < 0.1) {
            // The planet is inhabited
            numInhabited++;

            // Generate another random number to determine if the planet has been invaded
            if (randInt(0, 100) < 50) {
                // The planet has been invaded
                numInvaded++;
            }
        }
    }

    // Print the probability of an alien invasion
    printProbability(numPlanets, numInhabited, numInvaded);

    return 0;
}