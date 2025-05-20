//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Define the boundaries of the game world
#define MIN_X 1
#define MAX_X 100
#define MIN_Y 1
#define MAX_Y 100

// Define the starting position and health points of the player
#define START_X 50
#define START_Y 50
#define START_HP 100

// Define the enemy types and their stats
#define ENEMY_COUNT 3
#define ENEMY_TYPE_1 "Small alien"
#define ENEMY_TYPE_2 "Medium alien"
#define ENEMY_TYPE_3 "Big alien"
#define ENEMY_HP_1 20
#define ENEMY_HP_2 50
#define ENEMY_HP_3 100

int player_x, player_y, player_hp;
bool game_over = false;

// Function to randomly generate enemy positions
void generateEnemy(int *enemy_x, int *enemy_y) {
  do {
    *enemy_x = rand() % MAX_X + 1;
    *enemy_y = rand() % MAX_Y + 1;
  } while (*enemy_x == player_x && *enemy_y == player_y);
}

// Function to check if player is within boundaries
bool isPlayerWithinBoundaries() {
  return player_x >= MIN_X && player_x <= MAX_X && player_y >= MIN_Y && player_y <= MAX_Y;
}

// Function to check if player has collided with an enemy
bool hasPlayerCollidedWithEnemy(int enemy_x, int enemy_y) {
  return player_x == enemy_x && player_y == enemy_y;
}

// Function to simulate an enemy attack on the player
void enemyAttack(int enemy_hp) {
  player_hp -= enemy_hp;
  printf("You have been attacked by an enemy! Your current health is %d.\n", player_hp);
  if (player_hp <= 0) {
    game_over = true;
    printf("You have been defeated! Game Over.\n");
  }
}

int main() {
  srand(time(NULL)); // Initialize random seed

  // Initialize player position and health points
  player_x = START_X;
  player_y = START_Y;
  player_hp = START_HP;

  // Generate enemy positions and stats
  int enemy_x[ENEMY_COUNT], enemy_y[ENEMY_COUNT], enemy_hp[ENEMY_COUNT];
  for (int i = 0; i < ENEMY_COUNT; i++) {
    generateEnemy(&enemy_x[i], &enemy_y[i]);
    switch (i) {
      case 0:
        enemy_hp[i] = ENEMY_HP_1;
        break;
      case 1:
        enemy_hp[i] = ENEMY_HP_2;
        break;
      case 2:
        enemy_hp[i] = ENEMY_HP_3;
        break;
    }
    printf("A %s has appeared at (%d,%d) with health %d.\n", i == 0 ? ENEMY_TYPE_1 : i == 1 ? ENEMY_TYPE_2 : ENEMY_TYPE_3, enemy_x[i], enemy_y[i], enemy_hp[i]);
  }

  // Game loop
  while (!game_over) {
    printf("You are currently at (%d,%d) with health %d.\n", player_x, player_y, player_hp);

    // Handle player movement
    int move_x, move_y;
    printf("Enter x coordinate to move to: ");
    scanf("%d", &move_x);
    printf("Enter y coordinate to move to: ");
    scanf("%d", &move_y);
    if (move_x >= MIN_X && move_x <= MAX_X)
      player_x = move_x;
    if (move_y >= MIN_Y && move_y <= MAX_Y)
      player_y = move_y;
    if (!isPlayerWithinBoundaries()) {
      printf("You have moved outside of the game boundaries!\n");
      game_over = true;
      break;
    }

    // Check if player has collided with an enemy
    for (int i = 0; i < ENEMY_COUNT; i++) {
      if (hasPlayerCollidedWithEnemy(enemy_x[i], enemy_y[i])) {
        enemyAttack(enemy_hp[i]);
        break;
      }
    }

    // Check if all enemies have been defeated
    bool all_enemies_defeated = true;
    for (int i = 0; i < ENEMY_COUNT; i++) {
      if (enemy_hp[i] > 0) {
        all_enemies_defeated = false;
        break;
      }
    }
    if (all_enemies_defeated) {
      printf("Congratulations! You have defeated all enemies and won the game!\n");
      game_over = true;
      break;
    }
  }

  return 0;
}