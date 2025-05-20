//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // initialize random seed

    int player_hp = 100; // player starting hit points
    int enemy_hp = 100;  // enemy starting hit points
    int player_attack;   // player's attack damage
    int enemy_attack;    // enemy's attack damage
    int choice;          // player's choice of attack

    printf("Welcome to the Paranoid Battle Game!\n\n");

    // loop until either the player or the enemy's hit points reach 0
    while (player_hp > 0 && enemy_hp > 0)
    {
        printf("Your HP: %d\n", player_hp);
        printf("Enemy HP: %d\n\n", enemy_hp);

        // display attack options
        printf("Choose your attack:\n");
        printf("1. Quick Attack\n");
        printf("2. Heavy Attack\n");
        printf("3. Defensive Stance\n\n");

        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);

        // calculate player's attack damage based on choice
        switch (choice)
        {
            case 1:
                player_attack = rand() % 20 + 10; // quick attack: 10-29 damage
                printf("\nYou used Quick Attack!\n");
                break;
            case 2:
                player_attack = rand() % 30 + 20; // heavy attack: 20-49 damage
                printf("\nYou used Heavy Attack!\n");
                break;
            case 3:
                printf("\nYou took a Defensive Stance!\n");
                break;
            default:
                printf("\nInvalid choice. Try again.\n");
                continue;
        }

        // calculate enemy's attack damage
        enemy_attack = rand() % 30 + 10; // enemy attack: 10-39 damage

        // apply damage
        if (choice != 3) // player did not take defensive stance
        {
            enemy_hp -= player_attack;
            printf("You dealt %d damage to the enemy!\n", player_attack);
        }
        else // player took defensive stance
        {
            printf("You took less damage from the enemy!\n");
        }

        player_hp -= enemy_attack;
        printf("The enemy dealt %d damage to you!\n", enemy_attack);
    }

    // display outcome
    if (player_hp <= 0)
    {
        printf("\nOh no! You have been defeated...\n");
    }
    else
    {
        printf("\nCongratulations! You have defeated the enemy!\n");
    }

    return 0;
}