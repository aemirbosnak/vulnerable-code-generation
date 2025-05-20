//GEMINI-pro DATASET v1.0 Category: Temperature monitor ; Style: shape shifting
// Celsius to Fahrenheit Converter and Temperature Monitor
// A shape-shifting program that transforms itself from a simple converter to a sophisticated monitor

#include <stdio.h>

// Initializing variables
int choice, temp;
float celsius, fahrenheit;

void print_menu() {
  // Display the menu options
  printf("\n----- Temperature Monitor -----\n");
  printf("1. Convert Celsius to Fahrenheit\n");
  printf("2. Monitor Temperature\n");
  printf("3. Exit\n");
  printf("Enter your choice: ");
}

void convert_celsius_to_fahrenheit() {
  // Convert Celsius to Fahrenheit
  printf("Enter the temperature in Celsius: ");
  scanf("%f", &celsius);
  fahrenheit = (celsius * 9 / 5) + 32;
  printf("The temperature in Fahrenheit is: %.2f\n", fahrenheit);
}

void monitor_temperature() {
  // Monitor the temperature
  while (1) {
    printf("Enter the temperature in Celsius: ");
    scanf("%d", &temp);
    if (temp < 0) {
      printf("Temperature is below freezing!\n");
    } else if (temp >= 0 && temp <= 20) {
      printf("Temperature is mild.\n");
    } else if (temp > 20 && temp <= 30) {
      printf("Temperature is warm.\n");
    } else if (temp > 30) {
      printf("Temperature is hot!\n");
    }
    printf("Continue monitoring (1/0): ");
    scanf("%d", &choice);
    if (choice == 0) {
      break;
    }
  }
}

int main() {
  // Main function: the core of the program
  do {
    print_menu();
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        convert_celsius_to_fahrenheit();
        break;
      case 2:
        monitor_temperature();
        break;
      case 3:
        printf("Exiting...\n");
        break;
      default:
        printf("Invalid choice. Please try again.\n");
    }
  } while (choice != 3);
  return 0;
}