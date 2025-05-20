//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main() {
  // Initialize variables
  int num1, num2, choice;
  float result;
  bool valid = false;

  // Declare functions
  float add(int, int);
  float subtract(int, int);
  float multiply(int, int);
  float divide(int, int);
  bool is_valid_choice(int);

  // Get user input
  printf("\nWelcome to the Decentralized Math Exercise Program!\n\n");
  printf("Please choose an operation:\n");
  printf("1. Addition\n");
  printf("2. Subtraction\n");
  printf("3. Multiplication\n");
  printf("4. Division\n");
  printf("Choice: ");
  scanf("%d", &choice);

  // Validate user input
  valid = is_valid_choice(choice);

  // Perform calculations
  if (valid) {
    printf("Enter two numbers:\n");
    scanf("%d %d", &num1, &num2);

    switch (choice) {
      case 1:
        result = add(num1, num2);
        printf("%d + %d = %.2f\n", num1, num2, result);
        break;
      case 2:
        result = subtract(num1, num2);
        printf("%d - %d = %.2f\n", num1, num2, result);
        break;
      case 3:
        result = multiply(num1, num2);
        printf("%d * %d = %.2f\n", num1, num2, result);
        break;
      case 4:
        if (num2 == 0) {
          printf("Division by zero is undefined.\n");
        } else {
          result = divide(num1, num2);
          printf("%d / %d = %.2f\n", num1, num2, result);
        }
        break;
    }
  } else {
    printf("Invalid choice. Please enter a number between 1 and 4.\n");
  }

  return 0;
}

float add(int num1, int num2) {
  return num1 + num2;
}

float subtract(int num1, int num2) {
  return num1 - num2;
}

float multiply(int num1, int num2) {
  return num1 * num2;
}

float divide(int num1, int num2) {
  return (float)num1 / num2;
}

bool is_valid_choice(int choice) {
  return choice >= 1 && choice <= 4;
}