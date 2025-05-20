//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
  return (celsius * 9 / 5) + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
  return (fahrenheit - 32) * 5 / 9;
}

// Function to convert Miles to Kilometers
float milesToKilometers(float miles) {
  return miles * 1.60934;
}

// Function to convert Kilometers to Miles
float kilometersToMiles(float kilometers) {
  return kilometers / 1.60934;
}

// Function to convert Pounds to Kilograms
float poundsToKilograms(float pounds) {
  return pounds * 0.453592;
}

// Function to convert Kilograms to Pounds
float kilogramsToPounds(float kilograms) {
  return kilograms / 0.453592;
}

// Function to convert Gallons to Liters
float gallonsToLiters(float gallons) {
  return gallons * 3.78541;
}

// Function to convert Liters to Gallons
float litersToGallons(float liters) {
  return liters / 3.78541;
}

// Function to convert Ounces to Grams
float ouncesToGrams(float ounces) {
  return ounces * 28.3495;
}

// Function to convert Grams to Ounces
float gramsToOunces(float grams) {
  return grams / 28.3495;
}

int main() {
  // Declare variables to store user input and conversion results
  float value, result;
  char unitFrom, unitTo;

  // Get user input for the value to be converted
  printf("Enter the value to be converted: ");
  scanf("%f", &value);

  // Get user input for the unit of measurement to be converted from
  printf("Enter the unit of measurement to be converted from (C/F/M/KM/LB/KG/GL/L/OZ/G): ");
  scanf(" %c", &unitFrom);

  // Get user input for the unit of measurement to be converted to
  printf("Enter the unit of measurement to be converted to (C/F/M/KM/LB/KG/GL/L/OZ/G): ");
  scanf(" %c", &unitTo);

  // Convert the value based on the user input
  switch (unitFrom) {
    case 'C':
      switch (unitTo) {
        case 'F':
          result = celsiusToFahrenheit(value);
          break;
        default:
          printf("Invalid unit conversion specified.\n");
          return 1;
      }
      break;
    case 'F':
      switch (unitTo) {
        case 'C':
          result = fahrenheitToCelsius(value);
          break;
        default:
          printf("Invalid unit conversion specified.\n");
          return 1;
      }
      break;
    case 'M':
      switch (unitTo) {
        case 'KM':
          result = milesToKilometers(value);
          break;
        default:
          printf("Invalid unit conversion specified.\n");
          return 1;
      }
      break;
    case 'KM':
      switch (unitTo) {
        case 'M':
          result = kilometersToMiles(value);
          break;
        default:
          printf("Invalid unit conversion specified.\n");
          return 1;
      }
      break;
    case 'LB':
      switch (unitTo) {
        case 'KG':
          result = poundsToKilograms(value);
          break;
        default:
          printf("Invalid unit conversion specified.\n");
          return 1;
      }
      break;
    case 'KG':
      switch (unitTo) {
        case 'LB':
          result = kilogramsToPounds(value);
          break;
        default:
          printf("Invalid unit conversion specified.\n");
          return 1;
      }
      break;
    case 'GL':
      switch (unitTo) {
        case 'L':
          result = gallonsToLiters(value);
          break;
        default:
          printf("Invalid unit conversion specified.\n");
          return 1;
      }
      break;
    case 'L':
      switch (unitTo) {
        case 'GL':
          result = litersToGallons(value);
          break;
        default:
          printf("Invalid unit conversion specified.\n");
          return 1;
      }
      break;
    case 'OZ':
      switch (unitTo) {
        case 'G':
          result = ouncesToGrams(value);
          break;
        default:
          printf("Invalid unit conversion specified.\n");
          return 1;
      }
      break;
    case 'G':
      switch (unitTo) {
        case 'OZ':
          result = gramsToOunces(value);
          break;
        default:
          printf("Invalid unit conversion specified.\n");
          return 1;
      }
      break;
    default:
      printf("Invalid unit of measurement specified.\n");
      return 1;
  }

  // Print the conversion result
  printf("The converted value is: %.2f %c\n", result, unitTo);

  return 0;
}