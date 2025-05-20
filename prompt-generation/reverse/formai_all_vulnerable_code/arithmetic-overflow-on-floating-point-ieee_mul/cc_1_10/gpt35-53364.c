//FormAI DATASET v1.0 Category: Unit converter ; Style: expert-level
#include <stdio.h>

void printMenu() {
  printf("Welcome to the unit converter\n");
  printf("1. Convert Fahrenheit to Celsius\n");
  printf("2. Convert Celsius to Fahrenheit\n");
  printf("3. Convert Miles to Kilometers\n");
  printf("4. Convert Kilometers to Miles\n");
  printf("5. Quit\n");
}

double fahrenheitToCelsius(double f) {
  return (f - 32) * 5 / 9;
}

double celsiusToFahrenheit(double c) {
  return (c * 9 / 5) + 32;
}

double milesToKilometers(double m) {
  return m * 1.609344;
}

double kilometersToMiles(double k) {
  return k / 1.609344;
}

int main() {
  int choice = 0;
  double input = 0.0;

  while(choice != 5) {
    printMenu();
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("Enter temperature in Fahrenheit: ");
        scanf("%lf", &input);
        printf("%.2f degrees Fahrenheit is %.2f degrees Celsius\n", input, fahrenheitToCelsius(input));
        break;
      case 2:
        printf("Enter temperature in Celsius: ");
        scanf("%lf", &input);
        printf("%.2f degrees Celsius is %.2f degrees Fahrenheit\n", input, celsiusToFahrenheit(input));
        break;
      case 3:
        printf("Enter distance in miles: ");
        scanf("%lf", &input);
        printf("%.2f miles is %.2f kilometers\n", input, milesToKilometers(input));
        break;
      case 4:
        printf("Enter distance in kilometers: ");
        scanf("%lf", &input);
        printf("%.2f kilometers is %.2f miles\n", input, kilometersToMiles(input));
        break;
      case 5:
        printf("Thank you for using the unit converter!\n");
        break;
      default:
        printf("Invalid option. Please choose again.\n");
        break;
    }
  }

  return 0;
}