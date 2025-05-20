//FormAI DATASET v1.0 Category: Math exercise ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
   srand(time(0));
   printf("Welcome to the wackiest math exercise program ever!\n\n");
   printf("We're going to test your math skills with some random calculations!\n");
   printf("Are you ready? Let's go!\n\n");
   
   int score = 0; //initialize score to 0
   
   for(int i=0; i<10; i++) //ask 10 questions
   {
       int num1 = rand() % 10 + 1; //generate random number between 1 and 10
       int num2 = rand() % 10 + 1;
       int result;
       char op;
       
       switch(rand() % 4) //generate random operator
       {
           case 0:
               op = '+';
               result = num1 + num2;
               break;
           case 1:
               op = '-';
               result = num1 - num2;
               break;
           case 2:
               op = '*';
               result = num1 * num2;
               break;
           case 3:
               op = '/';
               result = num1 / num2;
               break;
       }
       
       printf("Question %d: %d %c %d = ", i+1, num1, op, num2); //ask question
       int answer;
       scanf("%d", &answer); //get user input
        
       if(answer == result) //check if answer is correct
       {
           printf("Correct!\n");
           score++;
       }
       else
       {
           printf("Wrong! The answer is %d\n", result);
       }
   }
   
   printf("\nCongratulations! You finished the exercise. Let's see how well you did.\n");
   printf("Your final score is %d out of 10.\n", score);
   
   if(score >= 8)
   {
       printf("Wow! You're a math genius!\n");
   }
   else if(score >= 5)
   { 
       printf("Not bad! You have some math skills!\n");
   }
   else 
   {
       printf("Oops! It looks like you need to practice more!\n");
   }
   
   return 0;
}