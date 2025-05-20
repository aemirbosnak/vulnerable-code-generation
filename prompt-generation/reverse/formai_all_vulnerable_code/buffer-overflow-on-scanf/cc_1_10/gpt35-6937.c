//FormAI DATASET v1.0 Category: Calculator ; Style: portable
#include <stdio.h>
#include <stdlib.h>

int main() {

   int choice, num1, num2;
   float result;

   printf("\nWelcome to the Calculator!\n\n");
   printf("Select the operation you want to perform:\n");
   printf("----------------------------------------\n");
   printf("1. Addition\n");
   printf("2. Subtraction\n");
   printf("3. Multiplication\n");
   printf("4. Division\n");
   printf("5. Modulus\n");
   printf("----------------------------------------\n");
   printf("Enter your choice: ");
   scanf("%d",&choice);

   switch(choice) {
      case 1:
         printf("\nEnter two numbers to add: ");
         scanf("%d %d",&num1,&num2);
         result = num1 + num2;
         printf("Result: %.1f\n",result);
         break;

      case 2:
         printf("\nEnter two numbers to subtract: ");
         scanf("%d %d",&num1,&num2);
         result = num1 - num2;
         printf("Result: %.1f\n",result);
         break;

      case 3:
         printf("\nEnter two numbers to multiply: ");
         scanf("%d %d",&num1,&num2);
         result = num1 * num2;
         printf("Result: %.1f\n",result);
         break;

      case 4:
         printf("\nEnter two numbers to divide: ");
         scanf("%d %d",&num1,&num2);
         if(num2 == 0) {
            printf("Error: Divide by zero\n");
            exit(0);
         }
         result = (float)num1 / num2;
         printf("Result: %.1f\n",result);
         break;

      case 5:
         printf("\nEnter two numbers to find modulus: ");
         scanf("%d %d",&num1,&num2);
         if(num2 == 0) {
            printf("Error: Divide by zero\n");
            exit(0);
         }
         result = num1 % num2;
         printf("Result: %.1f\n",result);
         break;

      default:
         printf("Error: Invalid choice\n");
         break;
   }

   printf("\nThanks for using the Calculator!\n");

   return 0;
}