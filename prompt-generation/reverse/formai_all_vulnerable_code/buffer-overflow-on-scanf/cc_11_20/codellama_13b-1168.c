//Code Llama-13B DATASET v1.0 Category: Unit converter ; Style: random
// Unit Converter

#include <stdio.h>

int main() {
  double value, result;
  char unit1, unit2;

  printf("Enter a value: ");
  scanf("%lf", &value);

  printf("Enter the unit (m, km, cm, mm): ");
  scanf(" %c", &unit1);

  printf("Enter the unit to convert to (m, km, cm, mm): ");
  scanf(" %c", &unit2);

  switch (unit1) {
    case 'm':
      switch (unit2) {
        case 'km':
          result = value / 1000;
          break;
        case 'cm':
          result = value * 100;
          break;
        case 'mm':
          result = value * 1000;
          break;
        default:
          result = value;
          break;
      }
      break;
    case 'km':
      switch (unit2) {
        case 'm':
          result = value * 1000;
          break;
        case 'cm':
          result = value * 100000;
          break;
        case 'mm':
          result = value * 1000000;
          break;
        default:
          result = value;
          break;
      }
      break;
    case 'cm':
      switch (unit2) {
        case 'm':
          result = value / 100;
          break;
        case 'km':
          result = value / 100000;
          break;
        case 'mm':
          result = value * 10;
          break;
        default:
          result = value;
          break;
      }
      break;
    case 'mm':
      switch (unit2) {
        case 'm':
          result = value / 1000;
          break;
        case 'km':
          result = value / 1000000;
          break;
        case 'cm':
          result = value / 10;
          break;
        default:
          result = value;
          break;
      }
      break;
    default:
      printf("Invalid unit\n");
      return 1;
  }

  printf("Result: %.2f %c\n", result, unit2);

  return 0;
}