//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
  return (celsius * 9 / 5) + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
  return (fahrenheit - 32) * 5 / 9;
}

// Function to convert miles to kilometers
float miles_to_kilometers(float miles) {
  return miles * 1.60934;
}

// Function to convert kilometers to miles
float kilometers_to_miles(float kilometers) {
  return kilometers * 0.621371;
}

// Function to convert pounds to kilograms
float pounds_to_kilograms(float pounds) {
  return pounds * 0.453592;
}

// Function to convert kilograms to pounds
float kilograms_to_pounds(float kilograms) {
  return kilograms * 2.20462;
}

// Function to convert inches to centimeters
float inches_to_centimeters(float inches) {
  return inches * 2.54;
}

// Function to convert centimeters to inches
float centimeters_to_inches(float centimeters) {
  return centimeters * 0.393701;
}

// Function to convert feet to meters
float feet_to_meters(float feet) {
  return feet * 0.3048;
}

// Function to convert meters to feet
float meters_to_feet(float meters) {
  return meters * 3.28084;
}

// Function to convert gallons to liters
float gallons_to_liters(float gallons) {
  return gallons * 3.78541;
}

// Function to convert liters to gallons
float liters_to_gallons(float liters) {
  return liters * 0.264172;
}

// Main function
int main() {
  // Get the user's input
  printf("Welcome to the Ultimate Unit Converter!\n");
  printf("What do you want to convert?\n");
  printf("1. Celsius to Fahrenheit\n");
  printf("2. Fahrenheit to Celsius\n");
  printf("3. Miles to Kilometers\n");
  printf("4. Kilometers to Miles\n");
  printf("5. Pounds to Kilograms\n");
  printf("6. Kilograms to Pounds\n");
  printf("7. Inches to Centimeters\n");
  printf("8. Centimeters to Inches\n");
  printf("9. Feet to Meters\n");
  printf("10. Meters to Feet\n");
  printf("11. Gallons to Liters\n");
  printf("12. Liters to Gallons\n");
  int choice;
  scanf("%d", &choice);

  // Convert the units
  float value;
  printf("Enter the value you want to convert: ");
  scanf("%f", &value);
  float result;
  switch (choice) {
    case 1:
      result = celsius_to_fahrenheit(value);
      printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", value, result);
      break;
    case 2:
      result = fahrenheit_to_celsius(value);
      printf("%.2f Fahrenheit is equal to %.2f Celsius.\n", value, result);
      break;
    case 3:
      result = miles_to_kilometers(value);
      printf("%.2f miles is equal to %.2f kilometers.\n", value, result);
      break;
    case 4:
      result = kilometers_to_miles(value);
      printf("%.2f kilometers is equal to %.2f miles.\n", value, result);
      break;
    case 5:
      result = pounds_to_kilograms(value);
      printf("%.2f pounds is equal to %.2f kilograms.\n", value, result);
      break;
    case 6:
      result = kilograms_to_pounds(value);
      printf("%.2f kilograms is equal to %.2f pounds.\n", value, result);
      break;
    case 7:
      result = inches_to_centimeters(value);
      printf("%.2f inches is equal to %.2f centimeters.\n", value, result);
      break;
    case 8:
      result = centimeters_to_inches(value);
      printf("%.2f centimeters is equal to %.2f inches.\n", value, result);
      break;
    case 9:
      result = feet_to_meters(value);
      printf("%.2f feet is equal to %.2f meters.\n", value, result);
      break;
    case 10:
      result = meters_to_feet(value);
      printf("%.2f meters is equal to %.2f feet.\n", value, result);
      break;
    case 11:
      result = gallons_to_liters(value);
      printf("%.2f gallons is equal to %.2f liters.\n", value, result);
      break;
    case 12:
      result = liters_to_gallons(value);
      printf("%.2f liters is equal to %.2f gallons.\n", value, result);
      break;
    default:
      printf("Invalid choice.\n");
  }

  return 0;
}