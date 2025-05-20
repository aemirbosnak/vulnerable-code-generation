//FormAI DATASET v1.0 Category: Arithmetic ; Style: curious
#include <stdio.h>

int main() {
  int num1, num2, sum, difference, product, quotient, remainder;
  
  printf("Welcome to the Curious Calculator!\n");
  printf("Enter the first number: ");
  scanf("%d", &num1);
  printf("Enter the second number: ");
  scanf("%d", &num2);
  
  // Calculation of sum
  sum = num1 + num2;
  printf("\nThe sum of %d and %d is: %d\n", num1, num2, sum);
  
  // Calculation of difference
  difference = num1 - num2;
  printf("The difference between %d and %d is: %d\n", num1, num2, difference);
  
  // Calculation of product
  product = num1 * num2;
  printf("The product of %d and %d is: %d\n", num1, num2, product);
  
  // Calculation of quotient and remainder
  quotient = num1 / num2;
  remainder = num1 % num2;
  printf("The quotient of %d and %d is: %d with a remainder of %d\n", num1, num2, quotient, remainder);
  
  // Curiosity begins...
  if (sum > product) {
    printf("\nThe sum is greater than the product! I wonder why...\n");
    printf("%d + %d = %d\n", num1, num2, sum);
    printf("%d * %d = %d\n", num1, num2, product);
  } else if (sum < product) {
    printf("\nThe product is greater than the sum! I wonder why...\n");
    printf("%d + %d = %d\n", num1, num2, sum);
    printf("%d * %d = %d\n", num1, num2, product);
  } else {
    printf("\nThe sum and the product are equal! How curious...\n");
    printf("%d + %d = %d\n", num1, num2, sum);
    printf("%d * %d = %d\n", num1, num2, product);
  }
  
  // More curiosity...
  if (num1 % 2 == 0 && num2 % 2 == 0) {
    printf("\nBoth numbers are even!\n");
  } else if (num1 % 2 != 0 && num2 % 2 != 0) {
    printf("\nBoth numbers are odd!\n");
  } else {
    printf("\nThe numbers are a curious combination of odd and even!\n");
  }
  
  // Final thoughts...
  printf("\nThank you for using the Curious Calculator, where every calculation is an adventure!\n");
  
  return 0;
}