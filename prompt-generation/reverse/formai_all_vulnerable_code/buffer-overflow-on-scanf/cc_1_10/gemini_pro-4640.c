//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// Define the unit conversion functions
double convertCelsiusToFahrenheit(double celsius) {
  return (celsius * 9 / 5) + 32;
}

double convertFahrenheitToCelsius(double fahrenheit) {
  return (fahrenheit - 32) * 5 / 9;
}

double convertMilesToKilometers(double miles) {
  return miles * 1.60934;
}

double convertKilometersToMiles(double kilometers) {
  return kilometers / 1.60934;
}

double convertPoundsToKilograms(double pounds) {
  return pounds * 0.453592;
}

double convertKilogramsToPounds(double kilograms) {
  return kilograms / 0.453592;
}

// Define the main function
int main() {
  // Get the user's input
  printf("Enter the value you want to convert: ");
  double value;
  scanf("%lf", &value);

  printf("Enter the unit of the value: ");
  char unit[10];
  scanf("%s", unit);

  // Convert the value to the desired unit
  double convertedValue;
  if (strcmp(unit, "Celsius") == 0) {
    convertedValue = convertCelsiusToFahrenheit(value);
    printf("The converted value is: %.2f Fahrenheit\n", convertedValue);
  } else if (strcmp(unit, "Fahrenheit") == 0) {
    convertedValue = convertFahrenheitToCelsius(value);
    printf("The converted value is: %.2f Celsius\n", convertedValue);
  } else if (strcmp(unit, "Miles") == 0) {
    convertedValue = convertMilesToKilometers(value);
    printf("The converted value is: %.2f Kilometers\n", convertedValue);
  } else if (strcmp(unit, "Kilometers") == 0) {
    convertedValue = convertKilometersToMiles(value);
    printf("The converted value is: %.2f Miles\n", convertedValue);
  } else if (strcmp(unit, "Pounds") == 0) {
    convertedValue = convertPoundsToKilograms(value);
    printf("The converted value is: %.2f Kilograms\n", convertedValue);
  } else if (strcmp(unit, "Kilograms") == 0) {
    convertedValue = convertKilogramsToPounds(value);
    printf("The converted value is: %.2f Pounds\n", convertedValue);
  } else {
    printf("Invalid unit entered. Please enter a valid unit.\n");
  }

  return 0;
}