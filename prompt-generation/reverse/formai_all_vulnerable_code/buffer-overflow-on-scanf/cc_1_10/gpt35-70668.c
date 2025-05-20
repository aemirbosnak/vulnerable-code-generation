//FormAI DATASET v1.0 Category: Unit converter ; Style: grateful
#include <stdio.h>

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
  float fahrenheit = (celsius * 9 / 5) + 32;
  return fahrenheit;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
  float celsius = (fahrenheit - 32) * 5 / 9;
  return celsius;
}

int main() {
  float temp;
  char choice;

  printf("\nWelcome to the Grateful Unit Converter!");

  do {
    printf("\n\nEnter the temperature: ");
    scanf("%f", &temp);

    printf("\nSelect the conversion option:");
    printf("\n1. Celsius to Fahrenheit");
    printf("\n2. Fahrenheit to Celsius");
    printf("\nYour choice: ");
    getchar();  // To clear the buffer
    scanf("%c", &choice);

    switch(choice) {
      case '1':
        printf("\n%.2f Celsius = %.2f Fahrenheit\n", temp, celsiusToFahrenheit(temp));
        break;
      case '2':
        printf("\n%.2f Fahrenheit = %.2f Celsius\n", temp, fahrenheitToCelsius(temp));
        break;
      default:
        printf("\nInvalid Choice! Please Try Again\n");
    }

    printf("\nDo you want to continue? (y/n): ");
    getchar();  // To clear the buffer
    scanf("%c", &choice);

  } while(choice == 'y' || choice == 'Y');

  printf("\n\nThank you for using Grateful Unit Converter!\n\n");

  return 0;
}