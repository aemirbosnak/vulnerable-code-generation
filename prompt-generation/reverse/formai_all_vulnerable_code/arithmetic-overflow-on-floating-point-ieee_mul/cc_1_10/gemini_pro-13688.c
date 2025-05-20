//GEMINI-pro DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Initialize the random number generator
void init_random() {
  srand(time(NULL));
}

// Generate a random number between 0 and 1
double rand_double() {
  return (double)rand() / (double)RAND_MAX;
}

// Calculate the probability of an alien invasion
double calc_invasion_prob(int num_planets, double avg_tech_level, double avg_aggression) {
  double prob = 0.0;
  for (int i = 0; i < num_planets; i++) {
    // Calculate the probability of invasion for each planet
    double planet_prob = rand_double() * avg_tech_level * avg_aggression;

    // Add the planet's probability to the total probability
    prob += planet_prob;
  }

  // Return the total probability of invasion
  return prob;
}

// Print the results of the calculation
void print_results(double prob) {
  printf("The probability of an alien invasion is: %.2f%%\n", prob * 100.0);
  if (prob > 0.5) {
    printf("WARNING: The probability of an alien invasion is high!\n");
  } else {
    printf("GOOD NEWS: The probability of an alien invasion is low!\n");
  }
}

int main() {
  // Initialize the random number generator
  init_random();

  // Get the number of planets from the user
  int num_planets;
  printf("Enter the number of planets in the galaxy: ");
  scanf("%d", &num_planets);

  // Get the average technology level from the user
  double avg_tech_level;
  printf("Enter the average technology level of the planets (0-10): ");
  scanf("%lf", &avg_tech_level);

  // Get the average aggression level from the user
  double avg_aggression;
  printf("Enter the average aggression level of the planets (0-10): ");
  scanf("%lf", &avg_aggression);

  // Calculate the probability of an alien invasion
  double prob = calc_invasion_prob(num_planets, avg_tech_level, avg_aggression);

  // Print the results of the calculation
  print_results(prob);

  return 0;
}