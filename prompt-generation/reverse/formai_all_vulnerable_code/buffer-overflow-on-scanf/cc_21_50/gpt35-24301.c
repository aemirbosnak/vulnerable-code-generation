//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Welcome Message
    printf("Welcome to Cryptic Dungeon, adventurer!\n");

    // Generate random seed for game
    srand(time(NULL));

    // Game Variables
    int health = 100;
    int max_health = 100;
    int enemies_defeated = 0;
    int level = 1;
    int boss_health = 200;
    int damage = 0;
    int boss_damage = 0;
    int num_potions = 3;

    // Game Loop
    while (1)
    {
        // Player Status
        printf("\n----------------------------------------------\n");
        printf("Level: %d\n", level);
        printf("Health: %d / %d\n", health, max_health);
        printf("Enemies Defeated: %d\n", enemies_defeated);

        // Generate enemy
        int enemy_health = rand() % (level * 10) + 1;
        printf("\nA Wild Monster Appears! (Health: %d)\n", enemy_health);

        // Battle Loop
        while (enemy_health > 0)
        {
            printf("\nWhat will you do?\n");
            printf("1. Attack\n");
            printf("2. Drink Health Potion (%d left)\n", num_potions);
            printf("3. Run Away\n");

            int choice;
            scanf("%d", &choice);

            // Attack
            if (choice == 1)
            {
                damage = rand() % 20 + level;
                enemy_health -= damage;
                printf("\nYou deal %d damage to the monster!\n", damage);
                if (enemy_health <= 0)
                {
                    printf("\nYou've defeated the monster!\n");
                    enemies_defeated++;
                    health += rand() % 10 + level;
                    if (enemies_defeated == 10)
                    {
                        printf("\nYou feel a strange force calling you deeper into the dungeon...\n");
                        break;
                    }
                }
                else
                {
                    boss_damage = rand() % 25 + level;
                    health -= boss_damage;
                    printf("\nThe monster deals %d damage to you!\n", boss_damage);
                    if (health <= 0)
                    {
                        printf("\nYou have died. Game Over.\n");
                        return 0;
                    }
                }
            }
            
            // Drink Health Potion
            else if (choice == 2)
            {
                if (num_potions == 0)
                {
                    printf("\nYou don't have any health potions left!\n");
                }
                else
                {
                    health += 25;
                    if (health > max_health)
                    {
                        health = max_health;
                    }
                    num_potions--;
                    printf("\nYou drink a health potion and recover 25 health! (%d left)\n", num_potions);
                }
            }

            // Run Away
            else if (choice == 3)
            {
                printf("\nYou managed to escape from the monster! Cowardly.\n");
                enemies_defeated--;
                break;
            }

            // Invalid Choice
            else
            {
                printf("\nInvalid choice. Try again.\n");
            }
        }

        // Boss Battle
        if (enemies_defeated == 10)
        {
            printf("\nYou have reached the end of the dungeon. Get ready for the Boss Fight!\n");
            while (boss_health > 0)
            {
                printf("\nWhat will you do?\n");
                printf("1. Attack\n");
                printf("2. Drink Health Potion (%d left)\n", num_potions);
                printf("3. Run Away (You're not going anywhere this time)\n");

                int boss_choice = rand() % 3 + 1;

                // Attack
                if (boss_choice == 1)
                {
                    boss_damage = rand() % 35 + level * 2;
                    health -= boss_damage;
                    printf("\nThe boss deals %d damage to you!\n", boss_damage);
                    if (health <= 0)
                    {
                        printf("\nYou have died. Game Over.\n");
                        return 0;
                    }
                    else
                    {
                        damage = rand() % 25 + level * 2;
                        boss_health -= damage;
                        printf("\nYou deal %d damage to the boss!\n", damage);
                        if (boss_health <= 0)
                        {
                            printf("\nCongratulations! You have defeated the Boss and escaped the Cryptic Dungeon!\n");
                            return 0;
                        }
                    }
                }
                
                // Drink Health Potion
                else if (boss_choice == 2)
                {
                    if (num_potions == 0)
                    {
                        printf("\nThe boss laughs at your empty hand. Drink some potion next time.\n");
                    }
                    else
                    {
                        health += 50;
                        if (health > max_health)
                        {
                            health = max_health;
                        }
                        num_potions--;
                        printf("\nYou drink a health potion and recover 50 health! (%d left)\n", num_potions);
                    }
                }

                // Coward's Choice
                else if (boss_choice == 3)
                {
                    printf("\nThe Boss watched your lame attempt to escape, and hits you with a fireball. \n");
                    boss_damage = rand() % 50 + level * 2;
                    health -= boss_damage;
                    printf("\nYou take %d damage!\n", boss_damage);
                    if (health <= 0)
                    {
                        printf("\nYou have died. Game Over.\n");
                        return 0;
                    }
                }

            }
        }

        // Increase Level
        level++;
    }

    return 0;
}