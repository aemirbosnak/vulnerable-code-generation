//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  // Declare the variables
  double inputValue, outputValue;
  int choice;

  // Display the menu
  printf("Welcome to the Unit Converter!\n");
  printf("Please select a conversion type:\n");
  printf("1. Length\n");
  printf("2. Weight\n");
  printf("3. Temperature\n");
  printf("4. Quit\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);

  // Get the input value
  printf("Enter the input value: ");
  scanf("%lf", &inputValue);

  // Convert the value based on the user's choice
  switch (choice) {
    case 1:
      // Convert length
      printf("Select the output unit:\n");
      printf("1. Inches\n");
      printf("2. Feet\n");
      printf("3. Yards\n");
      printf("4. Miles\n");
      printf("5. Kilometers\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);

      switch (choice) {
        case 1:
          outputValue = inputValue * 2.54;
          printf("The output value is: %.2f inches\n", outputValue);
          break;
        case 2:
          outputValue = inputValue * 0.3048;
          printf("The output value is: %.2f feet\n", outputValue);
          break;
        case 3:
          outputValue = inputValue * 0.9144;
          printf("The output value is: %.2f yards\n", outputValue);
          break;
        case 4:
          outputValue = inputValue * 1609.34;
          printf("The output value is: %.2f miles\n", outputValue);
          break;
        case 5:
          outputValue = inputValue * 1000;
          printf("The output value is: %.2f kilometers\n", outputValue);
          break;
        default:
          printf("Invalid choice\n");
          break;
      }
      break;
    case 2:
      // Convert weight
      printf("Select the output unit:\n");
      printf("1. Ounces\n");
      printf("2. Pounds\n");
      printf("3. Kilograms\n");
      printf("4. Grams\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);

      switch (choice) {
        case 1:
          outputValue = inputValue * 28.3495;
          printf("The output value is: %.2f ounces\n", outputValue);
          break;
        case 2:
          outputValue = inputValue * 0.453592;
          printf("The output value is: %.2f pounds\n", outputValue);
          break;
        case 3:
          outputValue = inputValue * 1000;
          printf("The output value is: %.2f kilograms\n", outputValue);
          break;
        case 4:
          outputValue = inputValue * 1000000;
          printf("The output value is: %.2f grams\n", outputValue);
          break;
        default:
          printf("Invalid choice\n");
          break;
      }
      break;
    case 3:
      // Convert temperature
      printf("Select the output unit:\n");
      printf("1. Fahrenheit\n");
      printf("2. Celsius\n");
      printf("3. Kelvin\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);

      switch (choice) {
        case 1:
          outputValue = inputValue * 1.8 + 32;
          printf("The output value is: %.2f Fahrenheit\n", outputValue);
          break;
        case 2:
          outputValue = (inputValue - 32) / 1.8;
          printf("The output value is: %.2f Celsius\n", outputValue);
          break;
        case 3:
          outputValue = inputValue + 273.15;
          printf("The output value is: %.2f Kelvin\n", outputValue);
          break;
        default:
          printf("Invalid choice\n");
          break;
      }
      break;
    case 4:
      // Quit the program
      printf("Thank you for using the Unit Converter!\n");
      return 0;
    default:
      printf("Invalid choice\n");
      break;
  }

  return 0;
}