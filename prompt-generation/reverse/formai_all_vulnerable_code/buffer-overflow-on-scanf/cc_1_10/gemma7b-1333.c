//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Game Variables
    int player_health = 100;
    int enemy_health = 50;
    int player_damage = 15;
    int enemy_damage = 10;
    int round = 1;

    // Game Loop
    while (player_health > 0 && enemy_health > 0)
    {
        // Player Turn
        printf("It is your turn.\n");
        printf("What do you want to do? (Attack/Parry/Heal)\n");
        char input;
        scanf("%c", &input);

        // Check if the input is valid
        if (input != 'a' && input != 'p' && input != 'h')
        {
            printf("Invalid input.\n");
            continue;
        }

        // Calculate damage
        int damage = 0;
        switch (input)
        {
            case 'a':
                damage = player_damage;
                break;
            case 'p':
                damage = player_damage / 2;
                break;
            case 'h':
                damage = player_damage / 4;
                break;
        }

        // Attack the enemy
        enemy_health -= damage;
        printf("You attacked the enemy for %d damage.\n", damage);

        // Enemy Turn
        printf("The enemy's turn.\n");
        damage = enemy_damage;
        player_health -= damage;
        printf("The enemy attacked you for %d damage.\n", damage);

        // Round Counter
        round++;
    }

    // Game Over
    if (player_health <= 0)
    {
        printf("You have been defeated. Game Over.\n");
    }
    else
    {
        printf("You have won! Congratulations!\n");
    }

    // Time Delay
    sleep(2);

    // Return to Main Menu
    printf("Press any key to continue...");
    getchar();

    return 0;
}