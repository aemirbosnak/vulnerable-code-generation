//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define error codes
#define ERR_INVALID_INPUT 100
#define ERR_DIVIDE_BY_ZERO 101
#define ERR_OUT_OF_BOUNDS 102

// Define error messages
#define ERR_INVALID_INPUT_MSG "Invalid input detected. Please enter a valid value."
#define ERR_DIVIDE_BY_ZERO_MSG "Division by zero encountered. Please check your calculations."
#define ERR_OUT_OF_BOUNDS_MSG "Out of bounds detected. Please enter a value within the allowed range."

int main() {
  // Define variables
  double x, y, z;
  int choice;

  // Initialize variables
  x = 0;
  y = 0;
  z = 0;
  choice = 0;

  // Error handling loop
  while (1) {
    // Prompt user for input
    printf("Enter a value for x: ");
    scanf("%lf", &x);

    // Check for invalid input
    if (x == 0) {
      printf(ERR_INVALID_INPUT_MSG);
      continue;
    }

    // Check for division by zero
    if (x == 0 && y == 0) {
      printf(ERR_DIVIDE_BY_ZERO_MSG);
      continue;
    }

    // Check for out of bounds
    if (x > 10 || x < -10) {
      printf(ERR_OUT_OF_BOUNDS_MSG);
      continue;
    }

    // Perform calculations
    z = x + y;

    // Print results
    printf("x + y = %lf\n", z);

    // Ask user for next input
    printf("Do you want to continue? (y/n): ");
    scanf(" %c", &choice);

    // Exit program if user chooses to stop
    if (choice == 'n' || choice == 'N') break;
  }

  return 0;
}