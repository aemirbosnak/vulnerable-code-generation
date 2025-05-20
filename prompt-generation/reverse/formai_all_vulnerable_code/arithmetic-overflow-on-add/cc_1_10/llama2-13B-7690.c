//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define error codes and messages
#define ERR_INVALID_INPUT 1001
#define ERR_OUT_OF_BOUNDS 1002
#define ERR_MATH_ERROR 1003

// Define error handling functions
void handle_error(int error_code) {
  switch (error_code) {
    case ERR_INVALID_INPUT:
      fprintf(stderr, "Invalid input detected! Please check your inputs and try again.\n");
      break;
    case ERR_OUT_OF_BOUNDS:
      fprintf(stderr, "Input values are out of bounds. Please check your inputs and try again.\n");
      break;
    case ERR_MATH_ERROR:
      fprintf(stderr, "Mathematical error detected! Please check your calculations and try again.\n");
      break;
    default:
      fprintf(stderr, "Unknown error detected. Please try again or consult the documentation.\n");
  }
}

int main() {
  int num1, num2, sum;
  double num3, sum_double;
  char str[50];

  // Get user input
  printf("Enter two integers: ");
  scanf("%d%d", &num1, &num2);

  // Check for invalid input
  if (num1 < 0 || num2 < 0) {
    handle_error(ERR_INVALID_INPUT);
    return 1;
  }

  // Calculate the sum
  sum = num1 + num2;

  // Check for out-of-bounds input
  if (sum > 100 || sum < 0) {
    handle_error(ERR_OUT_OF_BOUNDS);
    return 1;
  }

  // Calculate the sum using doubles
  num3 = (double)num1 + (double)num2;
  sum_double = num3 + num3;

  // Check for mathematical error
  if (sum_double > 100.0 || sum_double < 0.0) {
    handle_error(ERR_MATH_ERROR);
    return 1;
  }

  // Print the results
  printf("The sum of %d and %d is %d\n", num1, num2, sum);
  printf("The sum of %f and %f is %f\n", num3, num3, sum_double);

  // Get user input for a string
  printf("Enter a string: ");
  fgets(str, 50, stdin);

  // Check for invalid input
  if (strlen(str) == 0) {
    handle_error(ERR_INVALID_INPUT);
    return 1;
  }

  // Print the string
  printf("Your input string is: %s\n", str);

  return 0;
}