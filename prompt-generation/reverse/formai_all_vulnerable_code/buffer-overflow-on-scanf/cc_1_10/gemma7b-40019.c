//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("CLS");
    int choice, player_health = 100, enemy_health = 100, game_over = 0;

    // Introduce the characters
    printf("You are Elara, a sorceress of unparalleled power.\n");
    printf("You are facing the evil sorcerer, Mor'goth.\n\n");

    // Start the game loop
    while (!game_over)
    {
        // Display the current health of both player and enemy
        printf("Your health: %d/%d\n", player_health, player_health);
        printf("Mor'goth's health: %d/%d\n", enemy_health, enemy_health);

        // Choose an action
        printf("What do you want to do? (Attack, Cast Spell, Defend)\n");
        scanf("%d", &choice);

        // Process the player's choice
        switch (choice)
        {
            case 1: // Attack
                enemy_health -= 20;
                printf("You unleashed a powerful spell, striking Mor'goth for 20 damage.\n");
                break;
            case 2: // Cast Spell
                printf("Please choose a spell: (Fireball, Lightning Bolt, Frostbite)\n");
                scanf("%d", &choice);

                switch (choice)
                {
                    case 1: // Fireball
                        enemy_health -= 15;
                        printf("You unleashed a fiery fireball, burning Mor'goth for 15 damage.\n");
                        break;
                    case 2: // Lightning Bolt
                        enemy_health -= 25;
                        printf("You unleashed a bolt of lightning, striking Mor'goth for 25 damage.\n");
                        break;
                    case 3: // Frostbite
                        enemy_health -= 10;
                        printf("You cast a frostbite spell, freezing Mor'goth for 10 damage.\n");
                        break;
                }
                break;
            case 3: // Defend
                player_health += 15;
                printf("You used your magic to defend yourself, regaining 15 health points.\n");
                break;
        }

        // Check if the enemy is dead
        if (enemy_health <= 0)
        {
            printf("Mor'goth has been defeated! You have won the battle!\n");
            game_over = 1;
        }

        // Check if the player is dead
        if (player_health <= 0)
        {
            printf("You have been defeated by Mor'goth. Game Over.\n");
            game_over = 1;
        }
    }

    // End the game
    return 0;
}