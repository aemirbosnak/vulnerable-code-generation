//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int shipHealth = 100;
    int alienHealth = 50;
    int ammo = 20;
    int shield = 0;
    int damage;

    printf("Welcome to Procedural Space Adventure!\n");
    printf("You are the captain of your own spaceship and you are being attacked by aliens.\n");
    printf("Use your ammo to fight them off and protect your ship.\n");

    while (shipHealth > 0 && alienHealth > 0)
    {
        int attackChoice;
        printf("What would you like to do? (1)Attack or (2)Shield? ");
        scanf("%d", &attackChoice);

        if (attackChoice == 1)
        {
            if (ammo <= 0)
            {
                printf("You are out of ammo!\n");
            }
            else
            {
                damage = rand() % 10 + 1;
                alienHealth -= damage;
                printf("You attacked the alien and did %d damage!\n", damage);
                ammo--;
            }
        }
        else if (attackChoice == 2)
        {
            shield = rand() % 2;
            if (shield == 0)
            {
                printf("Your shield failed!\n");
            }
            else
            {
                printf("Your shield held up!\n");
            }
        }
        else
        {
            printf("Invalid choice, try again.\n");
        }

        if (alienHealth > 0)
        {
            damage = rand() % 10 + 1;
            shipHealth -= damage;
            printf("The alien attacked you and did %d damage!\n", damage);
        }

        printf("Your ship health: %d\n", shipHealth);
        printf("Alien health: %d\n", alienHealth);
    }

    if (shipHealth > 0)
    {
        printf("Congratulations, you defeated the aliens and saved your ship!\n");
    }
    else
    {
        printf("Game over. The aliens destroyed your ship.\n");
    }

    return 0;
}