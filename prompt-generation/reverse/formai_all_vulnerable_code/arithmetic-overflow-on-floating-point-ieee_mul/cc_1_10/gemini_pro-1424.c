//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

// Define the unit conversion constants
#define INCHES_TO_CENTIMETERS 2.54
#define CENTIMETERS_TO_INCHES 0.393701
#define POUNDS_TO_KILOGRAMS 0.453592
#define KILOGRAMS_TO_POUNDS 2.20462
#define MILES_TO_KILOMETERS 1.60934
#define KILOMETERS_TO_MILES 0.621371

// Define the unit types
typedef enum {
  INCHES,
  CENTIMETERS,
  POUNDS,
  KILOGRAMS,
  MILES,
  KILOMETERS
} unit_type;

// Define the unit conversion function
double convert_units(double value, unit_type from_unit, unit_type to_unit) {
  switch (from_unit) {
    case INCHES:
      switch (to_unit) {
        case CENTIMETERS:
          return value * INCHES_TO_CENTIMETERS;
        default:
          return value;
      }
    case CENTIMETERS:
      switch (to_unit) {
        case INCHES:
          return value * CENTIMETERS_TO_INCHES;
        default:
          return value;
      }
    case POUNDS:
      switch (to_unit) {
        case KILOGRAMS:
          return value * POUNDS_TO_KILOGRAMS;
        default:
          return value;
      }
    case KILOGRAMS:
      switch (to_unit) {
        case POUNDS:
          return value * KILOGRAMS_TO_POUNDS;
        default:
          return value;
      }
    case MILES:
      switch (to_unit) {
        case KILOMETERS:
          return value * MILES_TO_KILOMETERS;
        default:
          return value;
      }
    case KILOMETERS:
      switch (to_unit) {
        case MILES:
          return value * KILOMETERS_TO_MILES;
        default:
          return value;
      }
    default:
      return value;
  }
}

// Define the main function
int main() {
  // Get the input value and unit type from the user
  double value;
  unit_type from_unit;
  unit_type to_unit;
  printf("Enter the value to convert: ");
  scanf("%lf", &value);
  printf("Enter the unit type to convert from (inches, centimeters, pounds, kilograms, miles, kilometers): ");
  scanf("%s", &from_unit);
  printf("Enter the unit type to convert to (inches, centimeters, pounds, kilograms, miles, kilometers): ");
  scanf("%s", &to_unit);

  // Convert the value to the desired unit type
  double converted_value = convert_units(value, from_unit, to_unit);

  // Print the converted value
  printf("The converted value is: %f\n", converted_value);

  return 0;
}