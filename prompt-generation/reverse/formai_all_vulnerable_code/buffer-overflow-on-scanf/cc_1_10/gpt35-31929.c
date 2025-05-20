//FormAI DATASET v1.0 Category: Game ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main() {
    srand(time(NULL));  // set the seed of random numbers

    // initialize variables
    int player_health = 100;
    int enemy_health = 100;
    int player_attack, enemy_attack;
    bool player_turn = true;
    bool game_over = false;

    // print the introduction
    printf("\nWelcome to the post-apocalyptic arena!\n");
    printf("You have to fight against an enemy to survive.\n");
    printf("You and the enemy have 100 health points each.\n");
    printf("Let the battle begin!\n\n");

    // the game loop
    while (!game_over) {
        // determine the attack of the current turn's player
        if (player_turn) {
            printf("Your turn! Choose your attack (1-3):\n");
            printf("1. Quick attack (deals 20-30 damage)\n");
            printf("2. Strong attack (deals 40-50 damage, but you take 10 damage too)\n");
            printf("3. Heal (restores 20-30 health)\n");
            scanf("%d", &player_attack);
            while (player_attack < 1 || player_attack > 3) {
                printf("Invalid choice. Choose again (1-3):\n");
                scanf("%d", &player_attack);
            }
            if (player_attack == 1) {
                player_attack = rand() % 11 + 20;
                printf("You deal %d damage.\n", player_attack);
            } else if (player_attack == 2) {
                player_attack = rand() % 11 + 40;
                player_health -= 10;
                printf("You deal %d damage and take 10 damage.\n", player_attack);
            } else {
                player_attack = rand() % 11 + 20;
                player_health += player_attack;
                if (player_health > 100) {
                    player_health = 100;
                }
                printf("You heal %d health.\n", player_attack);
            }
        } else {
            printf("Enemy's turn!\n");
            enemy_attack = rand() % 11 + 20;
            enemy_health -= enemy_attack;
            printf("The enemy deals %d damage.\n", enemy_attack);
        }

        // check if any player has no health points left
        if (player_health <= 0) {
            printf("You lose! The enemy destroyed you. Try again!\n");
            game_over = true;
        } else if (enemy_health <= 0) {
            printf("Congratulations! You defeated the enemy and survived.\n");
            game_over = true;
        } else {
            // switch the turn to the other player
            player_turn = !player_turn;
            printf("Your health: %d\nEnemy's health: %d\n\n", player_health, enemy_health);
        }
    }

    return 0;
}