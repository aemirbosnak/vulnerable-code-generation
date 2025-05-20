//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: intelligent
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

// Probability Calculator for Alien Invasion
// Calculates the likelihood of an alien invasion based on user input

bool randomEvent(double probability) {
    // Simulates a random event and returns true or false based on the given probability
    double random = (double) rand() / (double) RAND_MAX;
    if (random < probability) {
        return true;
    } else {
        return false;
    }
}

int main() {
    srand(time(NULL));

    double likelihoodOfContact = 0.0;
    double populationRiskFactor = 0.0;
    double militaryPreparedness = 0.0;

    // Get input from user
    printf("Welcome to the Alien Invasion Probability Calculator.\n\n");
    printf("Please answer the following questions to determine the likelihood of an alien invasion.\n\n");

    printf("What is the likelihood of contact with extraterrestrial intelligence? (0.0 - 1.0)\n");
    scanf("%lf", &likelihoodOfContact);

    printf("What is the risk factor of our population being susceptible to an alien invasion? (0.0 - 1.0)\n");
    scanf("%lf", &populationRiskFactor);

    printf("What is the level of military preparedness for an alien invasion? (0.0 - 1.0)\n");
    scanf("%lf", &militaryPreparedness);

    // Calculate probability of alien invasion
    double probability = likelihoodOfContact * populationRiskFactor * militaryPreparedness;

    // Simulate random event to determine if alien invasion occurs
    if (randomEvent(probability)) {
        printf("\nProbability of Alien Invasion: %lf\n", probability);
        printf("ALIENS HAVE INVADED OUR PLANET!\n");
        printf("Please remain calm and follow evacuation procedures.\n");
    } else {
        printf("\nProbability of Alien Invasion: %lf\n", probability);
        printf("Good news! No alien invasion detected at this time.\n");
    }

    return 0;
}