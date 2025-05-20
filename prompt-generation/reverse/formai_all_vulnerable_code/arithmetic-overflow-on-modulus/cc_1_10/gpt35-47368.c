//FormAI DATASET v1.0 Category: Calculator ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>

int main() {
  int num1, num2, choice, result;
  
  do {
    printf("\n--------- CALCULATOR PROGRAM ---------\n");
    printf("\n\t1. Addition");
    printf("\n\t2. Subtraction");
    printf("\n\t3. Multiplication");
    printf("\n\t4. Division");
    printf("\n\t5. Modulus");
    printf("\n\t6. Exit");
    printf("\n\nPlease enter your choice: ");
    scanf("%d", &choice);
    printf("\n");

    switch(choice) {
      case 1:
        printf("\n You selected Addition \n");
        printf("\n Enter first number: ");
        scanf("%d", &num1);
        printf("\n Enter second number: ");
        scanf("%d", &num2);
        result = num1 + num2;
        printf("\n Result of %d + %d is: %d \n", num1, num2, result);
        break;

      case 2:
        printf("\n You selected Subtraction \n");
        printf("\n Enter first number: ");
        scanf("%d", &num1);
        printf("\n Enter second number: ");
        scanf("%d", &num2);
        result = num1 - num2;
        printf("\n Result of %d - %d is: %d \n", num1, num2, result);
        break;

      case 3:
        printf("\n You selected Multiplication \n");
        printf("\n Enter first number: ");
        scanf("%d", &num1);
        printf("\n Enter second number: ");
        scanf("%d", &num2);
        result = num1 * num2;
        printf("\n Result of %d * %d is: %d \n", num1, num2, result);
        break;

      case 4:
        printf("\n You selected Division \n");
        printf("\n Enter first number: ");
        scanf("%d", &num1);
        printf("\n Enter second number: ");
        scanf("%d", &num2);
        if(num2 == 0) {
          printf("\n ERROR! Cannot divide by zero! \n");
          break;
        }
        else {
          result = num1 / num2;
          printf("\n Result of %d / %d is: %d \n", num1, num2, result);
          break;
        }

      case 5:
        printf("\n You selected Modulus \n");
        printf("\n Enter first number: ");
        scanf("%d", &num1);
        printf("\n Enter second number: ");
        scanf("%d", &num2);
        if(num2 == 0) {
          printf("\n ERROR! Cannot divide by zero! \n");
          break;
        }
        else {
          result = num1 % num2;
          printf("\n Result of %d %% %d is: %d \n", num1, num2, result);
          break;
        }

      case 6:
        printf("\n Thank you for using Calculator Program \n");
        exit(0);

      default:
        printf("\n Invalid choice, Please select a valid option \n");
        break;
    }
  } while(choice != 6);

  return 0;
}