//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to calculate invasion probability
double calculateProbability(int sightings, int phenomena, int random_factor) {
    // Simple formula for probability
    // (sightings + phenomena + random_factor) / max_possible
    const int max_possible = 100;
    double invasion_probability = (double)(sightings + phenomena + random_factor) / max_possible;
    
    // Ensure the probability does not exceed 1
    if (invasion_probability > 1.0) {
        invasion_probability = 1.0;
    }
    return invasion_probability * 100; // Convert to percentage
}

// Function to get user input safely
int getUserInput(const char *prompt) {
    int input;
    printf("%s", prompt);
    while (scanf("%d", &input) != 1 || input < 0) {
        printf("Invalid input. Please enter a non-negative integer: ");
        while(getchar() != '\n'); // Clear input buffer
    }
    return input;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Prompt user for inputs
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    
    int sightings = getUserInput("Enter the number of UFO sightings: ");
    int phenomena = getUserInput("Enter the number of unexplained phenomena: ");

    // Generate a random factor to simulate uncertainty
    int random_factor = rand() % 20; // Random factor between 0 and 19
    printf("Random factor generated: %d\n", random_factor);

    // Calculate invasion probability
    double probability = calculateProbability(sightings, phenomena, random_factor);
    
    // Display the result
    printf("The probability of an alien invasion is: %.2f%%\n", probability);
    
    // Provide additional information
    if (probability > 75) {
        printf("Warning: High probability! Stay alert!\n");
    } else if (probability > 50) {
        printf("Caution: Moderate probability. Remain vigilant.\n");
    } else {
        printf("Low probability. You can relax... for now.\n");
    }
    
    return 0;
}