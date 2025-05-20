//GEMINI-pro DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Prototypes
int rollDice(int sides);
int getDistanceFromEarth(int maxDistance);
int getAlienPopulation(int maxPopulation);
int getAlienTechnologyLevel(int maxLevel);
int getAlienHostility(int maxHostility);
int calculateInvasionProbability(int distance, int population, int technology, int hostility);

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Get the user's input
  int maxDistance, maxPopulation, maxLevel, maxHostility;
  printf("Enter the maximum distance from Earth (in light years): ");
  scanf("%d", &maxDistance);
  printf("Enter the maximum alien population (in billions): ");
  scanf("%d", &maxPopulation);
  printf("Enter the maximum alien technology level (on a scale of 1 to 10): ");
  scanf("%d", &maxLevel);
  printf("Enter the maximum alien hostility (on a scale of 1 to 10): ");
  scanf("%d", &maxHostility);

  // Calculate the invasion probability
  int invasionProbability = calculateInvasionProbability(maxDistance, maxPopulation, maxLevel, maxHostility);

  // Print the results
  printf("The probability of an alien invasion is: %d%%\n", invasionProbability);

  return 0;
}

// Function to roll a dice
int rollDice(int sides) {
  return rand() % sides + 1;
}

// Function to get the distance from Earth
int getDistanceFromEarth(int maxDistance) {
  return rollDice(maxDistance);
}

// Function to get the alien population
int getAlienPopulation(int maxPopulation) {
  return rollDice(maxPopulation);
}

// Function to get the alien technology level
int getAlienTechnologyLevel(int maxLevel) {
  return rollDice(maxLevel);
}

// Function to get the alien hostility
int getAlienHostility(int maxHostility) {
  return rollDice(maxHostility);
}

// Function to calculate the invasion probability
int calculateInvasionProbability(int distance, int population, int technology, int hostility) {
  // Calculate the base invasion probability
  int baseProbability = 10;

  // Modify the base probability based on the distance
  if (distance <= 10) {
    baseProbability += 20;
  } else if (distance <= 25) {
    baseProbability += 10;
  } else if (distance <= 50) {
    baseProbability += 5;
  }

  // Modify the base probability based on the population
  if (population <= 1) {
    baseProbability -= 10;
  } else if (population <= 5) {
    baseProbability -= 5;
  } else if (population <= 10) {
    baseProbability += 5;
  } else if (population <= 25) {
    baseProbability += 10;
  } else if (population <= 50) {
    baseProbability += 20;
  }

  // Modify the base probability based on the technology
  if (technology <= 2) {
    baseProbability -= 10;
  } else if (technology <= 5) {
    baseProbability -= 5;
  } else if (technology <= 8) {
    baseProbability += 5;
  } else if (technology <= 10) {
    baseProbability += 10;
  }

  // Modify the base probability based on the hostility
  if (hostility <= 2) {
    baseProbability -= 10;
  } else if (hostility <= 5) {
    baseProbability -= 5;
  } else if (hostility <= 8) {
    baseProbability += 5;
  } else if (hostility <= 10) {
    baseProbability += 10;
  }

  // Return the final invasion probability
  return baseProbability;
}