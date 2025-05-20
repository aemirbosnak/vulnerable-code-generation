//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Game variables
    int player_health = 100;
    int monster_health = 50;
    char player_name[20];

    // Get the player's name
    printf("Enter your name: ");
    scanf("%s", player_name);

    // Loop until the player's health is 0 or the monster's health is 0
    while (player_health > 0 && monster_health > 0)
    {
        // Display the player's health and name
        printf("Name: %s, Health: %d\n", player_name, player_health);

        // Display the monster's health
        printf("Monster Health: %d\n", monster_health);

        // Attack the monster
        printf("Enter your attack: ");
        int attack = scanf("%d");

        // Calculate the damage
        int damage = attack - monster_health / 2;

        // Subtract the damage from the monster's health
        monster_health -= damage;

        // Check if the monster is dead
        if (monster_health <= 0)
        {
            printf("The monster is dead!\n");
        }
        // Check if the player is dead
        else if (player_health <= 0)
        {
            printf("You are dead. Game over!\n");
        }
        // Otherwise, continue the loop
        else
        {
            printf("You have attacked the monster.\n");
        }
    }

    // End of the game
    return 0;
}