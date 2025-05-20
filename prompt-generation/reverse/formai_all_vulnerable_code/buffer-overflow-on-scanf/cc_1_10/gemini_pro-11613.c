//GEMINI-pro DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declare the function to calculate the probability of an alien invasion
double calculate_alien_invasion_probability(int num_stars, int num_planets, int num_civilizations, int num_technologically_advanced_civilizations);

// Declare the main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Get the number of stars in the universe
    printf("Enter the estimated number of stars in the universe: ");
    int num_stars;
    scanf("%d", &num_stars);

    // Get the number of planets in the universe
    printf("Enter the estimated number of planets in the universe: ");
    int num_planets;
    scanf("%d", &num_planets);

    // Get the number of civilizations in the universe
    printf("Enter the estimated number of civilizations in the universe: ");
    int num_civilizations;
    scanf("%d", &num_civilizations);

    // Get the number of technologically advanced civilizations in the universe
    printf("Enter the estimated number of technologically advanced civilizations in the universe: ");
    int num_technologically_advanced_civilizations;
    scanf("%d", &num_technologically_advanced_civilizations);

    // Calculate the probability of an alien invasion
    double probability = calculate_alien_invasion_probability(num_stars, num_planets, num_civilizations, num_technologically_advanced_civilizations);

    // Print the probability of an alien invasion
    printf("The probability of an alien invasion is: %.2f%%\n", probability * 100);

    return 0;
}

// Define the function to calculate the probability of an alien invasion
double calculate_alien_invasion_probability(int num_stars, int num_planets, int num_civilizations, int num_technologically_advanced_civilizations) {
    // Calculate the probability of a star having a planet
    double probability_star_has_planet = (double)num_planets / num_stars;

    // Calculate the probability of a planet having a civilization
    double probability_planet_has_civilization = (double)num_civilizations / num_planets;

    // Calculate the probability of a civilization being technologically advanced
    double probability_civilization_is_technologically_advanced = (double)num_technologically_advanced_civilizations / num_civilizations;

    // Calculate the probability of an alien invasion
    double probability = probability_star_has_planet * probability_planet_has_civilization * probability_civilization_is_technologically_advanced;

    return probability;
}