//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_NUM 100000
#define MAGIC_NUMBER 42

int main() {
  srand(time(NULL));

  int num1, num2, sum, diff, mult, div, mod;
  char op;

  printf("Welcome to the Arithmetic Adventure! \n");

  do {
    printf("Enter a number: ");
    scanf("%d", &num1);

    printf("Enter another number: ");
    scanf("%d", &num2);

    printf("Enter an operation (+, -, *, /, %): ", &op);
    scanf(" %c", &op);

    switch (op) {
      case '+':
        sum = num1 + num2;
        break;
      case '-':
        diff = num1 - num2;
        break;
      case '*':
        mult = num1 * num2;
        break;
      case '/':
        div = num1 / num2;
        break;
      case '%':
        mod = num1 % num2;
        break;
      default:
        printf("Invalid operation! Please try again.\n");
        break;
    }

    printf("Result: %d\n", sum);

    printf("Want to play again? (y/n): ");
    scanf(" %c", &op);

  } while (op == 'y');

  return 0;
}