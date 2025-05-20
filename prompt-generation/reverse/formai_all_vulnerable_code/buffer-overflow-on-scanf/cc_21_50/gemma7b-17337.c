//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  int unit_type, target_unit;
  double value;

  // Display available units
  printf("Available units:\n");
  printf("1. meters\n");
  printf("2. kilometers\n");
  printf("3. miles\n");
  printf("4. centimeters\n");
  printf("5. inches\n");

  // Get the unit type and value from the user
  printf("Enter the unit type (1-5): ");
  scanf("%d", &unit_type);

  printf("Enter the value: ");
  scanf("%lf", &value);

  // Get the target unit
  printf("Enter the target unit (1-5): ");
  scanf("%d", &target_unit);

  // Convert the unit
  double conversion_factor = 1;
  switch (unit_type) {
    case 1:
      switch (target_unit) {
        case 2:
          conversion_factor = 1000;
          break;
        case 3:
          conversion_factor = 1609.34;
          break;
        case 4:
          conversion_factor = 100;
          break;
        case 5:
          conversion_factor = 39.3701;
          break;
      }
      break;
    case 2:
      switch (target_unit) {
        case 1:
          conversion_factor = 0.001;
          break;
        case 3:
          conversion_factor = 1.60934;
          break;
        case 4:
          conversion_factor = 1000;
          break;
        case 5:
          conversion_factor = 39.3701;
          break;
      }
      break;
    case 3:
      switch (target_unit) {
        case 1:
          conversion_factor = 0.001609;
          break;
        case 2:
          conversion_factor = 0.621371;
          break;
        case 4:
          conversion_factor = 1609.34;
          break;
        case 5:
          conversion_factor = 39.3701;
          break;
      }
      break;
    case 4:
      switch (target_unit) {
        case 1:
          conversion_factor = 10;
          break;
        case 2:
          conversion_factor = 0.001;
          break;
        case 3:
          conversion_factor = 0.001609;
          break;
        case 5:
          conversion_factor = 39.3701;
          break;
      }
      break;
    case 5:
      switch (target_unit) {
        case 1:
          conversion_factor = 25.4;
          break;
        case 2:
          conversion_factor = 2.54;
          break;
        case 3:
          conversion_factor = 2.54;
          break;
        case 4:
          conversion_factor = 0.0254;
          break;
      }
      break;
  }

  // Convert the value
  double converted_value = value * conversion_factor;

  // Display the converted value
  printf("The converted value is: %.2lf %s", converted_value, target_unit);

  return 0;
}