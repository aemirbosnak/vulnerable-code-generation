//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIALS 1000
#define MAX_DIMENSIONS 10

int main() {
  int num_dimensions;
  int num_trials;
  int num_successes = 0;
  double *lower_bounds;
  double *upper_bounds;
  double *point;
  double volume = 1.0;

  printf("Welcome to the Alien Invasion Probability Calculator!\n");
  printf("Please enter the number of dimensions you wish to consider: ");
  scanf("%d", &num_dimensions);
  printf("Please enter the number of trials you wish to run: ");
  scanf("%d", &num_trials);

  lower_bounds = malloc(num_dimensions * sizeof(double));
  upper_bounds = malloc(num_dimensions * sizeof(double));
  point = malloc(num_dimensions * sizeof(double));

  printf("Please enter the lower bounds for each dimension:\n");
  for (int i = 0; i < num_dimensions; i++) {
    scanf("%lf", &lower_bounds[i]);
  }

  printf("Please enter the upper bounds for each dimension:\n");
  for (int i = 0; i < num_dimensions; i++) {
    scanf("%lf", &upper_bounds[i]);
  }

  for (int i = 0; i < num_trials; i++) {
    printf("Trial %d:\n", i + 1);
    for (int j = 0; j < num_dimensions; j++) {
      point[j] = rand() % 100 / 100.0; // Generate a random number between 0 and 1
    }

    for (int j = 0; j < num_dimensions; j++) {
      if (point[j] < lower_bounds[j] || point[j] > upper_bounds[j]) {
        printf("Alien invasion detected in dimension %d!\n", j + 1);
        num_successes++;
        break;
      }
    }
  }

  printf("\nOut of %d trials, %d alien invasions were detected.\n", num_trials, num_successes);
  printf("The probability of an alien invasion is %.2f%%.\n", (double)num_successes / num_trials * 100.0);

  return 0;
}