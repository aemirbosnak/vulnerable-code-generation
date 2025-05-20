//FormAI DATASET v1.0 Category: Calculator ; Style: curious
#include <stdio.h>
#include <stdlib.h>

int main() {
  int option;
  float num1, num2, result;

  printf("Welcome to the Calculator program. Please select an option:\n");
  printf("1. Addition\n");
  printf("2. Subtraction\n");
  printf("3. Multiplication\n");
  printf("4. Division\n");
  printf("5. Exit\n");
  scanf("%d", &option);

  while (option != 5) {
    switch (option) {
      case 1:
        printf("Enter the first number: ");
        scanf("%f", &num1);
        printf("Enter the second number: ");
        scanf("%f", &num2);
        result = num1 + num2;
        printf("The result of %.2f + %.2f = %.2f\n", num1, num2, result);
        break;

      case 2:
        printf("Enter the first number: ");
        scanf("%f", &num1);
        printf("Enter the second number: ");
        scanf("%f", &num2);
        result = num1 - num2;
        printf("The result of %.2f - %.2f = %.2f\n", num1, num2, result);
        break;

      case 3:
        printf("Enter the first number: ");
        scanf("%f", &num1);
        printf("Enter the second number: ");
        scanf("%f", &num2);
        result = num1 * num2;
        printf("The result of %.2f * %.2f = %.2f\n", num1, num2, result);
        break;

      case 4:
        printf("Enter the first number: ");
        scanf("%f", &num1);
        printf("Enter the second number: ");
        scanf("%f", &num2);
        if (num2 == 0) {
          printf("Division by 0 is not allowed!\n");
        } else {
          result = num1 / num2;
          printf("The result of %.2f / %.2f = %.2f\n", num1, num2, result);
        }
        break;

      case 5:
        printf("Exiting program...\n");
        exit(0);
        break;

      default:
        printf("Invalid option. Please select again.\n");
        break;
    }

    printf("Please select another option:\n");
    scanf("%d", &option);
  }

  printf("Thank you for using the Calculator program!\n");

  return 0;
}