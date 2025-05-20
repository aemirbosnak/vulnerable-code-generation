//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char playerName[20];
    int playerHealth = 100;
    int playerAttack = 10;
    int playerDefense = 5;
    int playerMoney = 0;

    printf("What is your name?\n");
    scanf("%s", playerName);

    printf("\nWelcome to the adventure, %s! You start with %d health, %d attack, %d defense, and %d money.\n\n", playerName, playerHealth, playerAttack, playerDefense, playerMoney);

    while (playerHealth > 0)
    {
        printf("You are in a dark forest. There are two paths, which one do you take? (left/right)\n");

        char pathChoice[10];
        scanf("%s", pathChoice);

        if (strcmp(pathChoice, "left") == 0)
        {
            printf("\nYou encounter a troll! Do you want to fight or run? (fight/run)\n");

            char actionChoice[10];
            scanf("%s", actionChoice);

            if (strcmp(actionChoice, "fight") == 0)
            {
                int trollHealth = 50;
                int trollAttack = 8;
                int trollDefense = 2;

                while (trollHealth > 0)
                {
                    int playerDamage = playerAttack - trollDefense;
                    if (playerDamage < 0)
                        playerDamage = 0;
                    trollHealth -= playerDamage;

                    printf("\nYou hit the troll for %d damage. The troll has %d health left.\n", playerDamage, trollHealth);

                    if (trollHealth <= 0)
                    {
                        printf("\nYou defeated the troll and earned 20 money!\n\n");
                        playerMoney += 20;
                        break;
                    }

                    int trollDamage = trollAttack - playerDefense;
                    if (trollDamage < 0)
                        trollDamage = 0;
                    playerHealth -= trollDamage;

                    printf("\nThe troll hit you for %d damage. You have %d health left.\n", trollDamage, playerHealth);

                    if (playerHealth <= 0)
                    {
                        printf("\nYou died. Game over.\n");
                        exit(0);
                    }
                }
            }
            else if (strcmp(actionChoice, "run") == 0)
            {
                printf("\nYou ran away, but lost 5 health in the process.\n");
                playerHealth -= 5;
            }
            else
            {
                printf("\nInvalid action choice, %s. Try again.\n", actionChoice);
            }
        }
        else if (strcmp(pathChoice, "right") == 0)
        {
            printf("\nYou found a treasure chest! Do you want to open it? (yes/no)\n");

            char treasureChoice[10];
            scanf("%s", treasureChoice);

            if (strcmp(treasureChoice, "yes") == 0)
            {
                printf("\nYou found a magic sword and gained 10 attack!\n");
                playerAttack += 10;
            }
            else if (strcmp(treasureChoice, "no") == 0)
            {
                printf("\nYou decided not to open the chest.\n");
            }
            else
            {
                printf("\nInvalid treasure choice, %s. Try again.\n", treasureChoice);
            }
        }
        else
        {
            printf("\nInvalid path choice, %s. Try again.\n", pathChoice);
        }
    }

    printf("\nCongratulations, %s! You beat the game with %d health and %d money!\n", playerName, playerHealth, playerMoney);

    return 0;
}