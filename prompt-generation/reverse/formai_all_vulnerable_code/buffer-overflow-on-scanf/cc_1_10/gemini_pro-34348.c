//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: beginner-friendly
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

// Function to convert miles to kilometers
float milesToKilometers(float miles) {
  return miles * 1.60934;
}

// Function to convert kilometers to miles
float kilometersToMiles(float kilometers) {
  return kilometers * 0.621371;
}

// Function to convert pounds to kilograms
float poundsToKilograms(float pounds) {
  return pounds * 0.453592;
}

// Function to convert kilograms to pounds
float kilogramsToPounds(float kilograms) {
  return kilograms * 2.20462;
}

// Function to convert inches to centimeters
float inchesToCentimeters(float inches) {
  return inches * 2.54;
}

// Function to convert centimeters to inches
float centimetersToInches(float centimeters) {
  return centimeters * 0.393701;
}

int main() {
  // Get the user's input
  printf("Enter the value you want to convert: ");
  float value;
  scanf("%f", &value);

  printf("Enter the unit of the value (C for Celsius, F for Fahrenheit, M for Miles, K for Kilometers, P for Pounds, KG for Kilograms, I for Inches, CM for Centimeters): ");
  char unit;
  scanf(" %c", &unit);

  // Convert the value to the desired unit
  float convertedValue;
  switch (unit) {
    case 'C':
      convertedValue = celsiusToFahrenheit(value);
      printf("%.2f Celsius is %.2f Fahrenheit\n", value, convertedValue);
      break;
    case 'F':
      convertedValue = fahrenheitToCelsius(value);
      printf("%.2f Fahrenheit is %.2f Celsius\n", value, convertedValue);
      break;
    case 'M':
      convertedValue = milesToKilometers(value);
      printf("%.2f Miles is %.2f Kilometers\n", value, convertedValue);
      break;
    case 'K':
      convertedValue = kilometersToMiles(value);
      printf("%.2f Kilometers is %.2f Miles\n", value, convertedValue);
      break;
    case 'P':
      convertedValue = poundsToKilograms(value);
      printf("%.2f Pounds is %.2f Kilograms\n", value, convertedValue);
      break;
    case 'KG':
      convertedValue = kilogramsToPounds(value);
      printf("%.2f Kilograms is %.2f Pounds\n", value, convertedValue);
      break;
    case 'I':
      convertedValue = inchesToCentimeters(value);
      printf("%.2f Inches is %.2f Centimeters\n", value, convertedValue);
      break;
    case 'CM':
      convertedValue = centimetersToInches(value);
      printf("%.2f Centimeters is %.2f Inches\n", value, convertedValue);
      break;
    default:
      printf("Invalid unit entered\n");
  }

  return 0;
}