//GEMINI-pro DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Calculate the probability of an alien invasion based on various factors.
double calculate_alien_invasion_probability(int num_stars_in_galaxy, double avg_num_planets_per_star, double percent_of_planets_with_life, double percent_of_life_forms_intelligent, double percent_of_intelligent_life_forms_technologically_advanced, double percent_of_technologically_advanced_life_forms_hostile) {
  // Calculate the number of planets in the galaxy.
  double num_planets_in_galaxy = num_stars_in_galaxy * avg_num_planets_per_star;

  // Calculate the number of planets with life.
  double num_planets_with_life = num_planets_in_galaxy * percent_of_planets_with_life;

  // Calculate the number of intelligent life forms.
  double num_intelligent_life_forms = num_planets_with_life * percent_of_life_forms_intelligent;

  // Calculate the number of technologically advanced life forms.
  double num_technologically_advanced_life_forms = num_intelligent_life_forms * percent_of_intelligent_life_forms_technologically_advanced;

  // Calculate the number of hostile life forms.
  double num_hostile_life_forms = num_technologically_advanced_life_forms * percent_of_technologically_advanced_life_forms_hostile;

  // Calculate the probability of an alien invasion.
  double alien_invasion_probability = num_hostile_life_forms / num_stars_in_galaxy;

  // Return the probability of an alien invasion.
  return alien_invasion_probability;
}

// Get the user input.
void get_user_input(int *num_stars_in_galaxy, double *avg_num_planets_per_star, double *percent_of_planets_with_life, double *percent_of_life_forms_intelligent, double *percent_of_intelligent_life_forms_technologically_advanced, double *percent_of_technologically_advanced_life_forms_hostile) {
  printf("Enter the number of stars in the galaxy: ");
  scanf("%d", num_stars_in_galaxy);

  printf("Enter the average number of planets per star: ");
  scanf("%lf", avg_num_planets_per_star);

  printf("Enter the percentage of planets with life: ");
  scanf("%lf", percent_of_planets_with_life);

  printf("Enter the percentage of life forms intelligent: ");
  scanf("%lf", percent_of_life_forms_intelligent);

  printf("Enter the percentage of intelligent life forms technologically advanced: ");
  scanf("%lf", percent_of_intelligent_life_forms_technologically_advanced);

  printf("Enter the percentage of technologically advanced life forms hostile: ");
  scanf("%lf", percent_of_technologically_advanced_life_forms_hostile);
}

// Print the results.
void print_results(double alien_invasion_probability) {
  printf("The probability of an alien invasion is: %.2f%%\n", alien_invasion_probability * 100);
}

// Main function.
int main() {
  // Get the user input.
  int num_stars_in_galaxy;
  double avg_num_planets_per_star;
  double percent_of_planets_with_life;
  double percent_of_life_forms_intelligent;
  double percent_of_intelligent_life_forms_technologically_advanced;
  double percent_of_technologically_advanced_life_forms_hostile;
  get_user_input(&num_stars_in_galaxy, &avg_num_planets_per_star, &percent_of_planets_with_life, &percent_of_life_forms_intelligent, &percent_of_intelligent_life_forms_technologically_advanced, &percent_of_technologically_advanced_life_forms_hostile);

  // Calculate the probability of an alien invasion.
  double alien_invasion_probability = calculate_alien_invasion_probability(num_stars_in_galaxy, avg_num_planets_per_star, percent_of_planets_with_life, percent_of_life_forms_intelligent, percent_of_intelligent_life_forms_technologically_advanced, percent_of_technologically_advanced_life_forms_hostile);

  // Print the results.
  print_results(alien_invasion_probability);

  return 0;
}