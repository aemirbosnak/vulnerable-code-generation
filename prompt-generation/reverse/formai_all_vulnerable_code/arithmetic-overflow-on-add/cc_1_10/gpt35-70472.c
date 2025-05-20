//FormAI DATASET v1.0 Category: Educational ; Style: satisfied
#include <stdio.h>

int main() {
  int num1, num2, result, choice;

  printf("Welcome to my calculator program!\n");

  do {
    printf("\nChoose an operation from the list:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Exit\n");
    printf("Enter your choice (1-5): ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("\nEnter two numbers to add: ");
        scanf("%d %d", &num1, &num2);
        result = num1 + num2;
        printf("\n%d + %d = %d\n", num1, num2, result);
        break;
      case 2:
        printf("\nEnter two numbers to subtract: ");
        scanf("%d %d", &num1, &num2);
        result = num1 - num2;
        printf("\n%d - %d = %d\n", num1, num2, result);
        break;
      case 3:
        printf("\nEnter two numbers to multiply: ");
        scanf("%d %d", &num1, &num2);
        result = num1 * num2;
        printf("\n%d x %d = %d\n", num1, num2, result);
        break;
      case 4:
        printf("\nEnter two numbers to divide: ");
        scanf("%d %d", &num1, &num2);
        if (num2 == 0) {
          printf("\nError: cannot divide by zero.\n");
        } else {
          result = num1 / num2;
          printf("\n%d / %d = %d\n", num1, num2, result);
        }
        break;
      case 5:
        printf("\nThank you for using my calculator program!\n");
        break;
      default:
        printf("\nInvalid choice! Please choose again.\n");
        break;
    }
  } while (choice != 5);

  return 0;
}