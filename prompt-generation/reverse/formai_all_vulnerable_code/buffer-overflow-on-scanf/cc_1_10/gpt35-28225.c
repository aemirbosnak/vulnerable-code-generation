//FormAI DATASET v1.0 Category: Unit converter ; Style: excited
#include <stdio.h>

int main() {
  int option;
  printf("Welcome to the Ultimate C Unit Converter!\n\n");

  while (1) {
    printf("Select the option you want to convert:\n");
    printf("1. Meters to Feet\n");
    printf("2. Kilograms to Pounds\n");
    printf("3. Litres to Gallons\n");
    printf("4. Celsius to Fahrenheit\n");
    printf("5. Quit\n\n");

    scanf("%d", &option);

    if (option == 1) {
      float meters, feet;
      printf("Enter the value in meters: ");
      scanf("%f", &meters);
      feet = meters * 3.28084;
      printf("%.2f meters = %.2f feet\n\n", meters, feet);
    }

    if (option == 2) {
      float kg, lb;
      printf("Enter the value in kilograms: ");
      scanf("%f", &kg);
      lb = kg * 2.20462;
      printf("%.2f kilograms = %.2f pounds\n\n", kg, lb);
    }

    if (option == 3) {
      float litres, gallons;
      printf("Enter the value in litres: ");
      scanf("%f", &litres);
      gallons = litres * 0.264172;
      printf("%.2f litres = %.2f gallons\n\n", litres, gallons);
    }

    if (option == 4) {
      float celsius, fahrenheit;
      printf("Enter the value in celsius: ");
      scanf("%f", &celsius);
      fahrenheit = celsius * 1.8 + 32;
      printf("%.2f celsius = %.2f fahrenheit\n\n", celsius, fahrenheit);
    }

    if (option == 5) {
      printf("Thank you for using the Ultimate C Unit Converter!\n");
      break;
    }

    if (option < 1 || option > 5) {
      printf("Invalid option!\n\n");
    }
  }

  return 0;
}