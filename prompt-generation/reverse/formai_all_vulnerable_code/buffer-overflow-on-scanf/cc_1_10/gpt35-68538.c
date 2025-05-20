//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function Prototypes
void intro();
void gameStart();
void gameOver();

// Main Function
int main()
{
    intro();
    gameStart();
    gameOver();

    return 0;
}

void intro()
{
    printf("Welcome to the Text-Based Adventure Game!\n\n");
    printf("You are lost in a creepy forest and need to find your way out. Along the way you will encounter dangerous creatures and obstacles that will test your skills.\n\n");
    printf("Good luck!\n\n");
}

void gameStart()
{
    char name[20];
    int health = 100;
    int attack = 10;
    int defense = 5;
    int choice;
    int enemyHealth;
    int enemyAttack;
    int enemyDefense;
    int damage;
    int potion = 1;
    time_t t;

    srand((unsigned) time(&t));   // Initialization of random seed

    printf("What is your name?\n");
    scanf("%s", name);
    printf("Welcome, %s!\n\n", name);

    printf("You have %d health points, %d attack points, and %d defense points.\n", health, attack, defense);

    // First decision point
    printf("\nYou come across a fork in the road. Which way do you want to go?\n");
    printf("1. Left\n");
    printf("2. Right\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("\nYou chose to go left.\n");
        printf("You come across a giant spider.\n\n");

        // Enemy stats
        enemyHealth = rand() % 50 + 50;
        enemyAttack = rand() % 10 + 5;
        enemyDefense = rand() % 5 + 5;

        // Battle loop
        while (health > 0 && enemyHealth > 0)
        {
            printf("%s: %dHP\n", name, health);
            printf("Spider: %dHP\n\n", enemyHealth);

            printf("1. Attack\n");
            printf("2. Defend\n");
            printf("3. Use Potion\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice)
            {
                case 1: // Attack
                    damage = rand() % attack - enemyDefense + 5;
                    if (damage < 0)
                    {
                        printf("\nYour attack had no effect.\n\n");
                    }
                    else
                    {
                        printf("\nYou dealt %d damage to the spider.\n\n", damage);
                        enemyHealth -= damage;
                    }
                    break;
                    
                case 2: // Defend
                    defense += 5;
                    printf("\nYou take a defensive stance.\n\n");
                    break;
                    
                case 3: // Use Potion
                    if (potion > 0)
                    {
                        printf("\nYou use a health potion and regain 25HP.\n\n");
                        health += 25;
                        potion--;
                    }
                    else
                    {
                        printf("\nYou have no more health potions left.\n\n");
                    }
                    break;
                    
                default:
                    printf("\nThat is an invalid option.\n\n");
                    break;
            }

            // Enemy's turn
            if (enemyHealth > 0)
            {
                damage = rand() % enemyAttack - defense + 5;
                if (damage < 0)
                {
                    printf("The spider's attack had no effect.\n\n");
                }
                else
                {
                    printf("The spider dealt %d damage to you.\n\n", damage);
                    health -= damage;
                }
            }
        }

        // Check for win or loss
        if (health > 0)
        {
            printf("Congratulations! You defeated the giant spider and continue on your journey.\n\n");
        }
        else
        {
            printf("Game over. You were defeated by the giant spider.\n");
            gameOver();
        }
    }
    else if (choice == 2)
    {
        printf("\nYou chose to go right.\n");
        printf("You come across a deep ravine.\n\n");

        // Decision point
        printf("Do you want to try to jump the ravine or turn back?\n");
        printf("1. Jump\n");
        printf("2. Turn back\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("\nYou try to jump the ravine...\n");

            // 50% chance of success
            if (rand() % 2 == 0)
            {
                printf("You make it across safely and continue on your journey.\n\n");
            }
            else
            {
                printf("You fall into the ravine and lose 20HP.\n\n");
                health -= 20;
            }

            // Check for defeat
            if (health <= 0)
            {
                printf("Game over. You succumbed to your injuries in the ravine.\n");
                gameOver();
            }
        }
        else if (choice == 2)
        {
            printf("\nYou turn back and decide to take the other path.\n\n");
            gameStart();
        }
        else
        {
            printf("\nThat is an invalid option.\n\n");
            gameStart();
        }
    }
    else
    {
        printf("\nThat is an invalid option.\n\n");
        gameStart();
    }

}

void gameOver()
{
    char choice;

    printf("\nDo you want to play again? (Y/N): ");
    scanf(" %c", &choice);

    if (choice == 'Y' || choice == 'y')
    {
        printf("\n");
        gameStart();
    }
    else if (choice == 'N' || choice == 'n')
    {
        printf("\nThanks for playing!\n\n");
        exit(0);
    }
    else
    {
        printf("\nThat is an invalid option. Please enter Y or N.\n\n");
        gameOver();
    }
}