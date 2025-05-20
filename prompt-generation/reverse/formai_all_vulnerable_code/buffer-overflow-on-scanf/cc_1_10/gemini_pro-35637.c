//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: immersive
#include <stdio.h>

// Define the conversion formulas
#define CELSIUS_TO_FAHRENHEIT(c) (c * 9 / 5) + 32
#define FAHRENHEIT_TO_CELSIUS(f) (f - 32) * 5 / 9

// Define the temperature ranges
#define MIN_CELSIUS -273.15
#define MAX_CELSIUS 500
#define MIN_FAHRENHEIT -459.67
#define MAX_FAHRENHEIT 932

// Define the input and output messages
#define INPUT_CELSIUS "Enter the temperature in Celsius: "
#define INPUT_FAHRENHEIT "Enter the temperature in Fahrenheit: "
#define OUTPUT_CELSIUS "The temperature in Celsius is: "
#define OUTPUT_FAHRENHEIT "The temperature in Fahrenheit is: "

// Define the error messages
#define ERROR_INVALID_INPUT "Invalid input. Please enter a valid temperature."
#define ERROR_OUT_OF_RANGE "The temperature is out of range. Please enter a temperature within the valid range."

// Main function
int main() {
  // Declare the variables
  float temperature;
  char unit;

  // Get the input
  printf("%s", INPUT_CELSIUS);
  scanf("%f", &temperature);
  printf("%s", INPUT_FAHRENHEIT);
  scanf("%f", &temperature);
  printf("Enter the unit (C/F): ");
  scanf(" %c", &unit);

  // Convert the temperature
  float convertedTemperature;
  switch (unit) {
    case 'C':
      convertedTemperature = CELSIUS_TO_FAHRENHEIT(temperature);
      break;
    case 'F':
      convertedTemperature = FAHRENHEIT_TO_CELSIUS(temperature);
      break;
    default:
      printf("%s", ERROR_INVALID_INPUT);
      return 1;
  }

  // Check if the temperature is within the valid range
  if (convertedTemperature < MIN_CELSIUS || convertedTemperature > MAX_CELSIUS) {
    printf("%s", ERROR_OUT_OF_RANGE);
    return 1;
  }

  // Output the converted temperature
  printf("%s %.2f\n", OUTPUT_CELSIUS, convertedTemperature);
  return 0;
}