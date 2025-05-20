//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENEMY_HEALTH 10
#define MAX_PLAYER_HEALTH 100
#define WEAPON_POWER 20

int main()
{
    int playerHealth = MAX_PLAYER_HEALTH;
    int enemyHealth = MAX_ENEMY_HEALTH;
    int weaponPower = WEAPON_POWER;
    char input;

    printf("You are in a dark and shadowy cave.\n");
    printf("You hear footsteps approaching...\n");

    while (enemyHealth > 0 && playerHealth > 0)
    {
        printf("Enter 'a' to attack, 'f' to flee: ");
        scanf(" %c", &input);

        switch (input)
        {
            case 'a':
                enemyHealth -= weaponPower;
                printf("You attack the enemy and deal %d damage.\n", weaponPower);
                break;
            case 'f':
                printf("You flee from the enemy.\n");
                return 0;
            default:
                printf("Invalid input.\n");
                break;
        }

        if (enemyHealth > 0)
        {
            enemyHealth -= weaponPower;
            printf("The enemy attacks you and deals %d damage.\n", weaponPower);
            playerHealth -= weaponPower;
        }

        if (playerHealth <= 0)
        {
            printf("You have been defeated.\n");
            return 0;
        }
    }

    printf("You have defeated the enemy.\n");
    return 0;
}