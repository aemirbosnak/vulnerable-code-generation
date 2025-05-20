//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <float.h>

int main() {
  // Declare variables
  double num1, num2, result;
  int operation;

  // Get input from the user
  printf("Enter two numbers: ");
  scanf("%lf %lf", &num1, &num2);

  // Get the operation from the user
  printf("Enter the operation (1 for addition, 2 for subtraction, 3 for multiplication, 4 for division): ");
  scanf("%d", &operation);

  // Perform the operation
  switch (operation) {
    case 1:
      result = num1 + num2;
      break;
    case 2:
      result = num1 - num2;
      break;
    case 3:
      result = num1 * num2;
      break;
    case 4:
      if (num2 == 0) {
        printf("Division by zero is undefined.\n");
        return 1;
      } else {
        result = num1 / num2;
      }
      break;
    default:
      printf("Invalid operation.\n");
      return 1;
  }

  // Print the result
  printf("The result is: %lf\n", result);

  // Check if the result is an integer
  if (result == (int) result) {
    // If the result is an integer, print it as an integer
    printf("The result is an integer: %d\n", (int) result);
  }

  // Check if the result is within the range of representable float values
  if (result < FLT_MIN || result > FLT_MAX) {
    // If the result is outside the range of representable float values, print an error message
    printf("The result is outside the range of representable float values.\n");
  }

  // Check if the result is within the range of representable int values
  if (result < INT_MIN || result > INT_MAX) {
    // If the result is outside the range of representable int values, print an error message
    printf("The result is outside the range of representable int values.\n");
  }

  return 0;
}