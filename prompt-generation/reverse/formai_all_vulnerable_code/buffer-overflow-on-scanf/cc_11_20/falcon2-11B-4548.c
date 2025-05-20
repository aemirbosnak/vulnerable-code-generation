//Falcon2-11B DATASET v1.0 Category: Procedural Space Adventure ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct ship {
    char name[50];
    int health;
    int attack;
    int defense;
} Ship;

int main() {
    srand(time(NULL)); // Seed random number generator
    
    int num_ships = 5; // Number of ships in the fleet
    Ship fleet[num_ships]; // Array to store fleet of ships
    
    for (int i = 0; i < num_ships; i++) {
        sprintf(fleet[i].name, "Ship %d", i+1);
        fleet[i].health = rand() % 100 + 1;
        fleet[i].attack = rand() % 10 + 1;
        fleet[i].defense = rand() % 10 + 1;
    }
    
    printf("Fleet:\n");
    for (int i = 0; i < num_ships; i++) {
        printf("- %s\n", fleet[i].name);
    }
    
    int player_health = 100; // Health of the player's ship
    int player_attack = 10; // Attack power of the player's ship
    int player_defense = 5; // Defense power of the player's ship
    
    int enemy_health = rand() % 100 + 1; // Health of the enemy ship
    int enemy_attack = rand() % 10 + 1; // Attack power of the enemy ship
    int enemy_defense = rand() % 10 + 1; // Defense power of the enemy ship
    
    printf("You are controlling the %s with %d health, %d attack, and %d defense.\n", fleet[0].name, player_health, player_attack, player_defense);
    printf("You have encountered an enemy ship with %d health, %d attack, and %d defense.\n", enemy_health, enemy_attack, enemy_defense);
    
    int player_turn = 1; // Indicates if it's the player's turn or not
    int enemy_turn = 0; // Indicates if it's the enemy's turn or not
    
    while (player_health > 0 && enemy_health > 0) {
        if (player_turn) {
            printf("Player's turn:\n");
            printf("Attack power: %d\n", player_attack);
            printf("Defense power: %d\n", player_defense);
            printf("Choose an action:\n");
            printf("1. Attack\n");
            printf("2. Defend\n");
            printf("3. Retreat\n");
            int choice;
            scanf("%d", &choice);
            
            if (choice == 1) {
                printf("You have chosen to attack!\n");
                int damage = (rand() % 10) + 1;
                enemy_health -= damage;
                printf("You have dealt %d damage to the enemy ship.\n", damage);
            } else if (choice == 2) {
                printf("You have chosen to defend!\n");
                int defense_damage = (rand() % 10) + 1;
                player_health -= defense_damage;
                printf("You have defended successfully and taken %d damage.\n", defense_damage);
            } else if (choice == 3) {
                printf("You have chosen to retreat!\n");
                player_turn = 0;
            } else {
                printf("Invalid choice. Try again.\n");
            }
        } else {
            printf("Enemy's turn:\n");
            printf("Attack power: %d\n", enemy_attack);
            printf("Defense power: %d\n", enemy_defense);
            printf("Choose an action:\n");
            printf("1. Attack\n");
            printf("2. Defend\n");
            printf("3. Retreat\n");
            int choice;
            scanf("%d", &choice);
            
            if (choice == 1) {
                printf("Enemy has chosen to attack!\n");
                int damage = (rand() % 10) + 1;
                player_health -= damage;
                printf("The enemy has dealt %d damage to your ship.\n", damage);
            } else if (choice == 2) {
                printf("Enemy has chosen to defend!\n");
                int defense_damage = (rand() % 10) + 1;
                enemy_health -= defense_damage;
                printf("The enemy has defended successfully and taken %d damage.\n", defense_damage);
            } else if (choice == 3) {
                printf("Enemy has chosen to retreat!\n");
                enemy_turn = 0;
            } else {
                printf("Invalid choice. Try again.\n");
            }
        }
        
        printf("Player health: %d\n", player_health);
        printf("Enemy health: %d\n", enemy_health);
        
        if (player_health <= 0) {
            printf("You have lost the battle!\n");
            break;
        } else if (enemy_health <= 0) {
            printf("You have won the battle!\n");
            break;
        }
        
        player_turn =!player_turn;
        enemy_turn =!enemy_turn;
    }
    
    printf("Game over.\n");
    
    return 0;
}