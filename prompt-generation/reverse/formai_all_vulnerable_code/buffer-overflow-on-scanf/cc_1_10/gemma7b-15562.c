//Gemma-7B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void cosmic_harmony(int alien_army_size, double planetary_vibration);
double alien_invasion_probability(int alien_army_size, double planetary_vibration);

int main()
{
  int alien_army_size;
  double planetary_vibration;

  printf("Shall we dance to the stars, my dear, and calculate the probability of an alien invasion?\n");

  printf("Please provide the size of the alien army you wish to summon: ");
  scanf("%d", &alien_army_size);

  printf("Now, tell me the vibrational frequency of the planet you wish to conquer: ");
  scanf("%lf", &planetary_vibration);

  double invasion_probability = alien_invasion_probability(alien_army_size, planetary_vibration);

  printf("According to the celestial oracle, the probability of an alien invasion is: %.2f%%", invasion_probability * 100);

  cosmic_harmony(alien_army_size, planetary_vibration);

  return 0;
}

void cosmic_harmony(int alien_army_size, double planetary_vibration)
{
  for (int i = 0; i < alien_army_size; i++)
  {
    printf("Twinkle, twinkle, little star, dance with the alien army.\n");
  }

  printf("The stars shine on, forevermore, a symphony of celestial grace.\n");

  double frequency = planetary_vibration * 1000;
  for (int i = 0; i < frequency; i++)
  {
    printf("Buzz, buzz, the planets hum, in harmony with the alien drum.\n");
  }
}

double alien_invasion_probability(int alien_army_size, double planetary_vibration)
{
  double probability = 0.0;

  if (alien_army_size > 10000)
  {
    probability = 0.99;
  }
  else if (planetary_vibration > 5)
  {
    probability = 0.75;
  }
  else
  {
    probability = 0.25;
  }

  return probability;
}