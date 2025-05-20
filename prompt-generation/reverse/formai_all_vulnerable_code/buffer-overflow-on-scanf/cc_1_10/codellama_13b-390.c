//Code Llama-13B DATASET v1.0 Category: Unit converter ; Style: lively
/*
 * C Unit Converter Example Program
 *
 * This program converts a given value from one unit to another.
 */

#include <stdio.h>
#include <stdlib.h>

#define LENGTH 100

// Function to convert length units
void length_converter(float value, char* from_unit, char* to_unit) {
  // Convert from inches to feet
  if (strcmp(from_unit, "in") == 0 && strcmp(to_unit, "ft") == 0) {
    value /= 12;
  }

  // Convert from feet to inches
  else if (strcmp(from_unit, "ft") == 0 && strcmp(to_unit, "in") == 0) {
    value *= 12;
  }

  // Convert from inches to yards
  else if (strcmp(from_unit, "in") == 0 && strcmp(to_unit, "yd") == 0) {
    value /= 36;
  }

  // Convert from yards to inches
  else if (strcmp(from_unit, "yd") == 0 && strcmp(to_unit, "in") == 0) {
    value *= 36;
  }

  // Convert from inches to meters
  else if (strcmp(from_unit, "in") == 0 && strcmp(to_unit, "m") == 0) {
    value /= 39.3701;
  }

  // Convert from meters to inches
  else if (strcmp(from_unit, "m") == 0 && strcmp(to_unit, "in") == 0) {
    value *= 39.3701;
  }

  // Convert from inches to centimeters
  else if (strcmp(from_unit, "in") == 0 && strcmp(to_unit, "cm") == 0) {
    value /= 2.54;
  }

  // Convert from centimeters to inches
  else if (strcmp(from_unit, "cm") == 0 && strcmp(to_unit, "in") == 0) {
    value *= 2.54;
  }

  // Print the result
  printf("%f %s = %f %s\n", value, from_unit, value, to_unit);
}

int main() {
  // Declare variables
  float value;
  char from_unit[LENGTH], to_unit[LENGTH];

  // Get input from the user
  printf("Enter a value: ");
  scanf("%f", &value);
  printf("Enter the unit (in, ft, yd, m, cm): ");
  scanf("%s", from_unit);
  printf("Enter the unit to convert to (in, ft, yd, m, cm): ");
  scanf("%s", to_unit);

  // Convert the value
  length_converter(value, from_unit, to_unit);

  return 0;
}