//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_CONVERT_UNITS 10

typedef struct Unit {
  char name[20];
  double factor;
  double min_value;
  double max_value;
} Unit;

Unit units[MAX_CONVERT_UNITS] = {
  {"Celsius", 1.8, 0.0, 100.0},
  {"Fahrenheit", 1.8, 32.0, 212.0},
  {"Kelvin", 1.0, 0.0, 273.15},
  {"Pound", 0.45359, 0.0, 100.0},
  {"Kilo", 1000.0, 0.0, 1000000.0},
  {"Gram", 1000.0, 0.0, 1000000.0},
  {"Ounces", 0.035274, 0.0, 32.0},
  {"Tons", 2000.0, 0.0, 2000000.0},
  {"Mile", 1.613, 0.0, 5000.0},
  {"Kilometer", 1.613, 0.0, 10000.0}
};

int main() {
  int i, source_unit, destination_unit;
  double value;

  printf("Enter the value: ");
  scanf("%lf", &value);

  printf("Enter the source unit: ");
  scanf("%d", &source_unit);

  printf("Enter the destination unit: ");
  scanf("%d", &destination_unit);

  for (i = 0; i < MAX_CONVERT_UNITS; i++) {
    if (units[i].name[0] == units[source_unit].name[0] && units[i].name[1] == units[source_unit].name[1]) {
      source_unit = i;
    }
    if (units[i].name[0] == units[destination_unit].name[0] && units[i].name[1] == units[destination_unit].name[1]) {
      destination_unit = i;
    }
  }

  double conversion_factor = units[destination_unit].factor / units[source_unit].factor;
  double converted_value = value * conversion_factor;

  printf("The converted value is: %.2lf %s", converted_value, units[destination_unit].name);

  return 0;
}