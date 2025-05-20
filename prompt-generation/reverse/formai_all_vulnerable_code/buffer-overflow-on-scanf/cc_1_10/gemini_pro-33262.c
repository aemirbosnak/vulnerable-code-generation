//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: calm
/***********************************************************************
* Program : Temperature Converter
*
* Description:
* This program converts temperatures between Fahrenheit and Celsius.
* The user can enter a temperature in either Fahrenheit or Celsius,
* and the program will convert it to the other unit.
*
* Input:
* The user is prompted to enter a temperature and a unit of measure
* (Fahrenheit or Celsius).
*
* Output:
* The program displays the converted temperature.
*
***********************************************************************/

#include <stdio.h>  // for printf, scanf
#include <stdlib.h> // for exit

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
  return (fahrenheit - 32) * 5 / 9;
}

// Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
  return (celsius * 9 / 5) + 32;
}

int main() {
  float temperature;
  char unit;

  // Prompt the user to enter a temperature and a unit of measure
  printf("Enter a temperature and a unit of measure (F/C): ");
  scanf("%f %c", &temperature, &unit);

  // Convert the temperature to the other unit
  if (unit == 'F') {
    temperature = fahrenheit_to_celsius(temperature);
  } else if (unit == 'C') {
    temperature = celsius_to_fahrenheit(temperature);
  } else {
    // If the user enters an invalid unit, display an error message and exit
    printf("Invalid unit of measure. Please enter F or C.\n");
    exit(1);
  }

  // Display the converted temperature
  printf("The converted temperature is: %.2f %c\n", temperature,
         (unit == 'F') ? 'C' : 'F');

  return 0;
}