//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
  int choice;
  double temperature, converted_temperature;
  char unit;

  printf("Welcome to the Temperature Converter!\n");
  printf("Please enter your choice:\n");
  printf("1. Celsius to Fahrenheit\n");
  printf("2. Fahrenheit to Celsius\n");
  printf("3. Kelvin to Celsius\n");
  printf("4. Celsius to Kelvin\n");
  scanf("%d", &choice);

  printf("Enter the temperature: ");
  scanf("%lf", &temperature);

  printf("Enter the unit: ");
  scanf(" %c", &unit);

  switch(choice) {
    case 1:
      converted_temperature = (temperature * 9/5) + 32;
      printf("%lf %c = %lf %c\n", temperature, unit, converted_temperature, 'F');
      break;

    case 2:
      converted_temperature = (temperature - 32) * 5/9;
      printf("%lf %c = %lf %c\n", temperature, unit, converted_temperature, 'C');
      break;

    case 3:
      converted_temperature = temperature - 273.15;
      printf("%lf %c = %lf %c\n", temperature, unit, converted_temperature, 'C');
      break;

    case 4:
      converted_temperature = temperature + 273.15;
      printf("%lf %c = %lf %c\n", temperature, unit, converted_temperature, 'K');
      break;

    default:
      printf("Invalid choice!\n");
  }

  return 0;
}