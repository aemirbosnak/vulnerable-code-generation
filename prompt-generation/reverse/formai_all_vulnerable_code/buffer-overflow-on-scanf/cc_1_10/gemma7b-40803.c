//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("clear");
    printf("Welcome to the bizarre game of Qwibble!\n");
    printf("The objective is to be the last frog standing!\n");
    printf("To do this, you must answer questions correctly.\n");

    int score = 0;
    char answer;

    // Question 1
    printf("What is the sound a frog makes?\n");
    printf("a) Honk\n");
    printf("b) Squeak\n");
    printf("c) Ribbet\n");
    scanf(" %c", &answer);

    if (answer == 'c')
    {
        score++;
        printf("Correct! You have earned a point.\n");
    }
    else
    {
        printf("Incorrect. The answer is c.\n");
    }

    // Question 2
    printf("What is the most common color of a frog?\n");
    printf("a) Red\n");
    printf("b) Green\n");
    printf("c) Blue\n");
    scanf(" %c", &answer);

    if (answer == 'b')
    {
        score++;
        printf("Correct! You have earned a point.\n");
    }
    else
    {
        printf("Incorrect. The answer is b.\n");
    }

    // Question 3
    printf("What is the scientific name for the frog?\n");
    printf("a) Rana temporaria\n");
    printf("b) Bufo marinus\n");
    printf("c) Hyla arborea\n");
    scanf(" %c", &answer);

    if (answer == 'a')
    {
        score++;
        printf("Correct! You have earned a point.\n");
    }
    else
    {
        printf("Incorrect. The answer is a.\n");
    }

    // Final score
    printf("Your final score is: %d\n", score);

    return 0;
}