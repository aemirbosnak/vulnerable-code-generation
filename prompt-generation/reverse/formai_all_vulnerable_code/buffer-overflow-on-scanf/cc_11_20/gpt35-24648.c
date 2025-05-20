//FormAI DATASET v1.0 Category: Math exercise ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
   int num1, num2, result, choice;
   float num3, answer;
   char operator;

   srand(time(NULL));

   printf("Welcome to the Math Game!\n");
   printf("Choose the type of exercise:\n");
   printf("1. Addition\n");
   printf("2. Subtraction\n");
   printf("3. Division\n");
   printf("4. Multiplication\n");
   printf("5. Square Root\n");
   printf("Enter your choice: ");

   scanf("%d", &choice);

   switch (choice) {
      case 1:
         printf("You have chosen Addition.\n");
         num1 = rand() % 100;
         num2 = rand() % 100;
         printf("What is %d + %d? ", num1, num2);
         scanf("%d", &result);
         if (result == num1 + num2) {
            printf("Correct!\n");
         } else {
            printf("Incorrect. The answer is %d.\n", num1 + num2);
         }
         break;
      case 2:
         printf("You have chosen Subtraction.\n");
         num1 = rand() % 100;
         num2 = rand() % 100;
         printf("What is %d - %d? ", num1, num2);
         scanf("%d", &result);
         if (result == num1 - num2) {
            printf("Correct!\n");
         } else {
            printf("Incorrect. The answer is %d.\n", num1 - num2);
         }
         break;
      case 3:
         printf("You have chosen Division.\n");
         num1 = rand() % 100;
         num2 = rand() % 10 + 1;
         printf("What is %d / %d (rounded to two decimal places)? ", num1, num2);
         scanf("%f", &answer);
         if (answer == roundf((float)num1/num2 * 100) / 100) {
            printf("Correct!\n");
         } else {
            printf("Incorrect. The answer is %.2f.\n", (float)num1/num2);
         }
         break;
      case 4:
         printf("You have chosen Multiplication.\n");
         num1 = rand() % 20;
         num2 = rand() % 20;
         printf("What is %d * %d? ", num1, num2);
         scanf("%d", &result);
         if (result == num1 * num2) {
            printf("Correct!\n");
         } else {
            printf("Incorrect. The answer is %d.\n", num1 * num2);
         }
         break;
      case 5:
         printf("You have chosen Square Root.\n");
         num3 = rand() % 100 + 1;
         printf("What is the square root of %.2f (rounded to two decimal places)? ", num3);
         scanf("%f", &answer);
         if (answer == roundf(sqrt(num3) * 100) / 100) {
            printf("Correct!\n");
         } else {
            printf("Incorrect. The answer is %.2f.\n", sqrt(num3));
         }
         break;
      default:
         printf("Invalid choice.\n");
         return 0;
   }

   return 0;
}