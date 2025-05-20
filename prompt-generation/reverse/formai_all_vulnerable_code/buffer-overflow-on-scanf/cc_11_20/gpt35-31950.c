//FormAI DATASET v1.0 Category: Math exercise ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

   srand(time(NULL));

   printf("Welcome to the Math Exercise program! Let's test your skills!\n");

   int num1, num2, answer, userAnswer, mode, correctAnswers = 0, totalQuestions = 0;

   printf("Please select a mode:\n");
   printf("1. Addition\n");
   printf("2. Subtraction\n");
   printf("3. Multiplication\n");
   printf("4. Division\n");
   printf("Enter your choice: ");
   scanf("%d", &mode);

   while(mode < 1 || mode > 4) {
      printf("Invalid mode selected. Please try again.\n");
      printf("Enter your choice: ");
      scanf("%d", &mode);
   }

   printf("Good choice! You have selected mode %d.\n", mode);

   while(1) {

      if(totalQuestions % 10 == 0 && totalQuestions != 0) {
         printf("You have completed %d questions and got %d correct.\n", totalQuestions, correctAnswers);

         char choice;

         printf("Would you like to continue? (y/n): ");
         scanf(" %c", &choice);

         if(choice == 'n' || choice == 'N') {
            printf("Thanks for playing! Goodbye.\n");

            return 0;
         }
      }

      printf("Question %d: ", totalQuestions + 1);

      if(mode == 1) {
         num1 = rand() % 100;
         num2 = rand() % 100;
         answer = num1 + num2;

         printf("%d + %d = ", num1, num2);
      }

      else if(mode == 2) {
         num1 = rand() % 100;
         num2 = rand() % 100;

         if(num1 < num2) {
            int temp = num1;
            num1 = num2;
            num2 = temp;
         }

         answer = num1 - num2;

         printf("%d - %d = ", num1, num2);
      }

      else if(mode == 3) {
         num1 = rand() % 10;
         num2 = rand() % 10;
         answer = num1 * num2;

         printf("%d x %d = ", num1, num2);
      }

      else {
         num1 = rand() % 10;
         num2 = rand() % 10;

         while(num2 == 0) {
            num2 = rand() % 10;
         }

         answer = num1 / num2;

         printf("%d / %d = ", num1, num2);
      }

      scanf("%d", &userAnswer);

      if(userAnswer == answer) {
         printf("Correct! Well done.\n");
         correctAnswers++;
      }

      else {
         printf("Incorrect. The answer was %d.\n", answer);
      }

      totalQuestions++;
   }

   return 0;
}