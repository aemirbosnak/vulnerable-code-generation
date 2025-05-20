//Gemma-7B DATASET v1.0 Category: Temperature Converter ; Style: modular
#include <stdio.h>

int convert_celsius_to_fahrenheit(int celsius) {
  return (celsius * 9 / 5) + 32;
}

int convert_fahrenheit_to_celsius(int fahrenheit) {
  return (fahrenheit - 32) * 5 / 9;
}

int main() {
  int choice, temperature, unit_from, unit_to;

  printf("Enter 1 for Celsius to Fahrenheit or 2 for Fahrenheit to Celsius: ");
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      printf("Enter the temperature in Celsius: ");
      scanf("%d", &temperature);
      unit_from = 0;
      unit_to = 1;
      break;
    case 2:
      printf("Enter the temperature in Fahrenheit: ");
      scanf("%d", &temperature);
      unit_from = 1;
      unit_to = 0;
      break;
    default:
      printf("Invalid input.\n");
      return 1;
  }

  printf("Enter the units you want to convert from (0 for Celsius, 1 for Fahrenheit): ");
  scanf("%d", &unit_from);

  printf("Enter the units you want to convert to (0 for Celsius, 1 for Fahrenheit): ");
  scanf("%d", &unit_to);

  switch (unit_from) {
    case 0:
      temperature = convert_celsius_to_fahrenheit(temperature);
      break;
    case 1:
      temperature = convert_fahrenheit_to_celsius(temperature);
      break;
    default:
      printf("Invalid input.\n");
      return 1;
  }

  switch (unit_to) {
    case 0:
      printf("The temperature in Celsius is: %d\n", temperature);
      break;
    case 1:
      printf("The temperature in Fahrenheit is: %d\n", temperature);
      break;
    default:
      printf("Invalid input.\n");
      return 1;
  }

  return 0;
}