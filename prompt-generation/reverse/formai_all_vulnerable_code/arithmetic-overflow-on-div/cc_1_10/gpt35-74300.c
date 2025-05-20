//FormAI DATASET v1.0 Category: Arithmetic ; Style: creative
#include <stdio.h>

// This program demonstrates a creative example of arithmetic operations in C

int main() {
  
  printf("Let's play a game of maths!\n");
  
  // Initialize variables
  int num1, num2, num3, result;
  
  printf("Enter the first number: ");
  scanf("%d", &num1);
  
  printf("Enter the second number: ");
  scanf("%d", &num2);
  
  printf("Enter the third number: ");
  scanf("%d", &num3);
  
  // Addition operation
  result = num1 + num2 + num3;
  printf("The sum of %d, %d, and %d is %d\n", num1, num2, num3, result);
  
  // Multiplication operation
  result = num1 * num2 * num3;
  printf("The product of %d, %d, and %d is %d\n", num1, num2, num3, result);
  
  // Division operation
  if (num2 != 0 && num3 != 0) {
    result = num1 / num2 / num3;
    printf("The quotient of %d, %d, and %d is %d\n", num1, num2, num3, result);
  } else {
    printf("Cannot divide by zero. Please re-enter the numbers.\n");
  }
  
  // Subtraction operation
  result = num1 - num2 - num3;
  printf("The difference of %d, %d, and %d is %d\n", num1, num2, num3, result);
  
  // Modulo operation
  if (num2 != 0 && num3 != 0) {
    result = num1 % num2 % num3;
    printf("The remainder after dividing %d by %d and %d is %d\n", num1, num2, num3, result);
  } else {
    printf("Cannot perform modulo operation. Please re-enter the numbers.\n");
  }
  
  // Increment operation
  printf("The value of num1 before incrementing is %d\n", num1);
  num1++;
  printf("The value of num1 after  incrementing is %d\n", num1);
  
  // Decrement operation
  printf("The value of num2 before decrementing is %d\n", num2);
  num2--;
  printf("The value of num2 after decrementing is %d\n", num2);
  
  // Negation operation
  result = -num3;
  printf("The negation of %d is %d\n", num3, result);
  
  printf("Thanks for playing the game of maths!\n");
  
  return 0;
}