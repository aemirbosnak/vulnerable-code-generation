//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

// Declare the unit conversion functions
double feet_to_inches(double feet);
double inches_to_feet(double inches);
double meters_to_yards(double meters);
double yards_to_meters(double yards);
double gallons_to_liters(double gallons);
double liters_to_gallons(double liters);

// Declare the main function
int main() {
  // Create a variable to store the user's input
  char input[100];
  double current_value;

  // Get the user's input
  printf("Enter a value and the unit it's in (e.g. 10 feet): ");
  gets(input);

  // Parse the user's input
  sscanf(input, "%lf %s", &current_value, input);

  // Convert the user's input to the desired unit
  if (strcmp(input, "feet") == 0) {
    printf("%.2f inches\n", feet_to_inches(current_value));
  } else if (strcmp(input, "inches") == 0) {
    printf("%.2f feet\n", inches_to_feet(current_value));
  } else if (strcmp(input, "meters") == 0) {
    printf("%.2f yards\n", meters_to_yards(current_value));
  } else if (strcmp(input, "yards") == 0) {
    printf("%.2f meters\n", yards_to_meters(current_value));
  } else if (strcmp(input, "gallons") == 0) {
    printf("%.2f liters\n", gallons_to_liters(current_value));
  } else if (strcmp(input, "liters") == 0) {
    printf("%.2f gallons\n", liters_to_gallons(current_value));
  } else {
    printf("Sorry, I don't recognize that unit.\n");
  }
  return 0;
}

// Define the unit conversion functions
double feet_to_inches(double feet) {
  return feet * 12;
}

double inches_to_feet(double inches) {
  return inches / 12;
}

double meters_to_yards(double meters) {
  return meters * 1.09361;
}

double yards_to_meters(double yards) {
  return yards / 1.09361;
}

double gallons_to_liters(double gallons) {
  return gallons * 3.78541;
}

double liters_to_gallons(double liters) {
  return liters / 3.78541;
}