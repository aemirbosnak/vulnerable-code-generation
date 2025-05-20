//FormAI DATASET v1.0 Category: Scientific ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {

  //Welcome message
  printf("Hello there! Today we're going to have some fun with scientific calculations. \
         \n\nGet ready to use your scientific brains!\n\n");
         
  //Get user inputs
  int a, b;
  printf("Please enter two integers: ");
  scanf("%d %d", &a, &b);

  //Sum calculation
  int sum = a + b;
  printf("\nThe sum of %d and %d is: %d\n", a, b, sum);

  //Subtraction calculation
  int sub = a - b;
  printf("The difference of %d and %d is: %d\n", a, b, sub);

  //Multiplication calculation
  int mul = a * b;
  printf("The product of %d and %d is: %d\n", a, b, mul);

  //Division calculation
  float div = (float)a / b;
  printf("The quotient of %d and %d is: %.2f\n", a, b, div);

  //Factorial calculation
  int fact1 = 1, fact2 = 1;
  for (int i = 1; i <= a; i++) {
    fact1 *= i;
  }
  for (int i = 1; i <= b; i++) {
    fact2 *= i;
  }
  printf("The factorial of %d is: %d\n", a, fact1);
  printf("The factorial of %d is: %d\n", b, fact2);

  //Power calculation
  int power = 1;
  for (int i = 1; i <= b; i++) {
    power *= a;
  }
  printf("The value of %d raised to the power of %d is: %d\n", a, b, power);

  //End message
  printf("\nCongratulations, you have successfully completed all scientific calculations!\n");
  printf("Goodbye and have a scientifically fun day!\n");

  return 0;
}