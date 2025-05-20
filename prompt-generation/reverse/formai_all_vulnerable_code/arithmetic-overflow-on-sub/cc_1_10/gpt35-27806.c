//FormAI DATASET v1.0 Category: Arithmetic ; Style: accurate
#include <stdio.h>

int main() {
  int num1, num2, sum, diff, product;
  float quotient;
  
  printf("Enter first number: ");
  scanf("%d", &num1);
  
  printf("Enter second number: ");
  scanf("%d", &num2);
  
  // perform arithmetic operations
  sum = num1 + num2;
  diff = num1 - num2;
  product = num1 * num2;
  if (num2 != 0) {
    quotient = (float) num1 / num2;
  }

  printf("Sum of %d and %d is %d\n", num1, num2, sum);
  printf("Difference between %d and %d is %d\n", num1, num2, diff);
  printf("Product of %d and %d is %d\n", num1, num2, product);
  if (num2 != 0) {
    printf("Quotient of %d and %d is %.2f\n", num1, num2, quotient);
  } else {
    printf("Cannot divide by zero\n");
  }
  
  // bitwise operations
  int bitwise_and = num1 & num2;
  int bitwise_or = num1 | num2;
  int bitwise_xor = num1 ^ num2;
  int bitwise_left_shift = num1 << 1;
  int bitwise_right_shift = num1 >> 1;

  printf("Bitwise AND of %d and %d is %d\n", num1, num2, bitwise_and);
  printf("Bitwise OR of %d and %d is %d\n", num1, num2, bitwise_or);
  printf("Bitwise XOR of %d and %d is %d\n", num1, num2, bitwise_xor);
  printf("Left shift of %d is %d\n", num1, bitwise_left_shift);
  printf("Right shift of %d is %d\n", num1, bitwise_right_shift);
  
  // compound assignment operators
  int compound_add = num1;
  compound_add += num2;
  int compound_subtract = num1;
  compound_subtract -= num2;
  int compound_multiply = num1;
  compound_multiply *= num2;
  int compound_divide = num1;
  if (num2 != 0) {
    compound_divide /= num2;
  }

  printf("Compound add of %d and %d is %d\n", num1, num2, compound_add);
  printf("Compound subtract of %d by %d is %d\n", num1, num2, compound_subtract);
  printf("Compound multiply of %d and %d is %d\n", num1, num2, compound_multiply);
  if (num2 != 0) {
    printf("Compound divide of %d by %d is %d\n", num1, num2, compound_divide);
  } else {
    printf("Cannot divide by zero\n");
  }
  
  return 0;
}