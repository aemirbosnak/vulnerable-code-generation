//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: lively
#include <stdio.h>
#include <stdlib.h>

void convert_units(float value, char from_unit, char to_unit) {
  switch (from_unit) {
    case 'm':
      switch (to_unit) {
        case 'km':
          value *= 1000;
          break;
        case 'cm':
          value *= 100;
          break;
        case 'dm':
          value *= 10;
          break;
        default:
          printf("Error: Invalid unit conversion.\n");
          break;
      }
      break;
    case 'kg':
      switch (to_unit) {
        case 'g':
          value *= 1000;
          break;
        case 't':
          value *= 1000000;
          break;
        default:
          printf("Error: Invalid unit conversion.\n");
          break;
      }
      break;
    default:
      printf("Error: Invalid unit conversion.\n");
      break;
  }

  printf("Converted value: %.2f %s.\n", value, to_unit);
}

int main() {
  float value;
  char from_unit, to_unit;

  printf("Enter value: ");
  scanf("%f", &value);

  printf("Enter from unit: ");
  scanf(" %c", &from_unit);

  printf("Enter to unit: ");
  scanf(" %c", &to_unit);

  convert_units(value, from_unit, to_unit);

  return 0;
}