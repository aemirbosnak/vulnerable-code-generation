//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int player_health = 100;
int monster_health = 50;
int player_attack_power = 10;
int monster_attack_power = 5;

void fight()
{
    printf("You encounter a monster!\n");

    // fight loop
    while (player_health > 0 && monster_health > 0) {
        // player's turn
        int damage = rand() % player_attack_power + 1;
        monster_health -= damage;
        printf("You hit the monster for %d damage. Monster health: %d\n", damage, monster_health);

        // monster's turn
        damage = rand() % monster_attack_power + 1;
        player_health -= damage;
        printf("Monster hit you for %d damage. Your health: %d\n", damage, player_health);
    }

    if (player_health <= 0) {
        printf("You died. Game over.\n");
        exit(0);
    } else {
        printf("You won the fight! Your health: %d\n", player_health);
    }
}

int main()
{
    printf("Welcome to the adventure game!\n");

    while (true) {
        printf("You are in a dark forest. What do you want to do?\n");
        printf("1. Walk around\n");
        printf("2. Fight monster\n");
        printf("3. Quit game\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("You walk around the forest and find a treasure chest!\n");
                printf("You open it and find a shiny sword. Your attack power increases.\n");
                player_attack_power += 5;
                break;
            case 2:
                fight();
                break;
            case 3:
                printf("Thanks for playing!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}