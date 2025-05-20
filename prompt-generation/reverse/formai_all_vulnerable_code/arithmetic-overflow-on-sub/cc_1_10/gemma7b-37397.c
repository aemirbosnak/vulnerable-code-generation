//Gemma-7B DATASET v1.0 Category: Procedural Space Adventure ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENEMIES 5

typedef struct Enemy {
  char name[20];
  int health;
  int attack;
  int defense;
} Enemy;

Enemy enemies[MAX_ENEMIES] = {
  {"Space Pirate", 100, 15, 12},
  {"Alien Overlord", 80, 12, 10},
  {"Cybernetic Warrior", 60, 10, 8},
  {"Cosmic Horror", 40, 8, 6},
  {"Rogue AI", 20, 6, 4}
};

int main() {
  int player_health = 100;
  int player_attack = 12;
  int player_defense = 10;

  time_t start_time = time(NULL);

  // Generate a random encounter
  int encounter_index = rand() % MAX_ENEMIES;

  // Create a pointer to the enemy
  Enemy *enemy = &enemies[encounter_index];

  // Print the enemy's name
  printf("You encounter a %s!\n", enemy->name);

  // Battle loop
  while (player_health > 0 && enemy->health > 0) {
    // Player's turn
    int damage = player_attack - enemy->defense;
    enemy->health -= damage;
    printf("You attack the %s for %d damage.\n", enemy->name, damage);

    // Enemy's turn
    damage = enemy->attack - player_defense;
    player_health -= damage;
    printf("The %s attacks you for %d damage.\n", enemy->name, damage);
  }

  // Check if the player won or lost
  if (player_health <= 0) {
    printf("You have been defeated. Game over!\n");
  } else {
    printf("You have defeated the %s. Congratulations!\n", enemy->name);
  }

  time_t end_time = time(NULL);
  printf("Time elapsed: %.2f seconds\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);

  return 0;
}