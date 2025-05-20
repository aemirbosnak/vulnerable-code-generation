//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define POPULATION 1000000 // total number of people
#define INFECTION_RATE 0.08 // chance of infection
#define PROTECTION_RATE 0.05 // chance of protection

int main() {
  srand(time(0)); // seed for random number generator
  
  int infected = 0, protected = 0, invaded = 0;

  printf("Alien Invasion Probability Calculator\n");
  printf("=====================================\n");

  // get user input
  printf("Enter the number of people infected: ");
  scanf("%d", &infected);
  printf("Enter the number of people protected: ");
  scanf("%d", &protected);

  // calculate the number of vulnerable people
  int vulnerable = POPULATION - (infected + protected);

  // calculate the probability of an alien invasion
  float invasion_probability = 1 - (protected * PROTECTION_RATE + vulnerable * INFECTION_RATE);

  // randomly simulate an invasion
  float invasion_attempt = (float) rand() / RAND_MAX;
  if (invasion_attempt < invasion_probability) {
    invaded = 1;
  }

  // output results
  printf("\nResults\n");
  printf("=======\n");
  printf("Number of People:\n");
  printf(" Infected: %d\n", infected);
  printf(" Protected: %d\n", protected);
  printf(" Vulnerable: %d\n", vulnerable);
  printf("Probability of Alien Invasion: %.2f%%\n", invasion_probability * 100);

  if (invaded) {
    printf("ALIEN INVASION DETECTED!\n");
  } else {
    printf("No alien invasion detected.\n");
  }

  return 0;
}