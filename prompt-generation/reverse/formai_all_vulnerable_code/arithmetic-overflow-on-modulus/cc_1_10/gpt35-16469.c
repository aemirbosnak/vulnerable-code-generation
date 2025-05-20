//FormAI DATASET v1.0 Category: Error handling ; Style: irregular
// This program demonstrates exceptional error handling through the use of unconventional control structures
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function declarations
void fatal_error(char* error_msg);
void normal_error(char* error_msg);

// Main function
int main() {
  printf("Welcome to this irregular error handling program!\n");

  // Initialize variables
  int num1, num2;
  bool continue_flag = true;

  while (continue_flag) {
    // Prompt user for input
    printf("Please enter the first number: ");
    scanf("%d", &num1);
    printf("Please enter the second number: ");
    scanf("%d", &num2);

    // Perform arithmetic operations
    int sum = num1 + num2;
    int difference = num1 - num2;
    int product = num1 * num2;
    int quotient = num1 / num2;
    int remainder = num1 % num2;

    // Check for errors
    if (num2 == 0) {
      fatal_error("Division by 0 is not allowed.");
    }

    // Print results
    printf("The sum is: %d\n", sum);
    printf("The difference is: %d\n", difference);
    printf("The product is: %d\n", product);
    printf("The quotient is: %d\n", quotient);
    printf("The remainder is: %d\n\n", remainder);

    // Ask user if they want to continue
    char resp;
    printf("Do you want to continue? (y/n): ");
    scanf(" %c", &resp);

    // Handle response
    switch (resp) {
      case 'y':
      case 'Y':
        continue_flag = true;
        printf("\n");
        break;
      case 'n':
      case 'N':
        continue_flag = false;
        printf("Exiting program. Goodbye!\n");
        break;
      default:
        normal_error("Invalid response. Try again.");
        continue_flag = true;
        break;
    }
  }

  return 0;
}

// Handle fatal errors (terminate program)
void fatal_error(char* error_msg) {
  printf("*** FATAL ERROR: %s ***\n", error_msg);
  exit(1);
}

// Handle normal errors (continue program)
void normal_error(char* error_msg) {
  printf("*** ERROR: %s ***\n\n", error_msg);
}