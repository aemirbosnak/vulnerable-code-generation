//FormAI DATASET v1.0 Category: Arithmetic ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   
   int num1, num2, result, choice;
   char operator;
   srand(time(NULL));
   
   printf("Welcome to the math quiz game!\n");
   printf("Press 1 for addition\n");
   printf("Press 2 for subtraction\n");
   printf("Press 3 for multiplication\n");
   printf("Press 4 for division\n");
   
   scanf("%d", &choice);
   
   switch (choice) {
      case 1: 
         operator = '+';
         num1 = rand() % 100;
         num2 = rand() % 100;
         result = num1 + num2;
         break;
         
      case 2: 
         operator = '-';
         num1 = rand() % 1000;
         num2 = rand() % 500;
         result = num1 - num2;
         break;
         
      case 3: 
         operator = '*';
         num1 = rand() % 50;
         num2 = rand() % 50;
         result = num1 * num2;
         break;
         
      case 4: 
         operator = '/';
         num1 = rand() % 500;
         do {
            num2 = rand() % 100;
         } while (num2 == 0);
         result = num1 / num2;
         break;
         
      default:
         printf("Invalid choice. Try again.\n");
         return 0;
         break; 
  }
   
   printf("What is %d %c %d?\n", num1, operator, num2);   
   int user_result;
   scanf("%d", &user_result);
   
   if (user_result == result) {
      printf("You're a math genius! You got it right!\n");
   } else {
      printf("Oops! Sorry, the correct answer is %d\n", result);
   } 

   return 0;
}