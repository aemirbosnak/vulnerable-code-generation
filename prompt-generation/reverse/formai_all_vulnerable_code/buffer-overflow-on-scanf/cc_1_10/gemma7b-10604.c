//Gemma-7B DATASET v1.0 Category: Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 0;
    int score = 0;
    int lives = 3;
    char name[20];

    printf("What is your name, traveler?\n");
    scanf("%s", name);

    printf("Welcome to the wacky world of QuizMaster, %s! Prepare for a mind-bending journey!\n", name);

    while (lives > 0)
    {
        n = rand() % 10 + 1;
        score += n;

        printf("Question: What is the capital of France?\n");
        printf("a) Paris\n");
        printf("b) Rome\n");
        printf("c) Berlin\n");
        printf("Please choose an answer: ");

        int answer = getchar();

        switch (answer)
        {
            case 'a':
                printf("Correct! You've gained %d points.\n", n);
                break;
            case 'b':
                printf("Incorrect. The answer is Paris. You lose a life.\n");
                lives--;
                break;
            case 'c':
                printf("Incorrect. The answer is Paris. You lose a life.\n");
                lives--;
                break;
            default:
                printf("Invalid input. Please try again.\n");
                break;
        }
    }

    printf("Game over, %s. You scored a total of %d points.\n", name, score);

    return 0;
}