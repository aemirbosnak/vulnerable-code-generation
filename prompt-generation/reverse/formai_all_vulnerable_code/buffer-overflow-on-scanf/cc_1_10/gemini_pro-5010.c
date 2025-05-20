//GEMINI-pro DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the probability of an alien invasion
double alienInvasionProbability(int numStars, int numPlanets, int numIntelligentSpecies, int numSpacefaringSpecies) {
  // Calculate the probability of a star having a planet
  double probStarHasPlanet = 0.5;

  // Calculate the probability of a planet having intelligent life
  double probPlanetHasIntelligentLife = 0.1;

  // Calculate the probability of an intelligent species becoming spacefaring
  double probIntelligentSpeciesBecomesSpacefaring = 0.01;

  // Calculate the probability of an alien invasion
  double probAlienInvasion = probStarHasPlanet * probPlanetHasIntelligentLife * probIntelligentSpeciesBecomesSpacefaring * numStars * numPlanets * numIntelligentSpecies * numSpacefaringSpecies;

  return probAlienInvasion;
}

int main() {
  // Get the number of stars in the universe
  int numStars;
  printf("Enter the number of stars in the universe: ");
  scanf("%d", &numStars);

  // Get the number of planets per star
  int numPlanets;
  printf("Enter the average number of planets per star: ");
  scanf("%d", &numPlanets);

  // Get the number of intelligent species per planet
  int numIntelligentSpecies;
  printf("Enter the average number of intelligent species per planet: ");
  scanf("%d", &numIntelligentSpecies);

  // Get the number of spacefaring species per intelligent species
  int numSpacefaringSpecies;
  printf("Enter the average number of spacefaring species per intelligent species: ");
  scanf("%d", &numSpacefaringSpecies);

  // Calculate the probability of an alien invasion
  double probAlienInvasion = alienInvasionProbability(numStars, numPlanets, numIntelligentSpecies, numSpacefaringSpecies);

  // Print the probability of an alien invasion
  printf("The probability of an alien invasion is: %f\n", probAlienInvasion);

  return 0;
}