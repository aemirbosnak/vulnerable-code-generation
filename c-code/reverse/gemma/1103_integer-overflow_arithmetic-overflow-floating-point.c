#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  float value;
  char unit_from, unit_to;

  printf("Enter the value: ");
  scanf("%f", &value);

  printf("Enter the unit you are converting from: ");
  scanf(" %c", &unit_from);

  printf("Enter the unit you are converting to: ");
  scanf(" %c", &unit_to);

  float conversion_factor = 0;
  switch (unit_from) {
    case 'm':
      conversion_factor = 1;
      break;
    case 'k':
      conversion_factor = 1000;
      break;
    case 'mi':
      conversion_factor = 1609.34;
      break;
  }

  switch (unit_to) {
    case 'm':
      conversion_factor = 1;
      break;
    case 'k':
      conversion_factor = 1000;
      break;
    case 'mi':
      conversion_factor = 1609.34;
      break;
  }

  float converted_value = value * conversion_factor;

  printf("The converted value is: %.2f %s", converted_value, unit_to);

  return 0;
}
