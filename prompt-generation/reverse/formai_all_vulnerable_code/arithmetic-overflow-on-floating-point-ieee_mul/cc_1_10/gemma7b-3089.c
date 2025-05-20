//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: multivariable
#include <stdio.h>
#include <math.h>

void unit_converter(double value, int from_unit, int to_unit) {
  double conversion_factor;
  switch (from_unit) {
    case 1:
      conversion_factor = 1000;
      break;
    case 2:
      conversion_factor = 1000000;
      break;
    case 3:
      conversion_factor = 1000000000;
      break;
  }

  switch (to_unit) {
    case 1:
      conversion_factor = 1;
      break;
    case 2:
      conversion_factor = 1000;
      break;
    case 3:
      conversion_factor = 1000000;
      break;
  }

  double converted_value = value * conversion_factor;
  printf("%f", converted_value);
}

int main() {
  double value;
  int from_unit, to_unit;

  printf("Enter the value:");
  scanf("%lf", &value);

  printf("Enter the from unit (1, 2, 3):");
  scanf("%d", &from_unit);

  printf("Enter the to unit (1, 2, 3):");
  scanf("%d", &to_unit);

  unit_converter(value, from_unit, to_unit);

  return 0;
}