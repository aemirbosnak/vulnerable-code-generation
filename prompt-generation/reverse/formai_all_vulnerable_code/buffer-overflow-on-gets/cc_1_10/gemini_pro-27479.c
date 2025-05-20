//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to convert Celsius to Fahrenheit
double celsius_to_fahrenheit(double celsius) {
  return (celsius * 9 / 5) + 32;
}

// Function to convert Fahrenheit to Celsius
double fahrenheit_to_celsius(double fahrenheit) {
  return (fahrenheit - 32) * 5 / 9;
}

// Main function
int main() {
  // Declare variables
  char input[100];
  double temperature;
  int choice;

  while (1) {
    // Prompt the user to enter the temperature
    printf("Enter the temperature: ");
    gets(input);

    // Convert the input to a double
    temperature = atof(input);

    // Prompt the user to choose the conversion type
    printf("Choose the conversion type:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    scanf("%d", &choice);

    // Perform the conversion based on the user's choice
    switch (choice) {
      case 1:
        printf("The temperature in Fahrenheit is: %.2f\n", celsius_to_fahrenheit(temperature));
        break;
      case 2:
        printf("The temperature in Celsius is: %.2f\n", fahrenheit_to_celsius(temperature));
        break;
      default:
        printf("Invalid choice. Please choose 1 or 2.\n");
    }

    // Prompt the user to continue or exit
    printf("Do you want to continue? (y/n)\n");
    gets(input);

    // Exit the program if the user enters 'n'
    if (strcmp(input, "n") == 0) {
      break;
    }
  }

  return 0;
}