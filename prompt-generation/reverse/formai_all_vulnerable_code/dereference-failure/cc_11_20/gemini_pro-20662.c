//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the units
#define UNIT_CELSIUS 0
#define UNIT_FAHRENHEIT 1
#define UNIT_KELVIN 2
#define UNIT_RANKINE 3

// Define the conversion factors
#define CELSIUS_TO_FAHRENHEIT 1.8
#define CELSIUS_TO_KELVIN 273.15
#define CELSIUS_TO_RANKINE 491.67
#define FAHRENHEIT_TO_CELSIUS 0.5555555555555556
#define FAHRENHEIT_TO_KELVIN 255.9277777777778
#define FAHRENHEIT_TO_RANKINE 1.0
#define KELVIN_TO_CELSIUS -273.15
#define KELVIN_TO_FAHRENHEIT -459.67
#define KELVIN_TO_RANKINE 1.8
#define RANKINE_TO_CELSIUS -273.15
#define RANKINE_TO_FAHRENHEIT -459.67
#define RANKINE_TO_KELVIN 0.5555555555555556

// Define the unit names
const char *unit_names[] = {"Celsius", "Fahrenheit", "Kelvin", "Rankine"};

// Define the conversion function
double convert(double value, int from_unit, int to_unit) {
  switch (from_unit) {
    case UNIT_CELSIUS:
      switch (to_unit) {
        case UNIT_FAHRENHEIT:
          return value * CELSIUS_TO_FAHRENHEIT;
        case UNIT_KELVIN:
          return value + CELSIUS_TO_KELVIN;
        case UNIT_RANKINE:
          return value * CELSIUS_TO_RANKINE;
        default:
          return value;
      }
    case UNIT_FAHRENHEIT:
      switch (to_unit) {
        case UNIT_CELSIUS:
          return value * FAHRENHEIT_TO_CELSIUS;
        case UNIT_KELVIN:
          return (value + FAHRENHEIT_TO_KELVIN);
        case UNIT_RANKINE:
          return value * FAHRENHEIT_TO_RANKINE;
        default:
          return value;
      }
    case UNIT_KELVIN:
      switch (to_unit) {
        case UNIT_CELSIUS:
          return value + KELVIN_TO_CELSIUS;
        case UNIT_FAHRENHEIT:
          return (value + KELVIN_TO_FAHRENHEIT);
        case UNIT_RANKINE:
          return value * KELVIN_TO_RANKINE;
        default:
          return value;
      }
    case UNIT_RANKINE:
      switch (to_unit) {
        case UNIT_CELSIUS:
          return value + RANKINE_TO_CELSIUS;
        case UNIT_FAHRENHEIT:
          return (value + RANKINE_TO_FAHRENHEIT);
        case UNIT_KELVIN:
          return value * RANKINE_TO_KELVIN;
        default:
          return value;
      }
    default:
      return value;
  }
}

// Define the main function
int main(int argc, char *argv[]) {
  // Check the arguments
  if (argc != 4) {
    printf("Usage: %s value from_unit to_unit\n", argv[0]);
    return 1;
  }

  // Get the value
  double value = atof(argv[1]);

  // Get the from unit
  int from_unit = -1;
  for (int i = 0; i < 4; i++) {
    if (strcmp(argv[2], unit_names[i]) == 0) {
      from_unit = i;
      break;
    }
  }

  // Check the from unit
  if (from_unit == -1) {
    printf("Invalid from unit: %s\n", argv[2]);
    return 1;
  }

  // Get the to unit
  int to_unit = -1;
  for (int i = 0; i < 4; i++) {
    if (strcmp(argv[3], unit_names[i]) == 0) {
      to_unit = i;
      break;
    }
  }

  // Check the to unit
  if (to_unit == -1) {
    printf("Invalid to unit: %s\n", argv[3]);
    return 1;
  }

  // Convert the value
  double converted_value = convert(value, from_unit, to_unit);

  // Print the result
  printf("%f %s = %f %s\n", value, unit_names[from_unit], converted_value, unit_names[to_unit]);

  return 0;
}