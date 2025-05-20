//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int playerHealth = 100;
int enemyHealth = 75;
char playerName[20];

void mainMenu();
void startGame();
void attack();
void runAway();
void gameOver();

int main()
{
    printf("Welcome to the Text-Based Adventure Game!\n");
    mainMenu();

    return 0;
}

void mainMenu()
{
    int choice;

    printf("\n---MAIN MENU---\n");
    printf("1. Start Game\n");
    printf("2. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            startGame();
            break;
        case 2:
            printf("\nGoodbye!\n");
            exit(0);
            break;
        default:
            printf("\nInvalid choice! Please try again.\n");
            mainMenu();
            break;
    }
}

void startGame()
{
    printf("\nEnter your name: ");
    scanf("%s", playerName);
    printf("\nWelcome, %s! You are in a dark and spooky forest. You have no idea how you got here. All you know is that you want to get out!\n", playerName);

    while(1)
    {
        int choice;

        printf("\nWhat would you like to do?\n");
        printf("1. Attack\n");
        printf("2. Run Away\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                attack();
                break;
            case 2:
                runAway();
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
                break;
        }

        if(playerHealth <= 0 || enemyHealth <= 0)
        {
            gameOver();
            break;
        }
    }
}

void attack()
{
    int damage = rand() % 20 + 1;
    printf("\nYou attacked the enemy and did %d damage!\n", damage);
    enemyHealth -= damage;

    damage = rand() % 15 + 1;
    printf("The enemy attacked you and did %d damage!\n", damage);
    playerHealth -= damage;

    printf("\n%s's Health: %d\n", playerName, playerHealth);
    printf("Enemy's Health: %d\n", enemyHealth);
}

void runAway()
{
    int chance = rand() % 2;
    if(chance == 0)
    {
        printf("\nYou tried to run away but the enemy caught you!\n");

        int damage = rand() % 15 + 1;
        printf("The enemy attacked you and did %d damage!\n", damage);
        playerHealth -= damage;

        printf("\n%s's Health: %d\n", playerName, playerHealth);
        printf("Enemy's Health: %d\n", enemyHealth);
    }
    else
    {
        printf("\nYou successfully ran away!\n");
        enemyHealth = 0;
    }
}

void gameOver()
{
    if(playerHealth <= 0)
    {
        printf("\n%s died!\n", playerName);
    }
    else if(enemyHealth <= 0)
    {
        printf("\nYou defeated the enemy!\n");
    }

    mainMenu();
}