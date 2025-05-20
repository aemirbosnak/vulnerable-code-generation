//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Declare variables
  float value;
  char unit_from[20], unit_to[20];

  // Get the user's input
  printf("Enter the value to be converted: ");
  scanf("%f", &value);
  printf("Enter the unit of the value: ");
  scanf("%s", unit_from);
  printf("Enter the unit to convert to: ");
  scanf("%s", unit_to);

  // Check if the units are valid
  if (strcmp(unit_from, "km") != 0 && strcmp(unit_from, "m") != 0 && strcmp(unit_from, "cm") != 0 && strcmp(unit_from, "mm") != 0) {
    printf("Invalid unit: %s\n", unit_from);
    exit(1);
  }

  if (strcmp(unit_to, "km") != 0 && strcmp(unit_to, "m") != 0 && strcmp(unit_to, "cm") != 0 && strcmp(unit_to, "mm") != 0) {
    printf("Invalid unit: %s\n", unit_to);
    exit(1);
  }

  // Convert the value
  if (strcmp(unit_from, "km") == 0) {
    if (strcmp(unit_to, "m") == 0) {
      value *= 1000;
    } else if (strcmp(unit_to, "cm") == 0) {
      value *= 100000;
    } else if (strcmp(unit_to, "mm") == 0) {
      value *= 1000000;
    }
  } else if (strcmp(unit_from, "m") == 0) {
    if (strcmp(unit_to, "km") == 0) {
      value /= 1000;
    } else if (strcmp(unit_to, "cm") == 0) {
      value *= 100;
    } else if (strcmp(unit_to, "mm") == 0) {
      value *= 1000;
    }
  } else if (strcmp(unit_from, "cm") == 0) {
    if (strcmp(unit_to, "km") == 0) {
      value /= 100000;
    } else if (strcmp(unit_to, "m") == 0) {
      value /= 100;
    } else if (strcmp(unit_to, "mm") == 0) {
      value *= 10;
    }
  } else if (strcmp(unit_from, "mm") == 0) {
    if (strcmp(unit_to, "km") == 0) {
      value /= 1000000;
    } else if (strcmp(unit_to, "m") == 0) {
      value /= 1000;
    } else if (strcmp(unit_to, "cm") == 0) {
      value /= 10;
    }
  }

  // Print the result
  printf("The converted value is: %f %s\n", value, unit_to);

  return 0;
}