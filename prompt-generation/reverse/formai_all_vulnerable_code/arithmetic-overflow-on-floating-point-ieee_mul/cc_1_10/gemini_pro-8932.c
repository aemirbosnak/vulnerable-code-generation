//GEMINI-pro DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// The Drake Equation, used to calculate the probability of extraterrestrial life.
double drake(double stars, double planets, double life, double intelligence, double communication, double detection) {
  return stars * planets * life * intelligence * communication * detection;
}

// A function to generate a random number between 0 and 1.
double rand01() {
  return (double)rand() / (double)RAND_MAX;
}

// The main function.
int main() {
  // Seed the random number generator.
  srand(time(NULL));

  // Get the user's input.
  double stars;
  printf("Enter the number of stars in the galaxy: ");
  scanf("%lf", &stars);

  double planets;
  printf("Enter the average number of planets per star: ");
  scanf("%lf", &planets);

  double life;
  printf("Enter the fraction of planets that support life: ");
  scanf("%lf", &life);

  double intelligence;
  printf("Enter the fraction of planets with life that develop intelligence: ");
  scanf("%lf", &intelligence);

  double communication;
  printf("Enter the fraction of intelligent planets that develop communication technology: ");
  scanf("%lf", &communication);

  double detection;
  printf("Enter the fraction of communicating planets that we can detect: ");
  scanf("%lf", &detection);

  // Calculate the probability of extraterrestrial life.
  double probability = drake(stars, planets, life, intelligence, communication, detection);

  // Print the result.
  printf("The probability of extraterrestrial life is: %lf\n", probability);

  // Check if the probability is greater than 0.
  if (probability > 0) {
    // If the probability is greater than 0, then we should be prepared for an alien invasion.
    printf("We should be prepared for an alien invasion!\n");
  } else {
    // If the probability is 0, then we can rest easy.
    printf("We can rest easy, there is no chance of an alien invasion.\n");
  }

  return 0;
}