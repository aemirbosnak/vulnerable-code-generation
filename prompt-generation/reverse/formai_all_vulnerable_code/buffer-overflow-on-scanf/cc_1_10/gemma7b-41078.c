//Gemma-7B DATASET v1.0 Category: Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void play_game(void)
{
    char name[20];
    int score = 0;
    char answer;

    printf("Welcome to the Quiz Game, %s!\n", name);
    printf("Please answer the following questions:\n");

    // Question 1
    printf("What is the capital of France?\n");
    scanf(" %c", &answer);
    if (answer == 'r')
    {
        score++;
    }

    // Question 2
    printf("Which scientist invented the theory of relativity?\n");
    scanf(" %c", &answer);
    if (answer == 'a')
    {
        score++;
    }

    // Question 3
    printf("Which planet is known for its many volcanoes?\n");
    scanf(" %c", &answer);
    if (answer == 'v')
    {
        score++;
    }

    // Question 4
    printf("What is the meaning of the word 'entrepreneur'\n");
    scanf(" %c", &answer);
    if (answer == 'e')
    {
        score++;
    }

    // Question 5
    printf("What is the sound of one hand clapping?\n");
    scanf(" %c", &answer);
    if (answer == 's')
    {
        score++;
    }

    // Final Score
    printf("Your final score is: %d\n", score);

    if (score >= 5)
    {
        printf("Congratulations! You are a winner!\n");
    }
    else
    {
        printf("Sorry, you lose. Better luck next time.\n");
    }

    return;
}

int main(void)
{
    play_game();

    return 0;
}