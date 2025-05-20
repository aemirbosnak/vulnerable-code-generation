//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Random seed for generating random numbers
    srand(time(NULL));
    
    // Initializing variables
    int health = 100;
    int attack = 10;
    int defense = 5;
    int gold = 0;
    
    printf("Welcome to the Adventure Game!\n");
    printf("You find yourself in the middle of a dense forest with no memories of how you got there.\n");
    printf("Your goal is to reach the castle at the end of the forest.\n");
    
    // Loop for the game
    while (health > 0) {
        printf("\nYou have %d health, %d attack, %d defense, and %d gold.\n", health, attack, defense, gold);
        printf("What would you like to do?\n");
        printf("1. Go forward\n");
        printf("2. Rest\n");
        printf("3. Upgrade attack\n");
        printf("4. Upgrade defense\n");
        printf("5. Quit game\n");
        
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("You move forward and encounter an enemy!\n");
                // Generating random enemy stats between 50% to 150% of the player's stats
                int enemy_health = rand() % (150 - 50 + 1) + 50;
                int enemy_attack = rand() % (150 - 50 + 1) + 50;
                int enemy_defense = rand() % (150 - 50 + 1) + 50;
                
                printf("Enemy stats: %d health, %d attack, %d defense.\n", enemy_health, enemy_attack, enemy_defense);
                
                // Loop for the battle
                while (health > 0 && enemy_health > 0) {
                    // Player attacks
                    int damage = attack - (enemy_defense / 2);
                    if (damage < 0) {
                        damage = 0;
                    }
                    enemy_health -= damage;
                    printf("You attacked the enemy and dealt %d damage.\n", damage);
                    
                    // Enemy attacks
                    damage = enemy_attack - (defense / 2);
                    if (damage < 0) {
                        damage = 0;
                    }
                    health -= damage;
                    printf("The enemy attacked and dealt %d damage.\n", damage);
                }
                
                // Checking battle outcome
                if (health <= 0) {
                    printf("You died. Game over.\n");
                    return 0;
                } else {
                    printf("You defeated the enemy and gained 10 gold!\n");
                    gold += 10;
                }
                break;
                
            case 2:
                // Restores 30% of health and costs 5 gold
                if (gold >= 5) {
                    gold -= 5;
                    int restore = health * 0.3;
                    health += restore;
                    if (health > 100) {
                        health = 100;
                    }
                    printf("You took a rest and restored %d health.\n", restore);
                } else {
                    printf("You don't have enough gold to rest.\n");
                }
                break;
                
            case 3:
                // Upgrades attack by 5 and costs 10 gold
                if (gold >= 10) {
                    gold -= 10;
                    attack += 5;
                    printf("You upgraded your attack to %d.\n", attack);
                } else {
                    printf("You don't have enough gold to upgrade your attack.\n");
                }
                break;
                
            case 4:
                // Upgrades defense by 2 and costs 5 gold
                if (gold >= 5) {
                    gold -= 5;
                    defense += 2;
                    printf("You upgraded your defense to %d.\n", defense);
                } else {
                    printf("You don't have enough gold to upgrade your defense.\n");
                }
                break;
                
            case 5:
                printf("Thanks for playing the Adventure Game!\n");
                return 0;
                
            default:
                printf("Invalid input. Try again.\n");
        }
    }
    
    // If health reaches 0
    printf("You died. Game over.\n");
    return 0;
}