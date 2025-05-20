//FormAI DATASET v1.0 Category: Unit converter ; Style: irregular
#include <stdio.h>

int main() {
  printf("Welcome to the Unit Converter!\n");
  printf("Here are the available unit types to convert:\n");
  printf("1. Kilometers to Miles\n");
  printf("2. Pounds to Kilograms\n");
  printf("3. Gallons to Liters\n");
  printf("4. Fahrenheit to Celsius\n");
  printf("Please enter the number of your choice: ");

  int choice;
  scanf("%d", &choice);

  switch(choice) {
    case 1:
      printf("Kilometer to Mile converter\n");
      printf("Please enter the value in kilometers: ");

      double km_value, mile_value;
      scanf("%lf", &km_value);

      mile_value = km_value / 1.609;
      printf("%.2lf kilometers is equal to %.2lf miles\n", km_value, mile_value);
      break;
    case 2:
      printf("Pound to Kilogram converter\n");
      printf("Please enter the value in pounds: ");

      double pound_value, kg_value;
      scanf("%lf", &pound_value);

      kg_value = pound_value / 2.205;
      printf("%.2lf pounds is equal to %.2lf kilograms\n", pound_value, kg_value);
      break;
    case 3:
      printf("Gallon to Liter converter\n");
      printf("Please enter the value in gallons: ");

      double gallon_value, liter_value;
      scanf("%lf", &gallon_value);

      liter_value = gallon_value * 3.785;
      printf("%.2lf gallons is equal to %.2lf liters\n", gallon_value, liter_value);
      break;
    case 4:
      printf("Fahrenheit to Celsius converter\n");
      printf("Please enter the value in Fahrenheit: ");

      double fahrenheit_value, celsius_value;
      scanf("%lf", &fahrenheit_value);

      celsius_value = (fahrenheit_value - 32) * (5.0 / 9);
      printf("%.2lf degrees Fahrenheit is equal to %.2lf degrees Celsius\n", fahrenheit_value, celsius_value);
      break;
    default:
      printf("Invalid choice.\n");
      break;
  }

  return 0;
}