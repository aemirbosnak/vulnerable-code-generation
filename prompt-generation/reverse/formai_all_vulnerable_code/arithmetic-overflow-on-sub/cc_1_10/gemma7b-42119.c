//Gemma-7B DATASET v1.0 Category: Procedural Space Adventure ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENEMY_COUNT 5
#define MAX_POWER_LEVEL 10

typedef struct Enemy {
  char name[20];
  int health;
  int powerLevel;
} Enemy;

void battle(Enemy *enemy) {
  int damage = rand() % enemy->powerLevel + 1;
  enemy->health -= damage;
  printf("You attacked %s with %d damage, and it has %d health left.\n", enemy->name, damage, enemy->health);
  if (enemy->health <= 0) {
    printf("You have defeated %s!\n", enemy->name);
  } else {
    printf("It is still alive.\n");
  }
}

int main() {
  Enemy enemies[MAX_ENEMY_COUNT];
  int enemyCount = 0;
  int powerLevel = 0;
  time_t t;

  // Generate enemies
  while (enemyCount < MAX_ENEMY_COUNT) {
    enemies[enemyCount].name[0] = 'E' + enemyCount;
    enemies[enemyCount].health = rand() % MAX_POWER_LEVEL + 1;
    enemies[enemyCount].powerLevel = rand() % MAX_POWER_LEVEL + 1;
    enemyCount++;
  }

  // Set power level
  powerLevel = rand() % MAX_POWER_LEVEL + 1;

  // Start timer
  t = time(NULL);

  // Battle
  for (int i = 0; i < enemyCount; i++) {
    battle(&enemies[i]);
  }

  // End timer
  t = time(NULL) - t;

  // Print time taken
  printf("Total time taken: %d seconds\n", t);

  return 0;
}