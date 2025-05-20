//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: intelligent
#include <stdio.h>
#include <math.h>

#define PI 3.14159

int main() {
  int choice, unit_from, unit_to;
  float value;

  printf("Enter 1 for metric units, 2 for imperial units: ");
  scanf("%d", &choice);

  if (choice == 1) {
    printf("Enter the value: ");
    scanf("%f", &value);

    printf("Enter the unit you want to convert to: ");
    scanf("%d", &unit_to);

    switch (unit_to) {
      case 1:
        printf("The converted value is: %.2f grams", value * 1000);
        break;
      case 2:
        printf("The converted value is: %.2f kilograms", value * 1000);
        break;
      case 3:
        printf("The converted value is: %.2f meters", value * 1000);
        break;
      default:
        printf("Invalid unit conversion");
    }
  } else if (choice == 2) {
    printf("Enter the value: ");
    scanf("%f", &value);

    printf("Enter the unit you want to convert to: ");
    scanf("%d", &unit_to);

    switch (unit_to) {
      case 1:
        printf("The converted value is: %.2f milligrams", value * 4.88);
        break;
      case 2:
        printf("The converted value is: %.2f ounces", value * 0.0352);
        break;
      case 3:
        printf("The converted value is: %.2f feet", value * 0.0820);
        break;
      default:
        printf("Invalid unit conversion");
    }
  } else {
    printf("Invalid choice");
  }

  return 0;
}