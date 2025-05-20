//FormAI DATASET v1.0 Category: Error handling ; Style: lively
#include <stdio.h>
#include <stdlib.h>

int main() {
  int num1, num2, result;

  printf("Welcome to the Amazing Calculator!\n");
  printf("Input two numbers separated by a space: ");
  if(scanf("%d %d", &num1, &num2) != 2) {
    printf("Oops, something went wrong while reading input. Please try again.\n");
    exit(1);
  }

  printf("Choose an operation:\n");
  printf("1. Addition\n");
  printf("2. Subtraction\n");
  printf("3. Multiplication\n");
  printf("4. Division\n");

  int choice;
  if(scanf("%d", &choice) != 1) {
    printf("Oops, something went wrong while reading input. Please try again.\n");
    exit(1);
  }

  switch(choice) {
    case 1:
      result = num1 + num2;
      printf("Result: %d\n", result);
      break;
    case 2:
      result = num1 - num2;
      printf("Result: %d\n", result);
      break;
    case 3:
      result = num1 * num2;
      printf("Result: %d\n", result);
      break;
    case 4:
      if(num2 == 0) {
        printf("Oops, cannot divide by zero. Please try again.\n");
        exit(1);
      }

      result = num1 / num2;
      printf("Result: %d\n", result);
      break;
    default:
      printf("Oops, invalid choice. Please try again.\n");
      exit(1);
  }

  printf("Thank you for using the Amazing Calculator! Goodbye.\n");
  return 0;
}