//FormAI DATASET v1.0 Category: Arithmetic ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // seed the random number generator

    int num1, num2, answer, userAnswer;
    char operator;
    int score = 0;
    int numQuestions = 10;

    printf("Welcome to the Silly Arithmetic Quiz!\n");
    printf("In this quiz we won't ask you boring math questions, we'll ask you silly ones!\n");
    printf("Ready to start?\n");

    for (int i = 1; i <= numQuestions; i++)
    {
        // generate random numbers between 1 and 100
        num1 = rand() % 100 + 1;
        num2 = rand() % 100 + 1;

        // choose a random silly operator
        switch (rand() % 3)
        {
            case 0:
                operator = '+';
                answer = num1 + num2;
                break;
            case 1:
                operator = '-';
                answer = num1 - num2;
                break;
            case 2:
                operator = '*';
                answer = num1 * num2;
                break;
        }

        printf("Question %d: What is %d %c %d?\n", i, num1, operator, num2);
        printf("Enter your answer: ");
        scanf("%d", &userAnswer);

        if (userAnswer == answer)
        {
            printf("Correct! You get a point!\n");
            score++;
        }
        else
        {
            printf("Wrong! The correct answer is %d.\n", answer);
        }
    }

    printf("Quiz finished!\n");
    printf("You got %d out of %d questions right!\n", score, numQuestions);

    if (score >= 8)
    {
        printf("Wow, you are a math genius!\n");
    }
    else if (score >= 6)
    {
        printf("Not bad, not bad at all. You are definitely smarter than a squirrel!\n");
    }
    else
    {
        printf("Well, let's just say... a potato would probably get a higher score...\n");
    }

    return 0;
}