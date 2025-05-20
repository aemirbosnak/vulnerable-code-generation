//FormAI DATASET v1.0 Category: Unit converter ; Style: visionary
#include <stdio.h>

int main() {
  int choice;
  double value;

  printf("Welcome to the visionary C Unit Converter!\n");
  printf("Please select an option from the menu below:\n");
  printf("1. Convert meters to feet\n");
  printf("2. Convert kilometers to miles\n");
  printf("3. Convert celsius to fahrenheit\n");
  printf("4. Convert liters to gallons\n");
  printf("5. Quit the program\n");

  printf("Enter your choice (1-5): ");
  scanf("%d", &choice);

  while (choice != 5) {
    switch (choice) {
      case 1: {
        printf("Enter a value in meters: ");
        scanf("%lf", &value);
        double feet = value * 3.28084;
        printf("%lf meters = %lf feet\n", value, feet);
        break;
      }
      case 2: {
        printf("Enter a value in kilometers: ");
        scanf("%lf", &value);
        double miles = value * 0.621371;
        printf("%lf kilometers = %lf miles\n", value, miles);
        break;
      }
      case 3: {
        printf("Enter a value in celsius: ");
        scanf("%lf", &value);
        double fahrenheit = (value * 1.8) + 32;
        printf("%lf celsius = %lf fahrenheit\n", value, fahrenheit);
        break;
      }
      case 4: {
        printf("Enter a value in liters: ");
        scanf("%lf", &value);
        double gallons = value * 0.264172;
        printf("%lf liters = %lf gallons\n", value, gallons);
        break;
      }
      default:
        printf("Invalid choice, please enter a number from 1 to 5.\n");
    }
    printf("\nEnter your choice (1-5): ");
    scanf("%d", &choice);
  }

  printf("Thank you for using the visionary C Unit Converter! Goodbye.\n");

  return 0;
}