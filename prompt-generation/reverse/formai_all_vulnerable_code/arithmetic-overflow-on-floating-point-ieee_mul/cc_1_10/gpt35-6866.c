//FormAI DATASET v1.0 Category: Temperature Converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
  return (celsius * 9/5) + 32;
}

// Function to convert Celsius to Kelvin
double celsiusToKelvin(double celsius) {
  return celsius + 273.15;
}

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
  return (fahrenheit - 32) * 5/9;
}

// Function to convert Fahrenheit to Kelvin
double fahrenheitToKelvin(double fahrenheit) {
  return (fahrenheit - 32) * 5/9 + 273.15;
}

// Function to convert Kelvin to Celsius
double kelvinToCelsius(double kelvin) {
  return kelvin - 273.15;
}

// Function to convert Kelvin to Fahrenheit
double kelvinToFahrenheit(double kelvin) {
  return (kelvin - 273.15) * 9/5 + 32;
}

int main() {
  int choice;
  double temp;

  printf("***TEMPERATURE CONVERTER***\n\n");
  
  // Loop through options until user chooses to exit
  do {
    printf("Please select an option:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Celsius to Kelvin\n");
    printf("3. Fahrenheit to Celsius\n");
    printf("4. Fahrenheit to Kelvin\n");
    printf("5. Kelvin to Celsius\n");
    printf("6. Kelvin to Fahrenheit\n");
    printf("7. Exit\n");
    printf("Choice: ");
    scanf("%d", &choice);

    // Process user input based on chosen option
    switch (choice) {
      case 1:
        printf("Enter temperature in Celsius: ");
        scanf("%lf", &temp);
        printf("%.2lfC = %.2lfF\n\n", temp, celsiusToFahrenheit(temp));
        break;
      case 2:
        printf("Enter temperature in Celsius: ");
        scanf("%lf", &temp);
        printf("%.2lfC = %.2lfK\n\n", temp, celsiusToKelvin(temp));
        break;
      case 3:
        printf("Enter temperature in Fahrenheit: ");
        scanf("%lf", &temp);
        printf("%.2lfF = %.2lfC\n\n", temp, fahrenheitToCelsius(temp));
        break;
      case 4:
        printf("Enter temperature in Fahrenheit: ");
        scanf("%lf", &temp);
        printf("%.2lfF = %.2lfK\n\n", temp, fahrenheitToKelvin(temp));
        break;
      case 5:
        printf("Enter temperature in Kelvin: ");
        scanf("%lf", &temp);
        printf("%.2lfK = %.2lfC\n\n", temp, kelvinToCelsius(temp));
        break;
      case 6:
        printf("Enter temperature in Kelvin: ");
        scanf("%lf", &temp);
        printf("%.2lfK = %.2lfF\n\n", temp, kelvinToFahrenheit(temp));
        break;
      case 7:
        printf("Goodbye!\n");
        break;
      default:
        printf("Invalid choice. Please try again.\n\n");
        break;
    }
  } while (choice != 7);

  return 0;
}