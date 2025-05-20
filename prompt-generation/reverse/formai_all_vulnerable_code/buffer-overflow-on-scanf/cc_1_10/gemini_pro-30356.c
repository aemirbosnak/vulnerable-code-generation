//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Defines the player's structure
typedef struct {
    char name[20];
    int health;
    int attack;
    int defense;
} Player;

// Defines the enemy's structure
typedef struct {
    char name[20];
    int health;
    int attack;
    int defense;
} Enemy;

// Creates a new player
Player create_player() {
    Player player;

    // Gets the player's name
    printf("What is your name, brave adventurer? ");
    scanf("%s", player.name);

    // Sets the player's initial health, attack, and defense
    player.health = 100;
    player.attack = 10;
    player.defense = 10;

    return player;
}

// Creates a new enemy
Enemy create_enemy() {
    Enemy enemy;

    // Generates a random name for the enemy
    char enemy_names[][20] = {"Goblin", "Orc", "Troll", "Dragon", "Demon"};
    int random_index = rand() % 5;
    strcpy(enemy.name, enemy_names[random_index]);

    // Sets the enemy's initial health, attack, and defense
    enemy.health = 100;
    enemy.attack = 10;
    enemy.defense = 10;

    return enemy;
}

// Battles the player against the enemy
void battle(Player *player, Enemy *enemy) {
    int turn = 1;

    while (player->health > 0 && enemy->health > 0) {
        if (turn % 2 == 1) {
            // Player's turn
            int attack_damage = player->attack - enemy->defense;
            if (attack_damage < 0) {
                attack_damage = 0;
            }
            enemy->health -= attack_damage;

            printf("%s attacks %s for %d damage!\n", player->name, enemy->name, attack_damage);
        } else {
            // Enemy's turn
            int attack_damage = enemy->attack - player->defense;
            if (attack_damage < 0) {
                attack_damage = 0;
            }
            player->health -= attack_damage;

            printf("%s attacks %s for %d damage!\n", enemy->name, player->name, attack_damage);
        }

        turn++;
    }

    if (player->health <= 0) {
        printf("You have been defeated! Game over.\n");
    } else {
        printf("You have defeated %s! You win!\n", enemy->name);
    }
}

// Main function
int main() {
    // Sets the random seed
    srand(time(NULL));

    // Creates the player and enemy
    Player player = create_player();
    Enemy enemy = create_enemy();

    // Battles the player against the enemy
    battle(&player, &enemy);

    return 0;
}