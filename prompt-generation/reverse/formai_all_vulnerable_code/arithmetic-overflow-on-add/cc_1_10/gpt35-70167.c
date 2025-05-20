//FormAI DATASET v1.0 Category: Arithmetic ; Style: relaxed
/*
 * This program demonstrates the use of arithmetic operators and conditional statements in C language.
 * It will take two integers as input from the user and perform various arithmetic operations 
 * such as addition, subtraction, multiplication, division, modulus, increment and decrement.
 * It will also compare the two numbers and display the result of the comparison using if-else statements.
 */

#include <stdio.h>

int main() {

  int num1, num2, sum, diff, prod, mod, quotient;

  /*
   * Taking input from user
   */
  printf("Enter two integers: ");
  scanf("%d %d", &num1, &num2);

  /*
   * Performing arithmetic operations on the inputs
   */
  sum = num1 + num2;
  diff = num1 - num2;
  prod = num1 * num2;

  /*
   * Checking if the second input is zero
   * If not then performing division and modulus operation
   */
  if (num2 != 0) {
    quotient = num1 / num2;
    mod = num1 % num2;
  }
  
  /*
   * Incrementing and decrementing the first input
   */
  num1++;
  num2--;

  /*
   * Comparing the two numbers using if-else statements
   */
  if (num1 > num2) {
    printf("\n%d is greater than %d\n", num1, num2);
  } else if (num1 < num2) {
    printf("\n%d is less than %d\n", num1, num2);
  } else {
    printf("\n%d is equal to %d\n", num1, num2);
  }

  /*
   * Displaying all the arithmetic operation results
   */
  printf("\nArithmetic operations on %d and %d:\n", num1, num2);
  printf("%d + %d = %d\n", num1, num2, sum);
  printf("%d - %d = %d\n", num1, num2, diff);
  printf("%d * %d = %d\n", num1, num2, prod);

  if (num2 != 0) {
    printf("%d / %d = %d\n", num1, num2, quotient);
    printf("%d %% %d = %d\n", num1, num2, mod);
  } else {
    printf("Cannot perfrom division and modulus operation as second input is zero.\n");
  }

  printf("%d incremented by 1 is %d\n", num1-1, num1);
  printf("%d decremented by 1 is %d\n", num2+1, num2);

  return 0;
}