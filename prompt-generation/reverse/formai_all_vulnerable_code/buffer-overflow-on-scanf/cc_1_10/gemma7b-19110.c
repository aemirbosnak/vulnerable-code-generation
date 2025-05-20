//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

int main()
{
  system("clear");
  printf("__________________________________\n");
  printf("           CALCULATOR MAGIC!!!\n");
  printf("__________________________________\n");

  int num1, num2, operator;
  float result;

  printf("Enter the first number: ");
  scanf("%d", &num1);

  printf("Enter the operator (+, -, *, /): ");
  scanf("%d", &operator);

  printf("Enter the second number: ");
  scanf("%d", &num2);

  switch (operator)
  {
    case 1:
      result = (float)num1 + (float)num2;
      printf("The result is: %.2f\n", result);
      break;
    case 2:
      result = (float)num1 - (float)num2;
      printf("The result is: %.2f\n", result);
      break;
    case 3:
      result = (float)num1 * (float)num2;
      printf("The result is: %.2f\n", result);
      break;
    case 4:
      if (num2 == 0)
      {
        printf("Cannot divide by zero!\n");
      }
      else
      {
        result = (float)num1 / (float)num2;
        printf("The result is: %.2f\n", result);
      }
      break;
    default:
      printf("Invalid operator!\n");
  }

  system("pause");
  return 0;
}