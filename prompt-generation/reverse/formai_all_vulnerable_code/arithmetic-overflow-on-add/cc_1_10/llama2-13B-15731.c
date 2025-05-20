//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAGIC_NUMBER 42

int main() {
  int num1, num2, sum, diff, mult, div;
  char op;

  printf("Welcome to the Arithmetic Adventure! \n");
  printf("You are about to embark on a journey through the realms of addition, subtraction, multiplication, and division. \n");
  printf("Your trusty companion is a magical calculator, powered by the mystical number %d. \n", MAGIC_NUMBER);

  // Ask the user for the first number
  printf("Please enter the first number: ");
  scanf("%d", &num1);

  // Ask the user for the second number
  printf("Please enter the second number: ");
  scanf("%d", &num2);

  // Ask the user for the operation
  printf("Now, choose an operation: +, -, x, or /. Enter the corresponding letter: ");
  scanf(" %c", &op);

  // Perform the operation
  switch (op) {
    case '+':
      sum = num1 + num2;
      break;
    case '-':
      diff = num1 - num2;
      break;
    case 'x':
      mult = num1 * num2;
      break;
    case '/':
      div = num1 / num2;
      break;
    default:
      printf("Invalid operation. Please try again.\n");
      return 1;
  }

  // Print the result
  printf("The result of %d %c %d is %d\n", num1, op, num2, sum);

  // Ask the user if they want to play again
  printf("Do you want to play again? (y/n): ");
  char answer;
  scanf(" %c", &answer);

  if (answer == 'y') {
    return 0;
  } else {
    return 1;
  }
}