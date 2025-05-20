//Gemma-7B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int alien_invasion_probability(int year) {
  int alien_presence = alien_presence_check(year);
  int planetary_vibration = planetary_vibration_check(year);
  int cosmic_interference = cosmic_interference_check(year);
  return (alien_presence * planetary_vibration * cosmic_interference) / 1000;
}

int alien_presence_check(int year) {
  if (year % 12 == 0) {
    return 1;
  } else {
    return 0;
  }
}

int planetary_vibration_check(int year) {
  if (year % 400 == 0) {
    return 1;
  } else {
    return 0;
  }
}

int cosmic_interference_check(int year) {
  if (year % 2000 == 0) {
    return 1;
  } else {
    return 0;
  }
}

int main() {
  int year;
  printf("Enter the year: ");
  scanf("%d", &year);

  int probability = alien_invasion_probability(year);

  if (probability > 0) {
    printf("Warning: Alien invasion probability is high!\n");
  } else {
    printf("No need to worry, alien invasion probability is low.\n");
  }

  return 0;
}