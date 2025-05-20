//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
  return (celsius * 9.0) / 5.0 + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
  return (fahrenheit - 32) * 5.0 / 9.0;
}

// Main function
int main() {

  // Welcome message
  printf("\n\n************************************************************************************\n");
  printf("Welcome to the Magical Temperature Converter!\n\n");

  // Get user input
  int choice;
  float temperature;

  // Display options
  printf("Please choose an option:\n");
  printf("1. Convert Celsius to Fahrenheit\n");
  printf("2. Convert Fahrenheit to Celsius\n");
  printf("\nEnter your choice (1 or 2): ");
  scanf("%d", &choice);

  // Get temperature input
  printf("\nEnter the temperature: ");
  scanf("%f", &temperature);

  // Perform conversion based on choice
  float converted_temperature;
  switch (choice) {
    case 1:
      converted_temperature = celsius_to_fahrenheit(temperature);
      printf("\n%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", temperature, converted_temperature);
      break;
    case 2:
      converted_temperature = fahrenheit_to_celsius(temperature);
      printf("\n%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", temperature, converted_temperature);
      break;
    default:
      printf("\nInvalid choice. Please choose 1 or 2.\n");
  }

  // Thank you message
  printf("\nThank you for using the Magical Temperature Converter! Have a delightful day!\n");
  printf("************************************************************************************\n\n");

  return 0;
}