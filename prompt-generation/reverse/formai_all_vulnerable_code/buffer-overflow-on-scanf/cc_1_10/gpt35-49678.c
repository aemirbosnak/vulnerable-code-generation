//FormAI DATASET v1.0 Category: Math exercise ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int a, b, c, answer;
    char operator;
    srand(time(NULL));
    
    printf("Welcome to Math Exercise!\n");
    printf("Please enter the number of questions you'd like to answer: ");
    scanf("%d", &c);
    printf("\n");

    for(int i = 1; i <= c; i++)
    {
         a = rand() % 101;
         b = rand() % 101;
         operator = "+-*"[rand() % 3];

         if(operator == '+')
         {
             printf("%d + %d = ", a, b);
             answer = a + b;
         }
         else if(operator == '-')
         {
             printf("%d - %d = ", a, b);
             answer = a - b;
         }
         else
         {
             printf("%d * %d = ", a, b);
             answer = a * b;
         }

         int user_answer;
         scanf("%d", &user_answer);

         if(user_answer == answer)
         {
             printf("Correct!\n\n");
         }
         else
         {
             printf("Incorrect! The answer is %d.\n\n", answer);
         }
    }

    printf("Congratulations! You have completed all the questions.\n");

    return 0;
}