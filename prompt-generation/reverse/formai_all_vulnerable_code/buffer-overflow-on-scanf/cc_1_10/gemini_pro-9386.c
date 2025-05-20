//GEMINI-pro DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // Initialize random seed

  // Define constants
  const int MAX_ALIEN_SHIPS = 100;
  const int MAX_EARTH_DEFENSE_SHIPS = 50;

  // Get user input
  printf("Welcome to the Alien Invasion Probability Calculator! 👽\n\n");
  printf("Please enter the following information:\n");
  int numAlienShips;
  printf("Number of alien ships: ");
  scanf("%d", &numAlienShips);
  int numEarthDefenseShips;
  printf("Number of Earth defense ships: ");
  scanf("%d", &numEarthDefenseShips);

  // Validate user input
  if (numAlienShips <= 0) {
    printf("Error: Invalid number of alien ships. Must be greater than 0.\n");
    return 1;
  } else if (numEarthDefenseShips <= 0) {
    printf("Error: Invalid number of Earth defense ships. Must be greater than 0.\n");
    return 1;
  }

  // Calculate probability of alien invasion
  double probability = 0.0;
  if (numAlienShips > numEarthDefenseShips) {
    probability = 1.0; // Aliens win!
  } else {
    // Use binomial distribution to calculate probability
    for (int i = 0; i <= numAlienShips; i++) {
      double term = (double)numAlienShips * i / (numEarthDefenseShips + i);
      probability += (pow(0.5, numAlienShips + numEarthDefenseShips) / (2 * i + 1)) * term;
    }
  }

  // Display results
  printf("\n*** Results ***\n");
  printf("Probability of alien invasion: %.2f%%\n", probability * 100);

  // Cheer up the user if aliens will invade
  if (probability == 1.0) {
    printf("\nDon't worry! We have a secret weapon: hope! 🌈");
  }

  printf("\nThanks for playing! 🚀");
  return 0;
}