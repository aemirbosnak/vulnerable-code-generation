//Falcon-180B DATASET v1.0 Category: Game ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int choice;
    int score = 0;
    char name[20];
    int lives = 3;

    srand(time(NULL));

    printf("Welcome to the Love Adventure Game!\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    printf("\n%s, you are on a quest to find true love.\n", name);
    printf("You have %d lives to complete your journey.\n", lives);
    printf("Choose your path wisely.\n\n");

    while(lives > 0)
    {
        printf("You come across a fork in the road.\n");
        printf("Do you take the path to the left or the right?\n");
        printf("Enter 1 for left or 2 for right: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\nYou take the path to the left.\n");
                printf("You stumble upon a beautiful garden.\n");
                printf("Do you want to explore the garden?\n");
                printf("Enter 1 for yes or 2 for no: ");
                scanf("%d", &choice);

                if(choice == 1)
                {
                    printf("\nYou explore the garden and find a hidden treasure.\n");
                    printf("You gain 10 points!\n");
                    score += 10;
                }
                else
                {
                    printf("\nYou decide not to explore the garden.\n");
                }
                break;

            case 2:
                printf("\nYou take the path to the right.\n");
                printf("You come across a bridge.\n");
                printf("Do you want to cross the bridge?\n");
                printf("Enter 1 for yes or 2 for no: ");
                scanf("%d", &choice);

                if(choice == 1)
                {
                    printf("\nYou cross the bridge and find a magical castle.\n");
                    printf("You gain 20 points!\n");
                    score += 20;
                }
                else
                {
                    printf("\nYou decide not to cross the bridge.\n");
                }
                break;

            default:
                printf("\nInvalid choice.\n");
                lives--;
        }

        printf("\nYour score is %d.\n\n", score);
    }

    if(lives <= 0)
    {
        printf("\nGame over! You have run out of lives.\n");
        printf("%s, you did not find true love this time.\n", name);
    }
    else
    {
        printf("\nCongratulations! You have found true love.\n");
        printf("%s, you and your love live happily ever after.\n", name);
    }

    return 0;
}