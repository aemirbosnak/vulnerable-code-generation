//Gemma-7B DATASET v1.0 Category: Game ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int score = 0;
    char name[20];
    printf("Welcome to the Quiz Game, %s!\n", name);
    printf("Let's see if you can answer these questions:\n");

    // Question 1: What is the meaning of life?
    printf("What is the meaning of life?\n");
    scanf("%s", name);
    if (strcmp(name, "To be happy") == 0)
    {
        score++;
        printf("Correct! You have a high score, %s!\n", name);
    }

    // Question 2: What is the capital of France?
    printf("What is the capital of France?\n");
    scanf("%s", name);
    if (strcmp(name, "Paris") == 0)
    {
        score++;
        printf("Correct! You have a high score, %s!\n", name);
    }

    // Question 3: What is the sound of one hand clapping?
    printf("What is the sound of one hand clapping?\n");
    scanf("%s", name);
    if (strcmp(name, "A clap") == 0)
    {
        score++;
        printf("Correct! You have a high score, %s!\n", name);
    }

    // Final score
    printf("Your final score is: %d\n", score);
    if (score >= 3)
    {
        printf("Congratulations, %s! You are a winner!\n", name);
    }
    else
    {
        printf("Sorry, %s. You have not won.\n", name);
    }

    return 0;
}