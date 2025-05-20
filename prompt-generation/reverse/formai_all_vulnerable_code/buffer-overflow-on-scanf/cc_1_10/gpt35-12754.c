//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    //initialize variables
    int playerHealth = 100;
    int enemyHealth = 100;
    int playerCoolDown = 0;
    int enemyCoolDown = 0;
    int damage;
    char action;

    //seed the random number generator
    srand(time(NULL));

    //introduction
    printf("Welcome to Procedural Space Adventure!\n");
    printf("Your mission is to defeat the enemy spacecraft and save the galaxy.\n");
    printf("Press enter to begin.\n");
    getchar();

    //the game loop
    while (playerHealth > 0 && enemyHealth > 0)
    {
        //display player and enemy health
        printf("Player health: %d\n", playerHealth);
        printf("Enemy health: %d\n", enemyHealth);

        //get player action
        printf("Enter action (a = attack, h = heal): ");
        scanf(" %c", &action);

        //process player action
        if (action == 'a')
        {
            //check if player is ready to attack
            if (playerCoolDown <= 0)
            {
                //calculate damage
                damage = rand() % 21 + 10;
                printf("Player attacks for %d damage!\n", damage);

                //decrease enemy health
                enemyHealth -= damage;

                //set player cool down
                playerCoolDown = 2;
            }
            else
            {
                printf("Player is not ready to attack yet.\n");
            }
        }
        else if (action == 'h')
        {
            //check if player is ready to heal
            if (playerCoolDown <= 0)
            {
                //heal player
                playerHealth += 20;

                //cap player health at 100
                if (playerHealth > 100)
                {
                    playerHealth = 100;
                }

                printf("Player heals for 20 health!\n");

                //set player cool down
                playerCoolDown = 2;
            }
            else
            {
                printf("Player is not ready to heal yet.\n");
            }
        }
        else
        {
            printf("Invalid action.\n");
        }

        //process enemy action
        if (enemyCoolDown <= 0)
        {
            //calculate damage
            damage = rand() % 21 + 10;
            printf("Enemy attacks for %d damage!\n", damage);

            //decrease player health
            playerHealth -= damage;

            //set enemy cool down
            enemyCoolDown = 2;
        }
        else
        {
            printf("Enemy is not ready to attack yet.\n");
        }

        //decrease cool downs
        playerCoolDown--;
        enemyCoolDown--;
    }

    //check who won
    if (playerHealth > 0)
    {
        printf("Congratulations, you defeated the enemy spacecraft and saved the galaxy!\n");
    }
    else
    {
        printf("Game over, the enemy spacecraft defeated you.\n");
    }

    return 0;
}