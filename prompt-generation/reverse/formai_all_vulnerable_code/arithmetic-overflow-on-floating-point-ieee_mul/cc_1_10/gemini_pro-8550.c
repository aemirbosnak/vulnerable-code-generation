//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Define the conversion factors
#define INCHES_TO_FEET 0.08333333333333333
#define FEET_TO_INCHES 12.0
#define POUNDS_TO_KILOGRAMS 0.453592
#define KILOGRAMS_TO_POUNDS 2.20462

// Define the unit types
typedef enum {
  INCHES,
  FEET,
  POUNDS,
  KILOGRAMS
} unit_type;

// Define the unit conversion function
double convert_units(double value, unit_type from_unit, unit_type to_unit) {
  switch (from_unit) {
    case INCHES:
      switch (to_unit) {
        case FEET:
          return value * INCHES_TO_FEET;
        case POUNDS:
          return value * 0.0254;
        case KILOGRAMS:
          return value * 0.0254 * 0.453592;
        default:
          return value;
      }
    case FEET:
      switch (to_unit) {
        case INCHES:
          return value * FEET_TO_INCHES;
        case POUNDS:
          return value * 14.5939;
        case KILOGRAMS:
          return value * 14.5939 * 0.453592;
        default:
          return value;
      }
    case POUNDS:
      switch (to_unit) {
        case INCHES:
          return value * 39.3701;
        case FEET:
          return value * 0.068521;
        case KILOGRAMS:
          return value * 0.453592;
        default:
          return value;
      }
    case KILOGRAMS:
      switch (to_unit) {
        case INCHES:
          return value * 39.3701 * 2.20462;
        case FEET:
          return value * 0.068521 * 2.20462;
        case POUNDS:
          return value * 2.20462;
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
  unit_type from_unit, to_unit;
  printf("Enter the value: ");
  scanf("%lf", &value);
  printf("Enter the from unit (inches, feet, pounds, kilograms): ");
  scanf("%s", from_unit);
  printf("Enter the to unit (inches, feet, pounds, kilograms): ");
  scanf("%s", to_unit);

  // Convert the value to the desired unit
  double converted_value = convert_units(value, from_unit, to_unit);

  // Print the converted value
  printf("The converted value is: %lf\n", converted_value);

  return 0;
}