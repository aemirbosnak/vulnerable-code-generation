//GEMINI-pro DATASET v1.0 Category: Game ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the player's attributes
typedef struct {
  char name[20];
  int health;
  int attack;
  int defense;
} Player;

// Define the enemy's attributes
typedef struct {
  char name[20];
  int health;
  int attack;
  int defense;
} Enemy;

// Create a new player
Player *create_player() {
  Player *player = malloc(sizeof(Player));

  // Get the player's name
  printf("What is your name, brave adventurer?\n");
  scanf("%s", player->name);

  // Set the player's starting attributes
  player->health = 100;
  player->attack = 10;
  player->defense = 10;

  return player;
}

// Create a new enemy
Enemy *create_enemy() {
  Enemy *enemy = malloc(sizeof(Enemy));

  // Get the enemy's name
  char *enemy_names[] = {"Orc", "Goblin", "Skeleton", "Zombie", "Dragon"};
  int enemy_index = rand() % 5;
  strcpy(enemy->name, enemy_names[enemy_index]);

  // Set the enemy's starting attributes
  enemy->health = 100;
  enemy->attack = 10;
  enemy->defense = 10;

  return enemy;
}

// Battle the enemy
int battle(Player *player, Enemy *enemy) {
  int turn = 0;

  while (player->health > 0 && enemy->health > 0) {
    if (turn % 2 == 0) {
      // Player's turn
      int damage = player->attack - enemy->defense;
      if (damage < 0) {
        damage = 0;
      }
      enemy->health -= damage;
      printf("%s attacks %s for %d damage!\n", player->name, enemy->name, damage);
    } else {
      // Enemy's turn
      int damage = enemy->attack - player->defense;
      if (damage < 0) {
        damage = 0;
      }
      player->health -= damage;
      printf("%s attacks %s for %d damage!\n", enemy->name, player->name, damage);
    }

    turn++;
  }

  // Check who won the battle
  if (player->health <= 0) {
    printf("You have been defeated! Game over.\n");
    return 0;
  } else {
    printf("You have defeated %s! You win!\n", enemy->name);
    return 1;
  }
}

// Main game loop
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Create the player and enemy
  Player *player = create_player();
  Enemy *enemy = create_enemy();

  // Battle the enemy
  int result = battle(player, enemy);

  // Free the player and enemy memory
  free(player);
  free(enemy);

  return result;
}