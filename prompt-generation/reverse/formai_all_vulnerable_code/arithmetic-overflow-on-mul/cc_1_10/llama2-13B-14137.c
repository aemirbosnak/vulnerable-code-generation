//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAGIC_NUMBER 42

int main() {
  int num1, num2, sum;
  char op;

  // Let's get this party started!
  printf("Welcome to the arithmetic circus!\n");

  // Pick your number!
  printf("Pick a number between 1 and 100: ");
  scanf("%d", &num1);

  // What's your favorite operation?
  printf("Do you want to add, subtract, multiply, or divide? (type 'a', 's', 'm', or 'd') ");
  scanf(" %c", &op);

  // Let's get this show on the road!
  if (op == 'a') {
    // Add some magic to the mix!
    num2 = MAGIC_NUMBER;
    sum = num1 + num2;
    printf("The result of %d + %d is %d!\n", num1, num2, sum);
  } else if (op == 's') {
    // Subtract some silliness!
    num2 = MAGIC_NUMBER;
    sum = num1 - num2;
    printf("The result of %d - %d is %d!\n", num1, num2, sum);
  } else if (op == 'm') {
    // Multiply like there's no tomorrow!
    num2 = MAGIC_NUMBER;
    sum = num1 * num2;
    printf("The result of %d x %d is %d!\n", num1, num2, sum);
  } else if (op == 'd') {
    // Divide and conquer!
    num2 = MAGIC_NUMBER;
    sum = num1 / num2;
    printf("The result of %d / %d is %d!\n", num1, num2, sum);
  } else {
    // Oh no! You picked a invalid operation!
    printf("Oops, you picked a invalid operation! Better luck next time!\n");
  }

  // That's all folks!
  printf("Thanks for playing the arithmetic circus game!\n");
  return 0;
}