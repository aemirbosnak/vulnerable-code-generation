//Code Llama-13B DATASET v1.0 Category: Unit converter ; Style: surprised
// Unit Converter
// Program to convert units of measurement

#include <stdio.h>

int main() {
  float input, output;
  char unit_from, unit_to;

  printf("Enter a value: ");
  scanf("%f", &input);

  printf("Enter the unit of measurement (e.g. m for meters): ");
  scanf(" %c", &unit_from);

  printf("Enter the unit to convert to (e.g. cm for centimeters): ");
  scanf(" %c", &unit_to);

  switch (unit_from) {
    case 'm':
      if (unit_to == 'cm') {
        output = input * 100;
      } else if (unit_to == 'km') {
        output = input * 0.001;
      } else {
        output = input;
      }
      break;
    case 'cm':
      if (unit_to == 'm') {
        output = input * 0.01;
      } else if (unit_to == 'km') {
        output = input * 0.000001;
      } else {
        output = input;
      }
      break;
    case 'km':
      if (unit_to == 'm') {
        output = input * 1000;
      } else if (unit_to == 'cm') {
        output = input * 100000;
      } else {
        output = input;
      }
      break;
    default:
      output = input;
  }

  printf("The converted value is %f %c\n", output, unit_to);

  return 0;
}