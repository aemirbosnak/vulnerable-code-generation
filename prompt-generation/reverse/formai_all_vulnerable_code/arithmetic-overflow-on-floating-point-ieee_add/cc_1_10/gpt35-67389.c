//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: enthusiastic
#include <stdio.h>

// Function to perform addition
float add(float a, float b) {
  return a + b;
}

// Function to perform subtraction
float subtract(float a, float b) {
  return a - b;
}

// Function to perform multiplication
float multiply(float a, float b) {
  return a * b;
}

// Function to perform division
float divide(float a, float b) {
  return a / b;
}

int main() {
  float num1, num2, result;
  int choice;

  // Displaying the options to the user
  printf("Welcome to the Scientific Calculator!\n\n");
  printf("1. Addition\n");
  printf("2. Subtraction\n");
  printf("3. Multiplication\n");
  printf("4. Division\n\n");
  
  // Asking for user's choice
  printf("Enter your choice (1-4): ");
  scanf("%d", &choice);

  // Taking input for two numbers
  printf("\nEnter first number: ");
  scanf("%f", &num1);
  printf("Enter second number: ");
  scanf("%f", &num2);

  // Performing the calculation based on user's choice
  switch (choice) {
    case 1:
      result = add(num1, num2);
      printf("\n%.2f + %.2f = %.2f\n", num1, num2, result);
      break;
    case 2:
      result = subtract(num1, num2);
      printf("\n%.2f - %.2f = %.2f\n", num1, num2, result);
      break;
    case 3:
      result = multiply(num1, num2);
      printf("\n%.2f * %.2f = %.2f\n", num1, num2, result);
      break;
    case 4:
      result = divide(num1, num2);
      printf("\n%.2f / %.2f = %.2f\n", num1, num2, result);
      break;
    default:
      printf("\nInvalid choice!\n");
  }

  printf("\nThank you for using the Scientific Calculator!");

  return 0;
}