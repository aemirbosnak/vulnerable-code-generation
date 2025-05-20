//FormAI DATASET v1.0 Category: Game ; Style: shocked
#include <stdio.h>

int main() 
{
    printf("Welcome to Surprise Battle Game!\n");
    printf("Prepare to meet your doom!\n");

    int health = 100;
    int enemy_health = 100;
    int damage = 0;
    int enemy_damage = 0;
    int round = 1;
    int max_rounds = 10;
    char choice;

    printf("\nInstructions: You will engage in a battle with a surprise enemy.\n");
    printf("Choose your attack wisely. You will have 10 rounds.\n");

    while (round <= max_rounds && health > 0 && enemy_health > 0) 
    {
        printf("\nRound %d.\n", round);
        printf("Player Health: %d.\n", health);
        printf("Enemy Health: %d.\n", enemy_health);

        printf("\nChoose your attack:\n");
        printf("1: Sword Strike.\n");
        printf("2: Fireball.\n");
        printf("3: Ice Breath.\n");
        printf("4: Surprise Attack.\n");
        
        scanf("%c", &choice);

        if (choice == '1') 
        {
            damage = 20;
            enemy_damage = 10;
            printf("You attacked with Sword Strike.\n");
        }
        else if (choice == '2') 
        {
            damage = 25;
            enemy_damage = 15;
            printf("You attacked with Fireball.\n");
        }
        else if (choice == '3') 
        {
            damage = 30;
            enemy_damage = 20;
            printf("You attacked with Ice Breath.\n");
        }
        else if (choice == '4') 
        {
            printf("You attacked with Surprise Attack! It did 50 damage!\n");
            enemy_health -= 50;
            damage = 0;
            enemy_damage = 0;
        }
        else 
        {
            printf("You missed your attack!\n");
            damage = 0;
            enemy_damage = 0;
        }

        enemy_health -= damage;
        health -= enemy_damage;

        round++;
    }

    if (health <= 0) 
    {
        printf("\nYou have lost the battle!\n");
    }
    else if (enemy_health <= 0) 
    {
        printf("\nYou have won the battle!\n");
    }
    else 
    {
        printf("\nIt's a tie!\n");
    }

    printf("\nThanks for playing the Surprise Battle Game!\n");
    return 0;
}