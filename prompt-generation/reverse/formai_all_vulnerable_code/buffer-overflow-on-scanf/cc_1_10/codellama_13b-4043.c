//Code Llama-13B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: safe
/*
 * Alien Invasion Probability Calculator
 *
 * Written by: [Your Name]
 * Date: [Date]
 *
 * Calculates the probability of an alien invasion based on user input.
 */

#include <stdio.h>
#include <stdlib.h>

// Function to calculate the probability of an alien invasion
float calculate_probability(float earth_population, float alien_population) {
    return alien_population / earth_population;
}

// Function to print the result of the probability calculation
void print_result(float probability) {
    if (probability <= 0.01) {
        printf("The probability of an alien invasion is very low.\n");
    } else if (probability <= 0.1) {
        printf("The probability of an alien invasion is low.\n");
    } else if (probability <= 0.5) {
        printf("The probability of an alien invasion is moderate.\n");
    } else if (probability <= 0.9) {
        printf("The probability of an alien invasion is high.\n");
    } else {
        printf("The probability of an alien invasion is very high.\n");
    }
}

// Main function
int main() {
    // Declare variables
    float earth_population, alien_population, probability;

    // Get input from user
    printf("Enter the current population of Earth: ");
    scanf("%f", &earth_population);
    printf("Enter the population of the alien invasion: ");
    scanf("%f", &alien_population);

    // Calculate the probability of an alien invasion
    probability = calculate_probability(earth_population, alien_population);

    // Print the result
    print_result(probability);

    return 0;
}