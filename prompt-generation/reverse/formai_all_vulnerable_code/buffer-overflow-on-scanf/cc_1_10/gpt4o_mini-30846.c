//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void display_welcome_message();
void display_instructions();
float calculate_probability(int sightings, int technology, int government_factors, int media_exposure);
void display_probability(float probability);

int main() {
    int alien_sightings, advanced_technology, government_factors, media_exposure;
    float invasion_probability;

    // Seed the random number generator
    srand(time(NULL));

    // Welcome the user to the Alien Invasion Probability Calculator
    display_welcome_message();
    display_instructions();

    // Collect user input for each factor
    printf("Enter the number of reported alien sightings in the last year (0-100): ");
    scanf("%d", &alien_sightings);
    printf("Rate the level of advanced technology on a scale from 1 (low) to 10 (high): ");
    scanf("%d", &advanced_technology);
    printf("Classify government secrecy level from 1 (transparent) to 10 (very secretive): ");
    scanf("%d", &government_factors);
    printf("Assess media exposure to alien-related news (1 to 10): ");
    scanf("%d", &media_exposure);

    // Validate input
    if (alien_sightings < 0 || alien_sightings > 100 || advanced_technology < 1 || advanced_technology > 10 ||
        government_factors < 1 || government_factors > 10 || media_exposure < 1 || media_exposure > 10) {
        printf("Invalid input. Please enter values within the specified ranges.\n");
        return -1;
    }

    // Calculate the invasion probability
    invasion_probability = calculate_probability(alien_sightings, advanced_technology, government_factors, media_exposure);

    // Display the calculated probability of invasion
    display_probability(invasion_probability);

    return 0;
}

// Function to display a welcome message
void display_welcome_message() {
    printf("***************************************\n");
    printf("*     Welcome to the Alien Invasion   *\n");
    printf("*       Probability Calculator        *\n");
    printf("***************************************\n");
}

// Function to display instructions for the user
void display_instructions() {
    printf("Instructions:\n");
    printf("Please provide information about various factors that could influence the probability of an alien invasion.\n");
    printf("Each factor will be scored accordingly, and we will determine a probability percentage based on your input.\n");
    printf("\nLet's begin!\n");
}

// Function to calculate the invasion probability based on user factors
float calculate_probability(int sightings, int technology, int government_factors, int media_exposure) {
    float base_probability = 2.0; // Base probability percentage
    float sighting_weight = 0.5; // Weight assigned to sightings
    float technology_weight = 0.3; // Weight assigned to technology
    float government_weight = 0.1; // Weight assigned to government secrecy
    float media_weight = 0.1; // Weight assigned to media exposure

    // Calculate total weighted factors
    float total_probability = base_probability 
                            + (sightings * sighting_weight) 
                            + (technology * technology_weight * 5) 
                            + (government_factors * government_weight * 5) 
                            + (media_exposure * media_weight * 5);
    
    // Limit the maximum probability to 100
    if (total_probability > 100.0) {
        total_probability = 100.0;
    }

    return total_probability;
}

// Function to display the probability percentage
void display_probability(float probability) {
    printf("Based on your input, the probability of an alien invasion occurring is: %.2f%%\n", probability);
    if (probability > 50) {
        printf("Warning! The signs of an alien invasion are significant. Stay alert!\n");
    } else {
        printf("Looks like the threat of an alien invasion is minimal. You can relax... for now!\n");
    }
}