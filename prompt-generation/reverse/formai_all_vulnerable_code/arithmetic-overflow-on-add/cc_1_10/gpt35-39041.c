//FormAI DATASET v1.0 Category: Arithmetic ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int choice, a, b, c;
  char operator;
  printf("Welcome to the Intelligent Arithmetic Program\n");
  do {
    printf("\nPlease choose an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus\n");
    printf("6. Exit\n");
    printf("Enter your choice (1-6): ");

    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("\nEnter two numbers to add: ");
        scanf("%d %d", &a, &b);
        c = a + b;
        printf("\n%d + %d = %d\n", a, b, c);
        break;
      case 2:
        printf("\nEnter two numbers to subtract: ");
        scanf("%d %d", &a, &b);
        c = a - b;
        printf("\n%d - %d = %d\n", a, b, c);
        break;
      case 3:
        printf("\nEnter two numbers to multiply: ");
        scanf("%d %d", &a, &b);
        c = a * b;
        printf("\n%d x %d = %d\n", a, b, c);
        break;
      case 4:
        printf("\nEnter two numbers to divide: ");
        scanf("%d %d", &a, &b);
        c = a / b;
        printf("\n%d / %d = %d\n", a, b, c);
        break;
      case 5:
        printf("\nEnter two numbers to find modulus: ");
        scanf("%d %d", &a, &b);
        c = a % b;
        printf("\n%d %% %d = %d\n", a, b, c);
        break;
      case 6:
        printf("\nThank you for using Intelligent Arithmetic Program!\n");
        exit(0);
        break;
      default:
        printf("\nInvalid choice.\n");
    }
  } while(choice != 6);
  return 0;
}