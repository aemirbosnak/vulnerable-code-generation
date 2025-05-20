//GEMINI-pro DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: curious
#include <stdlib.h>
#include <stdio.h>

int main() {
  float distance_to_nearest_star;
  int num_stars_in_galaxy;
  float percentage_of_stars_with_planets;
  int num_planets_in_galaxy;
  float percentage_of_planets_with_life;
  int num_planets_with_life;
  float percentage_of_planets_with_intelligent_life;
  int num_planets_with_intelligent_life;
  float percentage_of_planets_with_spacefaring_civilizations;
  int num_planets_with_spacefaring_civilizations;
  float percentage_of_planets_with_hostile_spacefaring_civilizations;
  int num_planets_with_hostile_spacefaring_civilizations;
  float percentage_of_planets_with_spacefaring_civilizations_within_striking_distance;
  int num_planets_with_spacefaring_civilizations_within_striking_distance;
  float percentage_of_planets_with_spacefaring_civilizations_within_striking_distance_that_will_invade;
  int num_planets_with_spacefaring_civilizations_within_striking_distance_that_will_invade;
  float probability_of_alien_invasion;

  printf("What is the distance to the nearest star in light years?\n");
  scanf("%f", &distance_to_nearest_star);

  printf("How many stars are there in the galaxy?\n");
  scanf("%d", &num_stars_in_galaxy);

  printf("What percentage of stars have planets?\n");
  scanf("%f", &percentage_of_stars_with_planets);

  num_planets_in_galaxy = num_stars_in_galaxy * percentage_of_stars_with_planets;

  printf("What percentage of planets have life?\n");
  scanf("%f", &percentage_of_planets_with_life);

  num_planets_with_life = num_planets_in_galaxy * percentage_of_planets_with_life;

  printf("What percentage of planets with life have intelligent life?\n");
  scanf("%f", &percentage_of_planets_with_intelligent_life);

  num_planets_with_intelligent_life = num_planets_with_life * percentage_of_planets_with_intelligent_life;

  printf("What percentage of planets with intelligent life have spacefaring civilizations?\n");
  scanf("%f", &percentage_of_planets_with_spacefaring_civilizations);

  num_planets_with_spacefaring_civilizations = num_planets_with_intelligent_life * percentage_of_planets_with_spacefaring_civilizations;

  printf("What percentage of planets with spacefaring civilizations have hostile spacefaring civilizations?\n");
  scanf("%f", &percentage_of_planets_with_hostile_spacefaring_civilizations);

  num_planets_with_hostile_spacefaring_civilizations = num_planets_with_spacefaring_civilizations * percentage_of_planets_with_hostile_spacefaring_civilizations;

  printf("What percentage of planets with hostile spacefaring civilizations are within striking distance of Earth?\n");
  scanf("%f", &percentage_of_planets_with_spacefaring_civilizations_within_striking_distance);

  num_planets_with_spacefaring_civilizations_within_striking_distance = num_planets_with_hostile_spacefaring_civilizations * percentage_of_planets_with_spacefaring_civilizations_within_striking_distance;

  printf("What percentage of planets with hostile spacefaring civilizations within striking distance of Earth will invade Earth?\n");
  scanf("%f", &percentage_of_planets_with_spacefaring_civilizations_within_striking_distance_that_will_invade);

  num_planets_with_spacefaring_civilizations_within_striking_distance_that_will_invade = num_planets_with_spacefaring_civilizations_within_striking_distance * percentage_of_planets_with_spacefaring_civilizations_within_striking_distance_that_will_invade;

  probability_of_alien_invasion = (float)num_planets_with_spacefaring_civilizations_within_striking_distance_that_will_invade / (float)num_stars_in_galaxy;

  printf("The probability of an alien invasion is %.2f%%\n", probability_of_alien_invasion * 100);

  return 0;
}