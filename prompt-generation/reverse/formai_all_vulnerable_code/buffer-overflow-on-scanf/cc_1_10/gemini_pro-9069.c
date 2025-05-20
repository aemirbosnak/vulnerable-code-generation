//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: random
#include <stdio.h>
#include <stdlib.h>

// Define the conversion factors
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

// Define the unit names
const char *unit_names[] = {
  "inches",
  "centimeters",
  "pounds",
  "kilograms",
  "miles",
  "kilometers"
};

// Function to convert a value from one unit to another
double convert(double value, unit_type from_unit, unit_type to_unit) {
  // Check if the units are the same
  if (from_unit == to_unit) {
    return value;
  }

  // Convert the value to centimeters
  double centimeters;
  switch (from_unit) {
    case INCHES:
      centimeters = value * INCHES_TO_CENTIMETERS;
      break;
    case POUNDS:
      centimeters = value * POUNDS_TO_KILOGRAMS * 100;
      break;
    case MILES:
      centimeters = value * MILES_TO_KILOMETERS * 100000;
      break;
    default:
      fprintf(stderr, "Invalid unit: %d\n", from_unit);
      exit(1);
  }

  // Convert the value to the desired unit
  double result;
  switch (to_unit) {
    case CENTIMETERS:
      result = centimeters;
      break;
    case INCHES:
      result = centimeters * CENTIMETERS_TO_INCHES;
      break;
    case KILOGRAMS:
      result = centimeters / 100 * KILOGRAMS_TO_POUNDS;
      break;
    case MILES:
      result = centimeters / 100000 * KILOMETERS_TO_MILES;
      break;
    default:
      fprintf(stderr, "Invalid unit: %d\n", to_unit);
      exit(1);
  }

  return result;
}

// Function to print the conversion results
void print_results(double value, unit_type from_unit, unit_type to_unit) {
  printf("%f %s is equal to %f %s\n", value, unit_names[from_unit], convert(value, from_unit, to_unit), unit_names[to_unit]);
}

int main() {
  // Get the input value and units
  double value;
  unit_type from_unit, to_unit;
  printf("Enter the value to convert: ");
  scanf("%lf", &value);
  printf("Enter the unit to convert from (inches, centimeters, pounds, kilograms, miles, kilometers): ");
  char unit_name[100];
  scanf("%s", unit_name);
  for (int i = 0; i < 6; i++) {
    if (strcmp(unit_name, unit_names[i]) == 0) {
      from_unit = i;
      break;
    }
  }
  printf("Enter the unit to convert to (inches, centimeters, pounds, kilograms, miles, kilometers): ");
  scanf("%s", unit_name);
  for (int i = 0; i < 6; i++) {
    if (strcmp(unit_name, unit_names[i]) == 0) {
      to_unit = i;
      break;
    }
  }

  // Convert the value and print the results
  print_results(value, from_unit, to_unit);

  return 0;
}