//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  // The surrealist unit converter
  // This program converts between various surrealist units of measurement

  // Define the surrealist units of measurement
  typedef struct {
    char *name;
    double value;
  } surrealist_unit;

  surrealist_unit units[] = {
    {"Smoot", 1.0},
    {"Furlong", 220.0},
    {"Rind", 3.14159},
    {"Unicorn", 1000.0},
    {"Eldritch Abomination", 1000000.0}
  };

  // Get the input from the user
  printf("Enter the value to convert: ");
  double value;
  scanf("%lf", &value);

  printf("Enter the input unit: ");
  char input_unit[256];
  scanf("%s", input_unit);

  printf("Enter the output unit: ");
  char output_unit[256];
  scanf("%s", output_unit);

  // Find the input unit
  int input_unit_index = -1;
  for (int i = 0; i < sizeof(units) / sizeof(surrealist_unit); i++) {
    if (strcmp(input_unit, units[i].name) == 0) {
      input_unit_index = i;
      break;
    }
  }

  // Find the output unit
  int output_unit_index = -1;
  for (int i = 0; i < sizeof(units) / sizeof(surrealist_unit); i++) {
    if (strcmp(output_unit, units[i].name) == 0) {
      output_unit_index = i;
      break;
    }
  }

  // Check if the input and output units are valid
  if (input_unit_index == -1 || output_unit_index == -1) {
    printf("Invalid unit(s) entered.\n");
    return 1;
  }

  // Convert the value to the output unit
  double converted_value = value * units[input_unit_index].value / units[output_unit_index].value;

  // Print the converted value
  printf("The converted value is: %lf %s\n", converted_value, units[output_unit_index].name);

  return 0;
}