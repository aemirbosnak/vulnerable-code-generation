//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: standalone
#include <stdio.h>
#include <math.h>

int main() {
  float value, result;
  int choice;

  printf("Welcome to the Unit Converter!\n");
  printf("Please enter the value you want to convert: ");
  scanf("%f", &value);

  printf("Please select the unit you want to convert from:\n");
  printf("1. Meters\n2. Kilometers\n3. Centimeters\n4. Millimeters\n5. Inches\n6. Feet\n7. Yards\n8. Miles\n");
  scanf("%d", &choice);

  switch(choice) {
    case 1:
      result = value * 100;
      printf("The value in centimeters is: %.2f\n", result);
      break;
    case 2:
      result = value / 1000;
      printf("The value in meters is: %.2f\n", result);
      break;
    case 3:
      result = value / 100;
      printf("The value in decimeters is: %.2f\n", result);
      break;
    case 4:
      result = value / 10000;
      printf("The value in millimeters is: %.2f\n", result);
      break;
    case 5:
      result = value / 0.0254;
      printf("The value in inches is: %.2f\n", result);
      break;
    case 6:
      result = value / 0.3048;
      printf("The value in feet is: %.2f\n", result);
      break;
    case 7:
      result = value / 0.9144;
      printf("The value in yards is: %.2f\n", result);
      break;
    case 8:
      result = value / 160934.4;
      printf("The value in miles is: %.2f\n", result);
      break;
    default:
      printf("Invalid unit selected.\n");
  }

  return 0;
}