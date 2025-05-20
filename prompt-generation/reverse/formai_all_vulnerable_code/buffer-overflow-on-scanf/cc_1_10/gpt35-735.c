//FormAI DATASET v1.0 Category: Math exercise ; Style: Claude Shannon
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    printf("Welcome to the Math Quiz!\n");
    printf("Please answer the following question:\n");

    int num1 = rand() % 100;
    int num2 = rand() % 100;
    int answer, userAnswer;

    printf("What is the result of %d + %d?\n", num1, num2);
    answer = num1 + num2;
    scanf("%d", &userAnswer);

    if(answer == userAnswer)
    {
        printf("Correct!\n");
    }
    else
    {
        printf("Incorrect! The correct answer is %d.\n", answer);
    }

    printf("Next question:\n");

    num1 = rand() % 100;
    num2 = rand() % 100;

    printf("What is the result of %d - %d?\n", num1, num2);
    answer = num1 - num2;
    scanf("%d", &userAnswer);

    if(answer == userAnswer)
    {
        printf("Correct!\n");
    }
    else
    {
        printf("Incorrect! The correct answer is %d.\n", answer);
    }

    printf("Next question:\n");

    num1 = rand() % 10;
    num2 = rand() % 10;

    printf("What is the result of %d * %d?\n", num1, num2);
    answer = num1 * num2;
    scanf("%d", &userAnswer);

    if(answer == userAnswer)
    {
        printf("Correct!\n");
    }
    else
    {
        printf("Incorrect! The correct answer is %d.\n", answer);
    }

    printf("Next question:\n");

    num1 = rand() % 10;
    num2 = rand() % 10;

    printf("What is the result of %d / %d?\n", num1, num2);
    answer = num1 / num2;
    scanf("%d", &userAnswer);

    if(answer == userAnswer)
    {
        printf("Correct!\n");
    }
    else
    {
        printf("Incorrect! The correct answer is %d.\n", answer);
    }

    printf("Thank you for taking the Math Quiz!\n");

    return 0;
}