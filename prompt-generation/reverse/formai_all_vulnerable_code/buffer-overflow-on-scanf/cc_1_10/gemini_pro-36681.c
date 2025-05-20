//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
  // Formula: F = (C × 9/5) + 32
  return (celsius * 9/5) + 32;
}

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
  // Formula: C = (F - 32) × 5/9
  return (fahrenheit - 32) * 5/9;
}

// Function to check if the input is a valid number
int isValidNumber(char *input) {
  // Check if the input is not empty
  if (input == NULL || *input == '\0') {
    return 0;
  }

  // Check if the input contains only digits
  for (int i = 0; input[i] != '\0'; i++) {
    if (!isdigit(input[i])) {
      return 0;
    }
  }

  // Check if the input is within the range of integers
  long int number = strtol(input, NULL, 10);
  if (number < INT_MIN || number > INT_MAX) {
    return 0;
  }

  return 1;
}

// Function to get user input
double getUserInput() {
  // Get the user input
  char input[1024];
  printf("Enter the temperature: ");
  scanf("%s", input);

  // Validate the user input
  while (!isValidNumber(input)) {
    printf("Invalid input. Please enter a valid number: ");
    scanf("%s", input);
  }

  // Convert the input to a double
  return atof(input);
}

// Function to display the results
void displayResults(double celsius, double fahrenheit) {
  // Print the results
  printf("Celsius: %.2f\n", celsius);
  printf("Fahrenheit: %.2f\n", fahrenheit);
}

// Main function
int main() {
  // Get the user input
  double celsius = getUserInput();

  // Convert Celsius to Fahrenheit
  double fahrenheit = celsiusToFahrenheit(celsius);

  // Display the results
  displayResults(celsius, fahrenheit);

  return 0;
}