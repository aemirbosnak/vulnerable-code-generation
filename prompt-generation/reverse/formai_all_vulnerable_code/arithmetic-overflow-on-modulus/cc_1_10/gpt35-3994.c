//FormAI DATASET v1.0 Category: Arithmetic ; Style: thoughtful
#include <stdio.h>

int main() {
  
  int num1, num2, choice, result;

  printf("Welcome to the Arithmetic Program!\n");
  printf("Please enter your first number: ");
  scanf("%d", &num1);
  printf("Please enter your second number: ");
  scanf("%d", &num2);

  while (1) {
    printf("\nPlease select an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus\n");
    printf("6. Exit program\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        result = num1 + num2;
        printf("%d + %d = %d\n", num1, num2, result);
        break;
      case 2:
        result = num1 - num2;
        printf("%d - %d = %d\n", num1, num2, result);
        break;
      case 3:
        result = num1 * num2;
        printf("%d * %d = %d\n", num1, num2, result);
        break;
      case 4:
        if (num2 == 0) {
          printf("Error: cannot divide by 0\n");
        } else {
          result = num1 / num2;
          printf("%d / %d = %d\n", num1, num2, result);
        }
        break;
      case 5:
        result = num1 % num2;
        printf("%d mod %d = %d\n", num1, num2, result);
        break;
      case 6:
        printf("Program terminated. Goodbye!\n");
        return 0;
      default:
        printf("Error: invalid choice. Please try again.\n");
    }
  }

  return 0;
}