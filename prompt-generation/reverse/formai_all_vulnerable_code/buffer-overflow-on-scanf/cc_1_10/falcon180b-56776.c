//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
double calculateInvasionProbability(int numPlanets, int numInhabited, int numAdvanced);
void displayResults(double probability);

int main() {
    // Initialize variables
    int numPlanets, numInhabited, numAdvanced;
    double invasionProbability;

    // Get user input for number of planets
    printf("Enter the number of planets in the galaxy: ");
    scanf("%d", &numPlanets);

    // Get user input for number of inhabited planets
    printf("Enter the number of inhabited planets: ");
    scanf("%d", &numInhabited);

    // Get user input for number of advanced civilizations
    printf("Enter the number of advanced civilizations: ");
    scanf("%d", &numAdvanced);

    // Calculate invasion probability
    invasionProbability = calculateInvasionProbability(numPlanets, numInhabited, numAdvanced);

    // Display results
    displayResults(invasionProbability);

    return 0;
}

// Function to calculate invasion probability
double calculateInvasionProbability(int numPlanets, int numInhabited, int numAdvanced) {
    // Initialize variables
    double probability = 0.0;

    // Calculate probability based on number of planets, inhabited planets, and advanced civilizations
    probability = ((double)numInhabited / numPlanets) * ((double)numAdvanced / numInhabited);

    // Return probability
    return probability;
}

// Function to display results
void displayResults(double probability) {
    // Initialize variables
    char message[100];

    // Format probability as a percentage
    probability *= 100.0;

    // Create message based on probability
    if (probability < 1.0) {
        sprintf(message, "The probability of an alien invasion is less than 1%.\n");
    } else if (probability < 5.0) {
        sprintf(message, "The probability of an alien invasion is low (%.2f%).\n", probability);
    } else if (probability < 10.0) {
        sprintf(message, "The probability of an alien invasion is moderate (%.2f%).\n", probability);
    } else {
        sprintf(message, "The probability of an alien invasion is high (%.2f%).\n", probability);
    }

    // Display message
    printf("%s", message);
}