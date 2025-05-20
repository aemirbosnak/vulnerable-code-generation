//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define PRINT_DEBUG(x) if (0) printf x

#define INPUT_VALID(x) if (!(x)) { printf("Invalid input!\n"); return 1; }

#define OUTPUT_VALID(x) if (!(x)) { printf("Output invalid!\n"); return 2; }

#define RANDOM_NUMBER 10

int main() {
  int num1, num2, sum;
  char op;
  double result;

  PRINT_DEBUG(("Welcome to the retro calculator!"));

  do {
    PRINT_DEBUG(("Enter a number: "));
    scanf("%d", &num1);
    INPUT_VALID(num1);

    PRINT_DEBUG(("Enter an operation (+, -, *, /): "));
    scanf(" %c", &op);
    INPUT_VALID(op);

    if (op == '+') {
      PRINT_DEBUG(("Enter a second number: "));
      scanf("%d", &num2);
      INPUT_VALID(num2);

      sum = num1 + num2;
      PRINT_DEBUG(("Result: %d", sum));
    } else if (op == '-') {
      PRINT_DEBUG(("Enter a second number: "));
      scanf("%d", &num2);
      INPUT_VALID(num2);

      sum = num1 - num2;
      PRINT_DEBUG(("Result: %d", sum));
    } else if (op == '*') {
      PRINT_DEBUG(("Enter a second number: "));
      scanf("%d", &num2);
      INPUT_VALID(num2);

      sum = num1 * num2;
      PRINT_DEBUG(("Result: %f", sum));
    } else if (op == '/') {
      PRINT_DEBUG(("Enter a second number: "));
      scanf("%d", &num2);
      INPUT_VALID(num2);

      sum = num1 / num2;
      PRINT_DEBUG(("Result: %f", sum));
    } else {
      PRINT_DEBUG(("Invalid operation!"));
    }
  } while (1);

  PRINT_DEBUG(("Thank you for using the retro calculator!"));

  return 0;
}