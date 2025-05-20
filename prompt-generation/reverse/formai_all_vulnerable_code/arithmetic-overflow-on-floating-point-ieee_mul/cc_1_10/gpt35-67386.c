//FormAI DATASET v1.0 Category: Unit converter ; Style: futuristic
#include <stdio.h>

int main() {
  int selection;
  double value;
  double result;

  printf("Welcome to the Unit Converter 9000!\n");

  do {
    printf("\nPlease select a conversion option:\n");
    printf("1. Meters to Feet\n");
    printf("2. Kilograms to Pounds\n");
    printf("3. Celsius to Fahrenheit\n");
    printf("4. Exit Program\n");
    printf("Selection: ");
    scanf("%d", &selection);

    if (selection == 4) {
      printf("\nThank you for using the Unit Converter 9000!\n");
      break;
    }

    printf("Enter value: ");
    scanf("%lf", &value);

    switch (selection) {
      case 1:
        result = value * 3.281;
        printf("%.2lf meters is equal to %.2lf feet.\n", value, result);
        break;

      case 2:
        result = value * 2.205;
        printf("%.2lf kilograms is equal to %.2lf pounds.\n", value, result);
        break;

      case 3:
        result = (value * 1.8) + 32;
        printf("%.2lf Celsius is equal to %.2lf Fahrenheit.\n", value, result);
        break;

      default:
        printf("Invalid selection. Please try again.\n");
        break;
    }

  } while (selection != 4);

  return 0;
}