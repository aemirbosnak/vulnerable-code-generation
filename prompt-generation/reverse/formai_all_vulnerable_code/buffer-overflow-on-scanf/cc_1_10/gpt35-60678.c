//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // initialize random seed
    srand(time(NULL));
    
    // game variables
    int player_health = 100;
    int player_strength = 10;
    int enemy_health = 100;
    int enemy_strength = rand() % 15 + 5; // enemy strength between 5 and 20
    
    // game loop
    while (1) {
        // print game status
        printf("Player Health: %d\n", player_health);
        printf("Player Strength: %d\n", player_strength);
        printf("Enemy Health: %d\n", enemy_health);
        printf("Enemy Strength: %d\n", enemy_strength);
        printf("\n");
        
        // player turn
        printf("Player's Turn:\n");
        printf("What would you like to do?\n");
        printf("1. Attack\n");
        printf("2. Defend\n");
        int player_choice;
        scanf("%d", &player_choice);
        if (player_choice == 1) {
            int damage = rand() % player_strength + 1; // player damage between 1 and player_strength
            enemy_health -= damage;
            printf("Player attacks with %d damage!\n", damage);
        }
        else if (player_choice == 2) {
            printf("Player defends and gains 5 health!\n");
            player_health += 5;
        }
        else {
            printf("Invalid choice!\n");
            continue;
        }
        
        // check if enemy is defeated
        if (enemy_health <= 0) {
            printf("Player wins!\n");
            break;
        }
        
        // enemy turn
        printf("Enemy's Turn:\n");
        int enemy_choice = rand() % 2 + 1; // enemy randomly chooses between attack and defend
        if (enemy_choice == 1) {
            int damage = rand() % enemy_strength + 1; // enemy damage between 1 and enemy_strength
            player_health -= damage;
            printf("Enemy attacks with %d damage!\n", damage);
        }
        else {
            printf("Enemy defends and gains 5 health!\n");
            enemy_health += 5;
        }
        
        // check if player is defeated
        if (player_health <= 0) {
            printf("Enemy wins!\n");
            break;
        }
        
        printf("\n");
    }
    
    return 0;
}