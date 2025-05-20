//GEMINI-pro DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// Global variables
int num_solar_systems;
int num_stars;
int num_planets;
int num_civilizations;
int num_intelligent_civilizations;
int num_hostile_civilizations;
int num_peaceful_civilizations;
int num_invasions;
int num_successful_invasions;
double probability_of_invasion;
double probability_of_success;

// Function prototypes
double calculate_probability_of_invasion(void);
double calculate_probability_of_success(void);

// Main function
int main(void) {
  // Get the user input
  printf("Enter the number of solar systems: ");
  scanf("%d", &num_solar_systems);

  printf("Enter the number of stars: ");
  scanf("%d", &num_stars);

  printf("Enter the number of planets: ");
  scanf("%d", &num_planets);

  printf("Enter the number of civilizations: ");
  scanf("%d", &num_civilizations);

  printf("Enter the number of intelligent civilizations: ");
  scanf("%d", &num_intelligent_civilizations);

  printf("Enter the number of hostile civilizations: ");
  scanf("%d", &num_hostile_civilizations);

  printf("Enter the number of peaceful civilizations: ");
  scanf("%d", &num_peaceful_civilizations);

  printf("Enter the number of invasions: ");
  scanf("%d", &num_invasions);

  printf("Enter the number of successful invasions: ");
  scanf("%d", &num_successful_invasions);

  // Calculate the probability of invasion
  probability_of_invasion = calculate_probability_of_invasion();

  // Calculate the probability of success
  probability_of_success = calculate_probability_of_success();

  // Print the results
  printf("The probability of invasion is %f\n", probability_of_invasion);
  printf("The probability of success is %f\n", probability_of_success);

  return 0;
}

// Function to calculate the probability of invasion
double calculate_probability_of_invasion(void) {
  return (double)num_hostile_civilizations / (double)num_intelligent_civilizations;
}

// Function to calculate the probability of success
double calculate_probability_of_success(void) {
  return (double)num_successful_invasions / (double)num_invasions;
}