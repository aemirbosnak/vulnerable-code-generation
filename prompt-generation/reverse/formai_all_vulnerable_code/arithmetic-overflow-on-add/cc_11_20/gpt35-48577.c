//FormAI DATASET v1.0 Category: Calculator ; Style: imaginative
#include <stdio.h>
#include <string.h>

int main(void) {
  int num1, num2, option, result; 
  char operator, choice;
  
  printf("Welcome to the Calculator Program!\n");
  printf("Please enter the first number: ");
  scanf("%d", &num1);
  printf("Please enter the second number: ");
  scanf("%d", &num2);
  printf("Please choose an operator (+, -, *, /): ");
  scanf(" %c", &operator);

  switch(operator) {
    case '+':
      result = num1 + num2;
      printf("The sum of %d and %d is %d.\n", num1, num2, result);
      break;
    case '-':
      result = num1 - num2;
      printf("The difference between %d and %d is %d.\n", num1, num2, result);
      break;
    case '*':
      result = num1 * num2;
      printf("The product of %d and %d is %d.\n", num1, num2, result);
      break;
    case '/':
      result = num1 / num2;
      printf("The quotient when dividing %d by %d is %d.\n", num1, num2, result);
      break;
    default:
      printf("Invalid operator, please restart the program.\n");
      break;
  }
  
  printf("Do you want to perform another operation? (y/n): ");
  scanf(" %c", &choice);
  
  if(choice == 'y' || choice == 'Y') {
    printf("Please choose an operator (+, -, *, /): ");
    scanf(" %c", &operator);
    printf("Please enter another number: ");
    scanf("%d", &num2);
    
    switch(operator) {
      case '+':
        result = result + num2;
        printf("The sum of the previous result and %d is %d.\n", num2, result);
        break;
      case '-':
        result = result - num2;
        printf("%d minus %d is %d.\n", result, num2, result);
        break;
      case '*':
        result = result * num2;
        printf("Multiplying the previous result with %d gives %d.\n", num2, result);
        break;
      case '/':
        if(num2 == 0) {
          printf("Division by zero is undefined.\n");
        } else {
          result = result / num2;
          printf("%d divided by %d gives a quotient of %d.\n", result, num2, result);
        }
        break;
      default:
        printf("Invalid operator, please restart the program.\n");
        break;
    }
  }
  
  printf("Thanks for using the Calculator Program!\n");
  
  return 0;
}