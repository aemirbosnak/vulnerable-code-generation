//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// Define the unit conversion functions
double meters_to_feet(double meters) {
  return meters * 3.28084;
}

double feet_to_meters(double feet) {
  return feet / 3.28084;
}

double pounds_to_kilograms(double pounds) {
  return pounds * 0.453592;
}

double kilograms_to_pounds(double kilograms) {
  return kilograms / 0.453592;
}

// Define the main function
int main() {
  // Get the user's input
  printf("Enter the value you want to convert: ");
  double value;
  scanf("%lf", &value);

  printf("Enter the unit of the value (m, ft, lb, kg): ");
  char unit[3];
  scanf("%s", unit);

  // Convert the value to the desired unit
  double converted_value;
  if (strcmp(unit, "m") == 0) {
    converted_value = meters_to_feet(value);
  } else if (strcmp(unit, "ft") == 0) {
    converted_value = feet_to_meters(value);
  } else if (strcmp(unit, "lb") == 0) {
    converted_value = pounds_to_kilograms(value);
  } else if (strcmp(unit, "kg") == 0) {
    converted_value = kilograms_to_pounds(value);
  } else {
    printf("Invalid unit entered.\n");
    return 1;
  }

  // Print the converted value
  printf("The converted value is: %.2lf\n", converted_value);
  
  // Adding some introspection
  printf("This program is designed to convert units of measurement.\n");
  printf("It supports the following conversions:\n");
  printf("  - meters to feet\n");
  printf("  - feet to meters\n");
  printf("  - pounds to kilograms\n");
  printf("  - kilograms to pounds\n");

  return 0;
}