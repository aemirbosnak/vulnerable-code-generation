//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    system("clear");
    srand(time(NULL));

    int player_health = 100;
    int enemy_health = 100;

    while (player_health > 0 && enemy_health > 0)
    {
        // Display game stats
        printf("Player Health: %d\n", player_health);
        printf("Enemy Health: %d\n", enemy_health);

        // Choose an action
        char action;
        printf("Enter your action (attack, defend, heal): ");
        scanf(" %c", &action);

        // Process the action
        switch (action)
        {
            case 'a':
                enemy_health -= rand() % 10 + 1;
                printf("You attacked the enemy.\n");
                break;
            case 'd':
                player_health -= rand() % 5 + 1;
                printf("You defended against the enemy's attack.\n");
                break;
            case 'h':
                player_health += rand() % 5 + 1;
                printf("You healed yourself.\n");
                break;
            default:
                printf("Invalid action.\n");
                break;
        }

        // Check if the player has won or lost
        if (enemy_health <= 0)
        {
            printf("You have won!\n");
            player_health = 100;
            enemy_health = 100;
        }
        else if (player_health <= 0)
        {
            printf("You have lost.\n");
            player_health = 100;
            enemy_health = 100;
        }
    }

    return 0;
}