//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: safe
#include <stdio.h>
#include <stdlib.h>

// Create a function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
  return (fahrenheit - 32) * 5 / 9;
}

// Create a function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
  return (celsius * 9 / 5) + 32;
}

// Create a function to print the conversion results
void print_conversion_results(float fahrenheit, float celsius) {
  printf("Fahrenheit: %.2f\n", fahrenheit);
  printf("Celsius: %.2f\n", celsius);
}

// Create a function to get the user's input
float get_user_input(char *prompt) {
  float input;
  printf("%s", prompt);
  scanf("%f", &input);
  return input;
}

// Create a function to check if the user's input is valid
int is_valid_input(float input) {
  return input >= -273.15;
}

// Create a function to run the temperature conversion program
void run_temperature_conversion_program() {
  // Get the user's input
  float fahrenheit = get_user_input("Enter the temperature in Fahrenheit: ");
  float celsius = get_user_input("Enter the temperature in Celsius: ");

  // Check if the user's input is valid
  if (!is_valid_input(fahrenheit) || !is_valid_input(celsius)) {
    printf("Invalid input. Please enter a valid temperature.\n");
    return;
  }

  // Convert the temperatures
  float converted_fahrenheit = fahrenheit_to_celsius(fahrenheit);
  float converted_celsius = celsius_to_fahrenheit(celsius);

  // Print the conversion results
  print_conversion_results(converted_fahrenheit, converted_celsius);
}

// Create a main function to call the temperature conversion program
int main() {
  // Run the temperature conversion program
  run_temperature_conversion_program();

  return 0;
}