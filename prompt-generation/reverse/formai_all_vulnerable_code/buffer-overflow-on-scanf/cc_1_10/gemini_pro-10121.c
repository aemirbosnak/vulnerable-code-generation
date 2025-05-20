//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_UNITS 10

// Unit conversion table
typedef struct {
  char *name;
  double factor;
} unit_t;

unit_t units[] = {
  { "mm", 1.0 },
  { "cm", 10.0 },
  { "m", 1000.0 },
  { "km", 1000000.0 },
  { "in", 25.4 },
  { "ft", 304.8 },
  { "yd", 914.4 },
  { "mi", 1609344.0 },
  { "nm", 1852000.0 },
  { "ly", 9460730472580800.0 },
};

// Function to convert a value from one unit to another
double convert_unit(double value, char *from_unit, char *to_unit) {
  int i, j;

  // Find the index of the "from" unit
  for (i = 0; i < NUM_UNITS; i++) {
    if (strcmp(from_unit, units[i].name) == 0) {
      break;
    }
  }

  // Find the index of the "to" unit
  for (j = 0; j < NUM_UNITS; j++) {
    if (strcmp(to_unit, units[j].name) == 0) {
      break;
    }
  }

  // Convert the value
  return value * units[j].factor / units[i].factor;
}

// Main function
int main(int argc, char *argv[]) {
  double value;
  char from_unit[10], to_unit[10];

  // Get the input value and units
  printf("Enter the value to convert: ");
  scanf("%lf", &value);
  printf("Enter the unit to convert from: ");
  scanf("%s", from_unit);
  printf("Enter the unit to convert to: ");
  scanf("%s", to_unit);

  // Convert the value
  double converted_value = convert_unit(value, from_unit, to_unit);

  // Print the result
  printf("%lf %s = %lf %s\n", value, from_unit, converted_value, to_unit);

  return 0;
}