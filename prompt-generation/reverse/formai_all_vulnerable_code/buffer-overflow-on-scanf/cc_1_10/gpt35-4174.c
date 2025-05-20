//FormAI DATASET v1.0 Category: Arithmetic ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
   int num1, num2, op, result, guess, attempts = 0;
   srand(time(NULL));
   num1 = rand() % 100;
   num2 = rand() % 10 + 1;
   printf("Welcome to the Amazing Arithmetic Game!\n");
   printf("Your goal is to guess the result of a random arithmetic operation\n");
   printf("The numbers involved are a random integer and a divisor\n");
   printf("If you guess correctly, you win!\n");
   printf("You have 3 attempts to guess\n");
   printf("Good luck!\n\n");

   op = rand() % 4;
   switch(op) {
      case 0:
         printf("What is %d + %d / %d? ", num1, num1, num2);
         result = num1 + num1 / num2;
         break;
      case 1:
         printf("What is %d - %d * %d? ", num1, num1, num2);
         result = num1 - num1 * num2;
         break;
      case 2:
         printf("What is %d / %d + %d * %d? ", num1, num2, num1, num2);
         result = num1 / num2 + num1 * num2;
         break;
      default:
         printf("What is %d * %d / %d? ", num1, num2, num2);
         result = num1 * num2 / num2;
         break;
   }

   while(attempts < 3) {
      attempts++;
      scanf("%d", &guess);
      if(guess == result) {
         printf("Congratulations! You win!\n");
         break;
      } 
      else if(attempts == 3) {
         printf("Game Over! The answer was: %d\n", result);
      } 
      else {
         printf("Wrong answer! Try again (%d attempt(s) left): ", 3 - attempts);
      }
   }
   return 0;
}