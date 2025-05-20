//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: inquisitive
#include <stdio.h>

int main() {
  // Declare variables
  float celsius, fahrenheit, kelvin;
  int choice;

  // Display a welcoming message
  printf("Welcome to the Temperature Converter!\n");

  // Prompt the user to select a conversion type
  printf("Please select a conversion type:\n");
  printf("1. Celsius to Fahrenheit\n");
  printf("2. Fahrenheit to Celsius\n");
  printf("3. Celsius to Kelvin\n");
  printf("4. Kelvin to Celsius\n");
  scanf("%d", &choice);

  // Perform the conversion based on the user's choice
  switch (choice) {
    case 1:
      // Convert Celsius to Fahrenheit
      printf("Enter the temperature in Celsius: ");
      scanf("%f", &celsius);
      fahrenheit = (celsius * 9 / 5) + 32;
      printf("The temperature in Fahrenheit is: %.2f\n", fahrenheit);
      break;

    case 2:
      // Convert Fahrenheit to Celsius
      printf("Enter the temperature in Fahrenheit: ");
      scanf("%f", &fahrenheit);
      celsius = (fahrenheit - 32) * 5 / 9;
      printf("The temperature in Celsius is: %.2f\n", celsius);
      break;

    case 3:
      // Convert Celsius to Kelvin
      printf("Enter the temperature in Celsius: ");
      scanf("%f", &celsius);
      kelvin = celsius + 273.15;
      printf("The temperature in Kelvin is: %.2f\n", kelvin);
      break;

    case 4:
      // Convert Kelvin to Celsius
      printf("Enter the temperature in Kelvin: ");
      scanf("%f", &kelvin);
      celsius = kelvin - 273.15;
      printf("The temperature in Celsius is: %.2f\n", celsius);
      break;

    default:
      // Handle invalid choice
      printf("Invalid choice. Please select a valid conversion type.\n");
  }

  // Display a thank you message
  printf("Thank you for using the Temperature Converter!\n");

  return 0;
}