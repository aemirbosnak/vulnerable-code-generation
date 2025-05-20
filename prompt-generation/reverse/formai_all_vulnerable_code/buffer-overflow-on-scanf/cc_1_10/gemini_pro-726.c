//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the player's stats
typedef struct {
    int health;
    int attack;
    int defense;
} Player;

// Define the enemy's stats
typedef struct {
    int health;
    int attack;
    int defense;
} Enemy;

// Create a new player
Player* create_player() {
    Player* player = malloc(sizeof(Player));
    player->health = 100;
    player->attack = 10;
    player->defense = 5;
    return player;
}

// Create a new enemy
Enemy* create_enemy() {
    Enemy* enemy = malloc(sizeof(Enemy));
    enemy->health = 100;
    enemy->attack = 10;
    enemy->defense = 5;
    return enemy;
}

// Attack the enemy
void attack_enemy(Player* player, Enemy* enemy) {
    int damage = player->attack - enemy->defense;
    if (damage < 0) {
        damage = 0;
    }
    enemy->health -= damage;
    printf("You deal %d damage to the enemy.\n", damage);
}

// Attack the player
void attack_player(Player* player, Enemy* enemy) {
    int damage = enemy->attack - player->defense;
    if (damage < 0) {
        damage = 0;
    }
    player->health -= damage;
    printf("The enemy deals %d damage to you.\n", damage);
}

// Print the player's stats
void print_player_stats(Player* player) {
    printf("Your health: %d\n", player->health);
    printf("Your attack: %d\n", player->attack);
    printf("Your defense: %d\n", player->defense);
}

// Print the enemy's stats
void print_enemy_stats(Enemy* enemy) {
    printf("Enemy health: %d\n", enemy->health);
    printf("Enemy attack: %d\n", enemy->attack);
    printf("Enemy defense: %d\n", enemy->defense);
}

// Main game loop
int main() {
    // Create the player and enemy
    Player* player = create_player();
    Enemy* enemy = create_enemy();

    // Seed the random number generator
    srand(time(NULL));

    // Main game loop
    while (player->health > 0 && enemy->health > 0) {
        // Print the player's and enemy's stats
        print_player_stats(player);
        print_enemy_stats(enemy);

        // Get the player's input
        char input;
        printf("What do you want to do?\n");
        printf("a) Attack\n");
        printf("b) Defend\n");
        printf("c) Heal\n");
        scanf(" %c", &input);

        // Perform the player's action
        switch (input) {
            case 'a':
                attack_enemy(player, enemy);
                break;
            case 'b':
                // Defend the player
                player->defense += 5;
                printf("You defend yourself.\n");
                break;
            case 'c':
                // Heal the player
                player->health += 10;
                printf("You heal yourself.\n");
                break;
            default:
                printf("Invalid input.\n");
                break;
        }

        // Perform the enemy's action
        int enemy_action = rand() % 3;
        switch (enemy_action) {
            case 0:
                attack_player(enemy, player);
                break;
            case 1:
                // Defend the enemy
                enemy->defense += 5;
                printf("The enemy defends itself.\n");
                break;
            case 2:
                // Heal the enemy
                enemy->health += 10;
                printf("The enemy heals itself.\n");
                break;
        }
    }

    // Print the game over message
    if (player->health <= 0) {
        printf("You lose!\n");
    } else {
        printf("You win!\n");
    }

    // Free the player and enemy memory
    free(player);
    free(enemy);

    return 0;
}