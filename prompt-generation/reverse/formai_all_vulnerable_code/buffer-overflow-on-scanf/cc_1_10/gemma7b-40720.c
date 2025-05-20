//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int choice, score = 0, lives = 3;
    char name[20];

    printf("Welcome to the labyrinth of the lost city.\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    printf("Greetings, %s. You have a score of %d and %d lives left.\n", name, score, lives);

    while (lives > 0)
    {
        printf("You are at a crossroads. Choose your path:\n");
        printf("1. The red path (risk of high reward)\n");
        printf("2. The blue path (guaranteed safety)\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                // Code for the red path
                score += rand() % 10;
                printf("You chose the red path and gained %d points!\n", score);
                break;
            case 2:
                // Code for the blue path
                score += rand() % 5;
                printf("You chose the blue path and gained %d points!\n", score);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        printf("Your current score is: %d\n", score);

        if (score >= 100)
        {
            lives = 0;
            printf("Congratulations, %s! You have won the game!\n", name);
        }
    }

    if (lives == 0)
    {
        printf("Sorry, %s. You have lost the game.\n", name);
    }

    return;
}