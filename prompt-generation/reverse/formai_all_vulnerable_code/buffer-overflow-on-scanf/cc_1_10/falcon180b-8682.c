//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
  char input[100];
  char *token;
  int num1, num2, result;
  double num3, num4, sum;
  char operator;

  printf("Enter an expression in the format: num1 operator num2\n");
  scanf("%s", input);

  token = strtok(input, " ");
  num1 = atoi(token);

  token = strtok(NULL, " ");
  operator = toupper(token[0]);

  token = strtok(NULL, " ");
  num2 = atoi(token);

  switch(operator) {
    case '+':
      result = num1 + num2;
      printf("%d + %d = %d\n", num1, num2, result);
      break;
    case '-':
      result = num1 - num2;
      printf("%d - %d = %d\n", num1, num2, result);
      break;
    case '*':
      result = num1 * num2;
      printf("%d * %d = %d\n", num1, num2, result);
      break;
    case '/':
      if(num2 == 0) {
        printf("Error: Division by zero\n");
      } else {
        result = num1 / num2;
        printf("%d / %d = %.2f\n", num1, num2, (double)result);
      }
      break;
    case '^':
      result = pow(num1, num2);
      printf("%d ^ %d = %d\n", num1, num2, result);
      break;
    case 'S':
      num3 = num1;
      num4 = num2;
      sum = num3 + num4;
      printf("The sum of %.2f and %.2f is %.2f\n", num3, num4, sum);
      break;
    default:
      printf("Invalid operator\n");
  }

  return 0;
}