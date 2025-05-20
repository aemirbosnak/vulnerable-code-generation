//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: immersive
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
  return kilometers / 1.60934;
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
  return centimeters / 2.54;
}

// Function to convert gallons to liters
float gallons_to_liters(float gallons) {
  return gallons * 3.78541;
}

// Function to convert liters to gallons
float liters_to_gallons(float liters) {
  return liters / 3.78541;
}

int main() {
  // Welcome message
  printf("Welcome to the Unit Converter!\n");
  printf("This program can convert between the following units:\n");
  printf("- Celsius and Fahrenheit\n");
  printf("- Miles and Kilometers\n");
  printf("- Pounds and Kilograms\n");
  printf("- Inches and Centimeters\n");
  printf("- Gallons and Liters\n");

  // Get the user's input
  char choice;
  float value;
  printf("\nEnter your choice (C/F/M/K/P/L/I/G): ");
  scanf(" %c", &choice);
  printf("Enter the value: ");
  scanf(" %f", &value);

  // Convert the value
  float result;
  switch (choice) {
    case 'C':
      result = celsius_to_fahrenheit(value);
      printf("%.2f Celsius is %.2f Fahrenheit\n", value, result);
      break;
    case 'F':
      result = fahrenheit_to_celsius(value);
      printf("%.2f Fahrenheit is %.2f Celsius\n", value, result);
      break;
    case 'M':
      result = miles_to_kilometers(value);
      printf("%.2f miles is %.2f kilometers\n", value, result);
      break;
    case 'K':
      result = kilometers_to_miles(value);
      printf("%.2f kilometers is %.2f miles\n", value, result);
      break;
    case 'P':
      result = pounds_to_kilograms(value);
      printf("%.2f pounds is %.2f kilograms\n", value, result);
      break;
    case 'L':
      result = kilograms_to_pounds(value);
      printf("%.2f kilograms is %.2f pounds\n", value, result);
      break;
    case 'I':
      result = inches_to_centimeters(value);
      printf("%.2f inches is %.2f centimeters\n", value, result);
      break;
    case 'G':
      result = centimeters_to_inches(value);
      printf("%.2f centimeters is %.2f inches\n", value, result);
      break;
    default:
      printf("Invalid choice\n");
  }

  return 0;
}