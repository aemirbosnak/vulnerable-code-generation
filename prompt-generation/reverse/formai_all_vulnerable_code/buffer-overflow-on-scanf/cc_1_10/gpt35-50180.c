//FormAI DATASET v1.0 Category: Math exercise ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int num1, num2, num3, num4, answer, result, count = 0;
    char operator;
    srand(time(0)); // Initializing random number generator with current time

    printf("Welcome to the Math Exercise Program!\n");
    printf("You will be given 10 math problems to solve, let's get started.\n");

    while(count < 10) // Looping for 10 times
    {
        num1 = rand() % 10 + 1; // Generating random numbers
        num2 = rand() % 10 + 1;
        num3 = rand() % 10 + 1;
        num4 = rand() % 10 + 1;

        switch(rand() % 4) // Generating random operator
        {
            case 0:
                operator = '+';
                result = num1 + num2 + num3 + num4;
                break;
            case 1:
                operator = '-';
                result = num1 - num2 - num3 - num4;
                break;
            case 2:
                operator = '*';
                result = num1 * num2 * num3 * num4;
                break;
            case 3:
                operator = '/';
                result = num1 / num2 / num3 / num4;
                break;
        }

        printf("\nProblem %d: %d %c %d %c %d %c %d\n", count+1, num1, operator, num2, operator, num3, operator, num4);
        printf("What is your answer? ");
        scanf("%d", &answer);

        if(answer == result) // Checking for correct answer
        {
            printf("Correct! Great job.\n");
        }
        else
        {
            printf("Incorrect, the correct answer is %d. Better luck next time!\n", result);
        }

        count++; // Incrementing count
    }

    printf("\nYou have completed all the math problems. Good job!");

    return 0;
}