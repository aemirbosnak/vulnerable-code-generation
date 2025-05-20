//GEMINI-pro DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLANETS 100
#define MAX_ALIENS 1000
#define MAX_STRINGS 100

typedef struct {
  char name[MAX_STRINGS];
  int population;
  int distance;
} Planet;

typedef struct {
  char name[MAX_STRINGS];
  int intelligence;
  int aggression;
} Alien;

int main() {
  // Initialize variables.
  int num_planets = 0;
  int num_aliens = 0;
  Planet planets[MAX_PLANETS];
  Alien aliens[MAX_ALIENS];

  // Read input.
  FILE *fp = fopen("input.txt", "r");
  if (fp == NULL) {
    perror("Error opening file");
    return EXIT_FAILURE;
  }
  fscanf(fp, "%d", &num_planets);
  for (int i = 0; i < num_planets; i++) {
    fscanf(fp, "%s %d %d", planets[i].name, &planets[i].population, &planets[i].distance);
  }
  fscanf(fp, "%d", &num_aliens);
  for (int i = 0; i < num_aliens; i++) {
    fscanf(fp, "%s %d %d", aliens[i].name, &aliens[i].intelligence, &aliens[i].aggression);
  }
  fclose(fp);

  // Calculate the probability of alien invasion.
  double probability = 0.0;
  for (int i = 0; i < num_planets; i++) {
    for (int j = 0; j < num_aliens; j++) {
      if (aliens[j].intelligence > planets[i].population) {
        probability += (double)aliens[j].aggression / 100.0;
      }
    }
  }

  // Print the result.
  printf("The probability of alien invasion is %.2f%%\n", probability * 100.0);

  return EXIT_SUCCESS;
}