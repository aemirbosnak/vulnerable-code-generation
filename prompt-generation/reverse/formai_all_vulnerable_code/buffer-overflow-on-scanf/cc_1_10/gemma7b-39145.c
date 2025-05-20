//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_CONVERT_UNITS 5

typedef struct Unit {
  char name[20];
  int factor;
  double multiplier;
} Unit;

Unit units[MAX_CONVERT_UNITS] = {
  {"Meter", 1, 1.0},
  {"Centimeter", 10, 10.0},
  {"Millimeter", 100, 100.0},
  {"Mile", 1609, 1.609},
  {"Yard", 3600, 0.9144}
};

int main() {
  int i, sourceUnit, targetUnit;
  double value;

  printf("Enter the value to convert: ");
  scanf("%lf", &value);

  printf("Enter the source unit: ");
  scanf("%d", &sourceUnit);

  printf("Enter the target unit: ");
  scanf("%d", &targetUnit);

  if (sourceUnit < 0 || sourceUnit >= MAX_CONVERT_UNITS) {
    printf("Invalid source unit.\n");
    return 1;
  }

  if (targetUnit < 0 || targetUnit >= MAX_CONVERT_UNITS) {
    printf("Invalid target unit.\n");
    return 1;
  }

  for (i = 0; i < MAX_CONVERT_UNITS; i++) {
    if (units[i].name[0] == units[sourceUnit].name[0] && units[i].name[1] == units[sourceUnit].name[1]) {
      sourceUnit = i;
    }

    if (units[i].name[0] == units[targetUnit].name[0] && units[i].name[1] == units[targetUnit].name[1]) {
      targetUnit = i;
    }
  }

  double convertedValue = value * units[sourceUnit].multiplier / units[targetUnit].multiplier;

  printf("The converted value is: %.2lf %s\n", convertedValue, units[targetUnit].name);

  return 0;
}