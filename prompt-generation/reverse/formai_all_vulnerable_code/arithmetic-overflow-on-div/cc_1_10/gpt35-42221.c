//FormAI DATASET v1.0 Category: Calculator ; Style: imaginative
#include <stdio.h>

int main() {
  int a, b, choice, result;
  printf("Welcome to the Imaginative Calculator!\n");

  do {
    printf("\nEnter two numbers: ");
    scanf("%d %d", &a, &b);

    printf("Select the operation you want to perform:\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Average\n");

    scanf("%d", &choice);

    switch(choice) {
      case 1:
        result = a + b;
        printf("The sum of %d and %d is %d\n", a, b, result);
        break;
      case 2:
        result = a - b;
        printf("The difference between %d and %d is %d\n", a, b, result);
        break;
      case 3:
        result = a * b;
        printf("The product of %d and %d is %d\n", a, b, result);
        break;
      case 4:
        if(b == 0) {
          printf("Cannot divide by zero\n");
        } else {
          result = a / b;
          printf("The quotient of %d divided by %d is %d\n", a, b, result);
        }
        break;
      case 5:
        result = (a + b) / 2;
        printf("The average of %d and %d is %d\n", a, b, result);
        break;
      default:
        printf("Invalid choice. Please select again\n");
    }
  } while(choice != 0);

  printf("Thank you for using the Imaginative Calculator\n");

  return 0;
}