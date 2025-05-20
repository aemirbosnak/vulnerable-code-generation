//Code Llama-13B DATASET v1.0 Category: Temperature Converter ; Style: systematic
/*
 * Temperature Converter
 *
 * This program converts a temperature in one unit to another unit.
 *
 * Usage:
 *   ./temperature_converter <temp> <unit>
 *
 * Examples:
 *   ./temperature_converter 25 C
 *   ./temperature_converter 77 F
 *
 * Units:
 *   C: Celsius
 *   F: Fahrenheit
 */

#include <stdio.h>
#include <stdlib.h>

// Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
  return (celsius * 9 / 5) + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
  return (fahrenheit - 32) * 5 / 9;
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <temp> <unit>\n", argv[0]);
    return 1;
  }

  // Parse temperature and unit
  float temp = atof(argv[1]);
  char unit = *argv[2];

  // Convert temperature
  float result = 0.0;
  if (unit == 'C') {
    result = celsius_to_fahrenheit(temp);
  } else if (unit == 'F') {
    result = fahrenheit_to_celsius(temp);
  } else {
    fprintf(stderr, "Invalid unit: %c\n", unit);
    return 1;
  }

  // Print result
  printf("%f\n", result);

  return 0;
}