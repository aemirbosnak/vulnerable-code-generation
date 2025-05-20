//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

int main() {
  char input[100];
  int choice;
  float value, result;

  printf("Welcome to the Unit Converter!\n");
  printf("Enter the value you want to convert: ");
  scanf("%f", &value);

  printf("Choose the unit you want to convert from:\n");
  printf("1. Feet to Meters\n");
  printf("2. Meters to Feet\n");
  printf("3. Inches to Centimeters\n");
  printf("4. Centimeters to Inches\n");
  printf("5. Pounds to Kilograms\n");
  printf("6. Kilograms to Pounds\n");
  printf("7. Gallons to Liters\n");
  printf("8. Liters to Gallons\n");
  printf("9. Miles to Kilometers\n");
  printf("10. Kilometers to Miles\n");

  scanf("%d", &choice);

  switch (choice) {
    case 1:
      result = value * 0.3048;
      printf("%.2f feet is equal to %.2f meters\n", value, result);
      break;
    case 2:
      result = value * 3.281;
      printf("%.2f meters is equal to %.2f feet\n", value, result);
      break;
    case 3:
      result = value * 2.54;
      printf("%.2f inches is equal to %.2f centimeters\n", value, result);
      break;
    case 4:
      result = value * 0.3937;
      printf("%.2f centimeters is equal to %.2f inches\n", value, result);
      break;
    case 5:
      result = value * 0.4536;
      printf("%.2f pounds is equal to %.2f kilograms\n", value, result);
      break;
    case 6:
      result = value * 2.205;
      printf("%.2f kilograms is equal to %.2f pounds\n", value, result);
      break;
    case 7:
      result = value * 3.785;
      printf("%.2f gallons is equal to %.2f liters\n", value, result);
      break;
    case 8:
      result = value * 0.2642;
      printf("%.2f liters is equal to %.2f gallons\n", value, result);
      break;
    case 9:
      result = value * 1.609;
      printf("%.2f miles is equal to %.2f kilometers\n", value, result);
      break;
    case 10:
      result = value * 0.6214;
      printf("%.2f kilometers is equal to %.2f miles\n", value, result);
      break;
    default:
      printf("Invalid choice!\n");
      break;
  }

  return 0;
}