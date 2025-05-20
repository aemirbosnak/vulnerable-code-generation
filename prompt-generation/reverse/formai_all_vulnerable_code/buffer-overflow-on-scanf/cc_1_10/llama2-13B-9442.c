//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert units of length
double length_convert(double value, char from_unit, char to_unit) {
  double factor = 1;

  switch (from_unit) {
    case 'm':
      factor = 0.01;
      break;
    case 'cm':
      factor = 0.001;
      break;
    case 'mm':
      factor = 0.0001;
      break;
    case 'in':
      factor = 0.0254;
      break;
    case 'ft':
      factor = 0.3048;
      break;
    case 'yd':
      factor = 0.9144;
      break;
    case 'mi':
      factor = 1609.34;
      break;
    default:
      printf("Invalid unit: %c\n", from_unit);
      return 0;
  }

  switch (to_unit) {
    case 'm':
      return value * factor;
    case 'cm':
      return value * factor * 100;
    case 'mm':
      return value * factor * 1000;
    case 'in':
      return value * factor * 25.4;
    case 'ft':
      return value * factor * 304.8;
    case 'yd':
      return value * factor * 914.4;
    case 'mi':
      return value * factor * 1609.34;
    default:
      printf("Invalid unit: %c\n", to_unit);
      return 0;
  }
}

int main() {
  double value, from_unit, to_unit;

  // Get the value to convert
  printf("Enter a value to convert: ");
  scanf("%lf", &value);

  // Get the from unit
  printf("Enter the unit to convert from (m/cm/mm/in/ft/yd/mi): ");
  scanf(" %c", &from_unit);

  // Get the to unit
  printf("Enter the unit to convert to (m/cm/mm/in/ft/yd/mi): ");
  scanf(" %c", &to_unit);

  // Convert the value
  double converted_value = length_convert(value, from_unit, to_unit);

  // Print the converted value
  printf("The value is %f %s\n", converted_value, to_unit);

  return 0;
}