//FormAI DATASET v1.0 Category: Unit converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

int main() {
  int option;
  float measurement;
  printf("Welcome to the Unit Converter!\n");
  do {
    printf("Please choose an option:\n");
    printf("1. Inches to Centimeters\n");
    printf("2. Centimeters to Inches\n");
    printf("3. Feet to Meters\n");
    printf("4. Meters to Feet\n");
    printf("5. Pounds to Kilograms\n");
    printf("6. Kilograms to Pounds\n");
    printf("0. Exit\n");
    printf("Option: ");
    scanf("%d", &option);
    if (option > 0 && option < 7) {
      printf("Enter the measurement to convert: ");
      scanf("%f", &measurement);
    }
    switch(option) {
      case 0:
        break;
      case 1:
        printf("%.2f inches is %.2f centimeters.\n", measurement, measurement * 2.54);
        break;
      case 2:
        printf("%.2f centimeters is %.2f inches.\n", measurement, measurement / 2.54);
        break;
      case 3:
        printf("%.2f feet is %.2f meters.\n", measurement, measurement * 0.3048);
        break;
      case 4:
        printf("%.2f meters is %.2f feet.\n", measurement, measurement / 0.3048);
        break;
      case 5:
        printf("%.2f pounds is %.2f kilograms.\n", measurement, measurement * 0.4536);
        break;
      case 6:
        printf("%.2f kilograms is %.2f pounds.\n", measurement, measurement / 0.4536);
        break;
      default:
        printf("Invalid option. Please try again.\n");
        break;
    }
  } while (option != 0);
  printf("Thank you for using the Unit Converter!\n");
  return 0;
}