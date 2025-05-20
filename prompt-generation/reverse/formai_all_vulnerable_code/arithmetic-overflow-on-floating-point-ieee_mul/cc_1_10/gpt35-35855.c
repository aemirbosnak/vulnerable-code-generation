//FormAI DATASET v1.0 Category: Temperature Converter ; Style: shocked
#include <stdio.h>

int main() {
  char input_unit;
  char output_unit;
  float input_value, output_value;

  printf("Hello! Welcome to the Celsius/Fahrenheit/Kelvin Temperature Converter!\n\n");

  printf("Please enter temperature value: ");
  scanf("%f", &input_value);

  printf("Please enter temperature unit (C, F or K): ");
  scanf(" %c", &input_unit);

  printf("Please enter desired output unit (C, F or K): ");
  scanf(" %c", &output_unit);

  if (input_unit == 'C') {
    if (output_unit == 'F') {    // Celsius to Fahrenheit conversion
      output_value = (input_value * 9/5) + 32;
      printf("%f degrees Celsius is equal to %f degrees Fahrenheit.\n", input_value, output_value);
    } else if (output_unit == 'K') {    // Celsius to Kelvin conversion
      output_value = input_value + 273.15;
      printf("%f degrees Celsius is equal to %f Kelvin.\n", input_value, output_value);
    } else {
      printf("Invalid output unit. Please try again.\n");
      return 0;
    }
  } else if (input_unit == 'F') {
    if (output_unit == 'C') {    // Fahrenheit to Celsius conversion
      output_value = (input_value - 32) * 5/9;
      printf("%f degrees Fahrenheit is equal to %f degrees Celsius.\n", input_value, output_value);
    } else if (output_unit == 'K') {    // Fahrenheit to Kelvin conversion
      output_value = (input_value + 459.67) * 5/9;
      printf("%f degrees Fahrenheit is equal to %f Kelvin.\n", input_value, output_value);
    } else {
      printf("Invalid output unit. Please try again.\n");
      return 0;
    }
  } else if (input_unit == 'K') {
    if (output_unit == 'C') {    // Kelvin to Celsius conversion
      output_value = input_value - 273.15;
      printf("%f Kelvin is equal to %f degrees Celsius.\n", input_value, output_value);
    } else if (output_unit == 'F') {    // Kelvin to Fahrenheit conversion
      output_value = (input_value * 9/5) - 459.67;
      printf("%f Kelvin is equal to %f degrees Fahrenheit.\n", input_value, output_value);
    } else {
      printf("Invalid output unit. Please try again.\n");
      return 0;
    }
  } else {
    printf("Invalid input unit. Please try again.\n");
    return 0;
  }

  printf("Thank you for using our temperature converter! Have a nice day!\n");

  return 0;
}