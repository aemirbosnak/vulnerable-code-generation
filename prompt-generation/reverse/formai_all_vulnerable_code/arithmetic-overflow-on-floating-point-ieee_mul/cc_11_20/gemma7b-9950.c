//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

void main() {
  double value;
  char unit_from, unit_to;

  printf("Enter the value: ");
  scanf("%lf", &value);

  printf("Enter the unit of measurement from: ");
  scanf(" %c", &unit_from);

  printf("Enter the unit of measurement to: ");
  scanf(" %c", &unit_to);

  double conversion_factor = 0;
  switch (unit_from) {
    case 'm':
      switch (unit_to) {
        case 'kg':
          conversion_factor = 1000;
          break;
        case 'g':
          conversion_factor = 1000000;
          break;
        case 't':
          conversion_factor = 1000000000;
          break;
      }
      break;
    case 'kg':
      switch (unit_to) {
        case 'm':
          conversion_factor = 0.001;
          break;
        case 'g':
          conversion_factor = 1000;
          break;
        case 't':
          conversion_factor = 1000000;
          break;
      }
      break;
    case 'g':
      switch (unit_to) {
        case 'm':
          conversion_factor = 0.000001;
          break;
        case 'kg':
          conversion_factor = 0.001;
          break;
        case 't':
          conversion_factor = 1000000;
          break;
      }
      break;
    case 't':
      switch (unit_to) {
        case 'm':
          conversion_factor = 0.0000001;
          break;
        case 'kg':
          conversion_factor = 0.000001;
          break;
        case 'g':
          conversion_factor = 0.001;
          break;
      }
      break;
  }

  double converted_value = value * conversion_factor;

  printf("The converted value is: %.2lf %s\n", converted_value, unit_to);
}