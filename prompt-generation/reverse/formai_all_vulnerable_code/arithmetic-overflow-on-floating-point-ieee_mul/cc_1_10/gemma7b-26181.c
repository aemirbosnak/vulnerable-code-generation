//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void unit_converter(double value, char from_unit, char to_unit) {
  double conversion_factor;
  switch (from_unit) {
    case 'm':
      conversion_factor = 1000;
      break;
    case 'kg':
      conversion_factor = 1000;
      break;
    case 'L':
      conversion_factor = 1000;
      break;
    case 'g':
      conversion_factor = 1000;
      break;
    case 'n':
      conversion_factor = 1000;
      break;
  }

  switch (to_unit) {
    case 'm':
      conversion_factor = 1;
      break;
    case 'kg':
      conversion_factor = 1000;
      break;
    case 'L':
      conversion_factor = 1000;
      break;
    case 'g':
      conversion_factor = 1000;
      break;
    case 'n':
      conversion_factor = 1000;
      break;
  }

  double converted_value = value * conversion_factor;

  printf("%f %s converted to %f %s is %f", value, from_unit, to_unit, converted_value);
}

int main() {
  double value;
  char from_unit;
  char to_unit;

  printf("Enter the value:");
  scanf("%lf", &value);

  printf("Enter the from unit:");
  scanf(" %c", &from_unit);

  printf("Enter the to unit:");
  scanf(" %c", &to_unit);

  unit_converter(value, from_unit, to_unit);

  return 0;
}