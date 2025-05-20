//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char choice[10];
    int item1 = 0;
    int item2 = 0;
    int item3 = 0;

    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You find yourself in a dark and creepy forest...\n\n");
    printf("You see three paths in front of you. Which do you choose?\n");
    printf("1. Path of the Warrior\n");
    printf("2. Path of the Mage\n");
    printf("3. Path of the Rogue\n");
    printf("Enter your choice (1, 2, or 3): ");

    fgets(choice, sizeof(choice), stdin);
    sscanf(choice, "%d", &choice);

    if (choice == 1)
    {
        printf("\nYou have chosen the Path of the Warrior.\n");
        printf("You see a sword on the ground. Do you pick it up?\n");
        printf("1. Yes\n");
        printf("2. No\n");
        printf("Enter your choice (1 or 2): ");

        fgets(choice, sizeof(choice), stdin);
        sscanf(choice, "%d", &choice);

        if (choice == 1)
        {
            printf("\nYou picked up the sword.\n");
            item1 = 1;
        }
        else if (choice == 2)
        {
            printf("\nYou decide to leave the sword behind.\n");
        }
        else
        {
            printf("\nInvalid choice. Please try again.\n");
            return 0;
        }

        printf("\nYou continue down the path and encounter a monster!\n");
        printf("What do you do?\n");
        printf("1. Fight\n");
        printf("2. Flee\n");
        printf("Enter your choice (1 or 2): ");

        fgets(choice, sizeof(choice), stdin);
        sscanf(choice, "%d", &choice);

        if (choice == 1)
        {
            if (item1 == 1)
            {
                printf("\nYou use your sword to defeat the monster!\n");
            }
            else
            {
                printf("\nYou try to fight the monster without a weapon and fail.\n");
                printf("The monster kills you. Game over.\n");
                return 0;
            }
        }
        else if (choice == 2)
        {
            printf("\nYou decide to flee.\n");
            printf("As you turn to run, the monster attacks you from behind.\n");
            printf("You are killed. Game over.\n");
            return 0;
        }
        else
        {
            printf("\nInvalid choice. Please try again.\n");
            return 0;
        }

        printf("\nCongratulations, you have defeated the monster and completed the Path of the Warrior!\n");
    }
    else if (choice == 2)
    {
        printf("\nYou have chosen the Path of the Mage.\n");
        printf("You see a staff on the ground. Do you pick it up?\n");
        printf("1. Yes\n");
        printf("2. No\n");
        printf("Enter your choice (1 or 2): ");

        fgets(choice, sizeof(choice), stdin);
        sscanf(choice, "%d", &choice);

        if (choice == 1)
        {
            printf("\nYou picked up the staff.\n");
            item2 = 1;
        }
        else if (choice == 2)
        {
            printf("\nYou decide to leave the staff behind.\n");
        }
        else
        {
            printf("\nInvalid choice. Please try again.\n");
            return 0;
        }

        printf("\nYou continue down the path and encounter a monster!\n");
        printf("What do you do?\n");
        printf("1. Cast a spell\n");
        printf("2. Flee\n");
        printf("Enter your choice (1 or 2): ");

        fgets(choice, sizeof(choice), stdin);
        sscanf(choice, "%d", &choice);

        if (choice == 1)
        {
            if (item2 == 1)
            {
                printf("\nYou cast a powerful spell and defeat the monster!\n");
            }
            else
            {
                printf("\nYou try to cast a spell without a staff and fail.\n");
                printf("The monster kills you. Game over.\n");
                return 0;
            }
        }
        else if (choice == 2)
        {
            printf("\nYou decide to flee.\n");
            printf("As you turn to run, the monster attacks you from behind.\n");
            printf("You are killed. Game over.\n");
            return 0;
        }
        else
        {
            printf("\nInvalid choice. Please try again.\n");
            return 0;
        }

        printf("\nCongratulations, you have defeated the monster and completed the Path of the Mage!\n");
    }
    else if (choice == 3)
    {
        printf("\nYou have chosen the Path of the Rogue.\n");
        printf("You see a bow and arrow on the ground. Do you pick it up?\n");
        printf("1. Yes\n");
        printf("2. No\n");
        printf("Enter your choice (1 or 2): ");

        fgets(choice, sizeof(choice), stdin);
        sscanf(choice, "%d", &choice);

        if (choice == 1)
        {
            printf("\nYou picked up the bow and arrow.\n");
            item3 = 1;
        }
        else if (choice == 2)
        {
            printf("\nYou decide to leave the bow and arrow behind.\n");
        }
        else
        {
            printf("\nInvalid choice. Please try again.\n");
            return 0;
        }

        printf("\nYou continue down the path and encounter a monster!\n");
        printf("What do you do?\n");
        printf("1. Shoot the monster with your arrow\n");
        printf("2. Flee\n");
        printf("Enter your choice (1 or 2): ");

        fgets(choice, sizeof(choice), stdin);
        sscanf(choice, "%d", &choice);

        if (choice == 1)
        {
            if (item3 == 1)
            {
                printf("\nYou shoot the monster with your arrow and defeat it!\n");
            }
            else
            {
                printf("\nYou try to shoot the monster without a bow and arrow and fail.\n");
                printf("The monster kills you. Game over.\n");
                return 0;
            }
        }
        else if (choice == 2)
        {
            printf("\nYou decide to flee.\n");
            printf("As you turn to run, the monster attacks you from behind.\n");
            printf("You are killed. Game over.\n");
            return 0;
        }
        else
        {
            printf("\nInvalid choice. Please try again.\n");
            return 0;
        }

        printf("\nCongratulations, you have defeated the monster and completed the Path of the Rogue!\n");
    }
    else
    {
        printf("\nInvalid choice. Please try again.\n");
        return 0;
    }

    printf("\nThanks for playing the Text-Based Adventure Game!\n");
    return 0;
}