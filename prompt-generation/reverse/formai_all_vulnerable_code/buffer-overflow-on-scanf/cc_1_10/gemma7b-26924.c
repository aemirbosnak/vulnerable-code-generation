//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: active
#include <stdio.h>
#include <math.h>

void UnitConverter(double value, int fromUnit, int toUnit) {
  switch (fromUnit) {
    case 0:
      switch (toUnit) {
        case 0:
          printf("The same value: %.2lf", value);
          break;
        case 1:
          printf("Converted value: %.2lf kg", value * 1000);
          break;
        case 2:
          printf("Converted value: %.2lf g", value * 1000000);
          break;
      }
      break;
    case 1:
      switch (toUnit) {
        case 0:
          printf("Converted value: %.2lf kg", value / 1000);
          break;
        case 1:
          printf("The same value: %.2lf", value);
          break;
        case 2:
          printf("Converted value: %.2lf g", value * 1000);
          break;
      }
      break;
    case 2:
      switch (toUnit) {
        case 0:
          printf("Converted value: %.2lf kg", value / 1000000);
          break;
        case 1:
          printf("Converted value: %.2lf kg", value * 1000);
          break;
        case 2:
          printf("The same value: %.2lf", value);
          break;
      }
      break;
  }
}

int main() {
  double value;
  int fromUnit, toUnit;

  printf("Enter the value: ");
  scanf("%lf", &value);

  printf("Enter the from unit (0 - kg, 1 - g, 2 - mg): ");
  scanf("%d", &fromUnit);

  printf("Enter the to unit (0 - kg, 1 - g, 2 - mg): ");
  scanf("%d", &toUnit);

  UnitConverter(value, fromUnit, toUnit);

  return 0;
}