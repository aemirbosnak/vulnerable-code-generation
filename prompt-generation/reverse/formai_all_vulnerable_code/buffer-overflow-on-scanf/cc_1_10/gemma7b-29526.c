//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

void unit_converter(int from_unit, int to_unit, float value) {
  float conversion_factor;
  switch (from_unit) {
    case 0:
      switch (to_unit) {
        case 0:
          conversion_factor = 1;
          break;
        case 1:
          conversion_factor = 2.2;
          break;
        case 2:
          conversion_factor = 2.208;
          break;
      }
      break;
    case 1:
      switch (to_unit) {
        case 0:
          conversion_factor = 0.45359;
          break;
        case 1:
          conversion_factor = 1;
          break;
        case 2:
          conversion_factor = 2.208;
          break;
      }
      break;
    case 2:
      switch (to_unit) {
        case 0:
          conversion_factor = 0.45359;
          break;
        case 1:
          conversion_factor = 0.45359 / 2.2;
          break;
        case 2:
          conversion_factor = 1;
          break;
      }
      break;
  }

  value *= conversion_factor;
  printf("The converted value is: %.2f", value);
}

int main() {
  int from_unit, to_unit;
  float value;

  printf("Enter the from unit (0, 1, 2): ");
  scanf("%d", &from_unit);

  printf("Enter the to unit (0, 1, 2): ");
  scanf("%d", &to_unit);

  printf("Enter the value: ");
  scanf("%f", &value);

  unit_converter(from_unit, to_unit, value);

  return 0;
}