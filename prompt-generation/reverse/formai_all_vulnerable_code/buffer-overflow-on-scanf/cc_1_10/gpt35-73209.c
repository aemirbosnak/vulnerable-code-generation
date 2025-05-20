//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: synchronous
#include <stdio.h>
#include <string.h>

int main()
{
    char playerName[20];
    char choice;
    int health = 100;
    int score = 0;

    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("What's your name, adventurer? ");
    scanf("%s", playerName);
    printf("\nWelcome, %s! Your adventure begins now.\n", playerName);

    printf("\nYou find yourself in a forest. There are two paths ahead of you: one leads north, the other leads east.\n");
    printf("Which path do you choose (N/E)? ");
    scanf(" %c", &choice);

    if(choice == 'N')
    {
        printf("\nYou follow the path north and come across a clearing. There is a river running through it.\n");
        printf("Do you want to follow the river upstream (U) or downstream (D)? ");
        scanf(" %c", &choice);

        if(choice == 'D')
        {
            printf("\nYou follow the river downstream and soon come across a village. The villagers welcome you and reward you for your bravery.\n");
            health += 50;
            score += 100;
            printf("Your health is now %d and your score is %d.\n", health, score);
        }
        else if(choice == 'U')
        {
            printf("\nYou follow the river upstream and soon come across a group of bandits. They attack you and you lose 50 health.\n");
            health -= 50;
            printf("Your health is now %d.\n", health);
        }
        else
        {
            printf("\nInvalid choice. Please choose either U or D.\n");
        }
    }
    else if(choice == 'E')
    {
        printf("\nYou follow the path east and soon come across a cave entrance. Do you want to enter the cave (Y/N)? ");
        scanf(" %c", &choice);

        if(choice == 'Y')
        {
            printf("\nYou enter the cave and find a treasure chest. ");
            printf("You open the chest and gain 100 score points!\n");
            score += 100;
            printf("Your score is now %d.\n", score);
        }
        else if(choice == 'N')
        {
            printf("\nYou decide not to enter the cave and continue your journey.\n");
        }
        else
        {
            printf("\nInvalid choice. Please choose either Y or N.\n");
        }
    }
    else
    {
        printf("\nInvalid choice. Please choose either N or E.\n");
    }

    printf("\nCongratulations, %s! You have completed your adventure with a score of %d and a health of %d.\n", playerName, score, health);

    return 0;
}