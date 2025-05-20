//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Declare our unit conversion constants
  float miles_to_kilometers = 1.60934;
  float kilometers_to_miles = 0.621371;
  float gallons_to_liters = 3.78541;
  float liters_to_gallons = 0.264172;
  float pounds_to_kilograms = 0.453592;
  float kilograms_to_pounds = 2.20462;

  // Get the user's input
  int choice;
  float value;
  printf("Welcome to the Post-Apocalyptic Unit Converter!\n");
  printf("1. Convert Miles to Kilometers\n");
  printf("2. Convert Kilometers to Miles\n");
  printf("3. Convert Gallons to Liters\n");
  printf("4. Convert Liters to Gallons\n");
  printf("5. Convert Pounds to Kilograms\n");
  printf("6. Convert Kilograms to Pounds\n");
  printf("Enter your choice (1-6): ");
  scanf("%d", &choice);
  printf("Enter the value to convert: ");
  scanf("%f", &value);

  // Perform the conversion
  float result;
  switch (choice) {
    case 1:
      result = value * miles_to_kilometers;
      printf("%.2f miles is equal to %.2f kilometers.\n", value, result);
      break;
    case 2:
      result = value * kilometers_to_miles;
      printf("%.2f kilometers is equal to %.2f miles.\n", value, result);
      break;
    case 3:
      result = value * gallons_to_liters;
      printf("%.2f gallons is equal to %.2f liters.\n", value, result);
      break;
    case 4:
      result = value * liters_to_gallons;
      printf("%.2f liters is equal to %.2f gallons.\n", value, result);
      break;
    case 5:
      result = value * pounds_to_kilograms;
      printf("%.2f pounds is equal to %.2f kilograms.\n", value, result);
      break;
    case 6:
      result = value * kilograms_to_pounds;
      printf("%.2f kilograms is equal to %.2f pounds.\n", value, result);
      break;
    default:
      printf("Invalid choice. Please enter a number between 1 and 6.\n");
  }

  return 0;
}