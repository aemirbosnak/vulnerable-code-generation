//FormAI DATASET v1.0 Category: Arithmetic ; Style: configurable
#include <stdio.h>

int main() {
  int num1, num2, choice, result;
  char ch;

  do {
    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    printf("Choose an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("Your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
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
            result = num1 / num2;
            printf("%d / %d = %d\n", num1, num2, result);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    printf("Do you want to continue? (Y/N): ");
    scanf(" %c", &ch);

  } while(ch == 'Y' || ch == 'y');

  return 0;
}