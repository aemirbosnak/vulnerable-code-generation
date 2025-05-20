//GEMINI-pro DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Constants
#define MAX_PLANETS 100
#define MAX_STARS 1000
#define MAX_GALAXIES 10000

// Probability calculations
double calculate_planet_probability(int num_planets, int num_stars, int num_galaxies);
double calculate_star_probability(int num_stars, int num_galaxies);
double calculate_galaxy_probability(int num_galaxies);

// Input and output functions
void get_input(int *num_planets, int *num_stars, int *num_galaxies);
void print_results(double planet_probability, double star_probability, double galaxy_probability);

int main() {
  // Declare variables
  int num_planets, num_stars, num_galaxies;
  double planet_probability, star_probability, galaxy_probability;

  // Get input
  get_input(&num_planets, &num_stars, &num_galaxies);

  // Calculate probabilities
  planet_probability = calculate_planet_probability(num_planets, num_stars, num_galaxies);
  star_probability = calculate_star_probability(num_stars, num_galaxies);
  galaxy_probability = calculate_galaxy_probability(num_galaxies);

  // Print results
  print_results(planet_probability, star_probability, galaxy_probability);

  return 0;
}

// Calculate the probability of an alien invasion based on the number of planets, stars, and galaxies
double calculate_planet_probability(int num_planets, int num_stars, int num_galaxies) {
  // Calculate the probability of an alien invasion on a single planet
  double planet_probability = 1 / (double)num_planets;

  // Calculate the probability of an alien invasion on a single star
  double star_probability = calculate_star_probability(num_stars, num_galaxies);

  // Calculate the probability of an alien invasion on a single galaxy
  double galaxy_probability = calculate_galaxy_probability(num_galaxies);

  // Calculate the probability of an alien invasion on at least one planet
  double probability = 1 - (1 - planet_probability) * (1 - star_probability) * (1 - galaxy_probability);

  return probability;
}

// Calculate the probability of an alien invasion on a star
double calculate_star_probability(int num_stars, int num_galaxies) {
  // Calculate the probability of an alien invasion on a single star
  double star_probability = 1 / (double)num_stars;

  // Calculate the probability of an alien invasion on a single galaxy
  double galaxy_probability = calculate_galaxy_probability(num_galaxies);

  // Calculate the probability of an alien invasion on at least one star
  double probability = 1 - (1 - star_probability) * (1 - galaxy_probability);

  return probability;
}

// Calculate the probability of an alien invasion on a galaxy
double calculate_galaxy_probability(int num_galaxies) {
  // Calculate the probability of an alien invasion on a single galaxy
  double galaxy_probability = 1 / (double)num_galaxies;

  // Calculate the probability of an alien invasion on at least one galaxy
  double probability = 1 - (1 - galaxy_probability);

  return probability;
}

// Get input from the user
void get_input(int *num_planets, int *num_stars, int *num_galaxies) {
  printf("Enter the number of planets: ");
  scanf("%d", num_planets);

  printf("Enter the number of stars: ");
  scanf("%d", num_stars);

  printf("Enter the number of galaxies: ");
  scanf("%d", num_galaxies);
}

// Print the results
void print_results(double planet_probability, double star_probability, double galaxy_probability) {
  printf("The probability of an alien invasion on a planet is: %.2f%%\n", planet_probability * 100);
  printf("The probability of an alien invasion on a star is: %.2f%%\n", star_probability * 100);
  printf("The probability of an alien invasion on a galaxy is: %.2f%%\n", galaxy_probability * 100);
}