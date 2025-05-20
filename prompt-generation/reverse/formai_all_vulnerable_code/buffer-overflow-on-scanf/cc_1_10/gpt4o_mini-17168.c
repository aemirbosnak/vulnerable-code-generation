//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
float calculateProbability(int population, float awareness, float readiness);
void displayResults(float probability);

int main() {
    int population;
    float awareness, readiness, probability;

    // Seed the random number generator
    srand(time(NULL));

    // Welcome message
    printf("👽🌌 Welcome to the Alien Invasion Probability Calculator! 🌌👽\n\n");
    printf("Let's determine the likelihood of an alien invasion based on your inputs.\n");

    // Get user input
    printf("Enter the total population (in millions, e.g., 7 for 7 million): ");
    scanf("%d", &population);

    printf("Rate the awareness of extraterrestrial life (0.0 to 1.0, where 1.0 means everyone's aware): ");
    scanf("%f", &awareness);
    while(awareness < 0.0 || awareness > 1.0) {
        printf("Invalid input! Please enter a value between 0.0 and 1.0: ");
        scanf("%f", &awareness);
    }

    printf("Rate the readiness for an invasion (0.0 to 1.0, where 1.0 means fully prepared): ");
    scanf("%f", &readiness);
    while(readiness < 0.0 || readiness > 1.0) {
        printf("Invalid input! Please enter a value between 0.0 and 1.0: ");
        scanf("%f", &readiness);
    }

    // Calculate the probability of an alien invasion
    probability = calculateProbability(population, awareness, readiness);

    // Display the results
    displayResults(probability);

    return 0;
}

// Calculate the probability of an alien invasion
float calculateProbability(int population, float awareness, float readiness) {
    float invasionChance = ((float)population * awareness * readiness) / 100.0; // Scale it to a percentage
    return invasionChance > 100.0 ? 100.0 : invasionChance; // Cap the value at 100%
}

// Display the results
void displayResults(float probability) {
    printf("\n🚀👾 Invasion Probability Report 👾🚀\n");
    printf("The calculated probability of an alien invasion is: %.2f%%\n", probability);

    if (probability < 20.0) {
        printf("Chill! Looks like we are safe for now! 😌🌍\n");
    } else if (probability < 50.0) {
        printf("Keep your eyes peeled! Something may be lurking! 👀🛸\n");
    } else if (probability < 80.0) {
        printf("Oh no! The aliens are definitely considering us! 🛸⚠️\n");
    } else {
        printf("Brace yourself! High probability of intergalactic visitors! 🚨👽\n");
    }

    printf("\n👽🌌 Thank you for using the Alien Invasion Probability Calculator! 🌌👽\n");
}