//Gemma-7B DATASET v1.0 Category: Error handling ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ERROR_MESSAGE "An error occurred. Please try again."

void scientific_error(int error_code) {
  switch (error_code) {
    case 1:
      fprintf(stderr, "Error: Invalid input. Please provide a valid number.\n");
      break;
    case 2:
      fprintf(stderr, "Error: Divide by zero is not allowed. Please try a different number.\n");
      break;
    case 3:
      fprintf(stderr, "Error: Function not implemented yet. Please try again later.\n");
      break;
    default:
      fprintf(stderr, ERROR_MESSAGE);
      break;
  }
}

int main() {
  int choice, num1, num2;
  float result;

  // Get user input
  printf("Enter your choice: ");
  scanf("%d", &choice);

  // Calculate the result based on user input
  switch (choice) {
    case 1:
      printf("Enter two numbers: ");
      scanf("%d %d", &num1, &num2);
      result = (float)num1 + (float)num2;
      printf("The result is: %f\n", result);
      break;
    case 2:
      printf("Enter two numbers: ");
      scanf("%d %d", &num1, &num2);
      result = (float)num1 - (float)num2;
      printf("The result is: %f\n", result);
      break;
    case 3:
      printf("Enter two numbers: ");
      scanf("%d %d", &num1, &num2);
      result = (float)num1 * (float)num2;
      printf("The result is: %f\n", result);
      break;
    case 4:
      printf("Enter two numbers: ");
      scanf("%d %d", &num1, &num2);
      if (num2 == 0) {
        scientific_error(2);
      } else {
        result = (float)num1 / (float)num2;
        printf("The result is: %f\n", result);
      }
      break;
    default:
      scientific_error(3);
  }

  return 0;
}