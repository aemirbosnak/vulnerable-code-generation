//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to hold player data
struct Player {
    int health;
    int attack;
    int defense;
    int coins;
};

// Function to initialize player with random stats
struct Player initPlayer() {
    struct Player player;
    player.health = 50 + rand() % 50;
    player.attack = 5 + rand() % 10;
    player.defense = 2 + rand() % 5;
    player.coins = 0;
    return player;
}

// Function to simulate a battle
int battle(struct Player player, int enemyHealth, int enemyAttack, int enemyDefense) {
    while (player.health > 0 && enemyHealth > 0) {
        // Player turn
        int damage = player.attack - enemyDefense;
        if (damage <= 0) {
            damage = 1;
        }
        enemyHealth -= damage;
        printf("You hit the enemy for %d damage.\n", damage);
        if (enemyHealth <= 0) {
            printf("You won the battle!\n");
            return 1;
        }
        
        // Enemy turn
        damage = enemyAttack - player.defense;
        if (damage <= 0) {
            damage = 1;
        }
        player.health -= damage;
        printf("The enemy hit you for %d damage.\n", damage);
        if (player.health <= 0) {
            printf("You lost the battle.\n");
            return 0;
        }
    }
}

int main() {
    srand(time(NULL));
    struct Player player = initPlayer();
    printf("Welcome to the adventure game!\n");
    printf("You start with %d health, %d attack, and %d defense.\n", player.health, player.attack, player.defense);
    printf("Collect coins and fight enemies to become stronger!\n");
    char input;
    while (1) {
        printf("Enter 'b' to battle or 'q' to quit: ");
        scanf(" %c", &input);
        if (input == 'b') {
            int enemyHealth = 20 + rand() % 30;
            int enemyAttack = 3 + rand() % 8;
            int enemyDefense = 1 + rand() % 3;
            printf("You encounter an enemy with %d health, %d attack, and %d defense.\n", enemyHealth, enemyAttack, enemyDefense);
            if (battle(player, enemyHealth, enemyAttack, enemyDefense)) {
                int coins = 5 + rand() % 10;
                player.coins += coins;
                printf("You gained %d coins!\n", coins);
                printf("You now have %d health, %d attack, %d defense, and %d coins.\n", player.health, player.attack, player.defense, player.coins);
            } else {
                player.health = player.health / 2;
                printf("You lost half of your health!\n");
                printf("You now have %d health, %d attack, %d defense, and %d coins.\n", player.health, player.attack, player.defense, player.coins);
            }
        } else if (input == 'q') {
            printf("Thanks for playing!\n");
            break;
        } else {
            printf("Invalid input.\n");
        }
    }
    return 0;
}