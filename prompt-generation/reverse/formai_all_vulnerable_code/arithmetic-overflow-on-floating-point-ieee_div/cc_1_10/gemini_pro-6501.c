//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

// Define the conversion factors
#define METERS_TO_FEET 3.28084
#define FEET_TO_METERS 0.3048
#define POUNDS_TO_KILOGRAMS 0.453592
#define KILOGRAMS_TO_POUNDS 2.20462

// Define the unit types
typedef enum {
  METERS,
  FEET,
  POUNDS,
  KILOGRAMS
} unit_type;

// Define the unit conversion function
double convert_units(double value, unit_type from_unit, unit_type to_unit) {
  switch (from_unit) {
    case METERS:
      switch (to_unit) {
        case FEET:
          return value * METERS_TO_FEET;
        case POUNDS:
          return value * METERS_TO_FEET * POUNDS_TO_KILOGRAMS;
        case KILOGRAMS:
          return value * METERS_TO_FEET * POUNDS_TO_KILOGRAMS;
        default:
          return value;
      }
    case FEET:
      switch (to_unit) {
        case METERS:
          return value * FEET_TO_METERS;
        case POUNDS:
          return value * FEET_TO_METERS * POUNDS_TO_KILOGRAMS;
        case KILOGRAMS:
          return value * FEET_TO_METERS * POUNDS_TO_KILOGRAMS;
        default:
          return value;
      }
    case POUNDS:
      switch (to_unit) {
        case METERS:
          return value / FEET_TO_METERS / POUNDS_TO_KILOGRAMS;
        case FEET:
          return value / POUNDS_TO_KILOGRAMS / FEET_TO_METERS;
        case KILOGRAMS:
          return value * POUNDS_TO_KILOGRAMS;
        default:
          return value;
      }
    case KILOGRAMS:
      switch (to_unit) {
        case METERS:
          return value / FEET_TO_METERS / POUNDS_TO_KILOGRAMS;
        case FEET:
          return value / FEET_TO_METERS / POUNDS_TO_KILOGRAMS;
        case POUNDS:
          return value / POUNDS_TO_KILOGRAMS;
        default:
          return value;
      }
    default:
      return value;
  }
}

// Define the main function
int main() {
  // Get the input value and unit type
  double value;
  unit_type from_unit, to_unit;
  printf("Enter the value: ");
  scanf("%lf", &value);
  printf("Enter the from unit (0 for meters, 1 for feet, 2 for pounds, 3 for kilograms): ");
  scanf("%d", &from_unit);
  printf("Enter the to unit (0 for meters, 1 for feet, 2 for pounds, 3 for kilograms): ");
  scanf("%d", &to_unit);

  // Convert the value
  double converted_value = convert_units(value, from_unit, to_unit);

  // Print the converted value
  printf("The converted value is: %.2f\n", converted_value);

  return 0;
}