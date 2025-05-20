//FormAI DATASET v1.0 Category: Unit converter ; Style: random
#include <stdio.h>

int main() {
  printf("Welcome to the Unit Converter!\n");
  printf("What conversion would you like to perform?\n");
  printf("1. Feet to Meters\n");
  printf("2. Miles to Kilometers\n");
  printf("3. Gallons to Liters\n");

  int choice;
  printf("Enter your choice: ");
  scanf("%d", &choice);

  float fromValue, toValue;
  char* fromUnit, *toUnit;

  switch (choice) {
    case 1:
      fromUnit = "Feet";
      toUnit = "Meters";
      printf("Enter value in %s: ", fromUnit);
      scanf("%f", &fromValue);
      toValue = fromValue * 0.3048;
      break;

    case 2:
      fromUnit = "Miles";
      toUnit = "Kilometers";
      printf("Enter value in %s: ", fromUnit);
      scanf("%f", &fromValue);
      toValue = fromValue * 1.60934;
      break;

    case 3:
      fromUnit = "Gallons";
      toUnit = "Liters";
      printf("Enter value in %s: ", fromUnit);
      scanf("%f", &fromValue);
      toValue = fromValue * 3.78541;
      break;

    default:
      printf("Invalid choice!\n");
      return 1;
  }

  printf("%.2f %s equals %.2f %s.\n", fromValue, fromUnit, toValue, toUnit);
  
  return 0;
}