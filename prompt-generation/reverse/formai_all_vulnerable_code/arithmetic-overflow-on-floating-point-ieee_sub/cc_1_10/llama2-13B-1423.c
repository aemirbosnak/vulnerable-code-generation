//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define EPS 0.000001

int main() {
  double a, b, c;
  char op;

  // Input values
  printf("Enter the first number: ");
  scanf("%lf", &a);
  printf("Enter the second number: ");
  scanf("%lf", &b);
  printf("Enter the operation (+, -, *, /): ");
  scanf(" %c", &op);

  // Check for invalid input
  if (a == 0 && b == 0) {
    printf("Error: Divide by zero detected! \n");
    return 1;
  }

  // Perform operation
  if (op == '+') {
    c = a + b;
  } else if (op == '-') {
    c = a - b;
  } else if (op == '*') {
    c = a * b;
  } else if (op == '/') {
    c = a / b;
  } else {
    printf("Error: Unknown operation! \n");
    return 1;
  }

  // Check for overflow
  if (fabs(c) > 1E100) {
    printf("Error: Overflow detected! \n");
    return 1;
  }

  // Print result
  printf("Result: %f\n", c);

  return 0;
}