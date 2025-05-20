//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: all-encompassing
#include <stdio.h>
#include <math.h>

// Define the conversion function
double convert(double value, int from_unit, int to_unit) {
  switch (from_unit) {
    case 0:
      switch (to_unit) {
        case 1:
          return value * 1000;
        case 2:
          return value * 1600;
        case 3:
          return value * 2200;
      }
    case 1:
      switch (to_unit) {
        case 0:
          return value / 1000;
        case 2:
          return value * 1.6;
        case 3:
          return value * 2.2;
      }
    case 2:
      switch (to_unit) {
        case 0:
          return value / 1600;
        case 1:
          return value * 0.625;
        case 3:
          return value * 1.66666;
      }
    case 3:
      switch (to_unit) {
        case 0:
          return value / 2200;
        case 1:
          return value * 0.45454;
        case 2:
          return value * 0.66666;
        case 3:
          return value;
      }
  }

  return -1;
}

int main() {
  double value;
  int from_unit, to_unit;

  printf("Enter the value: ");
  scanf("%lf", &value);

  printf("Enter the from unit (0 for kg, 1 for g, 2 for lb, 3 for oz): ");
  scanf("%d", &from_unit);

  printf("Enter the to unit (0 for kg, 1 for g, 2 for lb, 3 for oz): ");
  scanf("%d", &to_unit);

  double result = convert(value, from_unit, to_unit);

  if (result == -1) {
    printf("Error: Invalid conversion.");
  } else {
    printf("The converted value is: %.2lf", result);
  }

  return 0;
}