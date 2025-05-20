//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
    srand(time(NULL)); // initializing random seed

    char player_name[20];
    printf("Welcome, adventurer! What is your name? ");
    scanf("%s", player_name);
    printf("\n");

    int player_hp = 100;
    int player_gold = 0;
    int player_choice;

    printf("Greetings, %s. You find yourself in a dark forest.\n", player_name);
    printf("You have %d health points and %d gold.\n", player_hp, player_gold);
    printf("What would you like to do? \n");
    printf("1. Explore the forest. \n");
    printf("2. Search for treasure. \n");
    printf("3. Quit game. \n");
    scanf("%d", &player_choice);
    printf("\n");

    while (player_choice != 3)
    {
        if (player_choice == 1)
        {
            int enemy_hp = rand() % 50 + 50;
            int player_damage = rand() % 20 + 10;
            int enemy_damage = rand() % 15 + 5;
            printf("You encounter a monster with %d health points!\n", enemy_hp);
            printf("You attack the monster and deal %d damage!\n", player_damage);
            enemy_hp -= player_damage;
            printf("The monster counterattacks and deals %d damage to you!\n", enemy_damage);
            player_hp -= enemy_damage;
            printf("You have %d health points left.\n", player_hp);
            printf("The monster has %d health points left.\n", enemy_hp);

            if (enemy_hp <= 0) 
            {
                printf("Congratulations, you have defeated the monster and gained 50 gold!\n");
                player_gold += 50;
            }
            else if (player_hp <= 0) 
            {
                printf("You have been defeated by the monster. GAME OVER.\n");
                break; // exits the game if player is defeated
            }
        } 
        else if (player_choice == 2)
        {
            int treasure = rand() % 100 + 50;
            printf("You search for treasure and find %d gold!\n", treasure);
            player_gold += treasure;
        } 
        else 
        {
            printf("Invalid input. Please try again.\n");
        }

        printf("You have %d health points and %d gold.\n", player_hp, player_gold);
        printf("What would you like to do? \n");
        printf("1. Explore the forest. \n");
        printf("2. Search for treasure. \n");
        printf("3. Quit game. \n");
        scanf("%d", &player_choice);
        printf("\n");
    }

    printf("Thank you for playing, %s! Goodbye!\n", player_name);

    return 0;
}