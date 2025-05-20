//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define UNIT_COUNT 10
#define UNIT_NAMES \
  "cm", "m", "km", "mm", "inch", "ft", "yd", "mile", "pica", "point"

struct unit {
  const char *name;
  double factor;
};

struct unit units[UNIT_COUNT] = {
  {"cm", 10.0},
  {"m", 100.0},
  {"km", 100000.0},
  {"mm", 0.1},
  {"inch", 2.54},
  {"ft", 12.0},
  {"yd", 36.0},
  {"mile", 1609.344},
  {"pica", 0.16},
  {"point", 0.016}
};

int main() {
  int choice;
  double value;
  char unit_input[20];
  char unit_output[20];

  printf("Welcome to the Unit Converter!\n");

  do {
    printf("Please enter a value: ");
    scanf("%lf", &value);

    printf("Please enter the unit you want to convert from (%s): ", "");
    fgets(unit_input, 20, stdin);

    for (int i = 0; i < UNIT_COUNT; i++) {
      if (strcasecmp(unit_input, units[i].name) == 0) {
        value *= units[i].factor;
        break;
      }
    }

    printf("The value in %s is: %lf\n", unit_output, value);

    printf("Would you like to convert again? (y/n): ");
    scanf(" %c", &choice);
  } while (choice == 'y');

  return 0;
}