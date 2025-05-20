//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char name[30];
    int choice;
    srand(time(NULL));
    int rand_num = rand() % 3;
    printf("Welcome to the Shape Shifting Adventure Game!\n");
    printf("What is your name?\n");
    scanf("%s", name);
    printf("Hello, %s! You will have to choose your path wisely.\n", name);
    printf("You come across a mysterious crystal ball.\n");
    printf("Do you:\n");
    printf("1. Touch the crystal ball.\n");
    printf("2. Ignore the crystal ball and continue walking.\n");
    scanf("%d", &choice);
    if (choice == 1)
    {
        printf("You feel a surge of power coursing through your veins as you touch the crystal ball.\n");
        printf("Suddenly, you begin to feel strange.\n");
        if (rand_num == 0)
        {
            printf("You transform into a fierce dragon!\n");
            printf("As a dragon, you can fly and breathe fire.\n");
        }
        else if (rand_num == 1)
        {
            printf("You transform into an agile wolf!\n");
            printf("As a wolf, you have heightened senses and incredible speed.\n");
        }
        else
        {
            printf("You transform into a graceful swan!\n");
            printf("As a swan, you can fly and swim with elegance.\n");
        }
        printf("What would you like to do now?\n");
        printf("1. Explore your surroundings.\n");
        printf("2. Return to your human form.\n");
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("You explore your surroundings and find a treasure chest!\n");
            printf("Do you:\n");
            printf("1. Open it.\n");
            printf("2. Leave it alone.\n");
            scanf("%d", &choice);
            if (choice == 1)
            {
                printf("You open the treasure chest and find a rare artifact!\n");
                printf("Congratulations, %s! You completed the game.\n", name);
            }
            else
            {
                printf("You leave the treasure chest alone and continue your adventure.\n");
                printf("Congratulations, %s! You completed the game.\n", name);
            }
        }
        else
        {
            printf("You transform back into your human form and continue your adventure.\n");
            printf("Congratulations, %s! You completed the game.\n", name);
        }
    }
    else
    {
        printf("You ignore the crystal ball and continue walking.\n");
        printf("Suddenly, a group of bandits appear and attack you!\n");
        printf("What do you do?\n");
        printf("1. Fight the bandits.\n");
        printf("2. Run away.\n");
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("You fight off the bandits and continue your adventure.\n");
            printf("Congratulations, %s! You completed the game.\n", name);
        }
        else
        {
            printf("You run away from the bandits, but they catch up to you.\n");
            printf("They take all your belongings and leave you stranded in the wilderness.\n");
            printf("Game over.\n");
        }
    }
    return 0;
}