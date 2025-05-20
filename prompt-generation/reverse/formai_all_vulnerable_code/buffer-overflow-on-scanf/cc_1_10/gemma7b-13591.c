//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: happy
#include <stdio.h>
#include <math.h>

void UnitConverter(float number, int fromUnit, int toUnit) {
  float conversionFactor;
  switch (fromUnit) {
    case 0:
      conversionFactor = 1;
      break;
    case 1:
      conversionFactor = 2.208;
      break;
    case 2:
      conversionFactor = 2.208 * 2;
      break;
    case 3:
      conversionFactor = 1.602;
      break;
  }

  switch (toUnit) {
    case 0:
      conversionFactor = 1;
      break;
    case 1:
      conversionFactor = 0.453592;
      break;
    case 2:
      conversionFactor = 0.453592 * 2;
      break;
    case 3:
      conversionFactor = 1.602;
      break;
  }

  float convertedNumber = number * conversionFactor;

  printf("Converted number: %.2f %s to %.2f %s\n", number, fromUnit, convertedNumber, toUnit);
}

int main() {
  float number;
  int fromUnit, toUnit;

  printf("Enter the number: ");
  scanf("%f", &number);

  printf("Enter the unit you want to convert from: (0, 1, 2, 3) ");
  scanf("%d", &fromUnit);

  printf("Enter the unit you want to convert to: (0, 1, 2, 3) ");
  scanf("%d", &toUnit);

  UnitConverter(number, fromUnit, toUnit);

  return 0;
}