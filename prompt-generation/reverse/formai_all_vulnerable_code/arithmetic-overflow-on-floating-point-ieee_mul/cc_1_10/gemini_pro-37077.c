//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Define the conversion factors for each unit
#define METERS_TO_FEET 3.28084
#define FEET_TO_METERS 0.3048
#define POUNDS_TO_KILOGRAMS 0.453592
#define KILOGRAMS_TO_POUNDS 2.20462
#define CELSIUS_TO_FAHRENHEIT 1.8
#define FAHRENHEIT_TO_CELSIUS 0.555556

// Define the unit types
typedef enum {
  METERS,
  FEET,
  POUNDS,
  KILOGRAMS,
  CELSIUS,
  FAHRENHEIT
} unit_type;

// Define the unit conversion function
double convert_units(double value, unit_type from, unit_type to) {
  switch (from) {
    case METERS:
      switch (to) {
        case FEET:
          return value * METERS_TO_FEET;
        case METERS:
          return value;
        default:
          return 0;
      }
    case FEET:
      switch (to) {
        case METERS:
          return value * FEET_TO_METERS;
        case FEET:
          return value;
        default:
          return 0;
      }
    case POUNDS:
      switch (to) {
        case KILOGRAMS:
          return value * POUNDS_TO_KILOGRAMS;
        case POUNDS:
          return value;
        default:
          return 0;
      }
    case KILOGRAMS:
      switch (to) {
        case POUNDS:
          return value * KILOGRAMS_TO_POUNDS;
        case KILOGRAMS:
          return value;
        default:
          return 0;
      }
    case CELSIUS:
      switch (to) {
        case FAHRENHEIT:
          return value * CELSIUS_TO_FAHRENHEIT + 32;
        case CELSIUS:
          return value;
        default:
          return 0;
      }
    case FAHRENHEIT:
      switch (to) {
        case CELSIUS:
          return (value - 32) * FAHRENHEIT_TO_CELSIUS;
        case FAHRENHEIT:
          return value;
        default:
          return 0;
      }
  }
}

// Define the main function
int main() {
  // Get the input value and unit type
  printf("Enter the value to be converted: ");
  double value;
  scanf("%lf", &value);
  printf("Enter the unit type of the input value:\n");
  printf("1. Meters\n");
  printf("2. Feet\n");
  printf("3. Pounds\n");
  printf("4. Kilograms\n");
  printf("5. Celsius\n");
  printf("6. Fahrenheit\n");
  int from_unit;
  scanf("%d", &from_unit);

  // Get the output unit type
  printf("Enter the unit type to convert to:\n");
  printf("1. Meters\n");
  printf("2. Feet\n");
  printf("3. Pounds\n");
  printf("4. Kilograms\n");
  printf("5. Celsius\n");
  printf("6. Fahrenheit\n");
  int to_unit;
  scanf("%d", &to_unit);

  // Convert the value
  double converted_value = convert_units(value, from_unit, to_unit);

  // Print the converted value
  printf("The converted value is: %.2f\n", converted_value);

  return 0;
}