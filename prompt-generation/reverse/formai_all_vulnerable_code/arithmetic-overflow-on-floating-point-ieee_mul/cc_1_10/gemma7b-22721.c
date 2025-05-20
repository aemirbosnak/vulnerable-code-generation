//Gemma-7B DATASET v1.0 Category: Temperature Converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main() {
  int choice, unit_from, unit_to;
  float temperature;

  printf("Welcome to the Temperature Converter!\n");
  printf("Please select an option:\n");
  printf("1. Fahrenheit to Celsius\n");
  printf("2. Celsius to Fahrenheit\n");
  printf("3. Kelvin to Celsius\n");
  printf("4. Celsius to Kelvin\n");

  scanf("%d", &choice);

  switch (choice) {
    case 1:
      unit_from = 1;
      unit_to = 2;
      break;
    case 2:
      unit_from = 2;
      unit_to = 1;
      break;
    case 3:
      unit_from = 3;
      unit_to = 2;
      break;
    case 4:
      unit_from = 2;
      unit_to = 3;
      break;
    default:
      printf("Invalid choice.\n");
      return;
  }

  printf("Enter the temperature: ");
  scanf("%f", &temperature);

  switch (unit_from) {
    case 1:
      temperature = (temperature - 32) * 5 / 9;
      break;
    case 2:
      temperature = (temperature * 9 / 5) + 32;
      break;
    case 3:
      temperature = temperature - 273.15;
      break;
    case 4:
      temperature = temperature + 273.15;
      break;
  }

  printf("The converted temperature is: %.2f %s.\n", temperature, unit_to);

  return;
}