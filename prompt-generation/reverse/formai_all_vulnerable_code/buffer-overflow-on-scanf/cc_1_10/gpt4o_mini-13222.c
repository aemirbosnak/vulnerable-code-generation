//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LOCATIONS 10
#define MAX_ATTEMPTS 100
#define PROBABILITY_MULTIPLIER 100

// Function to generate a random probability of alien invasion
float generateRandomProbability() {
    return (float)rand() / (float)(RAND_MAX / PROBABILITY_MULTIPLIER);
}

// Function to calculate the invasion probability for each location
void calculateInvasionProbabilities(float probabilities[MAX_LOCATIONS], int num_locations) {
    printf("Calculating alien invasion probabilities for %d locations...\n", num_locations);
    for (int i = 0; i < num_locations; ++i) {
        probabilities[i] = generateRandomProbability();
    }
}

// Function to display the invasion probabilities
void displayProbabilities(const float probabilities[MAX_LOCATIONS], int num_locations) {
    printf("\nAlien Invasion Probability Report:\n");
    printf("=====================================\n");
    for (int i = 0; i < num_locations; ++i) {
        printf("Location %d: %.2f%% chance of invasion!\n", i + 1, probabilities[i]);
    }
    printf("=====================================\n");
}

// Function to evaluate the overall seriousness of the situation
void evaluateInvasionRisk(const float probabilities[MAX_LOCATIONS], int num_locations) {
    float average_probability = 0;
    for (int i = 0; i < num_locations; ++i) {
        average_probability += probabilities[i];
    }
    average_probability /= num_locations;
    
    printf("Average Invasion Probability: %.2f%%\n", average_probability);
    
    if (average_probability > 75) {
        printf("Warning: HIGH risk of alien invasion detected!\n");
    } else if (average_probability > 50) {
        printf("Caution: Moderate risk present.\n");
    } else {
        printf("Safe: Low risk of alien invasion.\n");
    }
}

int main() {
    srand(time(NULL));
    
    int num_locations;
    float probabilities[MAX_LOCATIONS];

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("How many locations would you like to analyze? (max %d): ", MAX_LOCATIONS);
    scanf("%d", &num_locations);

    if (num_locations < 1 || num_locations > MAX_LOCATIONS) {
        printf("Invalid number of locations! Please run the program again.\n");
        return 1;
    }

    calculateInvasionProbabilities(probabilities, num_locations);
    displayProbabilities(probabilities, num_locations);
    evaluateInvasionRisk(probabilities, num_locations);

    printf("Thank you for using the Alien Invasion Probability Calculator. Stay safe! 👽🚀\n");
    
    return 0;
}