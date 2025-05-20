//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
  // Formula: Fahrenheit = (Celsius * 9 / 5) + 32
  float fahrenheit = (celsius * 9 / 5) + 32;
  return fahrenheit;
}

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
  // Formula: Celsius = (Fahrenheit - 32) * 5 / 9
  float celsius = (fahrenheit - 32) * 5 / 9;
  return celsius;
}

// Function to display the menu and get user input
int get_user_input() {
  printf("\nTemperature Converter\n");
  printf("----------------------\n");
  printf("1. Celsius to Fahrenheit\n");
  printf("2. Fahrenheit to Celsius\n");
  printf("3. Quit\n");
  printf("Enter your choice: ");

  int choice;
  scanf("%d", &choice);
  return choice;
}

// Function to run the temperature conversion
void run_temperature_conversion(int choice) {
  float temperature;
  float converted_temperature;

  switch (choice) {
    case 1:
      printf("Enter temperature in Celsius: ");
      scanf("%f", &temperature);
      converted_temperature = celsius_to_fahrenheit(temperature);
      printf("%f degrees Celsius is equal to %f degrees Fahrenheit\n", temperature, converted_temperature);
      break;
    case 2:
      printf("Enter temperature in Fahrenheit: ");
      scanf("%f", &temperature);
      converted_temperature = fahrenheit_to_celsius(temperature);
      printf("%f degrees Fahrenheit is equal to %f degrees Celsius\n", temperature, converted_temperature);
      break;
    case 3:
      printf("Exiting...\n");
      exit(0);
    default:
      printf("Invalid choice. Please enter a valid number.\n");
  }
}

// Main function
int main() {
  int choice;

  do {
    choice = get_user_input();
    run_temperature_conversion(choice);
  } while (choice != 3);

  return 0;
}