//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define MAX_CONVERT 10

typedef struct UnitConverter {
  char *unit_from;
  char *unit_to;
  double conversion_factor;
} UnitConverter;

int main() {
  UnitConverter converters[MAX_CONVERT] = {
    {"g", "kg", 1000},
    {"l", "ml", 1000},
    {"kg", "t", 1000000},
    {"km", "m", 1000},
    {"h", "min", 60},
    {"min", "sec", 60},
    {"°C", "°F", (double)5 / 9 + 32},
    {"$", "€", 1.05},
    {"£", "€", 0.84},
    {"¥", "€", 0.0128}
  };

  int num_converters = 10;

  char unit_from[20];
  char unit_to[20];
  double quantity;

  printf("Enter unit conversion:\n");
  printf("From: ");
  scanf("%s", unit_from);

  printf("To: ");
  scanf("%s", unit_to);

  printf("Quantity: ");
  scanf("%lf", &quantity);

  int i = 0;
  for (i = 0; i < num_converters; i++) {
    if (strcmp(unit_from, converters[i].unit_from) == 0 && strcmp(unit_to, converters[i].unit_to) == 0) {
      double converted_quantity = quantity * converters[i].conversion_factor;
      printf("Converted quantity: %.2lf %s\n", converted_quantity, converters[i].unit_to);
      break;
    }
  }

  if (i == num_converters) {
    printf("No conversion found.\n");
  }

  return 0;
}