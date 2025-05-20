//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: creative
#include <stdio.h>

// Define the conversion factors
#define INCHES_TO_CM 2.54
#define CM_TO_INCHES 0.393701
#define POUNDS_TO_KG 0.453592
#define KG_TO_POUNDS 2.20462

// Define the unit types
typedef enum {
  INCHES,
  CM,
  POUNDS,
  KG
} unit_type;

// Define the conversion function
double convert(double value, unit_type from, unit_type to) {
  // Check if the units are the same
  if (from == to) {
    return value;
  }

  // Convert the value to the intermediate unit
  double intermediate_value;
  switch (from) {
    case INCHES:
      intermediate_value = value * INCHES_TO_CM;
      break;
    case CM:
      intermediate_value = value * CM_TO_INCHES;
      break;
    case POUNDS:
      intermediate_value = value * POUNDS_TO_KG;
      break;
    case KG:
      intermediate_value = value * KG_TO_POUNDS;
      break;
  }

  // Convert the intermediate value to the target unit
  double converted_value;
  switch (to) {
    case INCHES:
      converted_value = intermediate_value * CM_TO_INCHES;
      break;
    case CM:
      converted_value = intermediate_value * INCHES_TO_CM;
      break;
    case POUNDS:
      converted_value = intermediate_value * KG_TO_POUNDS;
      break;
    case KG:
      converted_value = intermediate_value * POUNDS_TO_KG;
      break;
  }

  return converted_value;
}

// Define the main function
int main() {
  // Get the input values
  double value;
  char from_unit;
  char to_unit;
  printf("Enter the value to convert: ");
  scanf("%lf", &value);
  printf("Enter the unit to convert from (i/cm/lb/kg): ");
  scanf(" %c", &from_unit);
  printf("Enter the unit to convert to (i/cm/lb/kg): ");
  scanf(" %c", &to_unit);

  // Convert the value
  double converted_value = convert(value, from_unit, to_unit);

  // Print the result
  printf("The converted value is: %f %c\n", converted_value, to_unit);

  return 0;
}