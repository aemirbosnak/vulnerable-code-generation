//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Dennis Ritchie
#include <stdio.h>
#include <math.h>

int main() {
  float num1, num2;
  char operation;

  printf("Enter first number: ");
  scanf("%f", &num1);
  printf("Enter second number: ");
  scanf("%f", &num2);

  printf("Choose an operation: +, -, *, /, %% (modulus), sin, cos, tan\n");
  scanf(" %c", &operation);

  switch (operation) {
    case '+':
      printf("Result: %.2f\n", num1 + num2);
      break;
    case '-':
      printf("Result: %.2f\n", num1 - num2);
      break;
    case '*':
      printf("Result: %.2f\n", num1 * num2);
      break;
    case '/':
      printf("Result: %.2f\n", num1 / num2);
      break;
    case '%':
      printf("Result: %.0f\n", fmodf(num1, num2));
      break;
    case 's':
    case 'S':
      printf("Result: %.2f\n", sin(num1));
      break;
    case 'c':
    case 'C':
      printf("Result: %.2f\n", cos(num1));
      break;
    case 't':
    case 'T':
      printf("Result: %.2f\n", tan(num1));
      break;
    default:
      printf("Invalid operation\n");
      break;
  }

  return 0;
}