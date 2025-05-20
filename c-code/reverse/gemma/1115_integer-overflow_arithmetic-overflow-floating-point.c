#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <limits.h>

int main() {
  int choice, temperature, converted_temperature;
  float f_to_c_factor = 1.8f, c_to_f_factor = 1.8f, f_temp, c_temp;

  printf("Enter 1 for Celsius-to-Fahrenheit conversion or 2 for Fahrenheit-to-Celsius conversion: ");
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      printf("Enter the temperature in Celsius: ");
      scanf("%d", &temperature);
      c_temp = (float)temperature;
      converted_temperature = (int)((c_temp * f_to_c_factor) + 32);
      printf("The converted temperature in Fahrenheit is: %d\n", converted_temperature);
      break;
    case 2:
      printf("Enter the temperature in Fahrenheit: ");
      scanf("%d", &temperature);
      f_temp = (float)temperature;
      converted_temperature = (int)((f_temp - 32) * c_to_f_factor);
      printf("The converted temperature in Celsius is: %d\n", converted_temperature);
      break;
    default:
      printf("Invalid input. Please try again.\n");
  }

  return 0;
}
