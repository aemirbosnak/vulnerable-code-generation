//GEMINI-pro DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_PLANETS 100

typedef struct {
  double x;
  double y;
  double z;
} planet_t;

typedef struct {
  int num_planets;
  planet_t planets[MAX_PLANETS];
} galaxy_t;

double distance(planet_t p1, planet_t p2) {
  double dx = p1.x - p2.x;
  double dy = p1.y - p2.y;
  double dz = p1.z - p2.z;
  return sqrt(dx * dx + dy * dy + dz * dz);
}

double probability(galaxy_t galaxy) {
  double total_distance = 0;
  for (int i = 0; i < galaxy.num_planets; i++) {
    for (int j = i + 1; j < galaxy.num_planets; j++) {
      total_distance += distance(galaxy.planets[i], galaxy.planets[j]);
    }
  }

  double average_distance = total_distance / (galaxy.num_planets * (galaxy.num_planets - 1) / 2);
  double probability = 1 / (average_distance * average_distance);
  return probability;
}

int main() {
  int num_galaxies;
  scanf("%d", &num_galaxies);

  for (int i = 0; i < num_galaxies; i++) {
    galaxy_t galaxy;
    scanf("%d", &galaxy.num_planets);

    for (int j = 0; j < galaxy.num_planets; j++) {
      scanf("%lf %lf %lf", &galaxy.planets[j].x, &galaxy.planets[j].y, &galaxy.planets[j].z);
    }

    double prob = probability(galaxy);
    printf("%.9lf\n", prob);
  }

  return 0;
}