//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

int main() {
  int choice;
  float num1, num2, result;
  char op;

  while(1) {
    printf("\nCyberpunk Math++\n");
    printf("1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Division (/)\n");
    printf("5. Modulus (%)\n");
    printf("6. Exit\n");
    printf("Enter your choice (1-6): ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("Enter two numbers: ");
        scanf("%f %f", &num1, &num2);
        result = num1 + num2;
        printf("Result: %.2f\n", result);
        break;
      case 2:
        printf("Enter two numbers: ");
        scanf("%f %f", &num1, &num2);
        result = num1 - num2;
        printf("Result: %.2f\n", result);
        break;
      case 3:
        printf("Enter two numbers: ");
        scanf("%f %f", &num1, &num2);
        result = num1 * num2;
        printf("Result: %.2f\n", result);
        break;
      case 4:
        printf("Enter two numbers: ");
        scanf("%f %f", &num1, &num2);
        if (num2 == 0) {
          printf("Error: Division by zero\n");
        } else {
          result = num1 / num2;
          printf("Result: %.2f\n", result);
        }
        break;
      case 5:
        printf("Enter two numbers: ");
        scanf("%f %f", &num1, &num2);
        if (num2 == 0) {
          printf("Error: Division by zero\n");
        } else {
          result = (int)num1 % (int)num2;
          printf("Result: %d\n", result);
        }
        break;
      case 6:
        exit(0);
        break;
      default:
        printf("Invalid choice\n");
    }
  }

  return 0;
}