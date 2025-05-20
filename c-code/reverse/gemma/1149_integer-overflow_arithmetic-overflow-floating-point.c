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
  {"feet", 0.328, 3.28},
  {"Celsius", 0.0, 1.8},
  {"Fahrenheit", 1.8, 0.0},
  {"kilograms", 1.0, 1000.0}
};

int main() {
  int choice, from_unit, to_unit;
  double value;

  printf("Select the unit you want to convert from:");
  for (int i = 0; i < MAX_UNITS; i++) {
    printf("%d. %s\n", i + 1, units[i].name);
  }
  scanf("%d", &from_unit);

  printf("Select the unit you want to convert to:");
  for (int i = 0; i < MAX_UNITS; i++) {
    printf("%d. %s\n", i + 1, units[i].name);
  }
  scanf("%d", &to_unit);

  printf("Enter the value you want to convert:");
  scanf("%lf", &value);

  double converted_value = value * units[from_unit].factor * units[to_unit].conversion_factor;

  printf("The converted value is: %.2lf %s\n", converted_value, units[to_unit].name);

  return 0;
}
