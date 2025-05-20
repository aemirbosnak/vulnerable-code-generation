//FormAI DATASET v1.0 Category: Unit converter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

// function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float C) {
  return (C * 9/5) + 32;
}

// function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float F) {
  return (F - 32) * 5/9;
}

int main() {
  float temperature;
  char choice;

  printf("Welcome to the Temperature Converter!\n\n");

  do {
    printf("Enter the temperature: ");
    scanf("%f", &temperature);

    printf("Select an option:\n");
    printf("a) Celsius to Fahrenheit\n");
    printf("b) Fahrenheit to Celsius\n");
    printf("Your choice: ");
    scanf(" %c", &choice);

    switch (choice) {
      case 'a':
        printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n\n", temperature, celsiusToFahrenheit(temperature));
        break;
      case 'b':
        printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n\n", temperature, fahrenheitToCelsius(temperature));
        break;
      default:
        printf("Invalid option! Please try again.\n\n");
    }

    printf("Would you like to convert another temperature? (y/n) ");
    scanf(" %c", &choice);
    printf("\n");

  } while (choice == 'y' || choice == 'Y');

  printf("Thank you for using the Temperature Converter!\n");

  return 0;
}