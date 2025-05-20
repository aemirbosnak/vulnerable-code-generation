//GEMINI-pro DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Constants
#define MAX_STARS_PER_GALAXY 1000000000000
#define MAX_GALAXIES 1000000000
#define MIN_INTELLIGENT_LIFE_PERCENTAGE 0.01
#define MAX_INTELLIGENT_LIFE_PERCENTAGE 0.10
#define MIN_WARLIKE_LIFE_PERCENTAGE 0.01
#define MAX_WARLIKE_LIFE_PERCENTAGE 0.05
#define MIN_INVASION_SUCCESS_RATE 0.01
#define MAX_INVASION_SUCCESS_RATE 0.10

// Function prototypes
int get_random_number(int min, int max);
double get_random_double(double min, double max);
void calculate_alien_invasion_probability(int num_stars_per_galaxy, int num_galaxies, double intelligent_life_percentage, double warlike_life_percentage, double invasion_success_rate);

// Main function
int main() {
  // Set the random seed
  srand(time(NULL));

  // Get the user input
  int num_stars_per_galaxy = get_random_number(1000000000, 1000000000000);
  int num_galaxies = get_random_number(1000000000, 10000000000);
  double intelligent_life_percentage = get_random_double(0.01, 0.10);
  double warlike_life_percentage = get_random_double(0.01, 0.05);
  double invasion_success_rate = get_random_double(0.01, 0.10);

  // Calculate the alien invasion probability
  calculate_alien_invasion_probability(num_stars_per_galaxy, num_galaxies, intelligent_life_percentage, warlike_life_percentage, invasion_success_rate);

  return 0;
}

// Function to get a random number between a minimum and maximum value
int get_random_number(int min, int max) {
  return min + rand() % (max - min + 1);
}

// Function to get a random double between a minimum and maximum value
double get_random_double(double min, double max) {
  return min + ((double)rand() / RAND_MAX) * (max - min);
}

// Function to calculate the alien invasion probability
void calculate_alien_invasion_probability(int num_stars_per_galaxy, int num_galaxies, double intelligent_life_percentage, double warlike_life_percentage, double invasion_success_rate) {
  // Calculate the number of intelligent life-bearing planets
  int num_intelligent_life_planets = num_stars_per_galaxy * num_galaxies * intelligent_life_percentage;

  // Calculate the number of warlike life-bearing planets
  int num_warlike_life_planets = num_intelligent_life_planets * warlike_life_percentage;

  // Calculate the alien invasion probability
  double alien_invasion_probability = num_warlike_life_planets * invasion_success_rate;

  // Print the alien invasion probability
  printf("The alien invasion probability is %f\n", alien_invasion_probability);
}