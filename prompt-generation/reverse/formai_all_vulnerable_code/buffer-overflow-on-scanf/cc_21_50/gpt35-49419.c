//FormAI DATASET v1.0 Category: Unit converter ; Style: futuristic
#include <stdio.h>

int main() {
  printf("Welcome to SmartUnit v2.0 - Your futuristic Unit Converter!\n\n");

  float value;
  char from_unit[20], to_unit[20];

  printf("Enter value to be converted: ");
  scanf("%f", &value);

  printf("\nEnter unit to convert from: ");
  scanf("%s", from_unit);

  printf("\nEnter unit to convert to: ");
  scanf("%s", to_unit);

  if (strcmp(from_unit, to_unit) == 0) {
    printf("\nError: Cannot convert between the same units.\n");
    return 0;
  }

  float converted_value;
  float factor;

  // convert from kilograms to another unit
  if (strcmp(from_unit, "kg") == 0) {
    if (strcmp(to_unit, "g") == 0) {
      factor = 1000;
    } else if (strcmp(to_unit, "mg") == 0) {
      factor = 1000000;
    } else if (strcmp(to_unit, "lb") == 0) {
      factor = 2.20462;
    } else if (strcmp(to_unit, "oz") == 0) {
      factor = 35.274;
    } else {
      printf("\nError: Invalid unit to convert to.\n");
      return 0;
    }
    converted_value = value * factor;
  }

  // convert from grams to another unit
  else if (strcmp(from_unit, "g") == 0) {
    if (strcmp(to_unit, "kg") == 0) {
      factor = 0.001;
    } else if (strcmp(to_unit, "mg") == 0) {
      factor = 1000;
    } else if (strcmp(to_unit, "lb") == 0) {
      factor = 0.00220462;
    } else if (strcmp(to_unit, "oz") == 0) {
      factor = 0.035274;
    } else {
      printf("\nError: Invalid unit to convert to.\n");
      return 0;
    }
    converted_value = value * factor;
  }

  // convert from milligrams to another unit
  else if (strcmp(from_unit, "mg") == 0) {
    if (strcmp(to_unit, "kg") == 0) {
      factor = 0.000001;
    } else if (strcmp(to_unit, "g") == 0) {
      factor = 0.001;
    } else if (strcmp(to_unit, "lb") == 0) {
      factor = 0.00000220462;
    } else if (strcmp(to_unit, "oz") == 0) {
      factor = 0.000035274;
    } else {
      printf("\nError: Invalid unit to convert to.\n");
      return 0;
    }
    converted_value = value * factor;
  }

  // convert from pounds to another unit
  else if (strcmp(from_unit, "lb") == 0) {
    if (strcmp(to_unit, "kg") == 0) {
      factor = 0.453592;
    } else if (strcmp(to_unit, "g") == 0) {
      factor = 453.592;
    } else if (strcmp(to_unit, "mg") == 0) {
      factor = 453592;
    } else if (strcmp(to_unit, "oz") == 0) {
      factor = 16;
    } else {
      printf("\nError: Invalid unit to convert to.\n");
      return 0;
    }
    converted_value = value * factor;
  }

  // convert from ounces to another unit
  else if (strcmp(from_unit, "oz") == 0) {
    if (strcmp(to_unit, "kg") == 0) {
      factor = 0.0283495;
    } else if (strcmp(to_unit, "g") == 0) {
      factor = 28.3495;
    } else if (strcmp(to_unit, "mg") == 0) {
      factor = 28349.5;
    } else if (strcmp(to_unit, "lb") == 0) {
      factor = 0.0625;
    } else {
      printf("\nError: Invalid unit to convert to.\n");
      return 0;
    }
    converted_value = value * factor;
  } else {
    printf("\nError: Invalid unit to convert from.\n");
    return 0;
  }

  printf("\n%.2f %s is equal to %.2f %s.\n", value, from_unit, converted_value, to_unit);

  return 0;
}