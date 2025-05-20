//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

void displayIntro()
{
    printf("\n\nWelcome to the fun, exciting, and absolutely silly game of ADVENTURELAND!");
    printf("\n\nIn this game, you will encounter many odd characters and even stranger situations. ");
    printf("\n\nYou are on a mission to save the world! Or not, it honestly depends on what you want to do. Are you ready? Let's GO!\n");
}

void wait(int sec)
{
    time_t start_time = time(NULL);
    int current_time = start_time;
    while (current_time - start_time < sec)
    {
        current_time = time(NULL);
    }
}

int choosePath()
{
    int path;

    printf("\nYou are standing at a crossroads. Which path do you want to take, 1 or 2? \n");
    printf("\n1. Path of the warrior.");
    printf("\n2. Path of the health booster.");

    scanf("%d", &path);

    return path;
}

void pathWarrior()
{
    printf("\nYou come across a troll. ");
    printf("\nDo you want to fight the troll?");

    char choice[10];
    scanf("%s", &choice);

    if (strcmp(choice, "yes") == 0)
    {
        printf("\nGreat! Let's fight!");

        int health = 100;
        int trollHealth = 50;
        int trollAttack = 15;

        while (health > 0 && trollHealth > 0)
        {
            printf("\n---------------------------------------------------------------\n");

            int playerAttack = rand() % 25 + 5;
            int trollDefense = rand() % 10 + 1;

            printf("\nYour attack power: %d. Troll's defense power: %d.", playerAttack, trollDefense);

            if (playerAttack > trollDefense)
            {
                printf("\nYou hit the troll! Hurray!");
                trollHealth -= playerAttack;
            }
            else
            {
                printf("\nYou missed the troll. Boo-hoo!");
            }

            int trollAttack = rand() % 20 + 5;
            int playerDefense = rand() % 10 + 1;

            printf("\nTroll attack power: %d. Your defense power: %d.", trollAttack, playerDefense);

            if (trollAttack > playerDefense)
            {
                printf("\nThe troll hits you. Ouch!");
                health -= trollAttack;
            }
            else
            {
                printf("\nYou dodged the troll's attack.");
            }

            printf("\nYour health: %d. Troll's health: %d.", health, trollHealth);

            wait(1);
        }

        if (health <= 0)
        {
            printf("\nYou lost the battle. Better luck next time!");
        }
        else
        {
            printf("\nYou defeated the troll! Congratulations!");
        }
    }
    else
    {
        printf("\nYou chicken out and run back to the crossroads.");
    }
}

void pathHealthBooster()
{
    printf("\nYou come across a potion that will boost your health. ");
    printf("\nWould you like to drink it?");

    char choice[10];
    scanf("%s", &choice);

    if (strcmp(choice, "yes") == 0)
    {
        printf("\nYou choose to drink the potion.");

        int health = rand() % 50 + 50;

        printf("\nYour health is now %d.", health);
    }
    else
    {
        printf("\nYou rather lose health than drink something you don't know the origin of. You move back to the crossroads.");
    }
}

int main()
{
    srand(time(NULL));
    displayIntro();

    int path = choosePath();

    if (path == 1)
    {
        pathWarrior();
    }
    else if (path == 2)
    {
        pathHealthBooster();
    }
    else
    {
        printf("\nInvalid choice. You just sit there and contemplate your decisions.");
    }
    return 0;
}