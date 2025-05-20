//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the player and enemy structures
typedef struct {
    int health;
    int attack;
    int defense;
} Player;

typedef struct {
    int health;
    int attack;
    int defense;
} Enemy;

// Create the player and enemy objects
Player player;
Enemy enemy;

// Initialize the game
void initGame() {
    // Set the player's health, attack, and defense
    player.health = 100;
    player.attack = 10;
    player.defense = 5;

    // Set the enemy's health, attack, and defense
    enemy.health = 100;
    enemy.attack = 10;
    enemy.defense = 5;
}

// Print the player's and enemy's stats
void printStats() {
    printf("Player:\n");
    printf("Health: %d\n", player.health);
    printf("Attack: %d\n", player.attack);
    printf("Defense: %d\n\n", player.defense);

    printf("Enemy:\n");
    printf("Health: %d\n", enemy.health);
    printf("Attack: %d\n", enemy.attack);
    printf("Defense: %d\n\n", enemy.defense);
}

// Attack the enemy
void attackEnemy() {
    // Calculate the damage dealt
    int damage = player.attack - enemy.defense;

    // If the damage is negative, set it to 0
    if (damage < 0) {
        damage = 0;
    }

    // Apply the damage to the enemy
    enemy.health -= damage;

    // Print the damage dealt
    printf("You dealt %d damage to the enemy.\n", damage);
}

// Defend against the enemy's attack
void defend() {
    // Calculate the damage blocked
    int damage = enemy.attack - player.defense;

    // If the damage is negative, set it to 0
    if (damage < 0) {
        damage = 0;
    }

    // Apply the damage to the player
    player.health -= damage;

    // Print the damage blocked
    printf("You blocked %d damage from the enemy.\n", damage);
}

// Main game loop
int main() {
    // Initialize the game
    initGame();

    // Print the player's and enemy's stats
    printStats();

    // Main game loop
    while (player.health > 0 && enemy.health > 0) {
        // Get the player's input
        char input;
        printf("Enter your command (a)ttack, (d)efend, or (q)uit: ");
        scanf(" %c", &input);

        // Process the player's input
        switch (input) {
            case 'a':
                attackEnemy();
                break;
            case 'd':
                defend();
                break;
            case 'q':
                exit(0);
                break;
            default:
                printf("Invalid command.\n");
                break;
        }

        // Check if the enemy is still alive
        if (enemy.health <= 0) {
            printf("You win!\n");
            exit(0);
        }

        // The enemy attacks the player
        int damage = enemy.attack - player.defense;

        // If the damage is negative, set it to 0
        if (damage < 0) {
            damage = 0;
        }

        // Apply the damage to the player
        player.health -= damage;

        // Print the damage dealt
        printf("The enemy dealt %d damage to you.\n", damage);

        // Check if the player is still alive
        if (player.health <= 0) {
            printf("You lose!\n");
            exit(0);
        }
    }

    return 0;
}