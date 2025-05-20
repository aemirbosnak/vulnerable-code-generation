//GEMINI-pro DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// This function calculates the probability of an alien invasion based on the following factors:
//
// - The number of stars in the Milky Way galaxy
// - The number of planets orbiting each star
// - The number of planets that are habitable for life
// - The number of planets that have intelligent life
// - The number of planets that are hostile to life
//
// The function uses a Monte Carlo simulation to estimate the probability of an alien invasion.
//
// The input parameters are:
//
// - `num_stars`: The number of stars in the Milky Way galaxy
// - `num_planets_per_star`: The number of planets orbiting each star
// - `num_habitable_planets_per_star`: The number of planets that are habitable for life
// - `num_intelligent_planets_per_star`: The number of planets that have intelligent life
// - `num_hostile_planets_per_star`: The number of planets that are hostile to life
//
// The output of the function is the probability of an alien invasion.

double alien_invasion_probability(int num_stars, int num_planets_per_star, int num_habitable_planets_per_star, int num_intelligent_planets_per_star, int num_hostile_planets_per_star) {
  // Calculate the total number of planets in the Milky Way galaxy.

  int num_planets = num_stars * num_planets_per_star;

  // Calculate the total number of habitable planets in the Milky Way galaxy.

  int num_habitable_planets = num_planets * num_habitable_planets_per_star;

  // Calculate the total number of intelligent planets in the Milky Way galaxy.

  int num_intelligent_planets = num_habitable_planets * num_intelligent_planets_per_star;

  // Calculate the total number of hostile planets in the Milky Way galaxy.

  int num_hostile_planets = num_habitable_planets * num_hostile_planets_per_star;

  // Calculate the probability of an alien invasion.

  double probability = (double)num_hostile_planets / (double)num_intelligent_planets;

  return probability;
}

// This function prints the results of the alien invasion probability calculator.

void print_results(double probability) {
  printf("The probability of an alien invasion is %f%%\n", probability * 100);
}

// This is the main function.

int main() {
  // Set the input parameters.

  int num_stars = 1000000000;
  int num_planets_per_star = 10;
  int num_habitable_planets_per_star = 0.1;
  int num_intelligent_planets_per_star = 0.01;
  int num_hostile_planets_per_star = 0.001;

  // Calculate the probability of an alien invasion.

  double probability = alien_invasion_probability(num_stars, num_planets_per_star, num_habitable_planets_per_star, num_intelligent_planets_per_star, num_hostile_planets_per_star);

  // Print the results.

  print_results(probability);

  return 0;
}