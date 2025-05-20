//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: modular
#include <stdio.h>
#include <math.h>

#define MODULE_NAME "Unit Converter"

typedef struct UnitConverter {
  double conversionFactor;
  char unitFrom;
  char unitTo;
} UnitConverter;

UnitConverter unitConverterTable[] = {
  {2.26, 'L', 'kg'},
  {1.6, 'L', 'gal'},
  {3.78, 'kg', 'lb'},
  {1000, 'g', 'kg'}
};

double convertUnits(double value, char fromUnit, char toUnit) {
  for (int i = 0; i < sizeof(unitConverterTable) / sizeof(UnitConverter); i++) {
    if (unitConverterTable[i].unitFrom == fromUnit && unitConverterTable[i].unitTo == toUnit) {
      return value * unitConverterTable[i].conversionFactor;
    }
  }

  return -1;
}

int main() {
  double value;
  char fromUnit;
  char toUnit;

  printf("Enter the value: ");
  scanf("%lf", &value);

  printf("Enter the unit from: ");
  scanf(" %c", &fromUnit);

  printf("Enter the unit to: ");
  scanf(" %c", &toUnit);

  double convertedValue = convertUnits(value, fromUnit, toUnit);

  if (convertedValue != -1) {
    printf("The converted value is: %.2lf %s", convertedValue, toUnit);
  } else {
    printf("Error: Unit conversion not found.");
  }

  return 0;
}