//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: optimized
#include <stdio.h>
#include <math.h>

void unit_converter(double value, int from_unit, int to_unit) {
  double conversion_factor;
  switch (from_unit) {
    case 0:
      conversion_factor = 1;
      break;
    case 1:
      conversion_factor = 2.2046;
      break;
    case 2:
      conversion_factor = 1.618;
      break;
    case 3:
      conversion_factor = 0.08611;
      break;
  }
  switch (to_unit) {
    case 0:
      conversion_factor = 1;
      break;
    case 1:
      conversion_factor = 0.45359;
      break;
    case 2:
      conversion_factor = 1.618;
      break;
    case 3:
      conversion_factor = 11.574;
      break;
  }
  double converted_value = value * conversion_factor;
  printf("%f", converted_value);
}

int main() {
  double value;
  int from_unit, to_unit;

  printf("Enter the value: ");
  scanf("%lf", &value);

  printf("Enter the from unit (0 for kg, 1 for lb, 2 for g, 3 for oz): ");
  scanf("%d", &from_unit);

  printf("Enter the to unit (0 for kg, 1 for lb, 2 for g, 3 for oz): ");
  scanf("%d", &to_unit);

  unit_converter(value, from_unit, to_unit);

  return 0;
}