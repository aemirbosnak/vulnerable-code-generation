//FormAI DATASET v1.0 Category: Arithmetic ; Style: lively
#include <stdio.h>

int main () {
  int num1, num2, sum, difference, product, quotient, remainder;

  printf("Hello there! I am a program that can do some cool arithmetic operations.\n");
  printf("Give me a number: ");
  scanf("%d", &num1);
  printf("Give me another number: ");
  scanf("%d", &num2);
  
  sum = num1 + num2;
  difference = num1 - num2;
  product = num1 * num2;
  
  if (num2 != 0) {
      quotient = num1 / num2;
      remainder = num1 % num2;
      printf("%d divided by %d is %d with a remainder of %d.\n", num1, num2, quotient, remainder);
  } else {
      printf("Oops, you cannot divide by zero!\n");
  }

  printf("The sum of %d and %d is %d.\n", num1, num2, sum);
  printf("The difference between %d and %d is %d.\n", num1, num2, difference);
  printf("The product of %d and %d is %d.\n", num1, num2, product);

  printf("I can also do some advanced arithmetic operations like exponents and square roots.\n");
  printf("Let me show you!\n");
  
  int base, exponent, result;
  printf("Give me a base: ");
  scanf("%d", &base);
  printf("Give me an exponent: ");
  scanf("%d", &exponent);
  
  result = 1;
  for (int i = 0; i < exponent; i++) {
      result *= base;
  }
  printf("%d raised to the power of %d is %d.\n", base, exponent, result);

  printf("Now let's find the square root of a number.\n");
  double number;
  printf("Give me a number: ");
  scanf("%lf", &number);
  
  if (number >= 0) {
      double sqrt = 1.0;
      double precision = 0.0001;
      while ((sqrt * sqrt - number) > precision || (sqrt * sqrt - number) < -precision) {
          sqrt = (number / sqrt + sqrt) / 2.0;
      }
      printf("The square root of %.2lf is %.2lf.\n", number, sqrt);
  } else {
      printf("Oops, you cannot find the square root of a negative number!\n");
  }

  return 0;
}