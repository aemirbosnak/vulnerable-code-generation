//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: rigorous
#include <stdio.h>

// Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
  // Formula: Fahrenheit = (Celsius * 9/5) + 32
  return (celsius * 9.0 / 5.0) + 32.0;
}

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
  // Formula: Celsius = (Fahrenheit - 32) * 5/9
  return (fahrenheit - 32.0) * 5.0 / 9.0;
}

// Function to print a temperature conversion table
void print_temperature_conversion_table() {
  // Header
  printf("Celsius\t|\tFahrenheit\n");
  printf("---------\t|\t----------\n");

  // Print temperature conversions from -50 to 50 degrees Celsius
  for (float celsius = -50; celsius <= 50; celsius++) {
    float fahrenheit = celsius_to_fahrenheit(celsius);
    printf("%5.1f\t|\t%5.1f\n", celsius, fahrenheit);
  }
}

int main() {
  // Declare variables
  float temperature;
  char unit;

  // Prompt the user to enter a temperature and its unit
  printf("Enter a temperature and its unit (C/F): ");
  scanf("%f %c", &temperature, &unit);

  // Convert the temperature based on the specified unit
  float converted_temperature;
  switch (unit) {
    case 'C':
    case 'c':
      converted_temperature = celsius_to_fahrenheit(temperature);
      printf("%5.1f degrees Celsius is %5.1f degrees Fahrenheit.\n", temperature, converted_temperature);
      break;
    case 'F':
    case 'f':
      converted_temperature = fahrenheit_to_celsius(temperature);
      printf("%5.1f degrees Fahrenheit is %5.1f degrees Celsius.\n", temperature, converted_temperature);
      break;
    default:
      printf("Invalid unit entered. Please enter 'C' for Celsius or 'F' for Fahrenheit.\n");
      break;
  }

  // Print the temperature conversion table
  printf("\nTemperature Conversion Table:\n");
  print_temperature_conversion_table();

  return 0;
}