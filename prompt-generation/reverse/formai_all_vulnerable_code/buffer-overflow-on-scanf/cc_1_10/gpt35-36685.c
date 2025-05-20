//FormAI DATASET v1.0 Category: Temperature Converter ; Style: satisfied
#include <stdio.h>

// Celsius to Fahrenheit conversion function
double CelsiusToFahrenheit(double celsius) {
  return (celsius * 9 / 5) + 32;
}

// Fahrenheit to Celsius conversion function
double FahrenheitToCelsius(double fahrenheit) {
  return (fahrenheit - 32) * 5 / 9;
}

int main() {
  char choice;
  double temp, convertedTemp;

  printf("Welcome to the Temperature Converter program!\n\n");

  // Display the menu to the user
  do {
    printf("--------------------------------------------------\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    printf("3. Exit the program\n");
    printf("--------------------------------------------------\n");
    printf("Enter your choice: ");
    scanf(" %c", &choice);

    switch (choice) {
      case '1':
        // Convert Celsius to Fahrenheit
        printf("\nEnter temperature in Celsius: ");
        scanf("%lf", &temp);
        convertedTemp = CelsiusToFahrenheit(temp);
        printf("\n%.2f degrees Celsius is %.2f degrees Fahrenheit.\n", temp, convertedTemp);
        break;

      case '2':
        // Convert Fahrenheit to Celsius
        printf("\nEnter temperature in Fahrenheit: ");
        scanf("%lf", &temp);
        convertedTemp = FahrenheitToCelsius(temp);
        printf("\n%.2f degrees Fahrenheit is %.2f degrees Celsius.\n", temp, convertedTemp);
        break;

      case '3':
        // Exit the program
        printf("\nThank you for using the Temperature Converter program!\n");
        break;

      default:
        printf("\nInvalid choice! Please try again.\n");
    }
  } while (choice != '3');

  return 0;
}