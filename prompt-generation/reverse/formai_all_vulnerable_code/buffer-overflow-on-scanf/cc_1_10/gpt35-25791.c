//FormAI DATASET v1.0 Category: Unit converter ; Style: expert-level
#include <stdio.h>
#include <string.h>

#define SIZE 100 // Maximum number of characters in input string

// Function declarations
double convertToCentimeters(double);
double convertToInches(double);
double convertToFeet(double);
double convertToMeters(double);

int main() {
  char input[SIZE];
  double value, result;
  int choice;

  // Print unit conversion menu
  printf("Select the unit conversion you want to perform:\n");
  printf("1. Inches to Centimeters\n");
  printf("2. Centimeters to Inches\n");
  printf("3. Feet to Meters\n");
  printf("4. Meters to Feet\n");

  // Get user input for choice
  printf("\nEnter choice (1-4): ");
  scanf("%d", &choice);

  // Get user input for value to be converted
  printf("Enter value to be converted: ");
  scanf("%lf", &value);

  // Perform appropriate conversion based on user choice
  switch(choice) {
    case 1: // Inches to Centimeters
      result = convertToCentimeters(value);
      printf("%.2lf inches = %.2lf cm\n", value, result);
      break;
    case 2: // Centimeters to Inches
      result = convertToInches(value);
      printf("%.2lf cm = %.2lf inches\n", value, result);
      break;
    case 3: // Feet to Meters
      result = convertToMeters(value);
      printf("%.2lf feet = %.2lf meters\n", value, result);
      break;
    case 4: // Meters to Feet
      result = convertToFeet(value);
      printf("%.2lf meters = %.2lf feet\n", value, result);
      break;
    default:
      printf("Invalid choice!\n");
      break;
  }

  return 0;
}

// Function for converting inches to centimeters
double convertToCentimeters(double inches) {
  return inches * 2.54;
}

// Function for converting centimeters to inches
double convertToInches(double cm) {
  return cm / 2.54;
}

// Function for converting feet to meters
double convertToMeters(double feet) {
  return feet / 3.281;
}

// Function for converting meters to feet
double convertToFeet(double meters) {
  return meters * 3.281;
}