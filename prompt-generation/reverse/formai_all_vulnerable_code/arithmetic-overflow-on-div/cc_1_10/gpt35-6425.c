//FormAI DATASET v1.0 Category: Arithmetic ; Style: safe
#include<stdio.h>

int main()
{
  int a,b,c;
  char operator;

  printf("Enter an expression: ");
  scanf("%d %c %d", &a, &operator, &b);

  switch(operator)
  {
    case '+':
      c = a + b;
      printf("Result: %d\n", c);
      break;
    case '-':
      c = a - b;
      printf("Result: %d\n", c);
      break;
    case '*':
      c = a * b;
      printf("Result: %d\n", c);
      break;
    case '/':
      if(b == 0)
      {
        printf("Division by Zero Error!\n");
      }
      else
      {
        c = a / b;
        printf("Result: %d\n", c);
      }
      break;
    case '%':
      if(b == 0)
      {
        printf("Division by Zero Error!\n");
      }
      else
      {
        c = a % b;
        printf("Result: %d\n", c);
      }
      break;
    default:
      printf("Invalid Operator!\n");
  }

  return 0;
}