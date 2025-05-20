#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int metric_unit, imperial_unit, value;
  float converted_value;

  printf("Enter the unit you want to convert from (m/kg/l or lb/in/gal): ");
  scanf("%d", &imperial_unit);

  printf("Enter the value you want to convert: ");
  scanf("%d", &value);

  switch (imperial_unit) {
    case 1:
      converted_value = (float)value * 1.613;
      printf("The converted value is: %.2f kg\n", converted_value);
      break;
    case 2:
      converted_value = (float)value * 2.205;
      printf("The converted value is: %.2f lb\n", converted_value);
      break;
    case 3:
      converted_value = (float)value * 0.001;
      printf("The converted value is: %.2f l\n", converted_value);
      break;
    case 4:
      converted_value = (float)value * 0.001;
      printf("The converted value is: %.2f gal\n", converted_value);
      break;
    default:
      printf("Invalid unit selection\n");
  }

  return 0;
}
