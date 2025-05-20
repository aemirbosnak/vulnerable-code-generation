//Code Llama-13B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: romantic
/*
 * Alien Invasion Probability Calculator
 *
 * Calculates the probability of an alien invasion based on user input.
 *
 * Input:
 *   - Number of planets in the galaxy
 *   - Number of civilizations in the galaxy
 *   - Probability of each civilization having an alien
 *   - Probability of an alien civilization being hostile
 *
 * Output:
 *   - Probability of an alien invasion
 */

#include <stdio.h>
#include <stdlib.h>

// Prototypes
void get_input(int *num_planets, int *num_civilizations, double *prob_civilization, double *prob_hostile);
double calculate_probability(int num_planets, int num_civilizations, double prob_civilization, double prob_hostile);

// Main function
int main() {
  // Declare variables
  int num_planets, num_civilizations;
  double prob_civilization, prob_hostile;

  // Get user input
  get_input(&num_planets, &num_civilizations, &prob_civilization, &prob_hostile);

  // Calculate probability of alien invasion
  double prob_invasion = calculate_probability(num_planets, num_civilizations, prob_civilization, prob_hostile);

  // Print result
  printf("Probability of alien invasion: %.2f%%\n", prob_invasion);

  return 0;
}

// Function to get user input
void get_input(int *num_planets, int *num_civilizations, double *prob_civilization, double *prob_hostile) {
  printf("Enter the number of planets in the galaxy: ");
  scanf("%d", num_planets);

  printf("Enter the number of civilizations in the galaxy: ");
  scanf("%d", num_civilizations);

  printf("Enter the probability of each civilization having an alien: ");
  scanf("%lf", prob_civilization);

  printf("Enter the probability of an alien civilization being hostile: ");
  scanf("%lf", prob_hostile);
}

// Function to calculate probability of alien invasion
double calculate_probability(int num_planets, int num_civilizations, double prob_civilization, double prob_hostile) {
  double total_prob = 0.0;

  for (int i = 0; i < num_planets; i++) {
    total_prob += (prob_civilization / num_civilizations) * prob_hostile;
  }

  return total_prob * 100;
}