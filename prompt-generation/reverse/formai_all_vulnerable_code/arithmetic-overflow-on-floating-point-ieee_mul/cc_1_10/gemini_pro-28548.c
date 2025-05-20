//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: innovative
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

// Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
  return (celsius * 9 / 5) + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
  return (fahrenheit - 32) * 5 / 9;
}

// Function to print a header
void print_header() {
  printf("=========================\n");
  printf("Temperature Converter\n");
  printf("=========================\n");
}

// Function to get the user's choice
char get_choice() {
  char choice;
  printf("\nPlease enter your choice:\n");
  printf("1. Convert Celsius to Fahrenheit\n");
  printf("2. Convert Fahrenheit to Celsius\n");
  printf("3. Exit\n");
  scanf(" %c", &choice);
  return choice;
}

// Function to get the temperature value
float get_temperature() {
  float temperature;
  printf("\nEnter the temperature value:\n");
  scanf("%f", &temperature);
  return temperature;
}

// Function to print the result
void print_result(char choice, float temperature, float result) {
  switch (choice) {
    case '1':
      printf("\n%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", temperature, result);
      break;
    case '2':
      printf("\n%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", temperature, result);
      break;
    default:
      printf("\nInvalid choice.\n");
  }
}

// Main function
int main() {
  // Print the header
  print_header();

  bool running = true;
  while (running) {
    // Get the user's choice
    char choice = get_choice();

    // Exit the program if the user chooses to exit
    if (choice == '3') {
      running = false;
      continue;
    }

    // Get the temperature value
    float temperature = get_temperature();

    // Convert the temperature
    float result;
    if (choice == '1') {
      result = celsius_to_fahrenheit(temperature);
    } else if (choice == '2') {
      result = fahrenheit_to_celsius(temperature);
    }

    // Print the result
    print_result(choice, temperature, result);
  }

  printf("\nExiting the program.\n");
  return 0;
}