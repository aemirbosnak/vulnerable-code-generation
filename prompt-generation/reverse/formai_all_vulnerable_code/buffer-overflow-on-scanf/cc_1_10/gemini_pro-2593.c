//GEMINI-pro DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

// Declare global variables
double probability_of_alien_invasion;
int number_of_planets_visited;
int number_of_planets_with_life;
int number_of_planets_with_intelligent_life;
int number_of_planets_with_hostile_life;

// Declare function prototypes
double calculate_probability_of_alien_invasion();

int main() {
    // Welcome the user to the program
    printf("Welcome to the Alien Invasion Probability Calculator!\n\n");

    // Get user input
    printf("Please enter the following information:\n");
    printf("1. The number of planets you have visited: ");
    scanf("%d", &number_of_planets_visited);
    printf("2. The number of planets you have visited with life: ");
    scanf("%d", &number_of_planets_with_life);
    printf("3. The number of planets you have visited with intelligent life: ");
    scanf("%d", &number_of_planets_with_intelligent_life);
    printf("4. The number of planets you have visited with hostile life: ");
    scanf("%d", &number_of_planets_with_hostile_life);

    // Calculate the probability of alien invasion
    probability_of_alien_invasion = calculate_probability_of_alien_invasion();

    // Display the results
    printf("\nThe probability of an alien invasion is: %.2f%%\n", probability_of_alien_invasion * 100);

    // Exit the program
    return 0;
}

double calculate_probability_of_alien_invasion() {
    // Calculate the probability of finding life on a planet
    double probability_of_life = (double)number_of_planets_with_life / number_of_planets_visited;

    // Calculate the probability of finding intelligent life on a planet
    double probability_of_intelligent_life = (double)number_of_planets_with_intelligent_life / number_of_planets_with_life;

    // Calculate the probability of finding hostile life on a planet
    double probability_of_hostile_life = (double)number_of_planets_with_hostile_life / number_of_planets_with_intelligent_life;

    // Calculate the probability of an alien invasion
    probability_of_alien_invasion = probability_of_life * probability_of_intelligent_life * probability_of_hostile_life;

    // Return the probability of alien invasion
    return probability_of_alien_invasion;
}