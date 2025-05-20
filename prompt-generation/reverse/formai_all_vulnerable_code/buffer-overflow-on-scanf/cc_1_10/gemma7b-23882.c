//Gemma-7B DATASET v1.0 Category: Temperature Converter ; Style: immersive
#include <stdio.h>
#include <math.h>

int main()
{
  float f_celsius, f_fahrenheit, f_kelvin;
  char choice;

  printf("Welcome to the Temperature Converter!\n");

  printf("Please choose an option:\n");
  printf("1. Convert Celsius to Fahrenheit\n");
  printf("2. Convert Fahrenheit to Celsius\n");
  printf("3. Convert Kelvin to Celsius\n");
  printf("4. Convert Celsius to Kelvin\n");

  scanf(" %c", &choice);

  switch (choice)
  {
    case '1':
      printf("Enter the temperature in Celsius:");
      scanf(" %f", &f_celsius);
      f_fahrenheit = (f_celsius * 9.0 / 5.0) + 32.0;
      printf("The temperature in Fahrenheit is: %.2f", f_fahrenheit);
      break;

    case '2':
      printf("Enter the temperature in Fahrenheit:");
      scanf(" %f", &f_fahrenheit);
      f_celsius = (f_fahrenheit - 32.0) * 5.0 / 9.0;
      printf("The temperature in Celsius is: %.2f", f_celsius);
      break;

    case '3':
      printf("Enter the temperature in Kelvin:");
      scanf(" %f", &f_kelvin);
      f_celsius = f_kelvin - 273.15;
      printf("The temperature in Celsius is: %.2f", f_celsius);
      break;

    case '4':
      printf("Enter the temperature in Celsius:");
      scanf(" %f", &f_celsius);
      f_kelvin = f_celsius + 273.15;
      printf("The temperature in Kelvin is: %.2f", f_kelvin);
      break;

    default:
      printf("Invalid choice\n");
  }

  return 0;
}