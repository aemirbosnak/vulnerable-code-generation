//GEMINI-pro DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#define MAX_PLANETS 100

typedef struct {
  double probability;
  int num_planets;
  int* planets;
} AlienInvasion;

AlienInvasion* create_invasion(double probability, int num_planets, int* planets) {
  AlienInvasion* invasion = malloc(sizeof(AlienInvasion));
  invasion->probability = probability;
  invasion->num_planets = num_planets;
  invasion->planets = malloc(sizeof(int) * num_planets);
  for (int i = 0; i < num_planets; i++) {
    invasion->planets[i] = planets[i];
  }
  return invasion;
}

void free_invasion(AlienInvasion* invasion) {
  free(invasion->planets);
  free(invasion);
}

double calculate_invasion_probability(AlienInvasion* invasion) {
  if (invasion->num_planets == 0) {
    return 0.0;
  } else if (invasion->num_planets == 1) {
    return invasion->probability;
  } else {
    double probability = 0.0;
    for (int i = 0; i < invasion->num_planets; i++) {
      AlienInvasion* sub_invasion = create_invasion(invasion->probability, invasion->num_planets - 1, invasion->planets);
      for (int j = 0; j < invasion->num_planets; j++) {
        if (j != i) {
          sub_invasion->planets[j] = invasion->planets[j];
        }
      }
      probability += calculate_invasion_probability(sub_invasion) * invasion->probability;
      free_invasion(sub_invasion);
    }
    return probability;
  }
}

int main() {
  int num_planets;
  printf("Enter the number of planets: ");
  scanf("%d", &num_planets);

  int* planets = malloc(sizeof(int) * num_planets);
  printf("Enter the indices of the planets (0-indexed): ");
  for (int i = 0; i < num_planets; i++) {
    scanf("%d", &planets[i]);
  }

  double probability;
  printf("Enter the probability of an alien invasion: ");
  scanf("%lf", &probability);

  AlienInvasion* invasion = create_invasion(probability, num_planets, planets);
  double invasion_probability = calculate_invasion_probability(invasion);
  free_invasion(invasion);

  printf("The probability of an alien invasion is: %lf\n", invasion_probability);

  return 0;
}