//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define EPS 0.000001

int main() {
  double a, b, c;
  char op;

  printf("Enter three numbers: ");
  scanf("%lf%c%lf", &a, &op, &b);

  if (op != '+' && op != '-' && op != '*' && op != '/') {
    printf("Invalid operator. Please enter a valid operator (+, -, *, /).\n");
    return 1;
  }

  if (a == 0) {
    printf("Division by zero. Please enter a non-zero number.\n");
    return 1;
  }

  if (b == 0) {
    printf("Multiplication by zero. Please enter a non-zero number.\n");
    return 1;
  }

  c = 0;

  switch (op) {
    case '+':
      c = a + b;
      break;
    case '-':
      c = a - b;
      break;
    case '*':
      c = a * b;
      break;
    case '/':
      c = a / b;
      break;
    default:
      printf("Invalid operator. Please enter a valid operator (+, -, *, /).\n");
      return 1;
  }

  printf("Result: %f\n", c);

  if (fabs(c - (a + b)) > EPS) {
    printf("Result is not correct. Please check your calculations.\n");
    return 1;
  }

  return 0;
}