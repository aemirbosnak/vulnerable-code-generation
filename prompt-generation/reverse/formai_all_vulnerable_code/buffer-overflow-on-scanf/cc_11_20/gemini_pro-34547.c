//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: systematic
#include <stdio.h>

// Conversion factors for different units
#define INCHES_PER_FOOT 12
#define FEET_PER_YARD 3
#define YARDS_PER_MILE 1760
#define POUNDS_PER_OUNCE 16
#define OUNCES_PER_POUND 16
#define GALLONS_PER_QUART 4
#define QUARTS_PER_GALLON 4
#define PINTS_PER_QUART 2
#define QUARTS_PER_PINT 2
#define CUPS_PER_PINT 2
#define PINTS_PER_CUP 2

// Function to convert a value from one unit to another
double convert(double value, char from_unit, char to_unit) {
  double result;

  // Check if the units are the same
  if (from_unit == to_unit) {
    return value;
  }

  // Convert from inches to feet
  if (from_unit == 'i' && to_unit == 'f') {
    result = value / INCHES_PER_FOOT;
  }

  // Convert from feet to inches
  else if (from_unit == 'f' && to_unit == 'i') {
    result = value * INCHES_PER_FOOT;
  }

  // Convert from feet to yards
  else if (from_unit == 'f' && to_unit == 'y') {
    result = value / FEET_PER_YARD;
  }

  // Convert from yards to feet
  else if (from_unit == 'y' && to_unit == 'f') {
    result = value * FEET_PER_YARD;
  }

  // Convert from yards to miles
  else if (from_unit == 'y' && to_unit == 'm') {
    result = value / YARDS_PER_MILE;
  }

  // Convert from miles to yards
  else if (from_unit == 'm' && to_unit == 'y') {
    result = value * YARDS_PER_MILE;
  }

  // Convert from pounds to ounces
  else if (from_unit == 'l' && to_unit == 'o') {
    result = value * POUNDS_PER_OUNCE;
  }

  // Convert from ounces to pounds
  else if (from_unit == 'o' && to_unit == 'l') {
    result = value / POUNDS_PER_OUNCE;
  }

  // Convert from gallons to quarts
  else if (from_unit == 'g' && to_unit == 'q') {
    result = value * GALLONS_PER_QUART;
  }

  // Convert from quarts to gallons
  else if (from_unit == 'q' && to_unit == 'g') {
    result = value / GALLONS_PER_QUART;
  }

  // Convert from quarts to pints
  else if (from_unit == 'q' && to_unit == 'p') {
    result = value * QUARTS_PER_PINT;
  }

  // Convert from pints to quarts
  else if (from_unit == 'p' && to_unit == 'q') {
    result = value / QUARTS_PER_PINT;
  }

  // Convert from pints to cups
  else if (from_unit == 'p' && to_unit == 'c') {
    result = value * CUPS_PER_PINT;
  }

  // Convert from cups to pints
  else if (from_unit == 'c' && to_unit == 'p') {
    result = value / CUPS_PER_PINT;
  }

  // Return the result of the conversion
  return result;
}

// Main function
int main() {
  // Declare the variables
  double value;
  char from_unit;
  char to_unit;

  // Get the input from the user
  printf("Enter the value to be converted: ");
  scanf("%lf", &value);
  printf("Enter the unit of the value to be converted: ");
  scanf(" %c", &from_unit);
  printf("Enter the unit of the value to be converted to: ");
  scanf(" %c", &to_unit);

  // Convert the value
  double result = convert(value, from_unit, to_unit);

  // Print the result
  printf("The converted value is %lf %c.\n", result, to_unit);

  return 0;
}