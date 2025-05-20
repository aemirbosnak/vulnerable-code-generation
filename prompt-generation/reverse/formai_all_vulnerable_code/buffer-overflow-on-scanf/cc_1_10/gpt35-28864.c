//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SHIP_HEALTH 100
#define ALIEN_HEALTH 50

int main()
{
    int ship_health = SHIP_HEALTH;
    int alien_health = ALIEN_HEALTH;
    int player_choice;
    int alien_choice;

    // Set random seed
    srand(time(NULL));

    // Start game
    printf("Welcome to Procedural Space Adventure!\n");
    printf("You are the captain of a spaceship, currently exploring a distant planet.\n");

    while (ship_health > 0 && alien_health > 0)
    {
        printf("\nYour ship's health: %d\n", ship_health);
        printf("Alien's health: %d\n", alien_health);

        // Player's turn
        printf("\nWhat will you do?\n");
        printf("1. Attack\n");
        printf("2. Defend\n");
        scanf("%d", &player_choice);

        if (player_choice == 1) // Attack
        {
            int damage = rand() % 20 + 1;
            printf("You attack the alien and deal %d damage!\n", damage);
            alien_health -= damage;
        }
        else if (player_choice == 2) // Defend
        {
            int defense = rand() % 10 + 1;
            printf("You defend yourself and reduce the alien's damage by %d!\n", defense);
            alien_choice -= defense;
        }

        // Alien's turn
        alien_choice = rand() % 2;
        if (alien_choice == 0) // Attack
        {
            int damage = rand() % 10 + 1;
            printf("The alien attacks you and deals %d damage!\n", damage);
            ship_health -= damage;
        }
        else if (alien_choice == 1) // Defend
        {
            int defense = rand() % 5 + 1;
            printf("The alien defends itself and reduces your damage by %d!\n", defense);
            player_choice -= defense;
        }
    }

    // End game
    if (ship_health <= 0)
    {
        printf("\nYour ship has been destroyed!\n");
    }
    else if (alien_health <= 0)
    {
        printf("\nYou have defeated the alien!\n");
    }

    return 0;
}