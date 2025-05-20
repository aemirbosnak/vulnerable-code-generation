#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_CONVERT_VALUE 10000000000

int main() {
  double value;
  char unit_from, unit_to;

  printf("Enter the value: ");
  scanf("%lf", &value);

  printf("Enter the unit of measurement from: ");
  scanf(" %c", &unit_from);

  printf("Enter the unit of measurement to: ");
  scanf(" %c", &unit_to);

  double conversion_factor = 1;
  switch (unit_from) {
    case 'm':
      conversion_factor = 1;
      break;
    case 'km':
      conversion_factor = 1000;
      break;
    case 'mi':
      conversion_factor = 1609.34;
      break;
    default:
      printf("Invalid unit of measurement.\n");
      return 1;
  }

  switch (unit_to) {
    case 'm':
      conversion_factor = 1;
      break;
    case 'km':
      conversion_factor = 1000;
      break;
    case 'mi':
      conversion_factor = 1609.34;
      break;
    default:
      printf("Invalid unit of measurement.\n");
      return 1;
  }

  double converted_value = value * conversion_factor;

  if (converted_value > MAX_CONVERT_VALUE) {
    printf("The converted value is too large.\n");
  } else {
    printf("The converted value is: %.2lf %s.\n", converted_value, unit_to);
  }

  return 0;
}
