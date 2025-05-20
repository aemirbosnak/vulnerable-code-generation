//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: detailed
#include <stdio.h>
#include <math.h>

void UnitConverter(double value, int fromUnit, int toUnit)
{
  double conversionFactor;
  switch (fromUnit)
  {
    case 0:
      conversionFactor = 1;
      break;
    case 1:
      conversionFactor = 2.2046;
      break;
    case 2:
      conversionFactor = 2.2046 * 1.613;
      break;
    case 3:
      conversionFactor = 1.613;
      break;
    default:
      printf("Invalid unit conversion.\n");
      return;
  }

  switch (toUnit)
  {
    case 0:
      conversionFactor = 1;
      break;
    case 1:
      conversionFactor = 0.45359;
      break;
    case 2:
      conversionFactor = 0.45359 * 1.613;
      break;
    case 3:
      conversionFactor = 0.6226;
      break;
    default:
      printf("Invalid unit conversion.\n");
      return;
  }

  double convertedValue = value * conversionFactor;
  printf("Converted value: %.2f %s to %.2f %s is %.2f.\n", value, fromUnit, toUnit, convertedValue);
}

int main()
{
  double value;
  int fromUnit, toUnit;

  printf("Enter the value: ");
  scanf("%lf", &value);

  printf("Enter the unit conversion from: ");
  scanf("%d", &fromUnit);

  printf("Enter the unit conversion to: ");
  scanf("%d", &toUnit);

  UnitConverter(value, fromUnit, toUnit);

  return 0;
}