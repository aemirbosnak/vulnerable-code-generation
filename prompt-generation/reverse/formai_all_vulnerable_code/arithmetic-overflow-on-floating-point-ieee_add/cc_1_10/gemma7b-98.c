//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

int main()
{
  system("clear");
  printf("Welcome to the Future, my dear user!\n");

  char operator;
  float num1, num2;

  printf("Please enter an operator (+, -, *, /): ");
  operator = getchar();

  printf("Please enter the first number: ");
  scanf("%f", &num1);

  printf("Please enter the second number: ");
  scanf("%f", &num2);

  float result = 0;

  switch (operator)
  {
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
      if (num2 == 0)
      {
        printf("Cannot divide by zero!\n");
      }
      else
      {
        result = num1 / num2;
      }
      break;
    default:
      printf("Invalid operator!\n");
  }

  if (result != 0)
  {
    printf("The result is: %.2f\n", result);
  }

  printf("Thank you for using the Future Calculator, have a nice day!\n");

  return 0;
}