//GEMINI-pro DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Greetings from Planet Xenon!
void greet_user() {
    printf("Greetings, Earthling! Welcome to the Xenon Alien Invasion Probability Calculator.\n");
    printf("Strap yourself in and prepare for a thrilling adventure through the cosmos!\n\n");
}

// Calculate the probability of an alien invasion
double calculate_invasion_probability() {
    // Initialize random seed
    srand(time(NULL));

    // Generate random numbers for various factors
    double alien_population = (double)rand() / RAND_MAX * 1000000;
    double alien_technology = (double)rand() / RAND_MAX * 100;
    double human_defenses = (double)rand() / RAND_MAX * 100;

    // Calculate invasion probability
    double probability = alien_population * alien_technology / (human_defenses * 100);

    return probability;
}

// Display the invasion probability
void display_invasion_probability(double probability) {
    printf("According to our highly advanced calculations, the probability of an alien invasion is: %.2f%%\n", probability * 100);

    if (probability >= 0.5) {
        printf("Eeek! It seems like you better start building those underground bunkers.\n");
    } else {
        printf("Phew! Looks like you can relax for now. But don't get too comfortable, the aliens may be lurking just around the corner.\n");
    }
}

// Main function
int main() {
    // Greet the user
    greet_user();

    // Calculate the invasion probability
    double probability = calculate_invasion_probability();

    // Display the invasion probability
    display_invasion_probability(probability);

    return 0;
}