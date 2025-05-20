//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: genius
#include <stdio.h>
#include <math.h>

#define PI 3.14159

int main() {
  int choice, unit_from, unit_to;
  float value, conversion_factor;

  // Display menu options
  printf("Select a unit conversion:\n");
  printf("1. Length\n");
  printf("2. Mass\n");
  printf("3. Volume\n");
  printf("4. Temperature\n");

  // Get user input
  scanf("Enter your choice: ", &choice);

  // Calculate conversion factor based on user choice
  switch (choice) {
    case 1:
      unit_from = 1;
      unit_to = 2;
      conversion_factor = 2.54;
      break;
    case 2:
      unit_from = 2;
      unit_to = 3;
      conversion_factor = 1000;
      break;
    case 3:
      unit_from = 3;
      unit_to = 4;
      conversion_factor = 1000;
      break;
    case 4:
      unit_from = 4;
      unit_to = 5;
      conversion_factor = 1.8;
      break;
    default:
      printf("Invalid input.\n");
      return 1;
  }

  // Get the value to be converted
  printf("Enter the value: ");
  scanf("%f", &value);

  // Convert the value
  float converted_value = value * conversion_factor;

  // Display the converted value
  printf("The converted value is: %.2f %s.\n", converted_value, unit_to);

  return 0;
}