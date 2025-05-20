//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char *name;
  double factor;
} unit;

unit units[] = {
  {"kilometer", 1000.0},
  {"meter", 1.0},
  {"centimeter", 0.01},
  {"millimeter", 0.001},
  {"inch", 0.0254},
  {"foot", 0.3048},
  {"yard", 0.9144},
  {"mile", 1609.34}
};

int main() {
  double value;
  char *from, *to;

  printf("Welcome to the Galactic Unit Converter!\n");
  printf("Enter the value you want to convert: ");
  scanf("%lf", &value);
  printf("Enter the unit you want to convert from: ");
  scanf("%s", from);
  printf("Enter the unit you want to convert to: ");
  scanf("%s", to);

  int fromIndex = -1, toIndex = -1;

  for (int i = 0; i < sizeof(units) / sizeof(unit); i++) {
    if (strcmp(units[i].name, from) == 0) {
      fromIndex = i;
    }
    if (strcmp(units[i].name, to) == 0) {
      toIndex = i;
    }
  }

  if (fromIndex == -1 || toIndex == -1) {
    printf("Invalid unit(s) entered.\n");
    return 1;
  }

  double convertedValue = value * units[fromIndex].factor / units[toIndex].factor;

  printf("The converted value is: %lf\n", convertedValue);

  return 0;
}