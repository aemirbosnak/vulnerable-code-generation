//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX_CONVERT 10

void convert_units(float value, char from_unit, char to_unit) {
  float conversion_factor;
  switch (from_unit) {
    case 'm':
      switch (to_unit) {
        case 'kg':
          conversion_factor = 1000;
          break;
        case 'g':
          conversion_factor = 1000000;
          break;
        case 't':
          conversion_factor = 1000000000;
          break;
      }
      break;
    case 'kg':
      switch (to_unit) {
        case 'm':
          conversion_factor = 0.001;
          break;
        case 'g':
          conversion_factor = 1000;
          break;
        case 't':
          conversion_factor = 1000000;
          break;
      }
      break;
    case 'g':
      switch (to_unit) {
        case 'm':
          conversion_factor = 0.000001;
          break;
        case 'kg':
          conversion_factor = 0.001;
          break;
        case 't':
          conversion_factor = 1000000;
          break;
      }
      break;
    case 't':
      switch (to_unit) {
        case 'm':
          conversion_factor = 0.0000001;
          break;
        case 'kg':
          conversion_factor = 0.000001;
          break;
        case 'g':
          conversion_factor = 0.001;
          break;
      }
      break;
  }

  value *= conversion_factor;

  printf("%f %s converted to %f %s is %f\n", value, from_unit, to_unit, conversion_factor, value * conversion_factor);
}

int main() {
  float value;
  char from_unit;
  char to_unit;

  printf("Enter the value:");
  scanf("%f", &value);

  printf("Enter the from unit:");
  scanf(" %c", &from_unit);

  printf("Enter the to unit:");
  scanf(" %c", &to_unit);

  convert_units(value, from_unit, to_unit);

  return 0;
}