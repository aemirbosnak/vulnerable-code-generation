//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <math.h>

int main() {
  double num1, num2, result;
  char operator;

  printf("Enter an operator (+, -, *, /, sqrt, pow, sin, cos, tan): ");
  scanf("%c", &operator);

  if (operator == 'sqrt' || operator == 'sin' || operator == 'cos' || operator == 'tan') {
    printf("Enter a number: ");
    scanf("%lf", &num1);

    if (operator == 'sqrt') {
      result = sqrt(num1);
      printf("The square root of %.2lf is %.2lf", num1, result);
    } else if (operator == 'sin') {
      result = sin(num1);
      printf("The sine of %.2lf is %.2lf", num1, result);
    } else if (operator == 'cos') {
      result = cos(num1);
      printf("The cosine of %.2lf is %.2lf", num1, result);
    } else if (operator == 'tan') {
      result = tan(num1);
      printf("The tangent of %.2lf is %.2lf", num1, result);
    }
  } else {
    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);

    if (operator == '+') {
      result = num1 + num2;
      printf("%.2lf + %.2lf = %.2lf", num1, num2, result);
    } else if (operator == '-') {
      result = num1 - num2;
      printf("%.2lf - %.2lf = %.2lf", num1, num2, result);
    } else if (operator == '*') {
      result = num1 * num2;
      printf("%.2lf * %.2lf = %.2lf", num1, num2, result);
    } else if (operator == '/') {
      result = num1 / num2;
      printf("%.2lf / %.2lf = %.2lf", num1, num2, result);
    } else if (operator == 'pow') {
      result = pow(num1, num2);
      printf("%.2lf raised to the power of %.2lf is %.2lf", num1, num2, result);
    } else {
      printf("Invalid operator");
    }
  }

  return 0;
}