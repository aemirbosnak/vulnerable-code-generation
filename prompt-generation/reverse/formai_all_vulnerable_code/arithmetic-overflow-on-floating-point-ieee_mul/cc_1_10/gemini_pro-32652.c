//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: Donald Knuth
#include <stdlib.h>
#include <stdio.h>

// Constants
#define FREEZING_FAHRENHEIT 32.0
#define BOILING_FAHRENHEIT 212.0
#define FREEZING_CELSIUS 0.0
#define BOILING_CELSIUS 100.0

// Function prototypes
double fahrenheit_to_celsius(double fahrenheit);
double celsius_to_fahrenheit(double celsius);

// Main function
int main(void) {
  // Define variables
  double fahrenheit;
  double celsius;

  // Get the Fahrenheit temperature from the user
  printf("Enter the temperature in Fahrenheit: ");
  scanf("%lf", &fahrenheit);

  // Convert the Fahrenheit temperature to Celsius
  celsius = fahrenheit_to_celsius(fahrenheit);

  // Print the Celsius temperature
  printf("The temperature in Celsius is: %.2f\n", celsius);

  // Get the Celsius temperature from the user
  printf("Enter the temperature in Celsius: ");
  scanf("%lf", &celsius);

  // Convert the Celsius temperature to Fahrenheit
  fahrenheit = celsius_to_fahrenheit(celsius);

  // Print the Fahrenheit temperature
  printf("The temperature in Fahrenheit is: %.2f\n", fahrenheit);

  return 0;
}

// Function to convert Fahrenheit to Celsius
double fahrenheit_to_celsius(double fahrenheit) {
  return (fahrenheit - FREEZING_FAHRENHEIT) * (BOILING_CELSIUS - FREEZING_CELSIUS) / (BOILING_FAHRENHEIT - FREEZING_FAHRENHEIT) + FREEZING_CELSIUS;
}

// Function to convert Celsius to Fahrenheit
double celsius_to_fahrenheit(double celsius) {
  return (celsius - FREEZING_CELSIUS) * (BOILING_FAHRENHEIT - FREEZING_FAHRENHEIT) / (BOILING_CELSIUS - FREEZING_CELSIUS) + FREEZING_FAHRENHEIT;
}