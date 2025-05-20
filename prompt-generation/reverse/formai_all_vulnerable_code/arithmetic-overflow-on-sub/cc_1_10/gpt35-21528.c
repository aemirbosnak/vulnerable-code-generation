//FormAI DATASET v1.0 Category: Arithmetic ; Style: cheerful
#include <stdio.h>

int main() {
  int num1, num2, sum, difference, product, quotient, remainder;
  printf("Hey there! I am your cheerful calculator.\n");
  printf("Enter any two numbers, and I will perform some arithmetic operations on them!\n");
  printf("Enter the first number: ");
  scanf("%d", &num1);
  printf("Great! Now enter the second number: ");
  scanf("%d", &num2);

  // Addition
  sum = num1 + num2;
  printf("The sum of %d and %d is %d.\n", num1, num2, sum);

  // Subtraction
  difference = num1 - num2;
  printf("The difference between %d and %d is %d.\n", num1, num2, difference);

  // Multiplication
  product = num1 * num2;
  printf("The product of %d and %d is %d.\n", num1, num2, product);

  // Division
  if (num2 != 0) {
    quotient = num1 / num2;
    remainder = num1 % num2;
    printf("The quotient of %d and %d is %d, with a remainder of %d.\n", num1, num2, quotient, remainder);
  } else {
    printf("Oops! Division by zero is not allowed. Please try again with a non-zero second number.\n");
  }

  // Bitwise AND, OR, XOR
  int bitwiseAnd = num1 & num2;
  int bitwiseOr = num1 | num2;
  int bitwiseXor = num1 ^ num2;
  printf("The bitwise AND of %d and %d is %d.\n", num1, num2, bitwiseAnd);
  printf("The bitwise OR of %d and %d is %d.\n", num1, num2, bitwiseOr);
  printf("The bitwise XOR of %d and %d is %d.\n", num1, num2, bitwiseXor);

  // Shift left and right
  int shiftedLeft = num1 << 1;
  int shiftedRight = num2 >> 1;
  printf("Shifting %d to the left by 1 gives %d.\n", num1, shiftedLeft);
  printf("Shifting %d to the right by 1 gives %d.\n", num2, shiftedRight);

  printf("I hope you enjoyed using me as your calculator today! Have a great day!\n");

  return 0;
}