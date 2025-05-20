//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// Define the unit conversion functions
double convert_inches_to_centimeters(double inches) {
  return inches * 2.54;
}

double convert_centimeters_to_inches(double centimeters) {
  return centimeters / 2.54;
}

double convert_fahrenheit_to_celsius(double fahrenheit) {
  return (fahrenheit - 32) * 5 / 9;
}

double convert_celsius_to_fahrenheit(double celsius) {
  return (celsius * 9 / 5) + 32;
}

// Define the main function
int main() {
  // Declare the variables
  double inches, centimeters, fahrenheit, celsius;
  int choice;

  // Display the menu
  printf("Unit Converter\n");
  printf("1. Inches to Centimeters\n");
  printf("2. Centimeters to Inches\n");
  printf("3. Fahrenheit to Celsius\n");
  printf("4. Celsius to Fahrenheit\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);

  // Get the input value
  switch (choice) {
    case 1:
      printf("Enter the inches: ");
      scanf("%lf", &inches);
      centimeters = convert_inches_to_centimeters(inches);
      printf("%lf inches is equal to %lf centimeters.\n", inches, centimeters);
      break;
    case 2:
      printf("Enter the centimeters: ");
      scanf("%lf", &centimeters);
      inches = convert_centimeters_to_inches(centimeters);
      printf("%lf centimeters is equal to %lf inches.\n", centimeters, inches);
      break;
    case 3:
      printf("Enter the fahrenheit: ");
      scanf("%lf", &fahrenheit);
      celsius = convert_fahrenheit_to_celsius(fahrenheit);
      printf("%lf fahrenheit is equal to %lf celsius.\n", fahrenheit, celsius);
      break;
    case 4:
      printf("Enter the celsius: ");
      scanf("%lf", &celsius);
      fahrenheit = convert_celsius_to_fahrenheit(celsius);
      printf("%lf celsius is equal to %lf fahrenheit.\n", celsius, fahrenheit);
      break;
    default:
      printf("Invalid choice.\n");
  }

  return 0;
}