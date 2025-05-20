//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

// Constants for unit conversions
const double INCHES_PER_CM = 2.54;
const double CM_PER_INCHES = 0.393701;
const double LBS_PER_KG = 2.20462;
const double KG_PER_LBS = 0.453592;
const double MILES_PER_KM = 0.621371;
const double KM_PER_MILES = 1.60934;

// Function to convert inches to centimeters
double inchesToCm(double inches) {
  return inches * INCHES_PER_CM;
}

// Function to convert centimeters to inches
double cmToInches(double cm) {
  return cm * CM_PER_INCHES;
}

// Function to convert pounds to kilograms
double lbsToKg(double lbs) {
  return lbs * LBS_PER_KG;
}

// Function to convert kilograms to pounds
double kgToLbs(double kg) {
  return kg * KG_PER_LBS;
}

// Function to convert miles to kilometers
double milesToKm(double miles) {
  return miles * MILES_PER_KM;
}

// Function to convert kilometers to miles
double kmToMiles(double km) {
  return km * KM_PER_MILES;
}

// Main function
int main() {
  // Declare variables for user input and conversion results
  double inputValue;
  double convertedValue;
  char unitType;

  // Get user input
  printf("Enter the value to be converted: ");
  scanf("%lf", &inputValue);

  printf("Enter the unit type (i for inches, c for centimeters, l for pounds, k for kilograms, m for miles, or km for kilometers): ");
  scanf(" %c", &unitType);

  // Convert the value based on the user input
  switch (unitType) {
    case 'i':
      convertedValue = inchesToCm(inputValue);
      printf("%.2f inches is equal to %.2f centimeters.\n", inputValue, convertedValue);
      break;
    case 'c':
      convertedValue = cmToInches(inputValue);
      printf("%.2f centimeters is equal to %.2f inches.\n", inputValue, convertedValue);
      break;
    case 'l':
      convertedValue = lbsToKg(inputValue);
      printf("%.2f pounds is equal to %.2f kilograms.\n", inputValue, convertedValue);
      break;
    case 'k':
      convertedValue = kgToLbs(inputValue);
      printf("%.2f kilograms is equal to %.2f pounds.\n", inputValue, convertedValue);
      break;
    case 'm':
      convertedValue = milesToKm(inputValue);
      printf("%.2f miles is equal to %.2f kilometers.\n", inputValue, convertedValue);
      break;
    case 'km':
      convertedValue = kmToMiles(inputValue);
      printf("%.2f kilometers is equal to %.2f miles.\n", inputValue, convertedValue);
      break;
    default:
      printf("Invalid unit type entered.\n");
      return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}