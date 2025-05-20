//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int health = 100, food = 10, water = 10, ammo = 10;
int enemyHealth = 100;
int randNum;

void generateEnemy()
{
    randNum = rand() % 3;
    if (randNum == 0)
    {
        printf("You have encountered a bandit!\n\n");
        enemyHealth = 50;
    }
    else if (randNum == 1)
    {
        printf("You have encountered a zombie!\n\n");
        enemyHealth = 75;
    }
    else
    {
        printf("You have encountered a mutant!\n\n");
        enemyHealth = 100;
    }
}

void attack()
{
    randNum = rand() % 10;
    if (randNum % 2 == 0)
    {
        printf("You hit the enemy!\n");
        enemyHealth -= randNum;
        if (enemyHealth <= 0)
        {
            printf("You have defeated the enemy!\n");
            return;
        }
    }
    else
    {
        printf("You missed the enemy!\n");
    }
    printf("The enemy attacks you!\n");
    randNum = rand() % 10;
    health -= randNum;
    if (health <= 0)
    {
        printf("You have died.\n");
        exit(0);
    }
}

void checkStatus()
{
    printf("Health: %d\nFood: %d\nWater: %d\nAmmo: %d\n", health, food, water, ammo);
}

void rest()
{
    randNum = rand() % 10;
    printf("You rest for a while.\n");
    if (randNum % 2 == 0)
    {
        printf("You feel better.\n");
        health += randNum;
        food -= 1;
        water -= 1;
    }
    else
    {
        printf("You don't feel any better.\n");
        food -= 1;
        water -= 1;
    }
}

void search()
{
    randNum = rand() % 10;
    if (randNum % 2 == 0)
    {
        printf("You find some food and water!\n");
        food += randNum;
        water += randNum;
    }
    else
    {
        printf("You don't find anything.\n");
    }
}

int main()
{
    printf("You are a survivor in a post-apocalyptic world.\n");
    printf("Your goal is to survive as long as possible.\n\n");

    while (1)
    {
        printf("What do you want to do?\n");
        printf("1. Attack\n");
        printf("2. Check status\n");
        printf("3. Rest\n");
        printf("4. Search for supplies\n");
        printf("5. Quit\n\n");

        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            generateEnemy();
            attack();
            break;
        case 2:
            checkStatus();
            break;
        case 3:
            rest();
            break;
        case 4:
            search();
            break;
        case 5:
            printf("Thanks for playing!\n");
            exit(0);
        default:
            printf("Invalid choice.\n");
        }

        if (food <= 0 || water <= 0)
        {
            printf("You have died of starvation or thirst.\n");
            exit(0);
        }
    }

    return 0;
}