//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: standalone
#include <stdio.h>
#include <math.h>

void UnitConverter(double value, int fromUnit, int toUnit) {
  switch (fromUnit) {
    case 0:
      switch (toUnit) {
        case 1:
          printf("%f is equal to %.2lf units of mass in kilograms.\n", value, value * 1000);
          break;
        case 2:
          printf("%f is equal to %.2lf units of volume in liters.\n", value, value * 1000);
          break;
        case 3:
          printf("%f is equal to %.2lf units of temperature in degrees Celsius.\n", value, (value - 32) * 5 / 9);
          break;
      }
      break;
    case 1:
      switch (toUnit) {
        case 0:
          printf("%f is equal to %.2lf units of mass in grams.\n", value, value * 1000);
          break;
        case 2:
          printf("%f is equal to %.2lf units of volume in cubic centimeters.\n", value, value * 1000);
          break;
        case 3:
          printf("%f is equal to %.2lf units of temperature in degrees Fahrenheit.\n", value, (value * 9 / 5) + 32);
          break;
      }
      break;
    case 2:
      switch (toUnit) {
        case 0:
          printf("%f is equal to %.2lf units of mass in milligrams.\n", value, value * 1000);
          break;
        case 1:
          printf("%f is equal to %.2lf units of volume in cubic meters.\n", value, value * 1000);
          break;
        case 3:
          printf("%f is equal to %.2lf units of temperature in degrees Celsius.\n", value, (value - 32) * 5 / 9);
          break;
      }
      break;
    case 3:
      switch (toUnit) {
        case 0:
          printf("%f is equal to %.2lf units of mass in micrograms.\n", value, value * 1000);
          break;
        case 1:
          printf("%f is equal to %.2lf units of volume in cubic centimeters.\n", value, value * 1000);
          break;
        case 2:
          printf("%f is equal to %.2lf units of temperature in degrees Fahrenheit.\n", value, (value * 9 / 5) + 32);
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

  printf("Enter the from unit (0 for grams, 1 for kilograms, 2 for liters, 3 for degrees Celsius): ");
  scanf("%d", &fromUnit);

  printf("Enter the to unit (0 for grams, 1 for kilograms, 2 for liters, 3 for degrees Celsius): ");
  scanf("%d", &toUnit);

  UnitConverter(value, fromUnit, toUnit);

  return 0;
}