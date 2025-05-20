//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: grateful
#include <stdio.h>
#include <math.h>

int main() {

  // Declare our gratitude
  printf("I am grateful for the opportunity to convert units for you today!\n");

  // Get the user's input
  double inputValue;
  char inputUnit;
  char outputUnit;

  printf("Please enter the value you want to convert: ");
  scanf("%lf", &inputValue);

  printf("Please enter the unit of the value you entered (e.g., cm, m, ft, in): ");
  scanf(" %c", &inputUnit);

  printf("Please enter the unit you want to convert to (e.g., cm, m, ft, in): ");
  scanf(" %c", &outputUnit);

  // Convert the value
  double outputValue;

  switch (inputUnit) {
    case 'c': // centimeters
      switch (outputUnit) {
        case 'c':
          outputValue = inputValue;
          break;
        case 'm':
          outputValue = inputValue / 100;
          break;
        case 'f':
          outputValue = inputValue / 2.54;
          break;
        case 'i':
          outputValue = inputValue / 2.54 / 12;
          break;
      }
      break;
    case 'm': // meters
      switch (outputUnit) {
        case 'c':
          outputValue = inputValue * 100;
          break;
        case 'm':
          outputValue = inputValue;
          break;
        case 'f':
          outputValue = inputValue * 3.281;
          break;
        case 'i':
          outputValue = inputValue * 3.281 * 12;
          break;
      }
      break;
    case 'f': // feet
      switch (outputUnit) {
        case 'c':
          outputValue = inputValue * 2.54;
          break;
        case 'm':
          outputValue = inputValue / 3.281;
          break;
        case 'f':
          outputValue = inputValue;
          break;
        case 'i':
          outputValue = inputValue * 12;
          break;
      }
      break;
    case 'i': // inches
      switch (outputUnit) {
        case 'c':
          outputValue = inputValue * 2.54 * 12;
          break;
        case 'm':
          outputValue = inputValue / 3.281 / 12;
          break;
        case 'f':
          outputValue = inputValue / 12;
          break;
        case 'i':
          outputValue = inputValue;
          break;
      }
      break;
  }

  // Print the result
  printf("The converted value is: %lf %c\n", outputValue, outputUnit);

  // Express our gratitude again
  printf("Thank you for using my unit converter! I am grateful for the opportunity to help you.\n");

  return 0;
}