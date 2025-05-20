//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: light-weight
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// function prototype
bool invasionProbability();

// main function
int main() {

  // setting the seed for random number generation
  srand(time(0));

  // variables to store user input
  int planets,deaths,civilizations;

  printf("Welcome to the Alien Invasion Probability Calculator\n");

  printf("Please enter the number of planets in the galaxy: ");
  scanf("%d", &planets);

  printf("Please enter the number of civilizations in the galaxy: ");
  scanf("%d", &civilizations);

  printf("Please enter the number of deaths caused by alien invasions in the galaxy: ");
  scanf("%d", &deaths);

  // calculate the percentage of civilizations that have experienced alien invasions
  float invasions = (float) deaths / civilizations * 100;

  printf("According to our data, %.2f%% of civilizations in the galaxy have experienced alien invasions.\n\n", invasions);

  // calculate the probability of an alien invasion
  if (invasionProbability())
    printf("Based on current conditions, there is a HIGH probability of an alien invasion.\n");
  else
    printf("Based on current conditions, there is a LOW probability of an alien invasion.\n");

  return 0;
}

// function definition
bool invasionProbability() {

  // generate a random number between 1 and 100
  int num = (rand() % 100) + 1;

  // return true if the number is less than or equal to 50
  if (num <= 50)
    return true;
  else
    return false;
}