//FormAI DATASET v1.0 Category: Math exercise ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("************************************************************\n");
    printf("*            Welcome to the Math Exercise Program          *\n");
    printf("************************************************************\n");

    srand(time(NULL));

    int count = 0;
    int correctAnswers = 0;
    int incorrectAnswers = 0;

    while (count < 10)
    {
        int num1 = rand() % 10;
        int num2 = rand() % 10;
        char operator = rand() % 3 == 0 ? '+' : rand() % 2 == 0 ? '-' : '*';

        int answer;
        printf("Question %d: What is %d %c %d? \n", count+1, num1, operator, num2);
        scanf("%d", &answer);

        int actualAnswer;
        switch (operator)
        {
            case '+':
                actualAnswer = num1 + num2;
                break;
            case '-':
                actualAnswer = num1 - num2;
                break;
            case '*':
                actualAnswer = num1 * num2;
                break;
        }

        if (answer == actualAnswer) 
        {
            printf("Correct! %d %c %d = %d\n", num1, operator, num2, actualAnswer);
            correctAnswers++;
        } 
        else 
        {
            printf("Incorrect. %d %c %d = %d, not %d\n", num1, operator, num2, actualAnswer, answer);
            incorrectAnswers++;
        }
        printf("\n");
        count++;
    }

    printf("************************************************************\n");
    printf("*                        Results                           *\n");
    printf("************************************************************\n");
    printf("Total questions: %d\n", count);
    printf("Correct answers: %d\n", correctAnswers);
    printf("Incorrect answers: %d\n", incorrectAnswers);

    if (correctAnswers > 7) 
    {
        printf("Congratulations! You are a math whiz!\n");
    } 
    else 
    {
        printf("Don't worry, you can always practice to improve your math skills.\n");
    }

    return 0;
}