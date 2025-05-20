//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert units of measurement
void convert(double value, char fromUnit[20], char toUnit[20]) {
  // Convert units based on user input
  if (strcmp(fromUnit, "cm") == 0) {
    if (strcmp(toUnit, "m") == 0) {
      value *= 100;
    } else if (strcmp(toUnit, "ft") == 0) {
      value *= 3.28084;
    } else if (strcmp(toUnit, "in") == 0) {
      value *= 0.03937;
    }
  } else if (strcmp(fromUnit, "m") == 0) {
    if (strcmp(toUnit, "cm") == 0) {
      value /= 100;
    } else if (strcmp(toUnit, "ft") == 0) {
      value /= 3.28084;
    } else if (strcmp(toUnit, "in") == 0) {
      value /= 0.03937;
    }
  } else if (strcmp(fromUnit, "ft") == 0) {
    if (strcmp(toUnit, "cm") == 0) {
      value *= 30.48;
    } else if (strcmp(toUnit, "m") == 0) {
      value *= 100 / 3.28084;
    } else if (strcmp(toUnit, "in") == 0) {
      value *= 12 / 3.28084;
    }
  } else if (strcmp(fromUnit, "in") == 0) {
    if (strcmp(toUnit, "cm") == 0) {
      value *= 2.54;
    } else if (strcmp(toUnit, "m") == 0) {
      value *= 100 / 2.54;
    } else if (strcmp(toUnit, "ft") == 0) {
      value *= 12 / 2.54;
    }
  }
  printf("Converted value: %f %s\n", value, toUnit);
}

int main() {
  double value;
  char fromUnit[20], toUnit[20];

  // Get input from user
  printf("Enter a value: ");
  scanf("%lf", &value);
  printf("Enter from unit (cm/m/ft/in): ");
  scanf("%19s", fromUnit);
  printf("Enter to unit (cm/m/ft/in): ");
  scanf("%19s", toUnit);

  // Call convert function
  convert(value, fromUnit, toUnit);

  return 0;
}