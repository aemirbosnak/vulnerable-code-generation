//FormAI DATASET v1.0 Category: Unit converter ; Style: enthusiastic
#include <stdio.h>

int main() {
  printf("Welcome to Super Unit Converter!\n");
  printf("Please choose an option from the menu below:\n\n");

  printf("1. Convert Miles to Kilometers\n");
  printf("2. Convert Pounds to Kilograms\n");
  printf("3. Convert Fahrenheit to Celsius\n");
  printf("4. Convert Inches to Centimeters\n");
  printf("5. Quit\n\n");

  int choice = 0;
  scanf("%d", &choice);

  while (choice != 5) {
    if (choice == 1) {
      printf("Please enter the number of miles to convert: ");
      double miles = 0.0;
      scanf("%lf", &miles);
      double kilometers = miles * 1.60934;
      printf("%.2f miles is equal to %.2f kilometers.\n", miles, kilometers);
    } else if (choice == 2) {
      printf("Please enter the number of pounds to convert: ");
      double pounds = 0.0;
      scanf("%lf", &pounds);
      double kilograms = pounds * 0.453592;
      printf("%.2f pounds is equal to %.2f kilograms.\n", pounds, kilograms);
    } else if (choice == 3) {
      printf("Please enter the temperature in degrees Fahrenheit: ");
      double fahrenheit = 0.0;
      scanf("%lf", &fahrenheit);
      double celsius = (fahrenheit - 32) * 5 / 9;
      printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", fahrenheit, celsius);
    } else if (choice == 4) {
      printf("Please enter the number of inches to convert: ");
      double inches = 0.0;
      scanf("%lf", &inches);
      double centimeters = inches * 2.54;
      printf("%.2f inches is equal to %.2f centimeters.\n", inches, centimeters);
    } else {
      printf("Invalid choice, please try again.\n");
    }

    printf("Please choose an option from the menu below:\n\n");

    printf("1. Convert Miles to Kilometers\n");
    printf("2. Convert Pounds to Kilograms\n");
    printf("3. Convert Fahrenheit to Celsius\n");
    printf("4. Convert Inches to Centimeters\n");
    printf("5. Quit\n\n");

    scanf("%d", &choice);
  }

  printf("Thanks for using Super Unit Converter!\n");
  return 0;
}