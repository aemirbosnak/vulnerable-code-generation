//FormAI DATASET v1.0 Category: Arithmetic ; Style: irregular
#include <stdio.h>

int main() {
  int num1, num2, result;
  
  printf("Enter a number: ");
  scanf("%d", &num1);
  printf("Enter another number: ");
  scanf("%d", &num2);
  
  // Add the two numbers
  result = num1 + num2;
  printf("Addition Result: %d\n", result);
  
  // Subtract the two numbers
  result = num1 - num2;
  printf("Subtraction Result: %d\n", result);
  
  // Multiply the two numbers
  result = num1 * num2;
  printf("Multiplication Result: %d\n", result);
  
  // Divide the two numbers
  if(num2 == 0) {
    printf("Cannot divide by zero\n");
  } else {
    result = num1 / num2;
    printf("Division Result: %d\n", result);
  }
  
  // Modulus of the two numbers
  result = num1 % num2;
  printf("Modulus Result: %d\n", result);
  
  // Increment the first number
  num1++;
  printf("Increment Result: %d\n", num1);
  
  // Decrement the first number
  num1--;
  printf("Decrement Result: %d\n", num1);
  
  // Bitwise AND of the two numbers
  result = num1 & num2;
  printf("Bitwise AND Result: %d\n", result);
  
  // Bitwise OR of the two numbers
  result = num1 | num2;
  printf("Bitwise OR Result: %d\n", result);
  
  // Bitwise XOR of the two numbers
  result = num1 ^ num2;
  printf("Bitwise XOR Result: %d\n", result);
  
  // Left shift the first number by 2 bits
  result = num1 << 2;
  printf("Left Shift Result: %d\n", result);
  
  // Right shift the first number by 2 bits
  result = num1 >> 2;
  printf("Right Shift Result: %d\n", result);
  
  return 0;
}