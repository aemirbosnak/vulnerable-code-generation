//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PI 3.1415926535

int main() {
  int choice;
  float num;
  char unit;

  printf("Welcome to the Ultimate Unit Converter!\n");
  printf("Please select an option:**\n");
  printf("1. Convert meters to kilometers\n");
  printf("2. Convert liters to gallons\n");
  printf("3. Convert degrees to radians\n");
  printf("4. Convert pounds to kilograms\n");
  printf("Enter your selection: ");

  scanf("%d", &choice);

  switch (choice) {
    case 1:
      printf("Enter the number of meters: ");
      scanf("%f", &num);
      unit = 'k';
      break;
    case 2:
      printf("Enter the number of liters: ");
      scanf("%f", &num);
      unit = 'g';
      break;
    case 3:
      printf("Enter the number of degrees: ");
      scanf("%f", &num);
      unit = 'r';
      break;
    case 4:
      printf("Enter the number of pounds: ");
      scanf("%f", &num);
      unit = 'kg';
      break;
    default:
      printf("Invalid selection\n");
  }

  switch (unit) {
    case 'k':
      printf("%f meters is equal to %f kilometers.\n", num, num * 1000);
      break;
    case 'g':
      printf("%f liters is equal to %f gallons.\n", num, num * 1.05669);
      break;
    case 'r':
      printf("%f degrees is equal to %f radians.\n", num, num * PI / 180);
      break;
    case 'kg':
      printf("%f pounds is equal to %f kilograms.\n", num, num * 0.45359);
      break;
    default:
      printf("Invalid unit selection\n");
  }

  return 0;
}