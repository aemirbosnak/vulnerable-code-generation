//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: energetic
#include <stdio.h>

int main() {
  // Declare variables to store the input and output values.
  float inputValue;
  float outputValue;

  // Declare variables to store the conversion factors.
  float metersToFeet = 3.28084;
  float feetToMeters = 0.3048;
  float kilometersToMiles = 0.621371;
  float milesToKilometers = 1.60934;
  float celsiusToFahrenheit = 1.8;
  float fahrenheitToCelsius = 0.555556;

  // Get the input value from the user.
  printf("Enter the input value: ");
  scanf("%f", &inputValue);

  // Get the conversion type from the user.
  int conversionType;
  printf("Enter the conversion type (1 for meters to feet, 2 for feet to meters, 3 for kilometers to miles, 4 for miles to kilometers, 5 for celsius to fahrenheit, 6 for fahrenheit to celsius): ");
  scanf("%d", &conversionType);

  // Convert the input value based on the conversion type.
  switch (conversionType) {
    case 1:
      outputValue = inputValue * metersToFeet;
      printf("The converted value is: %f feet\n", outputValue);
      break;
    case 2:
      outputValue = inputValue * feetToMeters;
      printf("The converted value is: %f meters\n", outputValue);
      break;
    case 3:
      outputValue = inputValue * kilometersToMiles;
      printf("The converted value is: %f miles\n", outputValue);
      break;
    case 4:
      outputValue = inputValue * milesToKilometers;
      printf("The converted value is: %f kilometers\n", outputValue);
      break;
    case 5:
      outputValue = inputValue * celsiusToFahrenheit;
      printf("The converted value is: %f fahrenheit\n", outputValue);
      break;
    case 6:
      outputValue = inputValue * fahrenheitToCelsius;
      printf("The converted value is: %f celsius\n", outputValue);
      break;
    default:
      printf("Invalid conversion type\n");
  }

  return 0;
}