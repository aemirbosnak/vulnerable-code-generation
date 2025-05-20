//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: ephemeral
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Constants for unit conversions
const double FEET_TO_METERS = 0.3048;
const double METERS_TO_FEET = 3.28084;
const double POUNDS_TO_KILOGRAMS = 0.453592;
const double KILOGRAMS_TO_POUNDS = 2.20462;

// Function to convert feet to meters
double feet_to_meters(double feet) {
  return feet * FEET_TO_METERS;
}

// Function to convert meters to feet
double meters_to_feet(double meters) {
  return meters * METERS_TO_FEET;
}

// Function to convert pounds to kilograms
double pounds_to_kilograms(double pounds) {
  return pounds * POUNDS_TO_KILOGRAMS;
}

// Function to convert kilograms to pounds
double kilograms_to_pounds(double kilograms) {
  return kilograms * KILOGRAMS_TO_POUNDS;
}

// Main function
int main() {
  // Create a menu of options for the user to choose from
  printf("Welcome to the unit converter!\n");
  printf("Please choose one of the following options:\n");
  printf("1. Convert feet to meters\n");
  printf("2. Convert meters to feet\n");
  printf("3. Convert pounds to kilograms\n");
  printf("4. Convert kilograms to pounds\n");
  printf("5. Quit\n");

  // Get the user's choice
  int choice;
  scanf("%d", &choice);

  // Convert the units based on the user's choice
  double value;
  switch (choice) {
    case 1:
      printf("Enter the value in feet: ");
      scanf("%lf", &value);
      printf("%lf feet is equal to %lf meters\n", value, feet_to_meters(value));
      break;
    case 2:
      printf("Enter the value in meters: ");
      scanf("%lf", &value);
      printf("%lf meters is equal to %lf feet\n", value, meters_to_feet(value));
      break;
    case 3:
      printf("Enter the value in pounds: ");
      scanf("%lf", &value);
      printf("%lf pounds is equal to %lf kilograms\n", value, pounds_to_kilograms(value));
      break;
    case 4:
      printf("Enter the value in kilograms: ");
      scanf("%lf", &value);
      printf("%lf kilograms is equal to %lf pounds\n", value, kilograms_to_pounds(value));
      break;
    case 5:
      printf("Thank you for using the unit converter!\n");
      return 0;
    default:
      printf("Invalid choice. Please choose one of the options from 1 to 5.\n");
      break;
  }

  return 0;
}