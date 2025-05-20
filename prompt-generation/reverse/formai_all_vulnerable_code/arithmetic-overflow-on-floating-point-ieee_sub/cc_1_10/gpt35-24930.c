//FormAI DATASET v1.0 Category: Educational ; Style: genious
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  printf("Welcome to the Genius Calculator!\n");
  printf("Please enter the mathematical operator you want to use (+, -, *, /):\n");

  char operator;
  scanf("%c", &operator);

  printf("Please enter two numbers for your calculation:\n");
  double num1, num2;
  scanf("%lf %lf", &num1, &num2);

  double result;

  switch (operator)
  {
    case '+':
      result = num1 + num2;
      printf("%lf + %lf = %lf\n", num1, num2, result);
      break;
  
    case '-':
      result = num1 - num2;
      printf("%lf - %lf = %lf\n", num1, num2, result);
      break;

    case '*':
      result = num1 * num2;
      printf("%lf * %lf = %lf\n", num1, num2, result);
      break;

    case '/':
      if (num2 == 0)
      {
          printf("Cannot divide by zero\n");
          return 0;
      }
      else
      {
          result = num1 / num2;
          printf("%lf / %lf = %lf\n", num1, num2, result);
          break;
      }

    default:
      printf("Invalid operator selected\n");
      break;
  }

  printf("Thanks for using the Genius Calculator! Have a nice day!\n");

  return 0;
}