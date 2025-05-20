#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int convert_units(float distance, char unit, char target_unit) {
  float conversion_factor;
  int result;

  switch (unit) {
    case 'm':
      conversion_factor = 1.0f;
      break;
    case 'cm':
      conversion_factor = 0.01f;
      break;
    case 'km':
      conversion_factor = 0.001f;
      break;
    default:
      return -1;
  }

  switch (target_unit) {
    case 'm':
      conversion_factor = 1.0f;
      break;
    case 'cm':
      conversion_factor = 100.0f;
      break;
    case 'km':
      conversion_factor = 1000.0f;
      break;
    default:
      return -1;
  }

  result = (int)(distance * conversion_factor * conversion_factor);

  return result;
}

int main() {
  float distance = 1000000.0f;
  char unit = 'km';
  char target_unit = 'm';

  int converted_distance = convert_units(distance, unit, target_unit);

  printf("Converted distance: %d meters\n", converted_distance);

  return 0;
}
