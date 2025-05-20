//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Donald Knuth
/* C Alien Invasion Probability Calculator */
/* Copyright (C) 2021 by [Your Name] */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  int num_planets, invasion_prob, alien_tech_level, planet_tech_level;
  int i, j, invasion_count = 0;
  float invasion_chance;

  srand(time(NULL)); /* Initialize seed for random number generator */

  printf("Welcome to the Alien Invasion Probability Calculator!\n");
  printf("Please enter the number of planets in the galaxy: ");
  scanf("%d", &num_planets);

  /* Ensure at least two planets */
  while (num_planets < 2)
  {
    printf("Invalid number of planets, please enter at least two: ");
    scanf("%d", &num_planets);
  }

  /* Generate invasion probability (0-100) */
  invasion_prob = rand() % 101;

  /* Print invasion probability */
  printf("The probability of an alien invasion is %d%%.\n", invasion_prob);

  /* Loop through every possible planet pairing */
  for (i = 1; i <= num_planets; i++)
  {
    for (j = i+1; j <= num_planets; j++)
    {
      /* Generate alien tech level (1-10) */
      alien_tech_level = rand() % 10 + 1;

      /* Generate planet tech level (1-10) */
      planet_tech_level = rand() % 10 + 1;

      /* Calculate invasion chance */
      invasion_chance = invasion_prob * ((float)alien_tech_level / planet_tech_level) / 100;

      /* Determine if invasion occurs */
      if (invasion_chance >= rand() % 101)
      {
        printf("Planet %d is invaded by aliens from planet %d!\n", j, i);
        invasion_count++;
      }
    }
  }

  /* Print number of invasions */
  printf("%d planets were invaded by aliens!\n", invasion_count);

  return 0;
}