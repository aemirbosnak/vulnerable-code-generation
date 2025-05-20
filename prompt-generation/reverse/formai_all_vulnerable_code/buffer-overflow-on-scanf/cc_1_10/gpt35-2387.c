//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to calculate the probability of an alien invasion
float calculateProbability(int yearsOfResearch, int technologyLevel, int militaryStrength) {
    float basicProbability = 0.5; // Base probability of an alien invasion

    // Adjust probability based on years of research
    if (yearsOfResearch < 5) {
        basicProbability += (float) yearsOfResearch * 0.05; // Increase probability by 0.05 for each year of research
    } else {
        basicProbability += 0.25; // Maximum increase of 0.25 when research exceeds 5 years
    }

    // Adjust probability based on technology level
    if (technologyLevel == 1) {
        basicProbability += 0.1; // Increase probability by 0.1 for Level 1 technology
    } else if (technologyLevel == 2) {
        basicProbability += 0.2; // Increase probability by 0.2 for Level 2 technology
    } else {
        basicProbability += 0.3; // Increase probability by 0.3 for Level 3 technology
    }

    // Adjust probability based on military strength
    if (militaryStrength <= 100) {
        basicProbability += (float) militaryStrength * 0.01; // Increase probability by 0.01 for each point of military strength
    } else {
        basicProbability += 1.0; // Maximum increase of 1.0 when military strength exceeds 100
    }

    return basicProbability;
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    int yearsOfResearch, technologyLevel, militaryStrength;
    float probability;

    // Take input from the user
    printf("Enter years of research: ");
    scanf("%d", &yearsOfResearch);
    printf("Enter technology level (1 to 3): ");
    scanf("%d", &technologyLevel);
    printf("Enter military strength (0 to 100): ");
    scanf("%d", &militaryStrength);

    // Calculate the probability of an alien invasion
    probability = calculateProbability(yearsOfResearch, technologyLevel, militaryStrength);

    // Generate a random number between 0 and 1
    float random = (float) rand() / RAND_MAX;

    // Determine if there will be an alien invasion based on the probability and the random number
    if (random < probability) {
        printf("There is a %f%% chance of an alien invasion. RUN FOR YOUR LIVES!", probability*100);
    } else {
        printf("There is a %f%% chance of an alien invasion. You are safe... for now.", probability*100);
    }

    return 0; // End the program
}