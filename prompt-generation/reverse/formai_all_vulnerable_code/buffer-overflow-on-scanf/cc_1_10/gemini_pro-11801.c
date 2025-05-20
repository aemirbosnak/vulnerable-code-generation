//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// Define the unit conversion functions
double convert_celsius_to_fahrenheit(double celsius) {
  return (celsius * 9 / 5) + 32;
}

double convert_fahrenheit_to_celsius(double fahrenheit) {
  return (fahrenheit - 32) * 5 / 9;
}

double convert_miles_to_kilometers(double miles) {
  return miles * 1.60934;
}

double convert_kilometers_to_miles(double kilometers) {
  return kilometers / 1.60934;
}

double convert_pounds_to_kilograms(double pounds) {
  return pounds * 0.453592;
}

double convert_kilograms_to_pounds(double kilograms) {
  return kilograms / 0.453592;
}

// Define the main function
int main(void) {
  // Get the input from the user
  char input_unit;
  double input_value;
  printf("Enter the input unit (C, F, M, K, P, L): ");
  scanf(" %c", &input_unit);
  printf("Enter the input value: ");
  scanf(" %lf", &input_value);

  // Convert the input value to the desired unit
  double output_value;
  switch (input_unit) {
    case 'C':
      output_value = convert_celsius_to_fahrenheit(input_value);
      break;
    case 'F':
      output_value = convert_fahrenheit_to_celsius(input_value);
      break;
    case 'M':
      output_value = convert_miles_to_kilometers(input_value);
      break;
    case 'K':
      output_value = convert_kilometers_to_miles(input_value);
      break;
    case 'P':
      output_value = convert_pounds_to_kilograms(input_value);
      break;
    case 'L':
      output_value = convert_kilograms_to_pounds(input_value);
      break;
    default:
      printf("Invalid input unit. Please try again.\n");
      return EXIT_FAILURE;
  }

  // Print the output value
  char output_unit;
  switch (input_unit) {
    case 'C':
      output_unit = 'F';
      break;
    case 'F':
      output_unit = 'C';
      break;
    case 'M':
      output_unit = 'K';
      break;
    case 'K':
      output_unit = 'M';
      break;
    case 'P':
      output_unit = 'L';
      break;
    case 'L':
      output_unit = 'P';
      break;
  }
  printf("The converted value is: %.2f %c\n", output_value, output_unit);

  return EXIT_SUCCESS;
}