//GEMINI-pro DATASET v1.0 Category: Educational ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the player's stats
typedef struct Player {
  char *name;
  int health;
  int attack;
  int defense;
} Player;

// Define the enemy's stats
typedef struct Enemy {
  char *name;
  int health;
  int attack;
  int defense;
} Enemy;

// Create a new player and enemy
Player *createPlayer() {
  Player *player = malloc(sizeof(Player));
  player->name = malloc(20);
  printf("Enter your name, survivor: ");
  scanf("%s", player->name);
  player->health = 100;
  player->attack = 10;
  player->defense = 5;
  return player;
}

Enemy *createEnemy() {
  Enemy *enemy = malloc(sizeof(Enemy));
  enemy->name = malloc(20);
  strcpy(enemy->name, "Ghoul");
  enemy->health = 50;
  enemy->attack = 10;
  enemy->defense = 5;
  return enemy;
}

// Battle the player and enemy
void battle(Player *player, Enemy *enemy) {
  while (player->health > 0 && enemy->health > 0) {
    // Player attacks enemy
    int damage = player->attack - enemy->defense;
    if (damage < 0) damage = 0;
    enemy->health -= damage;

    // Enemy attacks player
    damage = enemy->attack - player->defense;
    if (damage < 0) damage = 0;
    player->health -= damage;

    // Print the battle status
    printf("Player health: %d\n", player->health);
    printf("Enemy health: %d\n", enemy->health);
    printf("---------------------\n");
  }

  // Determine the winner
  if (player->health <= 0) {
    printf("You have been defeated!\n");
  } else {
    printf("You have defeated the enemy!\n");
  }
}

// Free the player and enemy memory
void freePlayer(Player *player) {
  free(player->name);
  free(player);
}

void freeEnemy(Enemy *enemy) {
  free(enemy->name);
  free(enemy);
}

// Main function
int main() {
  // Create the player and enemy
  Player *player = createPlayer();
  Enemy *enemy = createEnemy();

  // Battle the player and enemy
  battle(player, enemy);

  // Free the player and enemy memory
  freePlayer(player);
  freeEnemy(enemy);

  return 0;
}