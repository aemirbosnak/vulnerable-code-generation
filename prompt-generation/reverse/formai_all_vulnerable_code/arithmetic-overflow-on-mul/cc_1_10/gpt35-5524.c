//FormAI DATASET v1.0 Category: Arithmetic ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Function to add two numbers
int add(int a, int b) {
  return a + b;
}

// Function to subtract two numbers
int subtract(int a, int b) {
  return a - b;
}

// Function to multiply two numbers
int multiply(int a, int b) {
  return a * b;
}

// Function to divide two numbers
float divide(float a, float b) {
  if (b == 0) {
    printf("Error: cannot divide by zero\n");
    return -1;
  }
  return a / b;
}

int main() {
  int a, b;
  int choice;
  printf("Enter two numbers: ");
  scanf("%d %d", &a, &b);

  printf("Select an operation:\n");
  printf("1. Add\n");
  printf("2. Subtract\n");
  printf("3. Multiply\n");
  printf("4. Divide\n");
  printf("5. Exit\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      printf("Result: %d\n", add(a, b));
      break;
    case 2:
      printf("Result: %d\n", subtract(a, b));
      break;
    case 3:
      printf("Result: %d\n", multiply(a, b));
      break;
    case 4:
      printf("Result: %f\n", divide((float) a, (float) b));
      break;
    case 5:
      printf("Exiting...\n");
      break;
    default:
      printf("Invalid choice\n");
  }
  return 0;
}