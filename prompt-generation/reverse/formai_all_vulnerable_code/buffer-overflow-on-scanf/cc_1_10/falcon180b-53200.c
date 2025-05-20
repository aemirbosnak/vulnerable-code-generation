//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define UNITS 6

struct unit {
  char *name;
  double factor;
};

struct unit units[UNITS] = {
  {"meters", 1.0},
  {"kilometers", 1000.0},
  {"centimeters", 0.01},
  {"inches", 0.0254},
  {"yards", 0.9144},
  {"feet", 0.3048}
};

int main() {
  char input[100];
  int choice;
  double value, result;

  printf("Welcome to the Unit Converter!\n");
  printf("Please enter the unit you want to convert from:\n");
  scanf("%s", input);

  for (int i = 0; i < UNITS; i++) {
    if (strcmp(units[i].name, input) == 0) {
      printf("Please enter the value you want to convert:\n");
      scanf("%lf", &value);

      printf("Please enter the unit you want to convert to:\n");
      scanf("%s", input);

      for (int j = 0; j < UNITS; j++) {
        if (strcmp(units[j].name, input) == 0) {
          result = value * units[j].factor;
          printf("%.2lf %s = %.2lf %s\n", value, units[i].name, result, units[j].name);
          break;
        }
      }

      break;
    }
  }

  printf("Thank you for using the Unit Converter! Have a nice day!\n");

  return 0;
}