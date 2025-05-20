//Gemma-7B DATASET v1.0 Category: Temperature Converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159

int main() {
  // Variables
  float temperature;
  char unit;
  float converted_temperature;
  int choice;

  // Display menu options
  printf("Choose an option:\n");
  printf("1. Convert Fahrenheit to Celsius\n");
  printf("2. Convert Celsius to Fahrenheit\n");
  printf("3. Convert Kelvin to Celsius\n");
  printf("4. Convert Celsius to Kelvin\n");

  // Get user input
  scanf("Enter your choice: ", &choice);

  // Calculate conversion factor based on user choice
  switch (choice) {
    case 1:
      converted_temperature = (temperature - 32) * 5 / 9;
      unit = 'C';
      break;
    case 2:
      converted_temperature = (temperature * 9 / 5) + 32;
      unit = 'F';
      break;
    case 3:
      converted_temperature = temperature - 273.15;
      unit = 'K';
      break;
    case 4:
      converted_temperature = temperature + 273.15;
      unit = 'K';
      break;
    default:
      printf("Invalid input.\n");
      return 1;
  }

  // Display converted temperature
  printf("Converted temperature: %.2f %c\n", converted_temperature, unit);

  return 0;
}