//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: lively
#include <stdio.h>

// Define the conversion functions
double inchesToCentimeters(double inches) {
  return inches * 2.54;
}

double centimetersToInches(double centimeters) {
  return centimeters / 2.54;
}

double poundsToKilograms(double pounds) {
  return pounds * 0.453592;
}

double kilogramsToPounds(double kilograms) {
  return kilograms * 2.20462;
}

double milesToKilometers(double miles) {
  return miles * 1.60934;
}

double kilometersToMiles(double kilometers) {
  return kilometers * 0.621371;
}

// Define the main function
int main() {
  // Get the user's input
  printf("Welcome to the Unit Converter!\n");
  printf("What type of conversion would you like to do?\n");
  printf("[1] Inches to centimeters\n");
  printf("[2] Centimeters to inches\n");
  printf("[3] Pounds to kilograms\n");
  printf("[4] Kilograms to pounds\n");
  printf("[5] Miles to kilometers\n");
  printf("[6] Kilometers to miles\n");
  int choice;
  scanf("%d", &choice);

  // Perform the conversion
  double value;
  printf("Enter the value you want to convert: ");
  scanf("%lf", &value);
  double result;
  switch (choice) {
    case 1:
      result = inchesToCentimeters(value);
      break;
    case 2:
      result = centimetersToInches(value);
      break;
    case 3:
      result = poundsToKilograms(value);
      break;
    case 4:
      result = kilogramsToPounds(value);
      break;
    case 5:
      result = milesToKilometers(value);
      break;
    case 6:
      result = kilometersToMiles(value);
      break;
    default:
      printf("Invalid choice. Please enter a number between 1 and 6.\n");
      return 1;
  }

  // Print the result
  printf("The converted value is: %lf\n", result);

  return 0;
}