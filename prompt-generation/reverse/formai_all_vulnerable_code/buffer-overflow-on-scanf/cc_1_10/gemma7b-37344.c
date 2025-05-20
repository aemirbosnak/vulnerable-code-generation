//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_CONVERTIONS 10

typedef struct Conversion {
  char *source_unit;
  char *target_unit;
  double conversion_factor;
} Conversion;

Conversion conversions[MAX_CONVERTIONS] = {
  {"kg", "g", 1000},
  {"L", "ml", 1000},
  {"km", "m", 1000},
  {"km/h", "m/s", 3.6},
  {"°C", "°F", (double)1.8 + 32},
  {"$" , "£", 0.84},
  {"€", "£", 0.84},
  {"MHz", "kHz", 1000},
  {"GB", "MB", 1000},
  {"TB", "GB", 1000}
};

int main() {
  char source_unit[20];
  char target_unit[20];
  double quantity;

  printf("Enter the source unit: ");
  scanf("%s", source_unit);

  printf("Enter the target unit: ");
  scanf("%s", target_unit);

  printf("Enter the quantity: ");
  scanf("%lf", &quantity);

  for (int i = 0; i < MAX_CONVERTIONS; i++) {
    if (strcmp(conversions[i].source_unit, source_unit) == 0 && strcmp(conversions[i].target_unit, target_unit) == 0) {
      double conversion_factor = conversions[i].conversion_factor;
      double result = quantity * conversion_factor;
      printf("The result is: %.2lf %s", result, conversions[i].target_unit);
      break;
    }
  }

  if (strcmp(source_unit, target_unit) == 0) {
    printf("Error: The source and target units are the same.");
  } else {
    printf("Error: Conversion not found.");
  }

  return 0;
}