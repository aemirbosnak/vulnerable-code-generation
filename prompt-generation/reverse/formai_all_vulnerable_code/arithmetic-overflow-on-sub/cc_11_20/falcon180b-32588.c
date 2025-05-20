//Falcon-180B DATASET v1.0 Category: Error handling ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main() {
  int num1 = 0, num2 = 0, result = 0;
  char operation = '\0';

  printf("Welcome to the Calculator!\n");

  while(1) {
    printf("Enter an operation (+, -, *, /): ");
    scanf("%c", &operation);

    if(operation == '+' || operation == '-' || operation == '*' || operation == '/') {
      break;
    } else {
      printf("Invalid operation. Please try again.\n");
    }
  }

  printf("Enter two numbers: ");
  if(scanf("%d %d", &num1, &num2)!= 2) {
    printf("Invalid input. Please try again.\n");
    return 1;
  }

  switch(operation) {
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
      if(num2 == 0) {
        printf("Error: Division by zero.\n");
        return 1;
      } else {
        result = num1 / num2;
      }
      break;
    default:
      printf("Invalid operation. Please try again.\n");
      return 1;
  }

  printf("Result: %d\n", result);

  return 0;
}