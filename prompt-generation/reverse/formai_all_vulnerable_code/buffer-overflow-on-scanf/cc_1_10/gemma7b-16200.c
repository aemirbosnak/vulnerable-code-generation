//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 10

int main()
{
    int num1, num2, num3, guess, score = 0;
    char name[20];

    printf("Please enter your name: ");
    scanf("%s", name);

    printf("Welcome, %s, to the Guessing Game!\n", name);

    num1 = rand() % MAX_NUM + 1;
    num2 = rand() % MAX_NUM + 1;
    num3 = rand() % MAX_NUM + 1;

    printf("Three numbers have been generated: %d, %d, and %d.\n", num1, num2, num3);

    printf("Guess the three numbers in the order they were generated. Enter your guesses one at a time: ");

    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &guess);

        if (guess == num1)
        {
            score++;
            printf("Correct! You guess the first number.\n");
        }
        else if (guess == num2)
        {
            score++;
            printf("Correct! You guess the second number.\n");
        }
        else if (guess == num3)
        {
            score++;
            printf("Correct! You guess the third number.\n");
        }
        else
        {
            printf("Incorrect. Please try again.\n");
        }
    }

    printf("Your total score is: %d.\n", score);

    return 0;
}