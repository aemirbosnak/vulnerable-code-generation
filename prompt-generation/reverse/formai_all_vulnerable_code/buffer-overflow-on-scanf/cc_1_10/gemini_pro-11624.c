//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the conversion factors
#define INCHES_PER_FOOT 12
#define FEET_PER_YARD 3
#define YARDS_PER_MILE 1760
#define MILES_PER_KILOMETER 1.60934

// Define the unit types
typedef enum {
  INCHES,
  FEET,
  YARDS,
  MILES,
  KILOMETERS
} unit_type;

// Define the unit names
static const char *unit_names[] = {
  "inches",
  "feet",
  "yards",
  "miles",
  "kilometers"
};

// Define the conversion function
double convert(double value, unit_type from, unit_type to) {
  // Check if the units are the same
  if (from == to) {
    return value;
  }

  // Convert the value to inches
  double inches = value;
  switch (from) {
    case FEET:
      inches *= INCHES_PER_FOOT;
      break;
    case YARDS:
      inches *= INCHES_PER_FOOT * FEET_PER_YARD;
      break;
    case MILES:
      inches *= INCHES_PER_FOOT * FEET_PER_YARD * YARDS_PER_MILE;
      break;
    case KILOMETERS:
      inches *= INCHES_PER_FOOT * FEET_PER_YARD * YARDS_PER_MILE * MILES_PER_KILOMETER;
      break;
  }

  // Convert the value to the desired units
  double result = inches;
  switch (to) {
    case FEET:
      result /= INCHES_PER_FOOT;
      break;
    case YARDS:
      result /= INCHES_PER_FOOT * FEET_PER_YARD;
      break;
    case MILES:
      result /= INCHES_PER_FOOT * FEET_PER_YARD * YARDS_PER_MILE;
      break;
    case KILOMETERS:
      result /= INCHES_PER_FOOT * FEET_PER_YARD * YARDS_PER_MILE * MILES_PER_KILOMETER;
      break;
  }

  return result;
}

// Get the unit type from the user
unit_type get_unit_type(const char *unit_name) {
  for (int i = 0; i < 5; i++) {
    if (strcmp(unit_name, unit_names[i]) == 0) {
      return i;
    }
  }

  return -1;
}

// Print the result
void print_result(double value, unit_type unit) {
  printf("%f %s\n", value, unit_names[unit]);
}

// Main function
int main() {
  // Get the input from the user
  double value;
  char from_unit_name[20];
  char to_unit_name[20];
  printf("Enter the value: ");
  scanf("%lf", &value);
  printf("Enter the from unit: ");
  scanf("%s", from_unit_name);
  printf("Enter the to unit: ");
  scanf("%s", to_unit_name);

  // Get the unit types
  unit_type from_unit = get_unit_type(from_unit_name);
  unit_type to_unit = get_unit_type(to_unit_name);

  // Check if the units are valid
  if (from_unit == -1 || to_unit == -1) {
    printf("Invalid unit.\n");
    return 1;
  }

  // Convert the value
  double result = convert(value, from_unit, to_unit);

  // Print the result
  print_result(result, to_unit);

  return 0;
}