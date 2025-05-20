//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

void clear_buffer(char *);

int main() {
  char buffer[MAX_BUFFER_SIZE];
  char operator;
  double num1, num2, result;

  printf("Enter an operator (+, -, *, /, %): ");
  scanf("%c", &operator);

  switch (operator) {
    case '+':
      printf("Enter the first number: ");
      scanf("%lf", &num1);
      printf("Enter the second number: ");
      scanf("%lf", &num2);
      result = num1 + num2;
      break;
    case '-':
      printf("Enter the first number: ");
      scanf("%lf", &num1);
      printf("Enter the second number: ");
      scanf("%lf", &num2);
      result = num1 - num2;
      break;
    case '*':
      printf("Enter the first number: ");
      scanf("%lf", &num1);
      printf("Enter the second number: ");
      scanf("%lf", &num2);
      result = num1 * num2;
      break;
    case '/':
      printf("Enter the first number: ");
      scanf("%lf", &num1);
      printf("Enter the second number: ");
      scanf("%lf", &num2);
      result = num1 / num2;
      break;
    default:
      printf("Invalid operator.\n");
  }

  if (result != 0) {
    printf("The result is: %.2lf\n", result);
  } else {
    printf("The result is: 0\n");
  }

  clear_buffer(buffer);

  return 0;
}

void clear_buffer(char *buffer) {
  int i = 0;
  while (buffer[i] != '\0') {
    buffer[i] = '\0';
    i++;
  }
}