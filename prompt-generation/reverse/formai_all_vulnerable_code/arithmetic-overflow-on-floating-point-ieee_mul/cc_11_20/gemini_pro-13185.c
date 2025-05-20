//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  char op;
  double num1, num2;
  printf("Enter an operator (+, -, *, /): ");
  scanf(" %c", &op);
  printf("Enter two numbers: ");
  scanf("%lf %lf", &num1, &num2);

  switch (op) {
  case '+':
    printf("The sum of %.2lf and %.2lf is %.2lf.\n", num1, num2, num1 + num2);
    break;
  case '-':
    printf("The difference of %.2lf and %.2lf is %.2lf.\n", num1, num2, num1 - num2);
    break;
  case '*':
    printf("The product of %.2lf and %.2lf is %.2lf.\n", num1, num2, num1 * num2);
    break;
  case '/':
    if (num2 == 0) {
      printf("Division by zero is undefined.\n");
    } else {
      printf("The quotient of %.2lf and %.2lf is %.2lf.\n", num1, num2, num1 / num2);
    }
    break;
  default:
    printf("Invalid operator.\n");
  }

  // Extra features for a scientific calculator
  printf("Do you want to calculate trigonometric functions (sin, cos, tan) or exponential functions (exp, pow)? (y/n): ");
  char choice;
  scanf(" %c", &choice);

  switch (choice) {
  case 'y':
    printf("Enter a function (sin, cos, tan, exp, pow) and a number: ");
    char func;
    double num;
    scanf(" %c %lf", &func, &num);

    switch (func) {
    case 'sin':
      printf("The sine of %.2lf is %.2lf.\n", num, sin(num));
      break;
    case 'cos':
      printf("The cosine of %.2lf is %.2lf.\n", num, cos(num));
      break;
    case 'tan':
      printf("The tangent of %.2lf is %.2lf.\n", num, tan(num));
      break;
    case 'exp':
      printf("The exponential of %.2lf is %.2lf.\n", num, exp(num));
      break;
    case 'pow':
      printf("Enter the power to which %.2lf should be raised: ", num);
      double power;
      scanf("%lf", &power);
      printf("%.2lf raised to the power of %.2lf is %.2lf.\n", num, power, pow(num, power));
      break;
    default:
      printf("Invalid function.\n");
    }
    break;
  case 'n':
    printf("Thank you for using the scientific calculator.\n");
    break;
  default:
    printf("Invalid choice.\n");
  }

  return 0;
}