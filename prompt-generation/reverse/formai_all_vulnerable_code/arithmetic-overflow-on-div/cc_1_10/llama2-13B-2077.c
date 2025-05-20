//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAGIC_NUMBER 42

int main() {
  int num1, num2, sum, diff, mult, div;
  char op;

  printf("Welcome to the Arithmetic Adventure! \n");

  do {
    printf("Please enter an operation (+, -, *, /, or ^): ");
    scanf("%c", &op);

    switch (op) {
      case '+':
        printf("Enter two numbers: ");
        scanf("%d%d", &num1, &num2);
        sum = num1 + num2;
        printf("The sum is %d\n", sum);
        break;

      case '-':
        printf("Enter two numbers: ");
        scanf("%d%d", &num1, &num2);
        diff = num1 - num2;
        printf("The difference is %d\n", diff);
        break;

      case '*':
        printf("Enter two numbers: ");
        scanf("%d%d", &num1, &num2);
        mult = num1 * num2;
        printf("The product is %d\n", mult);
        break;

      case '/':
        printf("Enter two numbers: ");
        scanf("%d%d", &num1, &num2);
        div = num1 / num2;
        printf("The quotient is %d\n", div);
        break;

      case '^':
        printf("Enter two numbers: ");
        scanf("%d%d", &num1, &num2);
        if (num1 < num2) {
          printf("Error: cannot raise %d to the power of %d\n", num1, num2);
          break;
        }
        else {
          int power = num2;
          while (power-- > 0) {
            num1 *= num2;
          }
          printf("The result is %d\n", num1);
        }
        break;

      default:
        printf("Invalid operation. Try again.\n");
        break;
    }
  } while (1);

  return 0;
}