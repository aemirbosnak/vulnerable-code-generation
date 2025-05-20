//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int player1_hp = 100;
    int player2_hp = 100;
    char player1_name[20];
    char player2_name[20];

    printf("Enter the name of player 1: ");
    scanf("%s", player1_name);

    printf("Enter the name of player 2: ");
    scanf("%s", player2_name);

    printf("Welcome to the Arena, %s and %s!\n", player1_name, player2_name);

    // Start the battle
    while (player1_hp > 0 && player2_hp > 0)
    {
        printf("What will you do, %s? (attack/ defend)\n", player1_name);
        char player1_action;
        scanf("%c", &player1_action);

        switch (player1_action)
        {
            case 'a':
                printf("You attacked %s. They have %d HP left.\n", player2_name, player2_hp - 10);
                player2_hp -= 10;
                break;
            case 'd':
                printf("You defended. You took no damage.\n");
                break;
            default:
                printf("Invalid action.\n");
                break;
        }

        // Check if player 2 is still alive
        if (player2_hp <= 0)
        {
            printf("%s has been defeated. %s wins!\n", player2_name, player1_name);
            break;
        }

        // Player 2's turn
        printf("What will you do, %s? (attack/ defend)\n", player2_name);
        char player2_action;
        scanf("%c", &player2_action);

        switch (player2_action)
        {
            case 'a':
                printf("You attacked %s. They have %d HP left.\n", player1_name, player1_hp - 15);
                player1_hp -= 15;
                break;
            case 'd':
                printf("You defended. You took no damage.\n");
                break;
            default:
                printf("Invalid action.\n");
                break;
        }

        // Check if player 1 is still alive
        if (player1_hp <= 0)
        {
            printf("%s has been defeated. %s wins!\n", player1_name, player2_name);
            break;
        }
    }

    // End the battle
    printf("The battle is over. Thanks for playing, %s and %s!\n", player1_name, player2_name);

    return 0;
}