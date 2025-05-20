//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global Variables
int playerHealth = 100;
int enemyHealth = 100;
int playerAttack = 20;
int enemyAttack = 10;
int roundNum = 1;

// Function declarations
void displayIntro();
void displayMenu();
void displayStats();
void playerAttackRound();
void enemyAttackRound();

int main()
{
    displayIntro();

    while (playerHealth > 0 && enemyHealth > 0) // Game loop
    {
        printf("\nROUND %d\n", roundNum);
        displayMenu();
        int choice;
        scanf("%d", &choice); // Get user input for menu choice

        switch (choice)
        {
            case 1:
                playerAttackRound();
                enemyAttackRound();
                break;
            case 2:
                displayStats();
                break;
            case 3:
                printf("\nYou decided to run away.\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }

        roundNum++; // Increment round number
    }

    if (playerHealth <= 0)
        printf("\nYou lost the game! Try again.\n");
    else if (enemyHealth <= 0)
        printf("\nCongratulations! You won the game.\n");

    return 0;
}

// Displays game introduction
void displayIntro()
{
    printf("\nWelcome to Medieval Battle Game!\n");
    printf("\nYou are a brave knight who is fighting for your kingdom.\n");
    printf("\nYour mission is to defeat the enemy lord and his army.\n");
    printf("\nBe careful! The enemy is strong and they won't go down without a fight.\n");
}

// Displays game menu
void displayMenu() 
{
    printf("\nChoose your next move:\n");
    printf("1. Attack\n");
    printf("2. View stats\n");
    printf("3. Run away\n");
}

// Displays player and enemy stats
void displayStats()
{
    printf("\nYour Health: %d\n", playerHealth);
    printf("Enemy Health: %d\n", enemyHealth);
}

// Simulates player attack
void playerAttackRound()
{
    srand(time(NULL)); // Seed random number
    int roll = rand() % 20 + 1; // Generate random number from 1 to 20
    int attackDamage = playerAttack;

    if (roll >= 18) // Critical hit
    {
        printf("\nCRITICAL HIT!\n");
        attackDamage *= 2;
    }
    else if (roll == 1) // Critical fail
    {
        printf("\nCRITICAL FAIL!\n");
        attackDamage = 0;
    }

    enemyHealth -= attackDamage; // Decrease enemy health by player's attack damage
    printf("\nYou attacked and dealt %d damage!\n", attackDamage);
}

// Simulates enemy attack
void enemyAttackRound()
{
    srand(time(NULL)); // Seed random number
    int roll = rand() % 20 + 1; // Generate random number from 1 to 20
    int attackDamage = enemyAttack;

    if (roll >= 18) // Critical hit
    {
        printf("\nEnemy landed a CRITICAL HIT!\n");
        attackDamage *= 2;
    }
    else if (roll == 1) // Critical fail
    {
        printf("\nEnemy had a CRITICAL FAIL!\n");
        attackDamage = 0;
    }

    playerHealth -= attackDamage; // Decrease player health by enemy's attack damage
    printf("\nEnemy attacked and dealt %d damage!\n", attackDamage);
}