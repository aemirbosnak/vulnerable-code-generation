//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int player_health = 100;

    srand(time(NULL));

    printf("Welcome to our haunted house simulator!\n");
    printf("You enter a spooky old house and are immediately greeted by a ghost!\n\n");

    while (player_health > 0)
    {
        int ghost_damage = rand() % 11 + 5;

        printf("You have %d health remaining.\n", player_health);
        printf("The ghost deals %d damage to you!\n", ghost_damage);

        player_health -= ghost_damage;

        if (player_health <= 0)
        {
            printf("\nYou have been defeated by the ghost! GAME OVER!\n");
            return 0;
        }

        printf("You have the following options:\n");
        printf("1) Attack the ghost\n");
        printf("2) Flee the haunted house\n");

        int choice;
        scanf("%d", &choice);

        if (choice == 2)
        {
            printf("\nYou have fled the haunted house. Goodbye!\n");
            return 0;
        }

        int player_damage = rand() % 21 + 10;

        printf("You attack the ghost and deal %d damage!\n", player_damage);

        if (player_damage >= 20)
        {
            printf("Critical hit! You deal double damage!\n");
            ghost_damage *= 2;
        }

        printf("The ghost has %d health remaining.\n\n", 100 - ghost_damage);

        if (ghost_damage >= 80)
        {
            printf("The ghost is enraged! It deals double damage next turn!\n");
        }

        player_health -= ghost_damage;

        if (player_health <= 0)
        {
            printf("\nYou have been defeated by the ghost! GAME OVER!\n");
            return 0;
        }
        
        if (ghost_damage >= 80)
        {
            printf("You have the following options:\n");
            printf("1) Attack the ghost\n");
            printf("2) Flee the haunted house\n");

            scanf("%d", &choice);

            if (choice == 2)
            {
                printf("\nYou have fled the haunted house. Goodbye!\n");
                return 0;
            }

            player_damage = rand() % 21 + 10;

            printf("You attack the ghost and deal %d damage!\n", player_damage);

            if (player_damage >= 20)
            {
                printf("Critical hit! You deal double damage!\n");
                ghost_damage *= 2;
            }

            printf("The ghost has %d health remaining.\n\n", 100 - ghost_damage);

            player_health -= ghost_damage;

            if (player_health <= 0)
            {
                printf("\nYou have been defeated by the ghost! GAME OVER!\n");
                return 0;
            }
        }
    }

    printf("\nYou have defeated the ghost and escaped the haunted house! Congratulations!\n");

    return 0;
}