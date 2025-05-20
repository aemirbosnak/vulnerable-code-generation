//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

// Define the unit conversion functions
double convert_length(double value, char from, char to) {
  if (from == 'm' && to == 'cm') {
    return value * 100;
  } else if (from == 'cm' && to == 'm') {
    return value / 100;
  } else if (from == 'm' && to == 'in') {
    return value * 39.3701;
  } else if (from == 'in' && to == 'm') {
    return value / 39.3701;
  } else if (from == 'cm' && to == 'in') {
    return value / 2.54;
  } else if (from == 'in' && to == 'cm') {
    return value * 2.54;
  } else {
    fprintf(stderr, "Invalid unit conversion: %c to %c\n", from, to);
    exit(EXIT_FAILURE);
  }
}

double convert_weight(double value, char from, char to) {
  if (from == 'kg' && to == 'g') {
    return value * 1000;
  } else if (from == 'g' && to == 'kg') {
    return value / 1000;
  } else if (from == 'kg' && to == 'lb') {
    return value * 2.20462;
  } else if (from == 'lb' && to == 'kg') {
    return value / 2.20462;
  } else if (from == 'g' && to == 'oz') {
    return value / 28.3495;
  } else if (from == 'oz' && to == 'g') {
    return value * 28.3495;
  } else {
    fprintf(stderr, "Invalid unit conversion: %c to %c\n", from, to);
    exit(EXIT_FAILURE);
  }
}

double convert_temperature(double value, char from, char to) {
  if (from == 'c' && to == 'f') {
    return value * 1.8 + 32;
  } else if (from == 'f' && to == 'c') {
    return (value - 32) / 1.8;
  } else if (from == 'c' && to == 'k') {
    return value + 273.15;
  } else if (from == 'k' && to == 'c') {
    return value - 273.15;
  } else if (from == 'f' && to == 'k') {
    return (value + 459.67) * 5 / 9;
  } else if (from == 'k' && to == 'f') {
    return (value * 9 / 5) - 459.67;
  } else {
    fprintf(stderr, "Invalid unit conversion: %c to %c\n", from, to);
    exit(EXIT_FAILURE);
  }
}

// Define the main function
int main() {
  // Get the user input
  printf("Enter the value to convert: ");
  double value;
  scanf("%lf", &value);

  printf("Enter the unit to convert from: ");
  char from;
  scanf(" %c", &from);

  printf("Enter the unit to convert to: ");
  char to;
  scanf(" %c", &to);

  // Check if the user input is valid
  if (from != 'm' && from != 'cm' && from != 'in' && from != 'kg' && from != 'g' && from != 'lb' && from != 'oz' && from != 'c' && from != 'f' && from != 'k') {
    fprintf(stderr, "Invalid unit: %c\n", from);
    exit(EXIT_FAILURE);
  }

  if (to != 'm' && to != 'cm' && to != 'in' && to != 'kg' && to != 'g' && to != 'lb' && to != 'oz' && to != 'c' && to != 'f' && to != 'k') {
    fprintf(stderr, "Invalid unit: %c\n", to);
    exit(EXIT_FAILURE);
  }

  // Convert the value
  double converted_value;
  if (from == 'm' || from == 'cm' || from == 'in') {
    converted_value = convert_length(value, from, to);
  } else if (from == 'kg' || from == 'g' || from == 'lb' || from == 'oz') {
    converted_value = convert_weight(value, from, to);
  } else if (from == 'c' || from == 'f' || from == 'k') {
    converted_value = convert_temperature(value, from, to);
  }

  // Print the result
  printf("%lf %c is equal to %lf %c\n", value, from, converted_value, to);

  return 0;
}