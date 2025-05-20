//GEMINI-pro DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Calculate the probability of an alien invasion based on various factors.

int main() {
  // Initialize the random number generator.
  srand(time(NULL));

  // Get the user's input.
  int age;
  printf("What is your age? ");
  scanf("%d", &age);

  char gender;
  printf("What is your gender? (m/f) ");
  scanf(" %c", &gender);

  char location;
  printf("Where do you live? (u/r) ");
  scanf(" %c", &location);

  // Calculate the probability of an alien invasion.
  double probability = 0.0;

  // Age factor.
  if (age < 18) {
    probability += 0.1;
  } else if (age >= 18 && age < 30) {
    probability += 0.2;
  } else if (age >= 30 && age < 45) {
    probability += 0.3;
  } else {
    probability += 0.4;
  }

  // Gender factor.
  if (gender == 'm') {
    probability += 0.1;
  } else if (gender == 'f') {
    probability += 0.2;
  }

  // Location factor.
  if (location == 'u') {
    probability += 0.1;
  } else if (location == 'r') {
    probability += 0.2;
  }

  // Random factor.
  probability += (double)rand() / (double)RAND_MAX * 0.3;

  // Print the probability.
  printf("The probability of an alien invasion is %.2f%%\n", probability * 100);
  char a, b;
  printf("Do you want to know more about aliens? (y/n) ");
  scanf(" %c", &a);
  if (a == 'y') {
    printf("They are coming...\n");
  } else {
    printf("Good choice. Ignorance is bliss.\n");
  }
  printf("Do you want to be abducted? (y/n) ");
  scanf(" %c", &b);
  if (b == 'y') {
    printf("Prepare for the probing.\n");
  } else {
    printf("Wise choice. Stay hidden.\n");
  }
  return 0;
}