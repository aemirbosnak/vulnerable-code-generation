//FormAI DATASET v1.0 Category: Unit converter ; Style: ultraprecise
#include<stdio.h>

/* Function to convert Celsius to Fahrenheit */
double celsiusToFahrenheit(double celsius) {
  return (celsius * 9 / 5) + 32;
}

/* Function to convert Fahrenheit to Celsius */
double fahrenheitToCelsius(double fahrenheit) {
  return (fahrenheit - 32) * 5 / 9;
}

/* Function to convert Celsius to Kelvin */
double celsiusToKelvin(double celsius) {
  return celsius + 273.15;
}

/* Function to convert Kelvin to Celsius */
double kelvinToCelsius(double kelvin) {
  return kelvin - 273.15;
}

/* Function to convert Fahrenheit to Kelvin */
double fahrenheitToKelvin(double fahrenheit) {
  return (fahrenheit + 459.67) * 5 / 9;
}

/* Function to convert Kelvin to Fahrenheit */
double kelvinToFahrenheit(double kelvin) {
  return kelvin * 9 / 5 - 459.67;
}

int main() {
  double temperature;
  int choice;

  printf("Enter temperature: ");
  scanf("%lf", &temperature);

  printf("Select conversion: \n");
  printf("1. Celsius to Fahrenheit\n");
  printf("2. Fahrenheit to Celsius\n");
  printf("3. Celsius to Kelvin\n");
  printf("4. Kelvin to Celsius\n");
  printf("5. Fahrenheit to Kelvin\n");
  printf("6. Kelvin to Fahrenheit\n");
  printf("Enter choice: ");
  scanf("%d", &choice);

  switch(choice) {
    case 1: printf("%.2f Celsius = %.2f Fahrenheit\n", temperature, celsiusToFahrenheit(temperature));
            break;

    case 2: printf("%.2f Fahrenheit = %.2f Celsius\n", temperature, fahrenheitToCelsius(temperature));
            break;

    case 3: printf("%.2f Celsius = %.2f Kelvin\n", temperature, celsiusToKelvin(temperature));
            break;

    case 4: printf("%.2f Kelvin = %.2f Celsius\n", temperature, kelvinToCelsius(temperature));
            break;

    case 5: printf("%.2f Fahrenheit = %.2f Kelvin\n", temperature, fahrenheitToKelvin(temperature));
            break;

    case 6: printf("%.2f Kelvin = %.2f Fahrenheit\n", temperature, kelvinToFahrenheit(temperature));
            break;

    default: printf("Invalid choice\n");
             break;
  }

  return 0;
}