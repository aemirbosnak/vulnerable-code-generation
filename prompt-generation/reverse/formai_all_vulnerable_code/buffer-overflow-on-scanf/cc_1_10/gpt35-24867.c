//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int randomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main(int argc, char* argv[]) {
    int alienProbability = 0;
    int numCities = 0;
    srand(time(NULL)); // Seed the random number generator with time

    // Accept user input for probability of alien invasion
    printf("Please enter the probability of an alien invasion (0-100): ");
    scanf("%d", &alienProbability);

    // Validate input
    while (alienProbability < 0 || alienProbability > 100) {
        printf("Invalid input. Probability must be between 0 and 100. Please enter a valid probability: ");
        scanf("%d", &alienProbability);
    }

    // Accept user input for number of cities
    printf("Please enter the number of cities in your region: ");
    scanf("%d", &numCities);

    // Validate input
    while (numCities <= 0) {
        printf("Invalid input. Number of cities must be greater than 0. Please enter a valid number of cities: ");
        scanf("%d", &numCities);
    }

    // Calculate probability of alien invasion for each city
    int cityProb[numCities];

    for (int i = 0; i < numCities; i++) {
        cityProb[i] = randomNumber(1, 100); // Generate a random probability for each city

        if (cityProb[i] <= alienProbability) {
            printf("City %d has a high probability of being invaded by aliens!\n", i+1);
        }
        else {
            printf("City %d is safe from alien invasion... for now.\n", i+1);
        }
    }

    return 0;
}