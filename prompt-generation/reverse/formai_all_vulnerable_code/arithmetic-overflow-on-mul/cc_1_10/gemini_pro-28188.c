//GEMINI-pro DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Define the number of stars in the Milky Way galaxy
#define NUM_STARS 1000000000000

// Define the number of planets per star
#define NUM_PLANETS 10

// Define the probability of a planet being habitable
#define PROB_HABITABLE 0.1

// Define the probability of a habitable planet being inhabited
#define PROB_INHABITED 0.01

// Define the probability of an inhabited planet being technologically advanced
#define PROB_ADVANCED 0.001

// Define the probability of a technologically advanced planet being hostile
#define PROB_HOSTILE 0.0001

// Define the probability of a hostile planet invading Earth
#define PROB_INVASION 0.00001

// Define the number of iterations to perform
#define NUM_ITERATIONS 1000000

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Initialize the number of hostile planets
  int num_hostile = 0;

  // Perform the iterations
  for (int i = 0; i < NUM_ITERATIONS; i++) {
    // Generate a random number for the number of stars
    int num_stars = rand() % NUM_STARS;

    // Generate a random number for the number of planets per star
    int num_planets = rand() % NUM_PLANETS;

    // Calculate the number of habitable planets
    int num_habitable = num_stars * num_planets * PROB_HABITABLE;

    // Calculate the number of inhabited planets
    int num_inhabited = num_habitable * PROB_INHABITED;

    // Calculate the number of technologically advanced planets
    int num_advanced = num_inhabited * PROB_ADVANCED;

    // Calculate the number of hostile planets
    int num_hostile_tmp = num_advanced * PROB_HOSTILE;

    // Add the number of hostile planets to the total
    num_hostile += num_hostile_tmp;
  }

  // Calculate the probability of an invasion
  double prob_invasion = (double)num_hostile / (double)NUM_ITERATIONS;

  // Print the probability of an invasion
  printf("The probability of an alien invasion is: %f\n", prob_invasion);

  return 0;
}