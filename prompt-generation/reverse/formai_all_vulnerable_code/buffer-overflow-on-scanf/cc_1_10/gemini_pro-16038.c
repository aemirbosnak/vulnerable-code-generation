//GEMINI-pro DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Cyberpunk
// Alien Invasion Probability Calculator in Cyberpunk Style

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Cyberpunk-style vocabulary
#define INVASION_CHANCE "Threat Level"
#define EARTH_DEFENSES "Firewall"
#define ALIEN_TECHNOLOGY "Cyberware"
#define HUMAN_RESISTANCE "Hackerspace"
#define SIMULATION_RUNS "Iterations"

// Function to calculate the probability of an alien invasion
int calculate_invasion_chance(int earth_defenses, int alien_technology, int human_resistance) {
  // Initialize the random number generator
  srand(time(NULL));

  // Calculate the invasion chance based on the given parameters
  int invasion_chance = (earth_defenses * 100) / (alien_technology * human_resistance);

  // Return the invasion chance
  return invasion_chance;
}

// Main function
int main() {
  // Cyberpunk-style introduction
  printf("Greetings, runner. Welcome to the Alien Invasion Probability Calculator.\n");
  printf("Let's jack into the Matrix and analyze the threat level.\n");

  // Get the user input
  int earth_defenses, alien_technology, human_resistance, simulation_runs;
  printf("Enter the strength of Earth's Firewall: ");
  scanf("%d", &earth_defenses);
  printf("Enter the level of Alien Cyberware: ");
  scanf("%d", &alien_technology);
  printf("Enter the proficiency of the Hackerspace: ");
  scanf("%d", &human_resistance);
  printf("Enter the number of Iterations: ");
  scanf("%d", &simulation_runs);

  // Run the simulation multiple times to get a more accurate result
  int total_invasion_chance = 0;
  for (int i = 0; i < simulation_runs; i++) {
    total_invasion_chance += calculate_invasion_chance(earth_defenses, alien_technology, human_resistance);
  }

  // Calculate the average invasion chance
  int average_invasion_chance = total_invasion_chance / simulation_runs;

  // Cyberpunk-style output
  printf("\n");
  printf("===========================================================\n");
  printf("**Alien Invasion Probability Report**\n");
  printf("===========================================================\n");
  printf("Earth's Firewall: %d\n", earth_defenses);
  printf("Alien Cyberware: %d\n", alien_technology);
  printf("Hackerspace Proficiency: %d\n", human_resistance);
  printf("Iterations: %d\n", simulation_runs);
  printf("-----------------------------------------------------------\n");
  printf("**Threat Level:** %d%%\n", average_invasion_chance);
  printf("===========================================================\n");

  // Cyberpunk-style conclusion
  if (average_invasion_chance <= 25) {
    printf("The matrix is in your favor, runner. Earth's defenses are holding strong.\n");
  } else if (average_invasion_chance <= 50) {
    printf("The situation is fluid. Reinforce the Firewall and upgrade your Cyberware.\n");
  } else if (average_invasion_chance <= 75) {
    printf("Prepare for a breach. Contact the Hackerspace and mobilize the resistance.\n");
  } else {
    printf("The Matrix is under siege. Brace yourself for the inevitable.\n");
  }

  return 0;
}