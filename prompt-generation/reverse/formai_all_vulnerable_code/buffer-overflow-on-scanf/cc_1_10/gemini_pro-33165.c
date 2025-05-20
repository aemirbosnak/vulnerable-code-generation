//GEMINI-pro DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the constants used in the calculation
#define NUM_STARS 1000000000000000000
#define NUM_PLANETS_PER_STAR 10
#define NUM_INTELLIGENT_CIVILIZATIONS_PER_PLANET 0.01
#define PROBABILITY_OF_INVASION_PER_CIVILIZATION 0.0001

// Calculate the probability of an alien invasion
double calculate_invasion_probability() {
  // Calculate the number of intelligent civilizations in the universe
  double num_civilizations = NUM_STARS * NUM_PLANETS_PER_STAR * NUM_INTELLIGENT_CIVILIZATIONS_PER_PLANET;

  // Calculate the probability of an alien invasion
  double invasion_probability = num_civilizations * PROBABILITY_OF_INVASION_PER_CIVILIZATION;

  // Return the invasion probability
  return invasion_probability;
}

// Print the invasion probability
void print_invasion_probability(double invasion_probability) {
  // Print the invasion probability as a percentage
  printf("The probability of an alien invasion is %.2f%%\n", invasion_probability * 100);
}

// Get user input
void get_user_input(int *num_stars, int *num_planets_per_star, double *num_intelligent_civilizations_per_planet, double *probability_of_invasion_per_civilization) {
  // Get the number of stars from the user
  printf("Enter the number of stars in the universe: ");
  scanf("%d", num_stars);

  // Get the number of planets per star from the user
  printf("Enter the number of planets per star: ");
  scanf("%d", num_planets_per_star);

  // Get the number of intelligent civilizations per planet from the user
  printf("Enter the number of intelligent civilizations per planet: ");
  scanf("%lf", num_intelligent_civilizations_per_planet);

  // Get the probability of invasion per civilization from the user
  printf("Enter the probability of invasion per civilization: ");
  scanf("%lf", probability_of_invasion_per_civilization);
}

// Main function
int main() {
  // Get user input
  int num_stars;
  int num_planets_per_star;
  double num_intelligent_civilizations_per_planet;
  double probability_of_invasion_per_civilization;
  get_user_input(&num_stars, &num_planets_per_star, &num_intelligent_civilizations_per_planet, &probability_of_invasion_per_civilization);

  // Calculate the invasion probability
  double invasion_probability = calculate_invasion_probability();

  // Print the invasion probability
  print_invasion_probability(invasion_probability);

  return 0;
}