//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert units of measurement
void convert_units(float value, char from_unit, char to_unit) {
  // Switch statement to handle different unit conversions
  switch (from_unit) {
    case 'm':
      if (to_unit == 'cm') {
        value *= 100;
      } else if (to_unit == 'in') {
        value *= 39.37;
      } else if (to_unit == 'ft') {
        value *= 12;
      }
      break;
    case 'cm':
      if (to_unit == 'm') {
        value /= 100;
      } else if (to_unit == 'in') {
        value /= 39.37;
      } else if (to_unit == 'ft') {
        value /= 12;
      }
      break;
    case 'in':
      if (to_unit == 'cm') {
        value /= 39.37;
      } else if (to_unit == 'm') {
        value /= 100;
      } else if (to_unit == 'ft') {
        value /= 12;
      }
      break;
    case 'ft':
      if (to_unit == 'm') {
        value /= 12;
      } else if (to_unit == 'cm') {
        value /= 100;
      } else if (to_unit == 'in') {
        value /= 39.37;
      }
      break;
    default:
      printf("Invalid unit\n");
      return;
  }
  printf("Value in %c unit: %f\n", to_unit, value);
}

int main() {
  float value = 5.6; // Initialize value to be converted
  char from_unit = 'm'; // Initialize from unit to be meters
  char to_unit = 'ft'; // Initialize to unit to be feet

  // Prompt user for input
  printf("Enter a value in meters: ");
  scanf("%f", &value);
  printf("Enter a unit to convert to (m/cm/in): ");
  scanf("%c", &from_unit);
  printf("Enter a unit to convert to (ft/cm/in): ");
  scanf("%c", &to_unit);

  // Call convert_units function with user input
  convert_units(value, from_unit, to_unit);

  return 0;
}