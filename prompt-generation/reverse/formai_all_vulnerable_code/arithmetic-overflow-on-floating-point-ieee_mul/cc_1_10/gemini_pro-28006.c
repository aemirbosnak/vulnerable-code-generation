//GEMINI-pro DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Constants
#define MAX_DISTANCE 1000000.0   // Maximum distance from Earth in light-years
#define MAX_SPEED 100000.0        // Maximum speed of an alien spaceship in light-years per year
#define MAX_LIFESPAN 10000.0       // Maximum lifespan of an alien in years
#define MIN_PROBABILITY 0.0000001  // Minimum probability of an alien invasion

// Function prototypes
double calculate_probability(double distance, double speed, double lifespan);
void print_probability(double probability);

int main() {
    // Variables
    double distance, speed, lifespan, probability;

    // Get user input
    printf("Enter the distance to Earth in light-years: ");
    scanf("%lf", &distance);
    printf("Enter the speed of the alien spaceship in light-years per year: ");
    scanf("%lf", &speed);
    printf("Enter the lifespan of an alien in years: ");
    scanf("%lf", &lifespan);

    // Calculate the probability of an alien invasion
    probability = calculate_probability(distance, speed, lifespan);

    // Print the probability
    print_probability(probability);

    return 0;
}

// Function to calculate the probability of an alien invasion
double calculate_probability(double distance, double speed, double lifespan) {
    // Check if the input is valid
    if (distance <= 0 || speed <= 0 || lifespan <= 0) {
        return 0.0;
    }

    // Calculate the probability
    double probability = 1.0 / ((distance / speed) * lifespan);

    // Ensure that the probability is within the valid range
    if (probability < MIN_PROBABILITY) {
        probability = MIN_PROBABILITY;
    }

    return probability;
}

// Function to print the probability
void print_probability(double probability) {
    // Print the probability
    printf("The probability of an alien invasion is: %.10f\n", probability);
}