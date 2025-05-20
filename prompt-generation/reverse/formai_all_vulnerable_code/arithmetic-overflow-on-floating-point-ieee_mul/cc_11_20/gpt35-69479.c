//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: excited
#include <stdio.h>
#include <math.h>

// This is a scientific calculator program!
// It can perform all sorts of advanced calculations!
// Ready to see some magic? Let's gooo!!

int main() {
  double num1, num2, result;
  char operator;

  printf("Welcome to the Scientific Calculator!\n");
  printf("Enter first number: ");
  scanf("%lf", &num1);

  printf("Enter operator (+, -, *, /, sin, cos, tan, log, sqrt): ");
  scanf(" %c", &operator);

  if(operator == '+' || operator == '-' || operator == '*' || operator == '/') {
    printf("Enter second number: ");
    scanf("%lf", &num2);
  }

  switch(operator) {
    case '+':
      result = num1 + num2;
      printf("Result: %lf\n", result);
      break;
    case '-':
      result = num1 - num2;
      printf("Result: %lf\n", result);
      break;
    case '*':
      result = num1 * num2;
      printf("Result: %lf\n", result);
      break;
    case '/':
      if(num2 != 0) {
        result = num1 / num2;
        printf("Result: %lf\n", result);
      } else {
        printf("Error: Cannot divide by zero\n");
      }
      break;
    case 's':
      result = sin(num1);
      printf("Result: %lf\n", result);
      break;
    case 'c':
      result = cos(num1);
      printf("Result: %lf\n", result);
      break;
    case 't':
      result = tan(num1);
      printf("Result: %lf\n", result);
      break;
    case 'l':
      result = log10(num1);
      printf("Result: %lf\n", result);
      break;
    case 'q':
      if(num1 >= 0) {
        result = sqrt(num1);
        printf("Result: %lf\n", result);
      } else {
        printf("Error: Cannot take square root of negative number\n");
      }
      break;
    default:
      printf("Error: Invalid operator\n");
  }

  printf("Thank you for using the Scientific Calculator!\n");
  return 0;
}