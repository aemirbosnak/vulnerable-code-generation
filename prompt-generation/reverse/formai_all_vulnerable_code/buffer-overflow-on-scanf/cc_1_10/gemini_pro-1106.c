//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// Unit conversion functions
double inchesToCentimeters(double inches) {
  return inches * 2.54;
}

double centimetersToInches(double centimeters) {
  return centimeters / 2.54;
}

double poundsToKilograms(double pounds) {
  return pounds * 0.453592;
}

double kilogramsToPounds(double kilograms) {
  return kilograms * 2.20462;
}

double fahrenheitToCelsius(double fahrenheit) {
  return (fahrenheit - 32) * 5 / 9;
}

double celsiusToFahrenheit(double celsius) {
  return (celsius * 9 / 5) + 32;
}

// Main function
int main() {
  // Print a welcome message
  printf("Welcome to the unit converter!\n");

  // Get the user's input
  printf("Enter the value you want to convert: ");
  double value;
  scanf("%lf", &value);

  printf("Enter the units of the value (inches, centimeters, pounds, kilograms, fahrenheit, or celsius): ");
  char units[10];
  scanf("%s", units);

  // Convert the value to the desired units
  double convertedValue;
  if (strcmp(units, "inches") == 0) {
    convertedValue = inchesToCentimeters(value);
  } else if (strcmp(units, "centimeters") == 0) {
    convertedValue = centimetersToInches(value);
  } else if (strcmp(units, "pounds") == 0) {
    convertedValue = poundsToKilograms(value);
  } else if (strcmp(units, "kilograms") == 0) {
    convertedValue = kilogramsToPounds(value);
  } else if (strcmp(units, "fahrenheit") == 0) {
    convertedValue = fahrenheitToCelsius(value);
  } else if (strcmp(units, "celsius") == 0) {
    convertedValue = celsiusToFahrenheit(value);
  } else {
    printf("Invalid units entered.\n");
    return 1;
  }

  // Print the converted value
  printf("The converted value is: %lf\n", convertedValue);

  return 0;
}