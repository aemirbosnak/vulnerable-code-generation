#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  float distance;
  char unit;

  printf("Enter distance: ");
  scanf("%f %c", &distance, &unit);

  switch (unit) {
    case 'm':
      printf("Equivalent in kilometers: %.2f km\n", distance * 1000);
      break;
    case 'k':
      printf("Equivalent in meters: %.2f m\n", distance * 1000);
      break;
    case 'cm':
      printf("Equivalent in meters: %.2f m\n", distance * 0.01);
      break;
    case 'mm':
      printf("Equivalent in meters: %.2f m\n", distance * 0.001);
      break;
    case 'ft':
      printf("Equivalent in meters: %.2f m\n", distance * 0.328);
      break;
    case 'in':
      printf("Equivalent in meters: %.2f m\n", distance * 0.0833);
      break;
    default:
      printf("Invalid unit.\n");
  }

  return 0;
}
