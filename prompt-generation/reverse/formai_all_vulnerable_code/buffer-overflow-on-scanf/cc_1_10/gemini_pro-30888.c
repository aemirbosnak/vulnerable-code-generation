//GEMINI-pro DATASET v1.0 Category: Educational ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

/*

  This program implements a simple command-line calculator that can perform the following operations:

  - Addition (+)
  - Subtraction (-)
  - Multiplication (*)
  - Division (/)
  - Modulus (%)

  The program first prompts the user to enter two numbers and an operator. It then performs the specified operation on the two numbers and prints the result.

*/

int main()
{
  // Declare variables to store the two numbers and the operator.
  double num1, num2;
  char op;

  // Prompt the user to enter the first number.
  printf("Enter the first number: ");
  scanf("%lf", &num1);

  // Prompt the user to enter the second number.
  printf("Enter the second number: ");
  scanf("%lf", &num2);

  // Prompt the user to enter the operator.
  printf("Enter the operator (+, -, *, /, %%): ");
  scanf(" %c", &op);

  // Perform the specified operation on the two numbers.
  switch (op)
  {
  case '+':
    printf("%lf + %lf = %lf\n", num1, num2, num1 + num2);
    break;
  case '-':
    printf("%lf - %lf = %lf\n", num1, num2, num1 - num2);
    break;
  case '*':
    printf("%lf * %lf = %lf\n", num1, num2, num1 * num2);
    break;
  case '/':
    if (num2 == 0)
    {
      printf("Division by zero is undefined.\n");
    }
    else
    {
      printf("%lf / %lf = %lf\n", num1, num2, num1 / num2);
    }
    break;
  case '%':
    if ((int)num2 == 0)
    {
      printf("Modulus by zero is undefined.\n");
    }
    else
    {
      printf("%lf %% %lf = %lf\n", num1, num2, (int)num1 % (int)num2);
    }
    break;
  default:
    printf("Invalid operator.\n");
    break;
  }

  return 0;
}