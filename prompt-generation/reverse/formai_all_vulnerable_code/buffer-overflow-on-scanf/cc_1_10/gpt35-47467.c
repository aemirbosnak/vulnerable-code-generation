//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//function declarations
void intro();
void gameStart();
void gameEnd();
void quitGame();
void fight();
void flee();
void win();
void lose();

int main()
{
    char playerName[20];
    int playerHealth = 20;
    int bossHealth = 30;
    int playerAttack;
    int bossAttack;

    srand(time(NULL)); //to produce random numbers

    intro(); //call intro function

    printf("\nPlease Enter Your Name: ");
    scanf("%s", playerName);

    printf("Hello %s! Welcome to the adventure game!\n", playerName);

    gameStart(); //call game start function

    while (1)
    {
        int action;

        printf("\nWhat would you like to do next?\n");
        printf("1. Fight\n");
        printf("2. Flee\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &action);

        switch (action)
        {
            case 1:
                fight(&playerHealth, &bossHealth, &playerAttack, &bossAttack); //call fight function
                break;

            case 2:
                flee(); //call flee function
                break;

            case 3:
                quitGame(); //call quit function
                break;

            default:
                printf("Invalid Choice! Try Again.\n"); //error handling
                break;
        }

        if (playerHealth <= 0) //player lose condition
        {
            lose();
            break;
        }

        else if (bossHealth <= 0) //player win condition
        {
            win();
            break;
        }
    }

    gameEnd(); //call game end function

    return 0;
}

void intro()
{
    printf("==============================================================\n");
    printf("                WELCOME TO THE ADVENTURE GAME!                 \n");
    printf("==============================================================\n");
    printf("         You are on a quest to defeat the evil dragon!         \n");
    printf("   You must travel through the dangerous forest and caves     \n");
    printf("  to reach the dragon's lair. Be careful and good luck hero!   \n");
    printf("==============================================================\n\n");
}

void gameStart()
{
    printf("==============================================================\n");
    printf("                         GAME START                            \n");
    printf("==============================================================\n\n");
}

void gameEnd()
{
    printf("==============================================================\n");
    printf("                         GAME END                              \n");
    printf("==============================================================\n\n");
}

void quitGame()
{
    printf("You have quit the game. Thanks for playing!");
    exit(0);
}

void fight(int *playerHealth, int *bossHealth, int *playerAttack, int *bossAttack)
{
    int randomNumber = rand() % 3; //to randomly select the attack of the boss
    *playerAttack = rand() % 6; //to randomly select the attack of the player

    printf("\nYou attacked the boss and caused %d damage\n", *playerAttack);
    *bossHealth = *bossHealth - *playerAttack; //reduce boss health by player attack

    printf("The boss attacked you and caused %d damage\n", randomNumber);
    *playerHealth = *playerHealth - randomNumber; //reduce player health by random number

    printf("Current Player Health: %d\n", *playerHealth);
    printf("Current Boss Health: %d\n", *bossHealth);
}

void flee()
{
    printf("You have fleed from the battle. Be brave hero and try again.");
}

void win()
{
    printf("==============================================================\n");
    printf("                         YOU WON!                              \n");
    printf("==============================================================\n\n");
    printf("Congratulations hero! You defeated the evil dragon and saved the kingdom. \n");
}

void lose()
{
    printf("==============================================================\n");
    printf("                         GAME OVER                             \n");
    printf("==============================================================\n\n");
    printf("The evil dragon has defeated you. The kingdom is now in darkness and despair. \n");
}