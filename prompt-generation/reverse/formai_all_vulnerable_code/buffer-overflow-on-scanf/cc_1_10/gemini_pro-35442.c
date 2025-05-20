//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

// Constants for conversion factors
#define METERS_TO_FEET 3.28084
#define FEET_TO_METERS 0.3048
#define KILOS_TO_POUNDS 2.20462
#define POUNDS_TO_KILOS 0.453592
#define CELSIUS_TO_FAHRENHEIT 1.8
#define FAHRENHEIT_TO_CELSIUS 0.555556

// Function to convert meters to feet
float meters_to_feet(float meters) {
  return meters * METERS_TO_FEET;
}

// Function to convert feet to meters
float feet_to_meters(float feet) {
  return feet * FEET_TO_METERS;
}

// Function to convert kilos to pounds
float kilos_to_pounds(float kilos) {
  return kilos * KILOS_TO_POUNDS;
}

// Function to convert pounds to kilos
float pounds_to_kilos(float pounds) {
  return pounds * POUNDS_TO_KILOS;
}

// Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
  return celsius * CELSIUS_TO_FAHRENHEIT + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
  return (fahrenheit - 32) * FAHRENHEIT_TO_CELSIUS;
}

// Function to print a menu of conversion options
void print_menu() {
  printf("Unit Converter\n");
  printf("----------------\n");
  printf("1. Meters to Feet\n");
  printf("2. Feet to Meters\n");
  printf("3. Kilos to Pounds\n");
  printf("4. Pounds to Kilos\n");
  printf("5. Celsius to Fahrenheit\n");
  printf("6. Fahrenheit to Celsius\n");
  printf("7. Quit\n");
  printf("----------------\n");
  printf("Enter your choice: ");
}

int main() {
  // Declare variables
  int choice;
  float value;
  float result;

  // Loop until the user chooses to quit
  while (1) {
    // Print the menu
    print_menu();

    // Get the user's choice
    scanf("%d", &choice);

    // Perform the conversion based on the user's choice
    switch (choice) {
      case 1:
        printf("Enter the value in meters: ");
        scanf("%f", &value);
        result = meters_to_feet(value);
        printf("%f meters is equal to %f feet.\n", value, result);
        break;
      case 2:
        printf("Enter the value in feet: ");
        scanf("%f", &value);
        result = feet_to_meters(value);
        printf("%f feet is equal to %f meters.\n", value, result);
        break;
      case 3:
        printf("Enter the value in kilos: ");
        scanf("%f", &value);
        result = kilos_to_pounds(value);
        printf("%f kilos is equal to %f pounds.\n", value, result);
        break;
      case 4:
        printf("Enter the value in pounds: ");
        scanf("%f", &value);
        result = pounds_to_kilos(value);
        printf("%f pounds is equal to %f kilos.\n", value, result);
        break;
      case 5:
        printf("Enter the temperature in Celsius: ");
        scanf("%f", &value);
        result = celsius_to_fahrenheit(value);
        printf("%f Celsius is equal to %f Fahrenheit.\n", value, result);
        break;
      case 6:
        printf("Enter the temperature in Fahrenheit: ");
        scanf("%f", &value);
        result = fahrenheit_to_celsius(value);
        printf("%f Fahrenheit is equal to %f Celsius.\n", value, result);
        break;
      case 7:
        printf("Exiting the program.\n");
        exit(0);
      default:
        printf("Invalid choice. Please enter a number between 1 and 7.\n");
    }
  }

  return 0;
}