//FormAI DATASET v1.0 Category: Math exercise ; Style: excited
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    printf("***********************************************\n");
    printf("*** Welcome to the Exciting Math Exercise! ***\n");
    printf("***********************************************\n\n");

    printf("This program will provide you with a series of challenging math problems to solve.\n");
    printf("You must solve each problem within a time limit of 30 seconds.\n\n");

    printf("Are you ready? Let's go!\n\n");

    int score = 0;
    char answer;

    // Problem 1
    printf("1. What is the square root of 256?\n");
    printf("A. 10\nB. 16\nC. 20\nD. 32\n");
    printf("Your answer: ");
    scanf(" %c", &answer);
    if(answer == 'B' || answer == 'b')
    {
        printf("Correct!\n");
        score++;
    }
    else
    {
        printf("Wrong answer! The correct answer is B.\n");
    }

    // Problem 2
    printf("\n2. Evaluate the expression: (5 + 3*2) / 2\n");
    printf("A. 4\nB. 5\nC. 6\nD. 7\n");
    printf("Your answer: ");
    scanf(" %c", &answer);
    if(answer == 'C' || answer == 'c')
    {
        printf("Correct!\n");
        score++;
    }
    else
    {
        printf("Wrong answer! The correct answer is C.\n");
    }

    // Problem 3
    printf("\n3. What is the value of cos(pi/3)?\n");
    printf("A. 1\nB. 1/2\nC. sqrt(3)/2\nD. 0\n");
    printf("Your answer: ");
    scanf(" %c", &answer);
    if(answer == 'C' || answer == 'c')
    {
        printf("Correct!\n");
        score++;
    }
    else
    {
        printf("Wrong answer! The correct answer is C.\n");
    }

    // Problem 4
    printf("\n4. Simplify the expression: 2x + 3y - 4x + 5y\n");
    printf("A. -2x - 2y\nB. 2x + 2y\nC. -2x + 8y\nD. 2x - 8y\n");
    printf("Your answer: ");
    scanf(" %c", &answer);
    if(answer == 'B' || answer == 'b')
    {
        printf("Correct!\n");
        score++;
    }
    else
    {
        printf("Wrong answer! The correct answer is B.\n");
    }

    // Problem 5
    printf("\n5. Find the value of x that satisfies the equation: 3x - 15 = 0\n");
    printf("A. 5\nB. 10\nC. 15\nD. 20\n");
    printf("Your answer: ");
    scanf(" %c", &answer);
    if(answer == 'C' || answer == 'c')
    {
        printf("Correct!\n");
        score++;
    }
    else
    {
        printf("Wrong answer! The correct answer is C.\n");
    }

    printf("\n***********************************************\n");
    printf("*** Your final score is %d out of 5! ***\n", score);
    printf("***********************************************\n");

    return 0;
}