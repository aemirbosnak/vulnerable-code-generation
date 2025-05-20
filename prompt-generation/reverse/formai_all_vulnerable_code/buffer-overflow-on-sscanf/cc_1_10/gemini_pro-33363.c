//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: curious
#include <stdio.h>

int main() {
  // Declare a curious array of unit conversion factors.
  float unit_conversions[] = {
    1.0,          // meters to meters
    0.3048,       // meters to feet
    0.9144,       // meters to yards
    1609.344,    // meters to kilometers
    2.54,         // centimeters to inches
    25.4,         // inches to centimeters
    0.45359237,  // kilograms to pounds
    2.20462262,  // pounds to kilograms
    3.78541178,  // liters to gallons
    0.26417205,  // gallons to liters
  };

  // Declare a curious array of unit names.
  char *unit_names[] = {
    "meters",
    "feet",
    "yards",
    "kilometers",
    "centimeters",
    "inches",
    "kilograms",
    "pounds",
    "liters",
    "gallons",
  };

  // Declare a curious variable to store the user's input.
  char input[256];

  // Prompt the user to enter a conversion.
  printf("Enter a conversion (e.g., \"10 meters to feet\"): ");
  fgets(input, sizeof(input), stdin);

  // Parse the user's input.
  float value;
  char from_unit[256];
  char to_unit[256];
  sscanf(input, "%f %s to %s", &value, from_unit, to_unit);

  // Find the conversion factor for the user's input.
  int from_unit_index = -1;
  int to_unit_index = -1;
  for (int i = 0; i < sizeof(unit_names) / sizeof(char *); i++) {
    if (strcmp(from_unit, unit_names[i]) == 0) {
      from_unit_index = i;
    }
    if (strcmp(to_unit, unit_names[i]) == 0) {
      to_unit_index = i;
    }
  }

  // If the user's input is invalid.
  if (from_unit_index == -1 || to_unit_index == -1) {
    printf("Invalid conversion.\n");
    return 1;
  }

  // Convert the value using the conversion factor.
  float converted_value = value * unit_conversions[from_unit_index * sizeof(unit_conversions) / sizeof(float) + to_unit_index];

  // Print the converted value.
  printf("%f %s is equal to %f %s.\n", value, from_unit, converted_value, to_unit);

  return 0;
}