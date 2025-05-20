//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: satisfied
#include <stdio.h>
#include <math.h>

void UnitConverter(float value, int fromUnit, int toUnit)
{
  float conversionFactor;
  switch (fromUnit)
  {
    case 0:
      switch (toUnit)
      {
        case 0:
          conversionFactor = 1;
          break;
        case 1:
          conversionFactor = 2;
          break;
        case 2:
          conversionFactor = 3;
          break;
      }
      break;
    case 1:
      switch (toUnit)
      {
        case 0:
          conversionFactor = 0.5;
          break;
        case 1:
          conversionFactor = 1;
          break;
        case 2:
          conversionFactor = 1.5;
          break;
      }
      break;
    case 2:
      switch (toUnit)
      {
        case 0:
          conversionFactor = 0.33333;
          break;
        case 1:
          conversionFactor = 0.66666;
          break;
        case 2:
          conversionFactor = 1;
          break;
      }
      break;
  }

  value *= conversionFactor;
  printf("The converted value is: %.2f", value);
}

int main()
{
  float value;
  int fromUnit, toUnit;

  printf("Enter the value: ");
  scanf("%f", &value);

  printf("Enter the from unit (0, 1, 2): ");
  scanf("%d", &fromUnit);

  printf("Enter the to unit (0, 1, 2): ");
  scanf("%d", &toUnit);

  UnitConverter(value, fromUnit, toUnit);

  return 0;
}