//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void f(int n) {
  switch (n) {
    case 0:
      printf("Error\n");
      break;
    case 1:
      printf("Invalid Operation\n");
      break;
    default:
      printf("Operation successful\n");
  }
}

int main() {
  char op;
  double num1, num2, result;

  printf("Enter operator (+, -, *, /, %): ");
  op = getchar();

  printf("Enter first number: ");
  scanf("%lf", &num1);

  printf("Enter second number: ");
  scanf("%lf", &num2);

  switch (op) {
    case '+':
      result = num1 + num2;
      break;
    case '-':
      result = num1 - num2;
      break;
    case '*':
      result = num1 * num2;
      break;
    case '/':
      if (num2 == 0) {
        f(0);
      } else {
        result = num1 / num2;
      }
      break;
    default:
      f(1);
  }

  printf("Result: %.2lf\n", result);

  return 0;
}