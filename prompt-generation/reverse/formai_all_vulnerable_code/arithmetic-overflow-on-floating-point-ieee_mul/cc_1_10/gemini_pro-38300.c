//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Define the unit conversion functions
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

double miles_to_kilometers(double miles) {
  return miles * 1.60934;
}

double kilometers_to_miles(double kilometers) {
  return kilometers / 1.60934;
}

// Define the main function
int main() {
  // Declare the variables
  double input_value, converted_value;
  char unit_type, conversion_type;

  // Get the input from the user
  printf("Enter the value to be converted: ");
  scanf("%lf", &input_value);

  printf("Enter the unit type (i for inches, c for centimeters, p for pounds, kg for kilograms, m for miles, km for kilometers): ");
  scanf(" %c", &unit_type);

  printf("Enter the conversion type (i to c, c to i, p to kg, kg to p, m to km, km to m): ");
  scanf(" %c", &conversion_type);

  // Convert the value based on the user's input
  switch (unit_type) {
    case 'i':
      switch (conversion_type) {
        case 'c':
          converted_value = inches_to_centimeters(input_value);
          break;
        default:
          printf("Invalid conversion type.\n");
          return EXIT_FAILURE;
      }
      break;
    case 'c':
      switch (conversion_type) {
        case 'i':
          converted_value = centimeters_to_inches(input_value);
          break;
        default:
          printf("Invalid conversion type.\n");
          return EXIT_FAILURE;
      }
      break;
    case 'p':
      switch (conversion_type) {
        case 'kg':
          converted_value = pounds_to_kilograms(input_value);
          break;
        default:
          printf("Invalid conversion type.\n");
          return EXIT_FAILURE;
      }
      break;
    case 'kg':
      switch (conversion_type) {
        case 'p':
          converted_value = kilograms_to_pounds(input_value);
          break;
        default:
          printf("Invalid conversion type.\n");
          return EXIT_FAILURE;
      }
      break;
    case 'm':
      switch (conversion_type) {
        case 'km':
          converted_value = miles_to_kilometers(input_value);
          break;
        default:
          printf("Invalid conversion type.\n");
          return EXIT_FAILURE;
      }
      break;
    case 'km':
      switch (conversion_type) {
        case 'm':
          converted_value = kilometers_to_miles(input_value);
          break;
        default:
          printf("Invalid conversion type.\n");
          return EXIT_FAILURE;
      }
      break;
    default:
      printf("Invalid unit type.\n");
      return EXIT_FAILURE;
  }

  // Print the converted value
  printf("The converted value is: %.2f\n", converted_value);

  return EXIT_SUCCESS;
}