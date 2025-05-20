//FormAI DATASET v1.0 Category: Game ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
    srand(time(0));

    // Variables
    int player_health = 100;
    int enemy_health = 100;
    int player_attack;
    int enemy_attack;
    int round = 1;
    char player_choice;

    printf("Welcome to Medieval RPG Battle Game!\n");

    // Game Loop
    while (player_health > 0 && enemy_health > 0) 
    {
        printf("\n\n-------------- Round %d --------------\n", round);

        // Player's Turn
        printf("Your Health: %d\n", player_health);
        printf("Enemy's Health: %d\n", enemy_health);
        printf("Choose your attack:\n");
        printf("A) Sword    B) Bow    C) Magic\n");
        scanf(" %c", &player_choice);

        switch (player_choice) 
        {
            case 'A':
                player_attack = rand() % 16 + 10;
                enemy_health -= player_attack;
                printf("You swung your sword and dealt %d damage!\n", player_attack);
                break;
            case 'B':
                player_attack = rand() % 11 + 8;
                enemy_health -= player_attack;
                printf("You shot your bow and dealt %d damage!\n", player_attack);
                break;
            case 'C':
                player_attack = rand() % 21 + 15;
                enemy_health -= player_attack;
                printf("You casted your magic spell and dealt %d damage!\n", player_attack);
                break;
            default:
                printf("Invalid input. Try again.\n");
                continue; // Restart loop without advancing
        }

        if (enemy_health <= 0) 
        {
            break; // End game loop
        }

        // Enemy's Turn
        enemy_attack = rand() % 16 + 8;
        player_health -= enemy_attack;
        printf("Enemy attacked you and dealt %d damage!\n", enemy_attack);

        if (player_health <= 0) 
        {
            break; // End game loop
        }

        round++;
    }

    // Game Ending
    printf("\n\n-------------- GAME OVER --------------\n");

    if (player_health > 0) 
    {
        printf("Congratulations! You won the battle!\n");
    } 
    else 
    {
        printf("Sorry, you lost the battle. Better luck next time!\n");
    }

    printf("Your Health: %d\n", player_health);
    printf("Enemy's Health: %d\n", enemy_health);

    return 0;
}