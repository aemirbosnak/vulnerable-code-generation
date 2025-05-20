//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char playerName[20];
    int health = 100;
    int damage = 0;
    char choice1[20], choice2[20], choice3[20], choice4[20], choice5[20];

    // Introduction
    printf("Welcome to the Adventure Game!\n");
    printf("What is your name adventurer? ");
    scanf("%s", playerName);

    // Setting the scene
    printf("\n%s, you find yourself standing in front of a dark cave.\n", playerName);
    printf("You know that deep inside the cave lies a treasure chest filled with gold coins.\n");
    printf("But beware! The cave is full of dangerous creatures and traps.\n");
    printf("Do you dare to enter the cave?\n");

    // Giving the player options
    printf("\n%s, what do you want to do?\n", playerName);
    printf("1. Enter the cave.\n");
    printf("2. Turn back and leave.\n");

    // Player decision 1
    scanf("%s", choice1);
    if (strcmp(choice1, "1") == 0)
    {
        printf("\nYou enter the cave and almost immediately something jumps out at you!\n");
        printf("It's a bat! Do you want to fight it or run away?\n");

        // Player decision 2
        printf("\n%s, what do you want to do?\n", playerName);
        printf("1. Fight the bat.\n");
        printf("2. Run away.\n");
        scanf("%s", choice2);
        if (strcmp(choice2, "1") == 0)
        {
            printf("\nYou fight the bat with your bare hands and manage to kill it!\n");
            printf("But it wasn't without consequence. You lost some health points.\n");
            health -= 20;

            // Player decision 3
            printf("\n%s, you see two paths. Which one do you want to take?\n", playerName);
            printf("1. Take the left path.\n");
            printf("2. Take the right path.\n");
            scanf("%s", choice3);
            if (strcmp(choice3, "1") == 0)
            {
                printf("\nYou take the left path and encounter a giant spider!\n");
                printf("Do you want to fight it or use a health potion?\n");

                // Player decision 4
                printf("\n%s, what do you want to do?\n", playerName);
                printf("1. Fight the spider.\n");
                printf("2. Use a health potion.\n");
                scanf("%s", choice4);
                if (strcmp(choice4, "1") == 0)
                {
                    printf("\nYou fight the spider and manage to kill it!\n");
                    printf("But once again, you lost some health points.\n");
                    health -= 30;

                    // Player decision 5
                    printf("\n%s, you see another two paths. Which one do you want to take?\n", playerName);
                    printf("1. Take the left path.\n");
                    printf("2. Take the right path.\n");
                    scanf("%s", choice5);
                    if (strcmp(choice5, "1") == 0)
                    {
                        printf("\nYou take the left path and finally find the treasure chest!\n");
                        printf("You open it and find it filled with gold coins!\n");
                        printf("Congratulations, %s! You have won the game!\n", playerName);
                    }
                    else if (strcmp(choice5, "2") == 0)
                    {
                        printf("\nYou take the right path and accidentally trigger a trap!\n");
                        printf("You lose all your remaining health points and sadly, the game is over.\n");
                    }
                    else
                    {
                        printf("\n%s, That was not a valid choice. The game is over!\n", playerName);
                    }
                }
                else if (strcmp(choice4, "2") == 0)
                {
                    printf("\nYou use a health potion and feel better!\n");
                    health += 30;
                }
                else
                {
                    printf("\n%s, That was not a valid choice. The game is over!\n", playerName);
                }
            }
            else if (strcmp(choice3, "2") == 0)
            {
                printf("\nYou take the right path and encounter a group of angry goblins!\n");
                printf("Do you want to fight them or sneak past them?\n");

                // Player decision 4 (different scenario)
                printf("\n%s, what do you want to do?\n", playerName);
                printf("1. Fight the goblins.\n");
                printf("2. Sneak past them.\n");
                scanf("%s", choice4);
                if (strcmp(choice4, "1") == 0)
                {
                    printf("\nYou fight the goblins and manage to kill them all!\n");
                    printf("But you took a lot of damage and lost some health points.\n");
                    health -= 50;

                    // Player decision 5 (same options as above)
                    printf("\n%s, you see another two paths. Which one do you want to take?\n", playerName);
                    printf("1. Take the left path.\n");
                    printf("2. Take the right path.\n");
                    scanf("%s", choice5);
                    if (strcmp(choice5, "1") == 0)
                    {
                        printf("\nYou take the left path and finally find the treasure chest!\n");
                        printf("You open it and find it filled with gold coins!\n");
                        printf("Congratulations, %s! You have won the game!\n", playerName);
                    }
                    else if (strcmp(choice5, "2") == 0)
                    {
                        printf("\nYou take the right path and accidentally trigger a trap!\n");
                        printf("You lose all your remaining health points and sadly, the game is over.\n");
                    }
                    else
                    {
                        printf("\n%s, That was not a valid choice. The game is over!\n", playerName);
                    }
                }
                else if (strcmp(choice4, "2") == 0)
                {
                    printf("\nYou try to sneak past the goblins but they spot you!\n");
                    printf("You lose some health points from their attacks.\n");
                    health -= 40;
                }
                else
                {
                    printf("\n%s, That was not a valid choice. The game is over!\n", playerName);
                }
            }
            else
            {
                printf("\n%s, That was not a valid choice. The game is over!\n", playerName);
            }
        }
        else if (strcmp(choice2, "2") == 0)
        {
            printf("\nYou try to run away but the bat catches up with you and attacks!\n");
            printf("You lose some health points.\n");
            health -= 10;
        }
        else
        {
            printf("\n%s, That was not a valid choice. The game is over!\n", playerName);
        }
    }
    else if (strcmp(choice1, "2") == 0)
    {
        printf("\n%s, you decide to turn back and leave the cave.\n", playerName);
        printf("You return to your village and live a peaceful life.\n");
        printf("Congratulations, you have won the game!\n");
    }
    else
    {
        printf("\n%s, That was not a valid choice. The game is over!\n", playerName);
    }

    // Check player's final health points
    if (health <= 0)
    {
        printf("\n%s, you have died in the game. Better luck next time!\n", playerName);
    }
    else if (health > 0 && health <= 50)
    {
        printf("\n%s, you have won the game, but you didn't finish with full health. Try again!\n", playerName);
    }
    else if (health > 50 && health < 100)
    {
        printf("\n%s, you have won the game and finished with almost full health. Well done!\n", playerName);
    }
    else if (health == 100)
    {
        printf("\n%s, you have won the game and finished with full health. Congratulations, you are a true adventurer!\n", playerName);
    }

    return 0;
}