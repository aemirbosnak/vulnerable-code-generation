//Gemma-7B DATASET v1.0 Category: Error handling ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define ERROR_NUMBER_TOO_BIG 1
#define ERROR_NUMBER_TOO_SMALL 2
#define ERROR_INVALID_OPERATION 3

int main() {
  int number;
  char operation;

  printf("Enter an integer: ");
  scanf("%d", &number);

  printf("Enter an operation (+, -, *, /): ");
  scanf(" %c", &operation);

  switch (operation) {
    case '+':
      if (number > 10) {
        printf("Error: Number too big.\n");
        return ERROR_NUMBER_TOO_BIG;
      } else if (number < 0) {
        printf("Error: Number too small.\n");
        return ERROR_NUMBER_TOO_SMALL;
      } else {
        printf("The result is: %d.\n", number + number);
      }
      break;
    case '-':
      if (number < 0) {
        printf("Error: Number too small.\n");
        return ERROR_NUMBER_TOO_SMALL;
      } else {
        printf("The result is: %d.\n", number - number);
      }
      break;
    case '*':
      if (number == 0) {
        printf("Error: Cannot divide by zero.\n");
        return ERROR_INVALID_OPERATION;
      } else {
        printf("The result is: %d.\n", number * number);
      }
      break;
    case '/':
      if (number == 0) {
        printf("Error: Cannot divide by zero.\n");
        return ERROR_INVALID_OPERATION;
      } else {
        printf("The result is: %d.\n", number / number);
      }
      break;
    default:
      printf("Error: Invalid operation.\n");
      return ERROR_INVALID_OPERATION;
  }

  return 0;
}