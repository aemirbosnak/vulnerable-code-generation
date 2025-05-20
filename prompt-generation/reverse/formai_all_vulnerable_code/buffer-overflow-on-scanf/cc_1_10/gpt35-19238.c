//FormAI DATASET v1.0 Category: Unit converter ; Style: Cyberpunk
#include <stdio.h>

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
  float fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
  return fahrenheit;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
  float celsius = (fahrenheit - 32.0) * 5.0 / 9.0;
  return celsius;
}

// Function to convert miles to kilometers
float milesToKilometers(float miles) {
  float kilometers = miles * 1.60934;
  return kilometers;
}

// Function to convert kilometers to miles
float kilometersToMiles(float kilometers) {
  float miles = kilometers / 1.60934;
  return miles;
}

void printCyberpunkLine() {
  printf("----------------------\n");
}

int main() {
  int choice;
  float value;

  printf("Welcome to the Cyberpunk Unit Converter!\n");

  do {
    printCyberpunkLine();
    printf("\nSelect an option:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Miles to Kilometers\n");
    printf("4. Kilometers to Miles\n");
    printf("5. Exit\n");

    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("\nEnter a value in Celsius: ");
        scanf("%f", &value);
        printf("%.2f Celsius = %.2f Fahrenheit\n", value, celsiusToFahrenheit(value));
        break;
      case 2:
        printf("\nEnter a value in Fahrenheit: ");
        scanf("%f", &value);
        printf("%.2f Fahrenheit = %.2f Celsius\n", value, fahrenheitToCelsius(value));
        break;
      case 3:
        printf("\nEnter a value in miles: ");
        scanf("%f", &value);
        printf("%.2f miles = %.2f kilometers\n", value, milesToKilometers(value));
        break;
      case 4:
        printf("\nEnter a value in kilometers: ");
        scanf("%f", &value);
        printf("%.2f kilometers = %.2f miles\n", value, kilometersToMiles(value));
        break;
      case 5:
        printf("\nGoodbye, Netrunner!\n");
        break;
      default:
        printf("\nInvalid option!\n");
        break;
    }
  } while (choice != 5);

  return 0;
}