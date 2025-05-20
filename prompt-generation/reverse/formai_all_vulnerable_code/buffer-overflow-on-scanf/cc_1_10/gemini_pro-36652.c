//GEMINI-pro DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

#define MAX_DISTANCE 1000000000
#define MAX_SPEED 1000000
#define MAX_TIME 1000000

struct AlienSpaceship {
  int id;
  double distance;
  double speed;
  double time;
};

struct AlienInvasionScenario {
  int num_spaceships;
  struct AlienSpaceship *spaceships;
};

double calculate_probability(struct AlienInvasionScenario *scenario) {
  double total_probability = 1.0;
  for (int i = 0; i < scenario->num_spaceships; i++) {
    double probability = 1.0;
    if (scenario->spaceships[i].distance > MAX_DISTANCE) {
      probability = 0.0;
    } else {
      probability *= exp(-(scenario->spaceships[i].distance / MAX_DISTANCE));
    }
    if (scenario->spaceships[i].speed > MAX_SPEED) {
      probability = 0.0;
    } else {
      probability *= exp(-(scenario->spaceships[i].speed / MAX_SPEED));
    }
    if (scenario->spaceships[i].time > MAX_TIME) {
      probability = 0.0;
    } else {
      probability *= exp(-(scenario->spaceships[i].time / MAX_TIME));
    }
    total_probability *= probability;
  }
  return total_probability;
}

int main() {
  int num_spaceships;
  scanf("%d", &num_spaceships);

  struct AlienInvasionScenario scenario;
  scenario.num_spaceships = num_spaceships;
  scenario.spaceships = malloc(sizeof(struct AlienSpaceship) * num_spaceships);

  for (int i = 0; i < num_spaceships; i++) {
    scanf("%d %lf %lf %lf", &scenario.spaceships[i].id, &scenario.spaceships[i].distance,
          &scenario.spaceships[i].speed, &scenario.spaceships[i].time);
  }

  double probability = calculate_probability(&scenario);
  printf("%lf\n", probability);

  return 0;
}