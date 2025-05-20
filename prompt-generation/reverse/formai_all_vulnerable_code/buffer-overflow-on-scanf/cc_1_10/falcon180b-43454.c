//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  char choice;
  float temp, converted;

  printf("Temperature Converter\n");
  printf("----------------------\n");
  printf("1. Celsius to Fahrenheit\n");
  printf("2. Celsius to Kelvin\n");
  printf("3. Fahrenheit to Celsius\n");
  printf("4. Fahrenheit to Kelvin\n");
  printf("5. Kelvin to Celsius\n");
  printf("6. Kelvin to Fahrenheit\n");
  printf("7. Quit\n");

  scanf("%c", &choice);

  switch(choice) {
    case '1':
      printf("Enter temperature in Celsius: ");
      scanf("%f", &temp);

      converted = (temp * 1.8) + 32;

      printf("%.2f Celsius = %.2f Fahrenheit\n", temp, converted);
      break;
    case '2':
      printf("Enter temperature in Celsius: ");
      scanf("%f", &temp);

      converted = temp + 273.15;

      printf("%.2f Celsius = %.2f Kelvin\n", temp, converted);
      break;
    case '3':
      printf("Enter temperature in Fahrenheit: ");
      scanf("%f", &temp);

      converted = (temp - 32) / 1.8;

      printf("%.2f Fahrenheit = %.2f Celsius\n", temp, converted);
      break;
    case '4':
      printf("Enter temperature in Fahrenheit: ");
      scanf("%f", &temp);

      converted = (temp + 459.67) * 5/9;

      printf("%.2f Fahrenheit = %.2f Kelvin\n", temp, converted);
      break;
    case '5':
      printf("Enter temperature in Kelvin: ");
      scanf("%f", &temp);

      converted = temp - 273.15;

      printf("%.2f Kelvin = %.2f Celsius\n", temp, converted);
      break;
    case '6':
      printf("Enter temperature in Kelvin: ");
      scanf("%f", &temp);

      converted = (temp - 273.15) * 1.8 + 32;

      printf("%.2f Kelvin = %.2f Fahrenheit\n", temp, converted);
      break;
    case '7':
      exit(0);
    default:
      printf("Invalid choice\n");
      exit(0);
  }

  return 0;
}