//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: Cyberpunk
// Welcome to the Cyberpunk Unit Converter!

#include <stdio.h>
#include <stdlib.h>

// Define the conversion factors
#define INCHES_TO_CENTIMETERS 2.54
#define POUNDS_TO_KILOGRAMS 0.453592
#define MILES_TO_KILOMETERS 1.60934
#define GALLONS_TO_LITERS 3.78541

// Define the unit types
typedef enum {
  INCHES,
  CENTIMETERS,
  POUNDS,
  KILOGRAMS,
  MILES,
  KILOMETERS,
  GALLONS,
  LITERS
} unit_type;

// Get the user's input
void get_input(unit_type *from_unit, unit_type *to_unit, double *value) {
  printf("Enter the unit you want to convert from (inches, pounds, miles, or gallons): ");
  scanf("%s", from_unit);

  printf("Enter the unit you want to convert to (centimeters, kilograms, kilometers, or liters): ");
  scanf("%s", to_unit);

  printf("Enter the value you want to convert: ");
  scanf("%lf", value);
}

// Convert the value
double convert_value(unit_type from_unit, unit_type to_unit, double value) {
  switch (from_unit) {
    case INCHES:
      if (to_unit == CENTIMETERS) {
        return value * INCHES_TO_CENTIMETERS;
      }
      break;
    case POUNDS:
      if (to_unit == KILOGRAMS) {
        return value * POUNDS_TO_KILOGRAMS;
      }
      break;
    case MILES:
      if (to_unit == KILOMETERS) {
        return value * MILES_TO_KILOMETERS;
      }
      break;
    case GALLONS:
      if (to_unit == LITERS) {
        return value * GALLONS_TO_LITERS;
      }
      break;
  }

  return value;
}

// Print the result
void print_result(unit_type from_unit, unit_type to_unit, double value) {
  printf("%lf %s is equal to %lf %s\n", value, from_unit, value, to_unit);
}

// Main function
int main() {
  // Declare the variables
  unit_type from_unit, to_unit;
  double value;

  // Get the user's input
  get_input(&from_unit, &to_unit, &value);

  // Convert the value
  double result = convert_value(from_unit, to_unit, value);

  // Print the result
  print_result(from_unit, to_unit, result);

  return 0;
}