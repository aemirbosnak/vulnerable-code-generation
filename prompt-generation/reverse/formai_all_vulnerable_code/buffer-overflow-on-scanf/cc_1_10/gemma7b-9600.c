//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAX_CONVERT 10

typedef struct Unit {
  char name[20];
  double factor;
  int min_digits;
} Unit;

Unit units[] = {
  {"kg", 1, 3},
  {"g", 1000, 3},
  {"mg", 1000000, 3},
  {"L", 1000, 2},
  {"ml", 1000, 2},
  {"dl", 1000, 2},
  {"km", 1000, 2},
  {"hm", 10000, 2},
  {"dm", 100000, 2},
  {"mm", 1000000, 2}
};

int main() {
  double value;
  char from_unit, to_unit;

  printf("Enter the value: ");
  scanf("%lf", &value);

  printf("Enter the from unit: ");
  scanf(" %c", &from_unit);

  printf("Enter the to unit: ");
  scanf(" %c", &to_unit);

  int i = 0;
  for (; i < MAX_CONVERT && units[i].name[0] != '\0'; i++) {
    if (units[i].name[0] == from_unit && units[i].name[0] == to_unit) {
      double factor = units[i].factor;
      double converted_value = value * factor;
      int min_digits = units[i].min_digits;

      printf("The converted value is: %.%d %s\n", min_digits, converted_value, units[i].name);
    }
  }

  return 0;
}