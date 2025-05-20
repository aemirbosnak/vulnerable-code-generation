//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// function prototypes
void clearScreen();
void printStats(int health, int attack, int defense);
void printInventory(int healthPotions, int manaPotions);
void printMonsterStats(char* monsterName, int monsterHealth, int monsterAttack, int monsterDefense);
void attackMonster(int* playerHealth, int* playerMana, int playerAttack, int playerDefense, char* monsterName, int* monsterHealth, int monsterAttack, int monsterDefense);
void drinkHealthPotion(int* playerHealth, int* healthPotions);
void drinkManaPotion(int* playerMana, int* manaPotions);

int main()
{
    srand(time(NULL)); // seed the random number generator

    // welcome message
    printf("Welcome to Statistical Adventure!\n");

    // player setup
    int health = 100;
    int attack = 10;
    int defense = 5;
    int healthPotions = 3;
    int manaPotions = 2;

    // game loop
    int gameRunning = 1;
    while (gameRunning)
    {
        clearScreen();

        // print player stats and inventory
        printStats(health, attack, defense);
        printInventory(healthPotions, manaPotions);

        // select a random monster to fight
        char* monsterNames[5] = {"Slime", "Goblin", "Troll", "Dragon", "Demon"};
        char* currentMonsterName = monsterNames[rand() % 5];
        int currentMonsterHealth = (rand() % 50) + 50;
        int currentMonsterAttack = (rand() % 5) + 5;
        int currentMonsterDefense = (rand() % 5) + 5;

        // print monster stats and prompt user to attack or use potion
        printf("\nA wild %s appears!\n", currentMonsterName);
        printMonsterStats(currentMonsterName, currentMonsterHealth, currentMonsterAttack, currentMonsterDefense);
        printf("What will you do?\n1. Attack\n2. Drink Health Potion\n3. Drink Mana Potion\n4. Run Away\n");
        int choice;
        char input[10];
        while (1)
        {
            printf("> ");
            fgets(input, 10, stdin);
            sscanf(input, "%d", &choice);
            if (choice >= 1 && choice <= 4)
            {
                break;
            }
            else
            {
                printf("\nInvalid choice. Please choose 1-4.\n");
            }
        }

        // take action based on user choice
        switch (choice)
        {
            case 1:
                attackMonster(&health, &manaPotions, attack, defense, currentMonsterName, &currentMonsterHealth, currentMonsterAttack, currentMonsterDefense);
                break;
            case 2:
                drinkHealthPotion(&health, &healthPotions);
                break;
            case 3:
                drinkManaPotion(&manaPotions, &manaPotions);
                break;
            case 4:
                printf("You run away from the %s.\n", currentMonsterName);
                break;
        }

        // check if player is dead
        if (health <= 0)
        {
            printf("You died. Game over.\n");
            gameRunning = 0;
        }
    }

    return 0;
}

void clearScreen()
{
    #if defined(__linux__) || defined(__unix__)
        system("clear");
    #elif defined(_WIN32) || defined(WIN32)
        system("cls");
    #endif
}

void printStats(int health, int attack, int defense)
{
    printf("Health: %d\nAttack: %d\nDefense: %d\n\n", health, attack, defense);
}

void printInventory(int healthPotions, int manaPotions)
{
    printf("Health Potions: %d\nMana Potions: %d\n\n", healthPotions, manaPotions);
}

void printMonsterStats(char* monsterName, int monsterHealth, int monsterAttack, int monsterDefense)
{
    printf("%s Health: %d\n%s Attack: %d\n%s Defense: %d\n\n", monsterName, monsterHealth, monsterName, monsterAttack, monsterName, monsterDefense);
}

void attackMonster(int* playerHealth, int* playerMana, int playerAttack, int playerDefense, char* monsterName, int* monsterHealth, int monsterAttack, int monsterDefense)
{
    // calculate damage to monster
    int damage = (playerAttack - monsterDefense) + (rand() % 10);
    if (damage <= 0)
    {
        printf("%s's defense is too strong. You deal no damage.\n", monsterName);
    }
    else
    {
        printf("You hit the %s for %d damage!\n", monsterName, damage);
        *monsterHealth -= damage;
    }

    // check if monster is dead
    if (*monsterHealth <= 0)
    {
        printf("You defeated the %s!\n", monsterName);
        return;
    }

    // calculate damage to player
    int monsterDamage = (monsterAttack - playerDefense) + (rand() % 10);
    if (monsterDamage <= 0)
    {
        printf("Your defense is too strong. %s deals no damage.\n", monsterName);
    }
    else
    {
        printf("%s hits you for %d damage!\n", monsterName, monsterDamage);
        *playerHealth -= monsterDamage;
    }

    // check if player is dead
    if (*playerHealth <= 0)
    {
        printf("You died. Game over.\n");
        exit(0);
    }
}

void drinkHealthPotion(int* playerHealth, int* healthPotions)
{
    if (*healthPotions == 0)
    {
        printf("You have no health potions left.\n");
    }
    else
    {
        *playerHealth += 50;
        *healthPotions -= 1;
        printf("You drink a health potion and recover 50 health.\n");
    }
}

void drinkManaPotion(int* playerMana, int* manaPotions)
{
    if (*manaPotions == 0)
    {
        printf("You have no mana potions left.\n");
    }
    else
    {
        *playerMana += 25;
        *manaPotions -= 1;
        printf("You drink a mana potion and recover 25 mana.\n");
    }
}