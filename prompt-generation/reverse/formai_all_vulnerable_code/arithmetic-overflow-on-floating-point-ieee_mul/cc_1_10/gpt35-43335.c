//FormAI DATASET v1.0 Category: Arithmetic ; Style: ultraprecise
#include <stdio.h>

int main() {

  float num1, num2, result;
  char operator;

  printf("Enter the first number: ");
  scanf("%f", &num1);

  printf("\nEnter the second number: ");
  scanf("%f", &num2);

  printf("\nEnter the operator (+,-,*,/): ");
  scanf(" %c", &operator);

  switch (operator) {
      
    case '+':
      result = num1 + num2;
      printf("\nResult: %.2f", result);
      break;

    case '-':
      result = num1 - num2;
      printf("\nResult: %.2f", result);
      break;

    case '*':
      result = num1*num2;
      printf("\nResult: %.2f", result);
      break;

    case '/':
      if (num2 == 0) {
        printf("\nError: Division by zero.");
      }
      
      else {
        result = num1/num2;
        printf("\nResult: %.2f", result);
      }
      break;

    default:
      printf("\nError: Invalid operator.");
      break;
  }

  return 0;
}