//FormAI DATASET v1.0 Category: Calculator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

int main()
{
  printf("Welcome to the Unique Calculator!\n");

  int option;
  float num1, num2;

  do
  {
    printf("\nChoose an option:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Exit\n");

    scanf("%d", &option);

    switch(option)
    {
      case 1:
        printf("\nEnter two numbers to add: ");
        scanf("%f%f", &num1, &num2);
        printf("Result: %.2f\n", num1 + num2);
        break;

      case 2:
        printf("\nEnter two numbers to subtract: ");
        scanf("%f%f", &num1, &num2);
        printf("Result: %.2f\n", num1 - num2);
        break;

      case 3:
        printf("\nEnter two numbers to multiply: ");
        scanf("%f%f", &num1, &num2);
        printf("Result: %.2f\n", num1 * num2);
        break;

      case 4:
        printf("\nEnter two numbers to divide: ");
        scanf("%f%f", &num1, &num2);
        if(num2 == 0)
        {
          printf("Error: Divide by zero!\n");
        }
        else
        {
          printf("Result: %.2f\n", num1 / num2);
        }
        break;

      case 5:
        printf("\nExiting program...\n");
        exit(0);
        break;

      default:
        printf("\nInvalid option. Please choose again.\n");
        break;
    }
  }
  while(option != 5);

  return 0;
}