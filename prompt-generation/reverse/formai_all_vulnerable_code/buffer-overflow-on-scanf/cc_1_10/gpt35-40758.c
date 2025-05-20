//FormAI DATASET v1.0 Category: Game ; Style: peaceful
#include <stdio.h>
#include <stdbool.h>

/* Global Variables */
bool peaceful = true;
int player_health = 100;
int enemy_health = 100;

/* Function Declarations */
void attack();
void defend();
void rest();

/* Main Function */
int main()
{
    printf("Welcome to Peaceful Game!\n");
    printf("In this game, you are a peaceful adventurer trying to navigate through dangerous territories.\n");
    printf("You may encounter enemies throughout your journey, but don't worry - violence is not the only answer!\n");

    while (player_health > 0)
    {
        printf("Player Health: %d\n", player_health);
        printf("Enemy Health: %d\n", enemy_health);
        printf("\nWhat would you like to do?\n");
        printf("1. Attack\n2. Defend\n3. Rest\n");

        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                attack();
                break;
            case 2:
                defend();
                break;
            case 3:
                rest();
                break;
            default:
                printf("Invalid Choice! Please try again.\n");
        }

        if (enemy_health <= 0)
        {
            printf("You've defeated the enemy peacefully!\n");
            peaceful = true;
            enemy_health = 100;
        }
        else if (peaceful == false)
        {
            printf("You've succumbed to violence and lost the game!\n");
            break;
        }
    }

    printf("Game Over!\n");

    return 0;
}

/* Function Definitions */
void attack()
{
    printf("You've decided to attack the enemy!\n");
    printf("Violence is never the answer, but sometimes it may be necessary to defend yourself.\n");
    enemy_health -= 25;
    peaceful = false;
}

void defend()
{
    printf("You've decided to defend against the enemy!\n");
    printf("Sometimes the best approach is to simply protect yourself and wait for the right opportunity to present itself.\n");
    player_health += 10;
    peaceful = true;
}

void rest()
{
    printf("You've decided to rest and regain your strength!\n");
    printf("Peaceful resolutions are always preferable, and sometimes simply taking a break and regrouping can be enough to resolve a conflict.\n");
    player_health += 5;
    peaceful = true;
}