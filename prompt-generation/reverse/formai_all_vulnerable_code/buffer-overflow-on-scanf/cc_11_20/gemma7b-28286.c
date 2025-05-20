//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: future-proof
#include <stdio.h>
#include <math.h>

#define PI 3.14159

int main() {
  double value;
  char unit;
  double conversion_factor;

  printf("Enter a value: ");
  scanf("%lf", &value);

  printf("Enter a unit: ");
  scanf(" %c", &unit);

  switch (unit) {
    case 'm':
      conversion_factor = 1;
      break;
    case 'kg':
      conversion_factor = 1000;
      break;
    case 'g':
      conversion_factor = 1000000;
      break;
    case 'L':
      conversion_factor = 1000;
      break;
    case 'V':
      conversion_factor = 1000;
      break;
    default:
      printf("Invalid unit.\n");
      return 1;
  }

  double converted_value = value * conversion_factor;

  switch (unit) {
    case 'm':
      printf("%lf meters is equal to %lf kilometers.\n", value, converted_value);
      break;
    case 'kg':
      printf("%lf kilograms is equal to %lf tons.\n", value, converted_value);
      break;
    case 'g':
      printf("%lf grams is equal to %lf kilograms.\n", value, converted_value);
      break;
    case 'L':
      printf("%lf liters is equal to %lf cubic meters.\n", value, converted_value);
      break;
    case 'V':
      printf("%lf volts is equal to %lf amperes.\n", value, converted_value);
      break;
  }

  return 0;
}