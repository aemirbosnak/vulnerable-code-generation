//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    srand((unsigned)time(NULL)); // Initialize random seed
    int player_health = 100;
    int enemy_health = 50;
    int player_damage = 20;
    int enemy_damage = 10;
    int player_score = 0;
    int enemy_type = rand() % 3; // Randomly select enemy type
    char player_name[50];

    printf("Welcome to the Adventure Game!\n");
    printf("Enter your name: ");
    scanf("%s", player_name);

    printf("Hello, %s! Get ready to embark on an adventure!\n\n", player_name);

    while(player_health > 0) {
        printf("Your health: %d\n", player_health);
        printf("Enemy's health: %d\n", enemy_health);
        printf("\n");

        int action;
        printf("Select an action:\n[1] Attack\n[2] Heal\n[3] Run Away\n");
        scanf("%d", &action);

        switch(action) {
            case 1:
                printf("\nYou attack the enemy!\n");
                enemy_health -= player_damage;

                if(enemy_health > 0) {
                    printf("The enemy counterattacks!\n");
                    player_health -= enemy_damage;
                }
                else {
                    printf("You have defeated the enemy!\n");
                    player_score += 10;
                    enemy_health = 50;
                    enemy_type = rand() % 3; // Randomly select new enemy type
                }

                break;
            case 2:
                printf("\nYou heal yourself!\n");
                player_health += 10;

                if(player_health > 100) {
                    player_health = 100; // Set maximum health to 100
                }

                printf("The enemy attacks while you heal!\n");
                player_health -= enemy_damage;

                break;
            case 3:
                printf("\nYou run away!\n");
                printf("You have survived this encounter and gained some experience.\n");
                player_score += 5;
                enemy_health = 50;
                enemy_type = rand() % 3; // Randomly select new enemy type

                break;
            default:
                printf("Invalid action!\n");

                break;
        }

        if(player_health <= 0) {
            printf("Game over! You have been defeated by the enemy.\n");
            printf("Final score: %d\n", player_score);

            return 0;
        }

        if(enemy_type == 0) {
            printf("\nYou have encountered a goblin!\n");
            enemy_damage = 10;
        }
        else if(enemy_type == 1) {
            printf("\nYou have encountered an orc!\n");
            enemy_damage = 20;
        }
        else {
            printf("\nYou have encountered a dragon!\n");
            enemy_damage = 30;
        }
    }

    printf("Congratulations! You have completed the Adventure Game!\n");
    printf("Final score: %d\n", player_score);

    return 0;
}