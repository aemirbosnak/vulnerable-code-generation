//GEMINI-pro DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: multivariable
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Define constants
#define MAX_PLANETS 100
#define MAX_STARS 1000
#define MAX_GALAXIES 1000000

// Define data structures
typedef struct {
    int num_planets;
    int num_stars;
    int num_galaxies;
    double probability;
} invasion_params;

// Define functions
double calculate_probability(invasion_params params);
void print_results(invasion_params params);

// Main function
int main() {
    // Get input from the user
    int num_planets;
    printf("Enter the number of planets in your galaxy: ");
    scanf("%d", &num_planets);

    int num_stars;
    printf("Enter the number of stars in your galaxy: ");
    scanf("%d", &num_stars);

    int num_galaxies;
    printf("Enter the number of galaxies in the universe: ");
    scanf("%d", &num_galaxies);

    // Create an invasion_params struct
    invasion_params params = {num_planets, num_stars, num_galaxies, 0.0};

    // Calculate the probability of an alien invasion
    double probability = calculate_probability(params);

    // Print the results
    print_results(params);

    return 0;
}

// Calculate the probability of an alien invasion
double calculate_probability(invasion_params params) {
    // Get the number of planets, stars, and galaxies
    int num_planets = params.num_planets;
    int num_stars = params.num_stars;
    int num_galaxies = params.num_galaxies;

    // Calculate the probability of an alien invasion
    double probability = (double)num_planets * (double)num_stars * (double)num_galaxies / (double)(MAX_PLANETS * MAX_STARS * MAX_GALAXIES);

    return probability;
}

// Print the results
void print_results(invasion_params params) {
    // Get the number of planets, stars, and galaxies
    int num_planets = params.num_planets;
    int num_stars = params.num_stars;
    int num_galaxies = params.num_galaxies;

    // Calculate the probability of an alien invasion
    double probability = params.probability;

    // Print the results
    printf("The probability of an alien invasion is: %f\n", probability);
}