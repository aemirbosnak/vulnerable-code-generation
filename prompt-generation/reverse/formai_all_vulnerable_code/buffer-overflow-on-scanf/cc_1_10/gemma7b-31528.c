//Gemma-7B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void morph(int n) {
  switch (n) {
  case 0:
    printf("You are a simple human.\n");
    break;
  case 1:
    printf("You are a mutant with a tail.\n");
    break;
  case 2:
    printf("You are an alien with tentacles.\n");
    break;
  case 3:
    printf("You are a cyborg with a robotic arm.\n");
    break;
  case 4:
    printf("You are a disembodied brain in a jar.\n");
    break;
  default:
    printf("You are a blob of goo.\n");
  }
}

int alien_invasion_probability(int year) {
  int probability = 0;
  if (year % 100 == 0) {
    probability = 1;
  } else if (year % 200 == 0) {
    probability = 3;
  } else if (year % 300 == 0) {
    probability = 5;
  } else {
    probability = 0;
  }
  return probability;
}

int main() {
  int year;
  printf("Enter the year:");
  scanf("%d", &year);

  int probability = alien_invasion_probability(year);

  morph(probability);

  return 0;
}