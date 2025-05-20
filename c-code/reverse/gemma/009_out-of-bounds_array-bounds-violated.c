#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 10

typedef struct Warrior {
  int x, y;
  int health;
  int attack_power;
} Warrior;

int main() {
  srand(time(NULL));

  Warrior warrior1 = {
    .x = rand() % GRID_SIZE,
    .y = rand() % GRID_SIZE,
    .health = 100,
    .attack_power = 20
  };

  Warrior warrior2 = {
    .x = rand() % GRID_SIZE,
    .y = rand() % GRID_SIZE,
    .health = 100,
    .attack_power = 25
  };

  while (warrior1.health > 0 && warrior2.health > 0) {
    int move_x = rand() % 3 - 1;
    int move_y = rand() % 3 - 1;

    if (move_x == 0 && move_y == 0) {
      // Attack
      int attack_x = rand() % GRID_SIZE;
      int attack_y = rand() % GRID_SIZE;

      if (warrior1.x == attack_x && warrior1.y == attack_y) {
        warrior2.health -= warrior1.attack_power;
      }
    } else {
      // Move
      warrior1.x += move_x;
      warrior1.y += move_y;
    }

    if (warrior1.x < 0) warrior1.x = 0;
    if (warrior1.x >= GRID_SIZE - 1) warrior1.x = GRID_SIZE - 1;
    if (warrior1.y < 0) warrior1.y = 0;
    if (warrior1.y >= GRID_SIZE - 1) warrior1.y = GRID_SIZE - 1;
  }

  printf("Winner: %s", warrior1.health > warrior2.health ? "Warrior 1" : "Warrior 2");

  return 0;
}
