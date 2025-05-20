#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_UNITS 5

typedef struct Unit {
  char name[20];
  double factor;
  double conversion_factor;
} Unit;

Unit units[MAX_UNITS] = {
  {"meters", 1.0, 1.0},
  {"feet", 3.28, 0.328},
  {"Celsius", 0.0, 1.8},
  {"Fahrenheit", 1.8, 0.5556},
  {"kilograms", 1.0, 1000.0}
};

int main() {
  char unit_from[20], unit_to[20];
  double value, converted_value = 0.0;
  int i = 0;

  printf("Enter the unit you want to convert from: ");
  scanf("%s", unit_from);

  printf("Enter the unit you want to convert to: ");
  scanf("%s", unit_to);

  printf("Enter the value you want to convert: ");
  scanf("%lf", &value);

  for (i = 0; i < MAX_UNITS; i++) {
    if (strcmp(units[i].name, unit_from) == 0) {
      converted_value = value * units[i].conversion_factor;
    }
  }

  for (i = 0; i < MAX_UNITS; i++) {
    if (strcmp(units[i].name, unit_to) == 0) {
      converted_value *= units[i].factor;
    }
  }

  if (converted_value != 0.0) {
    printf("The converted value is: %.2lf %s", converted_value, units[i].name);
  } else {
    printf("Error: Unsupported conversion.");
  }

  return 0;
}
