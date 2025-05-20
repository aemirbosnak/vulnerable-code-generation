//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

void unit_converter(double value, int from_unit, int to_unit) {
  switch (from_unit) {
    case 0:
      switch (to_unit) {
        case 0:
          printf("%f is the same as %f", value, value);
          break;
        case 1:
          printf("%f is equal to %f liters", value, value * 1000);
          break;
        case 2:
          printf("%f is equivalent to %f gallons", value, value * 3.785);
          break;
      }
      break;
    case 1:
      switch (to_unit) {
        case 0:
          printf("%f liters is the same as %f", value, value / 1000);
          break;
        case 1:
          printf("%f liters is equal to %f", value, value);
          break;
        case 2:
          printf("%f liters is equivalent to %f gallons", value, value * 3.785);
          break;
      }
      break;
    case 2:
      switch (to_unit) {
        case 0:
          printf("%f gallons is the same as %f", value, value * 0.832);
          break;
        case 1:
          printf("%f gallons is equal to %f liters", value, value * 1000);
          break;
        case 2:
          printf("%f gallons is equivalent to %f", value, value);
          break;
      }
      break;
  }
}

int main() {
  double value;
  int from_unit, to_unit;

  printf("Enter the value:");
  scanf("%lf", &value);

  printf("Enter the unit you want to convert from:");
  scanf("%d", &from_unit);

  printf("Enter the unit you want to convert to:");
  scanf("%d", &to_unit);

  unit_converter(value, from_unit, to_unit);

  return 0;
}