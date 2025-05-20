//GEMINI-pro DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the probability of an alien invasion
double alienInvasionProbability(int numStars, int numPlanets, int numIntelligentSpecies, int numHostileSpecies, int numInvadingSpecies) {
  // Calculate the probability of finding an intelligent species
  double probIntelligentSpecies = numIntelligentSpecies / numPlanets;

  // Calculate the probability of finding a hostile species
  double probHostileSpecies = numHostileSpecies / numIntelligentSpecies;

  // Calculate the probability of finding an invading species
  double probInvadingSpecies = numInvadingSpecies / numHostileSpecies;

  // Calculate the probability of an alien invasion
  double probAlienInvasion = probIntelligentSpecies * probHostileSpecies * probInvadingSpecies;

  return probAlienInvasion;
}

int main() {
  // Get the number of stars in the universe
  int numStars;
  printf("Enter the number of stars in the universe: ");
  scanf("%d", &numStars);

  // Get the number of planets in the universe
  int numPlanets;
  printf("Enter the number of planets in the universe: ");
  scanf("%d", &numPlanets);

  // Get the number of intelligent species in the universe
  int numIntelligentSpecies;
  printf("Enter the number of intelligent species in the universe: ");
  scanf("%d", &numIntelligentSpecies);

  // Get the number of hostile species in the universe
  int numHostileSpecies;
  printf("Enter the number of hostile species in the universe: ");
  scanf("%d", &numHostileSpecies);

  // Get the number of invading species in the universe
  int numInvadingSpecies;
  printf("Enter the number of invading species in the universe: ");
  scanf("%d", &numInvadingSpecies);

  // Calculate the probability of an alien invasion
  double probAlienInvasion = alienInvasionProbability(numStars, numPlanets, numIntelligentSpecies, numHostileSpecies, numInvadingSpecies);

  // Print the probability of an alien invasion
  printf("The probability of an alien invasion is: %f\n", probAlienInvasion);

  return 0;
}