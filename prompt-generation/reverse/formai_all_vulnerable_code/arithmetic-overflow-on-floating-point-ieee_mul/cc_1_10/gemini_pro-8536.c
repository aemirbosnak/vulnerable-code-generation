//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: unmistakable
#include <stdio.h>

// Define the conversion functions
double inchesToCentimeters(double inches);
double centimetersToInches(double centimeters);
double fahrenheitToCelsius(double fahrenheit);
double celsiusToFahrenheit(double celsius);
double milesToKilometers(double miles);
double kilometersToMiles(double kilometers);
double poundsToKilograms(double pounds);
double kilogramsToPounds(double kilograms);
double gallonsToLiters(double gallons);
double litersToGallons(double liters);

// Define the main function
int main() {
  // Get the user's input
  printf("Enter the value to be converted: ");
  double value;
  scanf("%lf", &value);

  // Get the user's choice of units
  printf("Enter the units to convert from (i/c/f/k/m/p/g/l): ");
  char fromUnits;
  scanf(" %c", &fromUnits);

  // Get the user's choice of units to convert to
  printf("Enter the units to convert to (i/c/f/k/m/p/g/l): ");
  char toUnits;
  scanf(" %c", &toUnits);

  // Convert the value using the appropriate function
  double convertedValue;
  switch (fromUnits) {
    case 'i':
      switch (toUnits) {
        case 'c':
          convertedValue = inchesToCentimeters(value);
          break;
        default:
          printf("Invalid conversion");
          return 1;
      }
      break;
    case 'c':
      switch (toUnits) {
        case 'i':
          convertedValue = centimetersToInches(value);
          break;
        default:
          printf("Invalid conversion");
          return 1;
      }
      break;
    case 'f':
      switch (toUnits) {
        case 'c':
          convertedValue = fahrenheitToCelsius(value);
          break;
        default:
          printf("Invalid conversion");
          return 1;
      }
      break;
    case 'k':
      switch (toUnits) {
        case 'm':
          convertedValue = kilometersToMiles(value);
          break;
        default:
          printf("Invalid conversion");
          return 1;
      }
      break;
    case 'm':
      switch (toUnits) {
        case 'k':
          convertedValue = milesToKilometers(value);
          break;
        default:
          printf("Invalid conversion");
          return 1;
      }
      break;
    case 'p':
      switch (toUnits) {
        case 'k':
          convertedValue = poundsToKilograms(value);
          break;
        default:
          printf("Invalid conversion");
          return 1;
      }
      break;
    case 'g':
      switch (toUnits) {
        case 'l':
          convertedValue = gallonsToLiters(value);
          break;
        default:
          printf("Invalid conversion");
          return 1;
      }
      break;
    case 'l':
      switch (toUnits) {
        case 'g':
          convertedValue = litersToGallons(value);
          break;
        default:
          printf("Invalid conversion");
          return 1;
      }
      break;
    default:
      printf("Invalid units");
      return 1;
  }

  // Print the converted value
  printf("%lf %c is equal to %lf %c\n", value, fromUnits, convertedValue, toUnits);

  return 0;
}

// Define the conversion functions
double inchesToCentimeters(double inches) {
  return inches * 2.54;
}

double centimetersToInches(double centimeters) {
  return centimeters / 2.54;
}

double fahrenheitToCelsius(double fahrenheit) {
  return (fahrenheit - 32) * 5 / 9;
}

double celsiusToFahrenheit(double celsius) {
  return (celsius * 9 / 5) + 32;
}

double milesToKilometers(double miles) {
  return miles * 1.60934;
}

double kilometersToMiles(double kilometers) {
  return kilometers / 1.60934;
}

double poundsToKilograms(double pounds) {
  return pounds * 0.453592;
}

double kilogramsToPounds(double kilograms) {
  return kilograms / 0.453592;
}

double gallonsToLiters(double gallons) {
  return gallons * 3.78541;
}

double litersToGallons(double liters) {
  return liters / 3.78541;
}