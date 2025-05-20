//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
void printIntro();
int choosePath();
void fight();
void flee();

int main()
{
    srand(time(NULL)); // seed for random number generator
    
    printIntro(); // print game introduction
    
    int path = choosePath(); // player chooses path
    
    if (path == 1) // if player chooses path 1, they must fight
    {
        fight();
    }
    else // if player chooses path 2, they can choose to fight or flee
    {
        printf("\nYou see a large, menacing monster blocking your path. What do you do?\n");
        printf("1. Fight\n");
        printf("2. Flee\n");
        
        int choice;
        scanf("%d", &choice); // get player's choice
        
        if (choice == 1)
        {
            fight();
        }
        else
        {
            flee();
        }
    }
    
    return 0;
}

// function to print game introduction
void printIntro()
{
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You find yourself in a dark, mysterious forest and must choose a path to follow.\n");
    printf("You can either:\n");
    printf("1. Choose the path with no obstacles, but a tough boss battle at the end.\n");
    printf("2. Choose the path with a challenging obstacle, but the chance to choose how to handle it.\n");
    printf("Choose wisely...\n\n");
}

// function for player to choose path
int choosePath()
{
    printf("Which path will you take?\n");
    printf("1. Path with tough boss battle at the end\n");
    printf("2. Path with challenging obstacle and choice to fight or flee\n");
    
    int choice;
    scanf("%d", &choice); // get player's choice
    
    return choice;
}

// function for player to fight boss
void fight()
{
    printf("\nYou continue down the path and reach a clearing with a large, imposing boss blocking your way.\n");
    printf("You must fight to move on!\n");
    
    int playerHealth = 100; // player starts with 100 health
    int bossHealth = 150; // boss starts with 150 health
    
    while (playerHealth > 0 && bossHealth > 0) // fight continues until one party wins
    {
        int playerDamage = rand() % 20 + 10; // generate random damage for player
        int bossDamage = rand() % 25 + 15; // generate random damage for boss
        
        printf("\nPLAYER HEALTH: %d\n", playerHealth);
        printf("BOSS HEALTH: %d\n", bossHealth);
        printf("\nWhat will you do?\n");
        printf("1. Attack\n");
        printf("2. Defend\n");

        int choice;
        scanf("%d", &choice); // get player's choice

        if (choice == 1)
        {
            bossHealth -= playerDamage;
            printf("You dealt %d damage to the boss!\n", playerDamage);
        }
        else
        {
            printf("You defend yourself!\n");
        }

        if (bossHealth <= 0) // if boss defeated, player wins
        {
            printf("\nCONGRATULATIONS! You defeated the boss and completed the game!\n");
        }
        else
        {
            playerHealth -= bossDamage;
            printf("The boss dealt %d damage to you!\n", bossDamage);

            if (playerHealth <= 0) // if player defeated, game over
            {
                printf("\nGAME OVER! You were defeated by the boss. Try again!\n");
            }
        }
    }
}

// function for player to flee
void flee()
{
    printf("\nYou attempt to flee from the monster...\n");
    
    int fleeChance = rand() % 2; // 50% chance to successfully flee
    
    if (fleeChance == 0)
    {
        printf("You successfully flee and continue along the path.\n");
        printf("As you walk, you come across a chest with treasure inside!\n");
        printf("Congratulations! You have completed the game.\n");
    }
    else
    {
        printf("The monster catches up to you and you must fight to survive!\n");
        fight(); // if flee fails, player must fight
    }
}