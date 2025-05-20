//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: shape shifting
#include <stdio.h>

// Declare the unit types
typedef enum {
  METERS,
  CENTIMETERS,
  INCHES,
  FEET,
  YARDS,
  MILES
} unit_type;

// Declare the conversion function
double convert(double value, unit_type from, unit_type to);

// Main function
int main() {
  // Get the input value and unit type
  printf("Enter the value to convert: ");
  double value;
  scanf("%lf", &value);

  printf("Enter the unit type to convert from (0 for meters, 1 for centimeters, 2 for inches, 3 for feet, 4 for yards, 5 for miles): ");
  int from_type;
  scanf("%d", &from_type);

  printf("Enter the unit type to convert to (0 for meters, 1 for centimeters, 2 for inches, 3 for feet, 4 for yards, 5 for miles): ");
  int to_type;
  scanf("%d", &to_type);

  // Convert the value
  double converted_value = convert(value, from_type, to_type);

  // Print the result
  printf("The converted value is: %lf\n", converted_value);

  return 0;
}

// Conversion function
double convert(double value, unit_type from, unit_type to) {
  // Check if the units are the same
  if (from == to) {
    return value;
  }

  // Convert the value to meters
  double meters;
  switch (from) {
    case METERS:
      meters = value;
      break;
    case CENTIMETERS:
      meters = value / 100.0;
      break;
    case INCHES:
      meters = value / 39.3701;
      break;
    case FEET:
      meters = value / 3.28084;
      break;
    case YARDS:
      meters = value / 1.09361;
      break;
    case MILES:
      meters = value * 1609.34;
      break;
  }

  // Convert the value from meters to the desired unit
  double converted_value;
  switch (to) {
    case METERS:
      converted_value = meters;
      break;
    case CENTIMETERS:
      converted_value = meters * 100.0;
      break;
    case INCHES:
      converted_value = meters * 39.3701;
      break;
    case FEET:
      converted_value = meters * 3.28084;
      break;
    case YARDS:
      converted_value = meters * 1.09361;
      break;
    case MILES:
      converted_value = meters / 1609.34;
      break;
  }

  return converted_value;
}