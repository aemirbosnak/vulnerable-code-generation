//FormAI DATASET v1.0 Category: Math exercise ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num1, num2, answer, userAnswer, count = 0;
    char operator;

    printf("\tWelcome to the Math Exercise Program!\n");
    printf("\t************************************\n\n");
    printf("This program will generate math exercises for you to solve.\n");

    while (count < 10) // Generate 10 exercises
    {
        // Generate random numbers and operators
        srand(time(NULL)); // Seed the random number generator
        num1 = rand() % 101; // Generate a number between 0 and 100
        num2 = rand() % 101;
        int operatorIndex = rand() % 4;
        if (operatorIndex == 0)
        {
            operator = '+';
            answer = num1 + num2;
        }
        else if (operatorIndex == 1)
        {
            operator = '-';
            answer = num1 - num2;
        }
        else if (operatorIndex == 2)
        {
            operator = '*';
            answer = num1 * num2;
        }
        else
        {
            operator = '/';
            answer = num1 / num2;
        }

        printf("\nExercise %d:\n", count + 1);
        printf("%d %c %d = ", num1, operator, num2);
        scanf("%d", &userAnswer);

        if (userAnswer == answer)
        {
            printf("Correct! Great job!\n");
        }
        else
        {
            printf("Incorrect. The correct answer is %d.\n", answer);
        }

        count++;
    }

    printf("\nCongratulations! You have completed all 10 exercises.\n");
    printf("Thanks for using the Math Exercise Program! Goodbye!\n");

    return 0;
}