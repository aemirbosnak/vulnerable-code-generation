//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Declare the function prototypes
int main(void);
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);

// Define the main function
int main(void) {
  // Declare the variables
  int a, b, choice;

  // Get the input from the user
  printf("Enter two numbers: ");
  scanf("%d %d", &a, &b);

  // Get the choice from the user
  printf("Enter your choice: ");
  printf("1. Add\n");
  printf("2. Subtract\n");
  printf("3. Multiply\n");
  printf("4. Divide\n");
  scanf("%d", &choice);

  // Perform the operation based on the choice
  switch (choice) {
    case 1:
      printf("The sum of %d and %d is %d\n", a, b, add(a, b));
      break;
    case 2:
      printf("The difference of %d and %d is %d\n", a, b, subtract(a, b));
      break;
    case 3:
      printf("The product of %d and %d is %d\n", a, b, multiply(a, b));
      break;
    case 4:
      if (b == 0) {
        printf("Division by zero is undefined\n");
      } else {
        printf("The quotient of %d and %d is %d\n", a, b, divide(a, b));
      }
      break;
    default:
      printf("Invalid choice\n");
  }

  return 0;
}

// Define the add function
int add(int a, int b) {
  return a + b;
}

// Define the subtract function
int subtract(int a, int b) {
  return a - b;
}

// Define the multiply function
int multiply(int a, int b) {
  return a * b;
}

// Define the divide function
int divide(int a, int b) {
  return a / b;
}