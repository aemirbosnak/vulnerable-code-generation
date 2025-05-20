//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Declare the variables
  double value, result;
  char unit_from, unit_to;

  // Get the input from the user
  printf("Enter the value: ");
  scanf("%lf", &value);
  printf("Enter the unit of measurement (from): ");
  scanf(" %c", &unit_from);
  printf("Enter the unit of measurement (to): ");
  scanf(" %c", &unit_to);

  // Convert the value to the desired unit
  switch (unit_from) {
    case 'm':
      switch (unit_to) {
        case 'cm':
          result = value * 100;
          break;
        case 'in':
          result = value * 39.37;
          break;
        case 'ft':
          result = value * 3.281;
          break;
        case 'yd':
          result = value * 1.094;
          break;
        case 'mi':
          result = value * 0.000621;
          break;
        default:
          printf("Invalid unit of measurement (to): %c\n", unit_to);
          return EXIT_FAILURE;
      }
      break;
    case 'cm':
      switch (unit_to) {
        case 'm':
          result = value / 100;
          break;
        case 'in':
          result = value * 0.3937;
          break;
        case 'ft':
          result = value * 0.03281;
          break;
        case 'yd':
          result = value * 0.01094;
          break;
        case 'mi':
          result = value * 0.00000621;
          break;
        default:
          printf("Invalid unit of measurement (to): %c\n", unit_to);
          return EXIT_FAILURE;
      }
      break;
    case 'in':
      switch (unit_to) {
        case 'm':
          result = value * 0.0254;
          break;
        case 'cm':
          result = value * 2.54;
          break;
        case 'ft':
          result = value * 0.08333;
          break;
        case 'yd':
          result = value * 0.02778;
          break;
        case 'mi':
          result = value * 0.00001578;
          break;
        default:
          printf("Invalid unit of measurement (to): %c\n", unit_to);
          return EXIT_FAILURE;
      }
      break;
    case 'ft':
      switch (unit_to) {
        case 'm':
          result = value * 0.3048;
          break;
        case 'cm':
          result = value * 30.48;
          break;
        case 'in':
          result = value * 12;
          break;
        case 'yd':
          result = value * 0.3333;
          break;
        case 'mi':
          result = value * 0.0001894;
          break;
        default:
          printf("Invalid unit of measurement (to): %c\n", unit_to);
          return EXIT_FAILURE;
      }
      break;
    case 'yd':
      switch (unit_to) {
        case 'm':
          result = value * 0.9144;
          break;
        case 'cm':
          result = value * 91.44;
          break;
        case 'in':
          result = value * 36;
          break;
        case 'ft':
          result = value * 3;
          break;
        case 'mi':
          result = value * 0.0005682;
          break;
        default:
          printf("Invalid unit of measurement (to): %c\n", unit_to);
          return EXIT_FAILURE;
      }
      break;
    case 'mi':
      switch (unit_to) {
        case 'm':
          result = value * 1609.34;
          break;
        case 'cm':
          result = value * 160934;
          break;
        case 'in':
          result = value * 63360;
          break;
        case 'ft':
          result = value * 5280;
          break;
        case 'yd':
          result = value * 1760;
          break;
        default:
          printf("Invalid unit of measurement (to): %c\n", unit_to);
          return EXIT_FAILURE;
      }
      break;
    default:
      printf("Invalid unit of measurement (from): %c\n", unit_from);
      return EXIT_FAILURE;
  }

  // Print the result
  printf("The converted value is: %.2f %c\n", result, unit_to);

  return EXIT_SUCCESS;
}