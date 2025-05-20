//FormAI DATASET v1.0 Category: Scientific ; Style: curious
#include <stdio.h>
#include <stdlib.h>

int main() {
  int num1, num2, sum, product, quotient, remainder;
  
  printf("Welcome to the Curious Scientific Calculator!\n");
  printf("Please enter two numbers: ");
  scanf("%d %d", &num1, &num2);
  
  sum = num1 + num2;
  product = num1 * num2;
  quotient = num1 / num2;
  remainder = num1 % num2;
  
  printf("\n");
  printf("The sum of %d and %d is %d.\n", num1, num2, sum);
  printf("The product of %d and %d is %d.\n", num1, num2, product);
  
  if (num2 == 0) {
    printf("Cannot divide by zero.\n");
    exit(1);
  } else {
    printf("The quotient of %d divided by %d is %d with a remainder of %d.\n", num1, num2, quotient, remainder);
  }
  
  printf("\n");
  printf("Now for something curious...\n");
  printf("Would you like to know the value of pi to how many decimal places? Enter a number: ");
  int decimalPlaces;
  scanf("%d", &decimalPlaces);
  
  if (decimalPlaces < 0) {
    printf("Please enter a positive number.\n");
    exit(1);
  } else if (decimalPlaces == 0) {
    printf("pi is approximately 3.\n");
  } else {
    printf("Calculating the value of pi to %d decimal places...\n", decimalPlaces);
    float pi = 3.0;
    int denominator = 2;
    int negate = 1;
    while (decimalPlaces > 0) {
      pi = pi + (4.0 / (denominator * (denominator + 1) * (denominator + 2))) * negate;
      denominator += 2;
      negate = -negate;
      decimalPlaces--;
    }
    printf("pi is approximately %.20f.\n", pi);
  }
  
  return 0;
}