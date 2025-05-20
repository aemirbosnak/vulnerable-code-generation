//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: grateful
#include <stdio.h>

// Define the unit conversion constants
#define LENGTH_INCHES 1
#define LENGTH_CENTIMETERS 10
#define LENGTH_METERS 100
#define WEIGHT_GRAMS 1
#define WEIGHT_POUNDS 2.2
#define TEMPERATURE_FAHRENHEIT 1
#define TEMPERATURE_CELSIUS (5 / 9)

// Define the function prototypes
void convertLength(int inches, int cm, int m);
void convertWeight(int grams, int pounds);
void convertTemperature(int fahrenheit, int celsius);

int main() {
  int inches, cm, m;
  int grams, pounds;
  int fahrenheit, celsius;

  // Ask the user for the input values
  printf("Enter a length in inches: ");
  scanf("%d", &inches);
  printf("Enter a length in centimeters: ");
  scanf("%d", &cm);
  printf("Enter a length in meters: ");
  scanf("%d", &m);

  // Call the conversion functions
  convertLength(inches, cm, m);

  // Ask the user for the weight input values
  printf("Enter a weight in grams: ");
  scanf("%d", &grams);
  printf("Enter a weight in pounds: ");
  scanf("%d", &pounds);

  // Call the conversion functions
  convertWeight(grams, pounds);

  // Ask the user for the temperature input values
  printf("Enter a temperature in Fahrenheit: ");
  scanf("%d", &fahrenheit);
  printf("Enter a temperature in Celsius: ");
  scanf("%d", &celsius);

  // Call the conversion functions
  convertTemperature(fahrenheit, celsius);

  // Print the output values
  printf("Length in meters: %d\n", m);
  printf("Length in centimeters: %d\n", cm);
  printf("Length in inches: %d\n", inches);
  printf("Weight in pounds: %d\n", pounds);
  printf("Weight in grams: %d\n", grams);
  printf("Temperature in Celsius: %d\n", celsius);
  printf("Temperature in Fahrenheit: %d\n", fahrenheit);

  return 0;
}

// Define the conversion functions
void convertLength(int inches, int cm, int m) {
  if (inches == 0) {
    inches = 1; // Set the default value to 1 inch
  }
  if (cm == 0) {
    cm = 10; // Set the default value to 10 cm
  }
  if (m == 0) {
    m = 100; // Set the default value to 1 m
  }

  // Perform the conversions
  cm = inches * LENGTH_CENTIMETERS / LENGTH_INCHES;
  m = cm * LENGTH_METERS / LENGTH_CENTIMETERS;

  // Print the output values
  printf("Length in centimeters: %d\n", cm);
  printf("Length in meters: %d\n", m);
}

void convertWeight(int grams, int pounds) {
  if (grams == 0) {
    grams = 1; // Set the default value to 1 gram
  }
  if (pounds == 0) {
    pounds = 2.2; // Set the default value to 2.2 pounds
  }

  // Perform the conversions
  pounds = grams * WEIGHT_POUNDS / WEIGHT_GRAMS;

  // Print the output values
  printf("Weight in pounds: %d\n", pounds);
}

void convertTemperature(int fahrenheit, int celsius) {
  if (fahrenheit == 0) {
    fahrenheit = 1; // Set the default value to 1 Fahrenheit
  }
  if (celsius == 0) {
    celsius = 0; // Set the default value to 0 Celsius
  }

  // Perform the conversions
  celsius = (fahrenheit - 32) * TEMPERATURE_CELSIUS / TEMPERATURE_FAHRENHEIT;

  // Print the output values
  printf("Temperature in Celsius: %d\n", celsius);
}