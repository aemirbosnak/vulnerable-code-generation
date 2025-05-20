#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <math.h>

float convert_temp(int temp, int unit) {
  switch (unit) {
    case 0:
      return (temp * 5.0 / 9.0) + 32.0;
    case 1:
      return (temp - 32.0) * 9.0 / 5.0;
    default:
      return -1.0;
  }
}

int main() {
  int temp;
  int unit_from, unit_to;

  printf("Enter the temperature: ");
  scanf("%d", &temp);

  printf("Enter the unit of the temperature (0 for Celsius, 1 for Fahrenheit): ");
  scanf("%d", &unit_from);

  printf("Enter the unit of the temperature you want to convert to (0 for Celsius, 1 for Fahrenheit): ");
  scanf("%d", &unit_to);

  float converted_temp = convert_temp(temp, unit_from);

  if (converted_temp != -1.0) {
    printf("The converted temperature is: %.2f", converted_temp);
  } else {
    printf("Error: Invalid input or conversion failed.");
  }

  return 0;
}
