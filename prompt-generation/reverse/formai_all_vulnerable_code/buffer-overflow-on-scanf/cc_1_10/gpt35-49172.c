//FormAI DATASET v1.0 Category: Educational ; Style: retro
#include <stdio.h>
#include <stdlib.h>

// function to find the sum of two numbers
int add(int a, int b) {
  return a + b;
}

// function to find the difference between two numbers
int subtract(int a, int b) {
  return a - b;
}

// function to find the product of two numbers
int multiply(int a, int b) {
  return a * b;
}

// function to find the quotient of two numbers
float divide(int a, int b) {
  if (b == 0) {
    printf("Error: Cannot divide by zero.\n");
    exit(0);
  }

  return (float) a / b;
}

int main() {
  int a, b, choice;
  float result;

  printf("=============================================\n");
  printf("|        RETRO CALCULATOR PROGRAM           |\n");
  printf("=============================================\n");

  do {
    printf("\n");
    printf("MENU:\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter two numbers: ");
        scanf("%d %d", &a, &b);
        result = add(a, b);
        printf("Result: %d\n", (int) result);
        break;

      case 2:
        printf("Enter two numbers: ");
        scanf("%d %d", &a, &b);
        result = subtract(a, b);
        printf("Result: %d\n", (int) result);
        break;

      case 3:
        printf("Enter two numbers: ");
        scanf("%d %d", &a, &b);
        result = multiply(a, b);
        printf("Result: %d\n", (int) result);
        break;

      case 4:
        printf("Enter two numbers: ");
        scanf("%d %d", &a, &b);
        result = divide(a, b);
        printf("Result: %.2f\n", result);
        break;

      case 5:
        printf("Exiting the program...\n");
        break;

      default:
        printf("Invalid choice. Please enter a number between 1 and 5.\n");
    }
  } while (choice != 5);

  return 0;
}