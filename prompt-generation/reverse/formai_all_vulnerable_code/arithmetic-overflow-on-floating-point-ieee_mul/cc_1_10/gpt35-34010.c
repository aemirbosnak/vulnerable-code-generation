//FormAI DATASET v1.0 Category: Unit converter ; Style: authentic
#include <stdio.h>

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
  return (celsius * 9 / 5) + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
  return (fahrenheit - 32) * 5 / 9;
}

// Function to convert Celsius to Kelvin
float celsiusToKelvin(float celsius) {
  return celsius + 273.15;
}

// Function to convert Kelvin to Celsius
float kelvinToCelsius(float kelvin) {
  return kelvin - 273.15;
}

// Function to convert Fahrenheit to Kelvin
float fahrenheitToKelvin(float fahrenheit) {
  return (fahrenheit - 32) * 5 / 9 + 273.15;
}

// Function to convert Kelvin to Fahrenheit
float kelvinToFahrenheit(float kelvin) {
  return (kelvin - 273.15) * 9 / 5 + 32;
}

// Function to display menu and get user choice
int getMenuChoice() {
  int choice;

  printf("Enter 1 for Celsius to Fahrenheit conversion\n");
  printf("Enter 2 for Fahrenheit to Celsius conversion\n");
  printf("Enter 3 for Celsius to Kelvin conversion\n");
  printf("Enter 4 for Kelvin to Celsius conversion\n");
  printf("Enter 5 for Fahrenheit to Kelvin conversion\n");
  printf("Enter 6 for Kelvin to Fahrenheit conversion\n");
  printf("Enter 7 to quit\n");

  scanf("%d", &choice);

  return choice;
}

int main() {

  int choice;
  float temperature, result;

  do {
    choice = getMenuChoice();

    switch (choice) {
      case 1:
        printf("Enter temperature in Celsius: ");
        scanf("%f", &temperature);
        result = celsiusToFahrenheit(temperature);
        printf("%.2f Celsius = %.2f Fahrenheit\n", temperature, result);
        break;
      case 2:
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &temperature);
        result = fahrenheitToCelsius(temperature);
        printf("%.2f Fahrenheit = %.2f Celsius\n", temperature, result);
        break;
      case 3:
        printf("Enter temperature in Celsius: ");
        scanf("%f", &temperature);
        result = celsiusToKelvin(temperature);
        printf("%.2f Celsius = %.2f Kelvin\n", temperature, result);
        break;
      case 4:
        printf("Enter temperature in Kelvin: ");
        scanf("%f", &temperature);
        result = kelvinToCelsius(temperature);
        printf("%.2f Kelvin = %.2f Celsius\n", temperature, result);
        break;
      case 5:
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &temperature);
        result = fahrenheitToKelvin(temperature);
        printf("%.2f Fahrenheit = %.2f Kelvin\n", temperature, result);
        break;
      case 6:
        printf("Enter temperature in Kelvin: ");
        scanf("%f", &temperature);
        result = kelvinToFahrenheit(temperature);
        printf("%.2f Kelvin = %.2f Fahrenheit\n", temperature, result);
        break;
      case 7:
        printf("Exiting...\n");
        break;
      default:
        printf("Invalid choice\n");
        break;
    }

    printf("\n");

  } while (choice != 7);

  return 0;
}