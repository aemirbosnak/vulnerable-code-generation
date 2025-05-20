//FormAI DATASET v1.0 Category: Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int num1, num2, result;
  char operator;

  printf("Welcome to the Happy Calculator!\n");
  printf("Here, you can perform addition, subtraction, multiplication, and division.\n");

  printf("Enter the first number: ");
  scanf("%d", &num1);

  printf("Enter the operator (+,-,*,/): ");
  scanf(" %c", &operator);

  printf("Enter the second number: ");
  scanf("%d", &num2);

  switch (operator)
  {
  case '+':
    result = num1 + num2;
    printf("The result of %d + %d is: %d\n", num1, num2, result);
    break;

  case '-':
    result = num1 - num2;
    printf("The result of %d - %d is: %d\n", num1, num2, result);
    break;

  case '*':
    result = num1 * num2;
    printf("The result of %d * %d is: %d\n", num1, num2, result);
    break;

  case '/':
    if (num2 == 0)
    {
      printf("Error: Cannot divide by zero.\n");
      exit(0);
    }
    else
    {
      result = num1 / num2;
      printf("The result of %d / %d is: %d\n", num1, num2, result);
    }
    break;

  default:
    printf("Error: The operator entered is invalid.\n");
    break;
  }

  printf("Thank you for using the Happy Calculator!\n");

  return 0;
}