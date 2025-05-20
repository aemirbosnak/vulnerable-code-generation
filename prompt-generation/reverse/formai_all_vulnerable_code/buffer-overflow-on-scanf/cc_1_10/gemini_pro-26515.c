//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// Unit conversion constants
#define METERS_TO_FEET 3.28084
#define FEET_TO_METERS 0.3048
#define KILOS_TO_POUNDS 2.20462
#define POUNDS_TO_KILOS 0.453592
#define CELSIUS_TO_FAHRENHEIT 1.8
#define FAHRENHEIT_TO_CELSIUS 0.555556

// Function prototypes
double convert_meters_to_feet(double meters);
double convert_feet_to_meters(double feet);
double convert_kilos_to_pounds(double kilos);
double convert_pounds_to_kilos(double pounds);
double convert_celsius_to_fahrenheit(double celsius);
double convert_fahrenheit_to_celsius(double fahrenheit);

int main() {
  // Welcome message
  printf("Welcome to the ultimate unit converter!\n");

  // Get the user's input
  char unit_type[100];
  double value;
  printf("Enter the type of unit you want to convert (ex: meters, feet, kilos, pounds, celsius, fahrenheit): ");
  scanf("%s", unit_type);
  printf("Enter the value to be converted: ");
  scanf("%lf", &value);

  // Convert the value based on the unit type
  double converted_value;
  if (strcmp(unit_type, "meters") == 0) {
    converted_value = convert_meters_to_feet(value);
    printf("%.2f meters is equal to %.2f feet.\n", value, converted_value);
  } else if (strcmp(unit_type, "feet") == 0) {
    converted_value = convert_feet_to_meters(value);
    printf("%.2f feet is equal to %.2f meters.\n", value, converted_value);
  } else if (strcmp(unit_type, "kilos") == 0) {
    converted_value = convert_kilos_to_pounds(value);
    printf("%.2f kilos is equal to %.2f pounds.\n", value, converted_value);
  } else if (strcmp(unit_type, "pounds") == 0) {
    converted_value = convert_pounds_to_kilos(value);
    printf("%.2f pounds is equal to %.2f kilos.\n", value, converted_value);
  } else if (strcmp(unit_type, "celsius") == 0) {
    converted_value = convert_celsius_to_fahrenheit(value);
    printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", value, converted_value);
  } else if (strcmp(unit_type, "fahrenheit") == 0) {
    converted_value = convert_fahrenheit_to_celsius(value);
    printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", value, converted_value);
  } else {
    printf("Invalid unit type entered.\n");
  }

  // Thank you message
  printf("Thank you for using the ultimate unit converter!\n");

  return 0;
}

// Function to convert meters to feet
double convert_meters_to_feet(double meters) {
  return meters * METERS_TO_FEET;
}

// Function to convert feet to meters
double convert_feet_to_meters(double feet) {
  return feet * FEET_TO_METERS;
}

// Function to convert kilos to pounds
double convert_kilos_to_pounds(double kilos) {
  return kilos * KILOS_TO_POUNDS;
}

// Function to convert pounds to kilos
double convert_pounds_to_kilos(double pounds) {
  return pounds * POUNDS_TO_KILOS;
}

// Function to convert Celsius to Fahrenheit
double convert_celsius_to_fahrenheit(double celsius) {
  return celsius * CELSIUS_TO_FAHRENHEIT + 32;
}

// Function to convert Fahrenheit to Celsius
double convert_fahrenheit_to_celsius(double fahrenheit) {
  return (fahrenheit - 32) * FAHRENHEIT_TO_CELSIUS;
}