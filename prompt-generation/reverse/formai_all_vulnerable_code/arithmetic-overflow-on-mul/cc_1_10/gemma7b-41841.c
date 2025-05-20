//Gemma-7B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int alien_invasion_probability(int num_aliens, int num_ships, int distance, int time_since_last_invasion);

int main()
{
  int num_aliens, num_ships, distance, time_since_last_invasion;

  printf("Enter the number of aliens: ");
  scanf("%d", &num_aliens);

  printf("Enter the number of ships: ");
  scanf("%d", &num_ships);

  printf("Enter the distance from the last invasion: ");
  scanf("%d", &distance);

  printf("Enter the time since the last invasion: ");
  scanf("%d", &time_since_last_invasion);

  int probability = alien_invasion_probability(num_aliens, num_ships, distance, time_since_last_invasion);

  printf("The probability of an alien invasion is: %.2f%%", probability);

  return 0;
}

int alien_invasion_probability(int num_aliens, int num_ships, int distance, int time_since_last_invasion)
{
  int probability = 0;

  // The closer the distance and the more time since the last invasion, the higher the probability of an invasion.
  if (distance < 10 && time_since_last_invasion > 24)
  {
    probability = (num_aliens * num_ships) / 100;
  }

  // If there are a lot of aliens or ships, the probability of invasion is also higher.
  else if (num_aliens > 100 || num_ships > 20)
  {
    probability = (num_aliens * num_ships) / 200;
  }

  // Otherwise, the probability of invasion is low.
  else
  {
    probability = (num_aliens * num_ships) / 500;
  }

  return probability;
}