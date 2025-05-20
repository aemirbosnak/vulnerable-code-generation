#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <math.h>

int main() {
  float distance;
  char unit_from, unit_to;

  printf("Enter the distance: ");
  scanf("%f", &distance);

  printf("Enter the units (m/km/mi): ");
  scanf(" %c", &unit_from);

  printf("Enter the units you want to convert to: ");
  scanf(" %c", &unit_to);

  switch (unit_from) {
    case 'm':
      switch (unit_to) {
        case 'km':
          distance *= 1000;
          break;
        case 'mi':
          distance *= 1609.344;
          break;
      }
      break;
    case 'km':
      switch (unit_to) {
        case 'm':
          distance *= 1000;
          break;
        case 'mi':
          distance *= 0.621371;
          break;
      }
      break;
    case 'mi':
      switch (unit_to) {
        case 'm':
          distance *= 1609.344 / 1000;
          break;
        case 'km':
          distance *= 0.621371;
          break;
      }
      break;
  }

  printf("The converted distance is: %.2f %s", distance, unit_to);

  return 0;
}
