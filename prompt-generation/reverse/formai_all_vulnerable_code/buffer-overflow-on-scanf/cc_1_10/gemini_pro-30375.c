//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

// Define the conversion functions
double inches_to_centimeters(double inches) {
  return inches * 2.54;
}

double centimeters_to_inches(double centimeters) {
  return centimeters / 2.54;
}

double pounds_to_kilograms(double pounds) {
  return pounds * 0.453592;
}

double kilograms_to_pounds(double kilograms) {
  return kilograms / 0.453592;
}

double fahrenheit_to_celsius(double fahrenheit) {
  return (fahrenheit - 32) * 5 / 9;
}

double celsius_to_fahrenheit(double celsius) {
  return (celsius * 9 / 5) + 32;
}

// Define the main function
int main() {
  // Get the user's input
  printf("Enter the value to be converted: ");
  double value;
  scanf("%lf", &value);

  printf("Enter the unit of the value: ");
  char unit;
  scanf(" %c", &unit);

  // Convert the value to the desired unit
  double converted_value;
  switch (unit) {
    case 'i':
      converted_value = inches_to_centimeters(value);
      printf("%lf inches is equal to %lf centimeters.\n", value, converted_value);
      break;
    case 'c':
      converted_value = centimeters_to_inches(value);
      printf("%lf centimeters is equal to %lf inches.\n", value, converted_value);
      break;
    case 'p':
      converted_value = pounds_to_kilograms(value);
      printf("%lf pounds is equal to %lf kilograms.\n", value, converted_value);
      break;
    case 'k':
      converted_value = kilograms_to_pounds(value);
      printf("%lf kilograms is equal to %lf pounds.\n", value, converted_value);
      break;
    case 'f':
      converted_value = fahrenheit_to_celsius(value);
      printf("%lf fahrenheit is equal to %lf celsius.\n", value, converted_value);
      break;
    case 'C':
      converted_value = celsius_to_fahrenheit(value);
      printf("%lf celsius is equal to %lf fahrenheit.\n", value, converted_value);
      break;
    default:
      printf("Invalid unit entered.\n");
  }

  return 0;
}