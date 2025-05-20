//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  // Define Celsius and Fahrenheit temperatures
  float celsius, fahrenheit;
  char choice;

  while (1) {
    // Display the menu
    printf("\n**** Temperature Conversion Menu ****\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf(" %c", &choice);

    // Check the user's choice
    switch (choice) {
      case '1':
        // Get the Celsius temperature
        printf("Enter the Celsius temperature: ");
        scanf(" %f", &celsius);

        // Convert Celsius to Fahrenheit
        fahrenheit = (celsius * 9 / 5) + 32;

        // Display the result
        printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit\n", celsius, fahrenheit);
        break;

      case '2':
        // Get the Fahrenheit temperature
        printf("Enter the Fahrenheit temperature: ");
        scanf(" %f", &fahrenheit);

        // Convert Fahrenheit to Celsius
        celsius = (fahrenheit - 32) * 5 / 9;

        // Display the result
        printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius\n", fahrenheit, celsius);
        break;

      case '3':
        // Exit the program
        printf("Exiting the program...\n");
        exit(0);

      default:
        // Invalid choice
        printf("Invalid choice. Please enter 1, 2, or 3.\n");
        break;
    }
  }

  return 0;
}