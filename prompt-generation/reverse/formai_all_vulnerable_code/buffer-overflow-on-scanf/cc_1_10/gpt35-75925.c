//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int prob = 0;
  float rand_num = 0.0;

  srand(time(0)); // Seed the random number generator with the current time

  printf("Welcome to the Alien Invasion Probability Calculator!\n\n");

  // Get user input for initial parameters
  int num_days = 0;
  printf("Enter the number of days you expect to wait for the aliens to arrive: ");
  scanf("%d", &num_days);

  int num_cities = 0;
  printf("Enter the number of cities that you think will be affected: ");
  scanf("%d", &num_cities);

  int num_people = 0;
  printf("Enter the estimated number of people in each affected city: ");
  scanf("%d", &num_people);

  printf("\nCalculating alien invasion probability...\n\n");

  // Loop through each day
  for (int i = 1; i <= num_days; i++) {
    // Loop through each impacted city
    for (int j = 1; j <= num_cities; j++) {
      // Loop through each person in the city
      for (int k = 1; k <= num_people; k++) {
        rand_num = (float)rand() / RAND_MAX; // Generate a random number between 0 and 1
        if (rand_num <= 0.00001) { // 1 in 10,000 chance of an alien invasion
          prob = 1; // Set probability to 1 if an invasion occurs
        }
      }
    }
  }

  // Print final probability
  if (prob == 1) {
    printf("Alien invasion probability: HIGH\n");
  } else {
    printf("Alien invasion probability: LOW\n");
  }

  return 0;
}