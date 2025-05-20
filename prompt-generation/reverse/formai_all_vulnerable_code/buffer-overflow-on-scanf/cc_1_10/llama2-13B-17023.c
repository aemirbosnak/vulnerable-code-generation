//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  int i, j, k;
  long double sum = 0, product = 1;
  char num1[10], num2[10];

  printf("Welcome to the Mathemagical Adventure! \n");

  // Exercise 1: Simplify the expression
  printf("Enter two numbers: ");
  scanf("%ld%ld", &num1[0], &num2[0]);
  sum = (long double)num1[0] + (long double)num2[0];
  product = (long double)num1[0] * (long double)num2[0];
  printf("The sum is: %Lf\n", sum);
  printf("The product is: %Lf\n", product);

  // Exercise 2: Solve the equation
  printf("Enter a number: ");
  scanf("%ld", &num1[0]);
  sum = (long double)num1[0] + (long double)num2[0];
  product = (long double)num1[0] * (long double)num2[0];
  if (sum == 0) {
    printf("You are in the magical forest of zeroes! \n");
  } else if (sum > 0) {
    printf("You are in the enchanted land of positivity! \n");
  } else {
    printf("You are in the mystical realm of negativity! \n");
  }

  // Exercise 3: Find the maximum
  for (i = 0; i < 10; i++) {
    for (j = 0; j < 10; j++) {
      if (i != j) {
        long double max = 0;
        for (k = 0; k < 10; k++) {
          if (i * k > j * k) {
            max = i * k;
          }
        }
        if (max > product) {
          product = max;
        }
      }
    }
  }
  printf("The maximum product is: %Lf\n", product);

  return 0;
}