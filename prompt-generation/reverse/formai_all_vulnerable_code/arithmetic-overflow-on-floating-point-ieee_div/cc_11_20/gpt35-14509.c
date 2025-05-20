//FormAI DATASET v1.0 Category: Calculator ; Style: curious
#include <stdio.h>

// This is a unique calculator program!
// It allows users to not only perform standard arithmetic operations, but also
// discover fun facts about their numbers!

int main() {
  printf("Welcome to the Unique Calculator Program!\n");
  printf("Enter two numbers to perform arithmetic operations on:\n");

  double num1, num2;
  scanf("%lf %lf", &num1, &num2);

  printf("\nGreat! Now, select the desired arithmetic operation\n");
  printf("1. Addition\n");
  printf("2. Subtraction\n");
  printf("3. Multiplication\n");
  printf("4. Division\n");
  printf("5. Fun Fact (about num1 or num2)\n");

  int operation;
  scanf("%d", &operation);

  if (operation == 1) {
    double result = num1 + num2;
    printf("\n%f + %f = %f\n", num1, num2, result);
  } else if (operation == 2) {
    double result = num1 - num2;
    printf("\n%f - %f = %f\n", num1, num2, result);
  } else if (operation == 3) {
    double result = num1 * num2;
    printf("\n%f * %f = %f\n", num1, num2, result);
  } else if (operation == 4) {
    if (num2 == 0) {
      printf("\nError: Cannot divide by zero\n");
    } else {
      double result = num1 / num2;
      printf("\n%f / %f = %f\n", num1, num2, result);
    }
  } else if (operation == 5) {
    printf("\nWould you like a fun fact about num1 or num2?\n");
    printf("1. About num1\n");
    printf("2. About num2\n");
    int fact_choice;
    scanf("%d", &fact_choice);

    if (fact_choice == 1) {
      // Let's find out if num1 is prime!
      int is_prime = 1;
      for (int i = 2; i < num1; i++) {
        if (fmod(num1, i) == 0) {
          // num1 is not prime
          is_prime = 0;
          break;
        }
      }
      if (is_prime) {
        printf("\nDid you know? %f is a prime number!\n", num1);
      } else {
        printf("\nDid you know? %f is not a prime number.\n", num1);
      }
    } else if (fact_choice == 2) {
      // Let's find out if num2 is even or odd!
      if (fmod(num2, 2) == 0) {
        printf("\nDid you know? %f is an even number!\n", num2);
      } else {
        printf("\nDid you know? %f is an odd number.\n", num2);
      }
    } else {
      printf("\nError: Invalid input\n");
    }
  } else {
    printf("\nError: Invalid input\n");
  }

  printf("\nThank you for using the Unique Calculator Program!\n");
  return 0;
}