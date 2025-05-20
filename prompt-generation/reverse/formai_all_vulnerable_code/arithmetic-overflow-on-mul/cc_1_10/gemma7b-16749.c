//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159

int main() {
  int choice, num, unit_from, unit_to;
  float result;

  printf("Welcome to the Unit Converter!\n");
  printf("Please select an option:\n");
  printf("1. Convert meters to kilometers\n");
  printf("2. Convert liters to gallons\n");
  printf("3. Convert kilograms to pounds\n");
  printf("4. Convert degrees to radians\n");

  scanf("%d", &choice);

  switch (choice) {
    case 1:
      printf("Enter the number of meters:");
      scanf("%d", &num);
      unit_from = 1;
      unit_to = 2;
      result = num * 1000;
      break;
    case 2:
      printf("Enter the number of liters:");
      scanf("%d", &num);
      unit_from = 3;
      unit_to = 4;
      result = num * 1.05669;
      break;
    case 3:
      printf("Enter the number of kilograms:");
      scanf("%d", &num);
      unit_from = 2;
      unit_to = 3;
      result = num * 2.20462;
      break;
    case 4:
      printf("Enter the number of degrees:");
      scanf("%d", &num);
      unit_from = 5;
      unit_to = 6;
      result = num * PI / 180;
      break;
    default:
      printf("Invalid option.\n");
  }

  printf("The result is: %.2f %s.\n", result, unit_to);

  return 0;
}