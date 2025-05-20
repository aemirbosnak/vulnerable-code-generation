//Code Llama-13B DATASET v1.0 Category: Unit converter ; Style: thoughtful
// Unit Converter Example Program
#include <stdio.h>
#include <stdlib.h>

// Function to convert from inches to feet
float inches_to_feet(float inches) {
  return inches / 12.0;
}

// Function to convert from feet to inches
float feet_to_inches(float feet) {
  return feet * 12.0;
}

// Function to convert from pounds to kilograms
float pounds_to_kilograms(float pounds) {
  return pounds * 0.453592;
}

// Function to convert from kilograms to pounds
float kilograms_to_pounds(float kilograms) {
  return kilograms / 0.453592;
}

// Main function to handle user input and output
int main() {
  // Declare variables
  float input, output;
  char unit;

  // Ask user for input
  printf("Enter a value: ");
  scanf("%f", &input);

  // Ask user for unit
  printf("Enter a unit (i for inches, f for feet, p for pounds, k for kilograms): ");
  scanf(" %c", &unit);

  // Convert input based on unit
  if (unit == 'i') {
    output = inches_to_feet(input);
  } else if (unit == 'f') {
    output = feet_to_inches(input);
  } else if (unit == 'p') {
    output = pounds_to_kilograms(input);
  } else if (unit == 'k') {
    output = kilograms_to_pounds(input);
  } else {
    printf("Invalid unit\n");
    return 1;
  }

  // Print output
  printf("%f %c is equal to %f\n", input, unit, output);

  return 0;
}