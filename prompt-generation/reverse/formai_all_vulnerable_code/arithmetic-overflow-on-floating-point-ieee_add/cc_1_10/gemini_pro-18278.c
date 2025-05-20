//GEMINI-pro DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the probability of an alien invasion as a function of several variables.
double alien_invasion_probability(double distance_to_earth, double alien_technology_level, double human_technology_level, double alien_aggression_level) {
  // Calculate the probability of an alien invasion based on the given variables.
  double probability = 1 / (1 + exp(-(distance_to_earth + alien_technology_level - human_technology_level + alien_aggression_level)));

  // Return the probability of an alien invasion.
  return probability;
}

// Get the distance to Earth from the user.
double get_distance_to_earth() {
  // Prompt the user to enter the distance to Earth.
  printf("Enter the distance to Earth in light years: ");

  // Get the distance to Earth from the user.
  double distance_to_earth;
  scanf("%lf", &distance_to_earth);

  // Return the distance to Earth.
  return distance_to_earth;
}

// Get the alien technology level from the user.
double get_alien_technology_level() {
  // Prompt the user to enter the alien technology level.
  printf("Enter the alien technology level on a scale of 1 to 10: ");

  // Get the alien technology level from the user.
  double alien_technology_level;
  scanf("%lf", &alien_technology_level);

  // Return the alien technology level.
  return alien_technology_level;
}

// Get the human technology level from the user.
double get_human_technology_level() {
  // Prompt the user to enter the human technology level.
  printf("Enter the human technology level on a scale of 1 to 10: ");

  // Get the human technology level from the user.
  double human_technology_level;
  scanf("%lf", &human_technology_level);

  // Return the human technology level.
  return human_technology_level;
}

// Get the alien aggression level from the user.
double get_alien_aggression_level() {
  // Prompt the user to enter the alien aggression level.
  printf("Enter the alien aggression level on a scale of 1 to 10: ");

  // Get the alien aggression level from the user.
  double alien_aggression_level;
  scanf("%lf", &alien_aggression_level);

  // Return the alien aggression level.
  return alien_aggression_level;
}

// Main function.
int main() {
  // Get the distance to Earth from the user.
  double distance_to_earth = get_distance_to_earth();

  // Get the alien technology level from the user.
  double alien_technology_level = get_alien_technology_level();

  // Get the human technology level from the user.
  double human_technology_level = get_human_technology_level();

  // Get the alien aggression level from the user.
  double alien_aggression_level = get_alien_aggression_level();

  // Calculate the probability of an alien invasion.
  double probability = alien_invasion_probability(distance_to_earth, alien_technology_level, human_technology_level, alien_aggression_level);

  // Print the probability of an alien invasion.
  printf("The probability of an alien invasion is: %lf\n", probability);

  // Return 0 to indicate success.
  return 0;
}