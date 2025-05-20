//FormAI DATASET v1.0 Category: Temperature Converter ; Style: recursive
#include <stdio.h>

// Declare function signature
float celsius_to_fahrenheit(float);
float fahrenheit_to_celsius(float);

int main() {
  int option;
  float temperature, result;

  do {
    printf("Choose an option:\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    printf("3. Exit\n");
    scanf("%d", &option);

    switch (option) {
      case 1:
        printf("Enter temperature in Celsius: ");
        scanf("%f", &temperature);
        result = celsius_to_fahrenheit(temperature);
        printf("%.2f Celsius = %.2f Fahrenheit\n", temperature, result);
        break;
      case 2:
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &temperature);
        result = fahrenheit_to_celsius(temperature);
        printf("%.2f Fahrenheit = %.2f Celsius\n", temperature, result);
        break;
      case 3:
        printf("Exiting...\n");
        break;
      default:
        printf("Invalid option\n");
    }
  } while (option != 3);

  return 0;
}

// Function to convert Celsius to Fahrenheit recursively
float celsius_to_fahrenheit(float celsius) {
  if (celsius == 0) {
    return 32;
  } else {
    return (1.8 * celsius_to_fahrenheit(celsius - 1)) + 32;
  }
}

// Function to convert Fahrenheit to Celsius recursively
float fahrenheit_to_celsius(float fahrenheit) {
  if (fahrenheit == 32) {
    return 0;
  } else {
    return (fahrenheit_to_celsius(fahrenheit - 1) - 32) / 1.8;
  }
}