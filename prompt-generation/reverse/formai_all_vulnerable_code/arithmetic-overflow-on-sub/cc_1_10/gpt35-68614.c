//FormAI DATASET v1.0 Category: Calculator ; Style: peaceful
#include <stdio.h>

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
float divide(int a, int b) {
  if(b == 0) {
    printf("Cannot divide by zero");
    return 0;
  }
  else {
    return (float)a / b;
  }
}

int main() {
  int num1, num2, choice;
  float result;
  printf("Welcome to the Peaceful Calculator\n\n");

  while(1) {
    printf("Please choose an option:\n1. Add two numbers\n2. Subtract two numbers\n3. Multiply two numbers\n4. Divide two numbers\n5. Exit\n");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("\nEnter two numbers: ");
        scanf("%d %d", &num1, &num2);
        result = add(num1, num2);
        printf("\nResult: %d\n\n", (int)result);
        break;
      
      case 2:
        printf("\nEnter two numbers: ");
        scanf("%d %d", &num1, &num2);
        result = subtract(num1, num2);
        printf("\nResult: %d\n\n", (int)result);
        break;
      
      case 3:
        printf("\nEnter two numbers: ");
        scanf("%d %d", &num1, &num2);
        result = multiply(num1, num2);
        printf("\nResult: %d\n\n", (int)result);
        break;
      
      case 4:
        printf("\nEnter two numbers: ");
        scanf("%d %d", &num1, &num2);
        result = divide(num1, num2);
        if(result != 0) {
          printf("\nResult: %.2f\n\n", result);
        }
        break;

      case 5:
        printf("\nThank you for using the Peaceful Calculator.\n");
        return 0;

      default:
        printf("\nInvalid choice. Please select again.\n\n");
        break;
    }
  }
  return 0;
}