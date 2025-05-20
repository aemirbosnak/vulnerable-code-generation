//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare a function to validate user input.
int validate_input(char *input, char *expected_format) {
  // Check if the input is empty.
  if (strlen(input) == 0) {
    return 0;
  }

  // Check if the input matches the expected format.
  if (strcmp(input, expected_format) != 0) {
    return 0;
  }

  // If the input is valid, return 1.
  return 1;
}

// Declare a function to convert a temperature from Celsius to Fahrenheit.
float convert_celsius_to_fahrenheit(float celsius) {
  // Convert the temperature from Celsius to Fahrenheit.
  float fahrenheit = (celsius * 9 / 5) + 32;

  // Return the converted temperature.
  return fahrenheit;
}

// Declare a function to convert a temperature from Fahrenheit to Celsius.
float convert_fahrenheit_to_celsius(float fahrenheit) {
  // Convert the temperature from Fahrenheit to Celsius.
  float celsius = (fahrenheit - 32) * 5 / 9;

  // Return the converted temperature.
  return celsius;
}

// Declare a function to print the temperature conversion results.
void print_temperature_conversion_results(float celsius, float fahrenheit) {
  // Print the temperature conversion results.
  printf("Celsius: %.2f\n", celsius);
  printf("Fahrenheit: %.2f\n", fahrenheit);
}

// Declare the main function.
int main() {
  // Declare variables to store the user input and the converted temperatures.
  char input[100];
  float celsius, fahrenheit;

  // Prompt the user to enter the temperature in Celsius or Fahrenheit.
  printf("Enter the temperature in Celsius or Fahrenheit (e.g., 20C or 68F): ");

  // Get the user input.
  fgets(input, sizeof(input), stdin);

  // Validate the user input.
  if (!validate_input(input, "#[0-9]+C") && !validate_input(input, "#[0-9]+F")) {
    // If the input is invalid, print an error message.
    printf("Invalid input. Please enter the temperature in Celsius or Fahrenheit (e.g., 20C or 68F).\n");

    // Exit the program.
    return EXIT_FAILURE;
  }

  // Convert the temperature to Celsius or Fahrenheit based on the user input.
  if (validate_input(input, "#[0-9]+C")) {
    // Convert the temperature from Celsius to Fahrenheit.
    celsius = atof(input);
    fahrenheit = convert_celsius_to_fahrenheit(celsius);
  } else {
    // Convert the temperature from Fahrenheit to Celsius.
    fahrenheit = atof(input);
    celsius = convert_fahrenheit_to_celsius(fahrenheit);
  }

  // Print the temperature conversion results.
  print_temperature_conversion_results(celsius, fahrenheit);

  // Exit the program.
  return EXIT_SUCCESS;
}