//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  double num1, num2, answer;
  char operator;

  printf("Enter first number: ");
  scanf("%lf", &num1);

  printf("Enter operator (+, -, *, /, sin, cos, tan): ");
  scanf(" %c", &operator);

  if (operator == 'sin' || operator == 'cos' || operator == 'tan') {
    double radians = num1 * (M_PI / 180);
    switch (operator) {
      case 'sin':
        answer = sin(radians);
        break;
      case 'cos':
        answer = cos(radians);
        break;
      case 'tan':
        answer = tan(radians);
        break;
      default:
        printf("Invalid input");
        return -1;
    }
  } else {
    printf("Enter second number: ");
    scanf("%lf", &num2);

    switch (operator) {
      case '+':
        answer = num1 + num2;
        break;
      case '-':
        answer = num1 - num2;
        break;
      case '*':
        answer = num1 * num2;
        break;
      case '/':
        if (num2 == 0) {
          printf("Error! Cannot divide by 0");
          return -1;
        } else {
          answer = num1 / num2;
        }
        break;
      default:
        printf("Invalid input");
        return -1;
    }
  }

  printf("The answer is: %lf\n", answer);

  return 0;
}