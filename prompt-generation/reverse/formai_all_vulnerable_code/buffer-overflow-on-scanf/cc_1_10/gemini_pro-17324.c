//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// Declare the unit conversion functions
double metersToInches(double meters);
double inchesToMeters(double inches);
double centimetersToFeet(double centimeters);
double feetToCentimeters(double feet);
double kilometersToMiles(double kilometers);
double milesToKilometers(double miles);
double poundsToKilograms(double pounds);
double kilogramsToPounds(double kilograms);
double gallonsToLiters(double gallons);
double litersToGallons(double liters);

// Declare the main function
int main() {
  // Declare the input variables
  double inputValue;
  char inputUnit;
  char outputUnit;

  // Get the input value from the user
  printf("Enter the value to be converted: ");
  scanf("%lf", &inputValue);

  // Get the input unit from the user
  printf("Enter the input unit (m, in, cm, ft, km, mi, lb, kg, gal, l): ");
  scanf(" %c", &inputUnit);

  // Get the output unit from the user
  printf("Enter the output unit (m, in, cm, ft, km, mi, lb, kg, gal, l): ");
  scanf(" %c", &outputUnit);

  // Convert the input value to the output unit
  double outputValue;
  switch (inputUnit) {
    case 'm':
      switch (outputUnit) {
        case 'm':
          outputValue = inputValue;
          break;
        case 'in':
          outputValue = metersToInches(inputValue);
          break;
        case 'cm':
          outputValue = metersToCentimeters(inputValue);
          break;
        case 'ft':
          outputValue = metersToFeet(inputValue);
          break;
        case 'km':
          outputValue = metersToKilometers(inputValue);
          break;
        case 'mi':
          outputValue = metersToMiles(inputValue);
          break;
        default:
          printf("Invalid output unit!\n");
          return EXIT_FAILURE;
      }
      break;
    case 'in':
      switch (outputUnit) {
        case 'm':
          outputValue = inchesToMeters(inputValue);
          break;
        case 'in':
          outputValue = inputValue;
          break;
        case 'cm':
          outputValue = inchesToCentimeters(inputValue);
          break;
        case 'ft':
          outputValue = inchesToFeet(inputValue);
          break;
        case 'km':
          outputValue = inchesToKilometers(inputValue);
          break;
        case 'mi':
          outputValue = inchesToMiles(inputValue);
          break;
        default:
          printf("Invalid output unit!\n");
          return EXIT_FAILURE;
      }
      break;
    case 'cm':
      switch (outputUnit) {
        case 'm':
          outputValue = centimetersToMeters(inputValue);
          break;
        case 'in':
          outputValue = centimetersToInches(inputValue);
          break;
        case 'cm':
          outputValue = inputValue;
          break;
        case 'ft':
          outputValue = centimetersToFeet(inputValue);
          break;
        case 'km':
          outputValue = centimetersToKilometers(inputValue);
          break;
        case 'mi':
          outputValue = centimetersToMiles(inputValue);
          break;
        default:
          printf("Invalid output unit!\n");
          return EXIT_FAILURE;
      }
      break;
    case 'ft':
      switch (outputUnit) {
        case 'm':
          outputValue = feetToMeters(inputValue);
          break;
        case 'in':
          outputValue = feetToInches(inputValue);
          break;
        case 'cm':
          outputValue = feetToCentimeters(inputValue);
          break;
        case 'ft':
          outputValue = inputValue;
          break;
        case 'km':
          outputValue = feetToKilometers(inputValue);
          break;
        case 'mi':
          outputValue = feetToMiles(inputValue);
          break;
        default:
          printf("Invalid output unit!\n");
          return EXIT_FAILURE;
      }
      break;
    case 'km':
      switch (outputUnit) {
        case 'm':
          outputValue = kilometersToMeters(inputValue);
          break;
        case 'in':
          outputValue = kilometersToInches(inputValue);
          break;
        case 'cm':
          outputValue = kilometersToCentimeters(inputValue);
          break;
        case 'ft':
          outputValue = kilometersToFeet(inputValue);
          break;
        case 'km':
          outputValue = inputValue;
          break;
        case 'mi':
          outputValue = kilometersToMiles(inputValue);
          break;
        default:
          printf("Invalid output unit!\n");
          return EXIT_FAILURE;
      }
      break;
    case 'mi':
      switch (outputUnit) {
        case 'm':
          outputValue = milesToMeters(inputValue);
          break;
        case 'in':
          outputValue = milesToInches(inputValue);
          break;
        case 'cm':
          outputValue = milesToCentimeters(inputValue);
          break;
        case 'ft':
          outputValue = milesToFeet(inputValue);
          break;
        case 'km':
          outputValue = milesToKilometers(inputValue);
          break;
        case 'mi':
          outputValue = inputValue;
          break;
        default:
          printf("Invalid output unit!\n");
          return EXIT_FAILURE;
      }
      break;
    case 'lb':
      switch (outputUnit) {
        case 'lb':
          outputValue = inputValue;
          break;
        case 'kg':
          outputValue = poundsToKilograms(inputValue);
          break;
        default:
          printf("Invalid output unit!\n");
          return EXIT_FAILURE;
      }
      break;
    case 'kg':
      switch (outputUnit) {
        case 'lb':
          outputValue = kilogramsToPounds(inputValue);
          break;
        case 'kg':
          outputValue = inputValue;
          break;
        default:
          printf("Invalid output unit!\n");
          return EXIT_FAILURE;
      }
      break;
    case 'gal':
      switch (outputUnit) {
        case 'gal':
          outputValue = inputValue;
          break;
        case 'l':
          outputValue = gallonsToLiters(inputValue);
          break;
        default:
          printf("Invalid output unit!\n");
          return EXIT_FAILURE;
      }
      break;
    case 'l':
      switch (outputUnit) {
        case 'gal':
          outputValue = litersToGallons(inputValue);
          break;
        case 'l':
          outputValue = inputValue;
          break;
        default:
          printf("Invalid output unit!\n");
          return EXIT_FAILURE;
      }
      break;
    default:
      printf("Invalid input unit!\n");
      return EXIT_FAILURE;
  }

  // Print the output value
  printf("The converted value is: %f %c\n", outputValue, outputUnit);

  return EXIT_SUCCESS;
}

// Define the unit conversion functions
double metersToInches(double meters) {
  return meters * 39.3701;
}

double inchesToMeters(double inches) {
  return inches * 0.0254;
}

double centimetersToFeet(double centimeters) {
  return centimeters * 0.0328084;
}

double feetToCentimeters(double feet) {
  return feet * 30.48;
}

double kilometersToMiles(double kilometers) {
  return kilometers * 0.621371;
}

double milesToKilometers(double miles) {
  return miles * 1.60934;
}

double poundsToKilograms(double pounds) {
  return pounds * 0.453592;
}

double kilogramsToPounds(double kilograms) {
  return kilograms * 2.20462;
}

double gallonsToLiters(double gallons) {
  return gallons * 3.78541;
}

double litersToGallons(double liters) {
  return liters * 0.264172;
}