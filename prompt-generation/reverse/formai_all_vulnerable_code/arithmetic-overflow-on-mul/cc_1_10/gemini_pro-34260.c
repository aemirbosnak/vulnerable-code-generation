//GEMINI-pro DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declare function prototypes
double calculateProbability(int numGalaxies, int numStars, int numPlanets, int numHabitablePlanets, int numIntelligentSpecies, int numSpeciesInvaded);
void printProbability(double probability);

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Get the number of galaxies in the universe
  int numGalaxies;
  printf("Enter the number of galaxies in the universe: ");
  scanf("%d", &numGalaxies);

  // Get the number of stars in each galaxy
  int numStars;
  printf("Enter the number of stars in each galaxy: ");
  scanf("%d", &numStars);

  // Get the number of planets around each star
  int numPlanets;
  printf("Enter the number of planets around each star: ");
  scanf("%d", &numPlanets);

  // Get the number of habitable planets around each star
  int numHabitablePlanets;
  printf("Enter the number of habitable planets around each star: ");
  scanf("%d", &numHabitablePlanets);

  // Get the number of intelligent species on each habitable planet
  int numIntelligentSpecies;
  printf("Enter the number of intelligent species on each habitable planet: ");
  scanf("%d", &numIntelligentSpecies);

  // Get the number of species that have invaded Earth
  int numSpeciesInvaded;
  printf("Enter the number of species that have invaded Earth: ");
  scanf("%d", &numSpeciesInvaded);

  // Calculate the probability of an alien invasion
  double probability = calculateProbability(numGalaxies, numStars, numPlanets, numHabitablePlanets, numIntelligentSpecies, numSpeciesInvaded);

  // Print the probability
  printProbability(probability);

  return 0;
}

// Calculate the probability of an alien invasion
double calculateProbability(int numGalaxies, int numStars, int numPlanets, int numHabitablePlanets, int numIntelligentSpecies, int numSpeciesInvaded) {
  // Calculate the number of habitable planets in the universe
  double numHabitablePlanetsInUniverse = numGalaxies * numStars * numPlanets * numHabitablePlanets;

  // Calculate the number of intelligent species in the universe
  double numIntelligentSpeciesInUniverse = numHabitablePlanetsInUniverse * numIntelligentSpecies;

  // Calculate the number of species that have invaded Earth
  double numSpeciesInvadedUniverse = numIntelligentSpeciesInUniverse * numSpeciesInvaded;

  // Calculate the probability of an alien invasion
  double probability = numSpeciesInvadedUniverse / numIntelligentSpeciesInUniverse;

  return probability;
}

// Print the probability
void printProbability(double probability) {
  printf("The probability of an alien invasion is: %.2f%%\n", probability * 100);
}