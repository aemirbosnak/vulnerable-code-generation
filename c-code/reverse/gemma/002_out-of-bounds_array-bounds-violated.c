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
} Warrior;

int main() {
  Warrior warrior1 = {0, 0, 100};
  Warrior warrior2 = {5, 5, 100};

  srand(time(NULL));

  while (warrior1.health > 0 && warrior2.health > 0) {
    // Move warriors randomly
    warrior1.x = rand() % GRID_SIZE;
    warrior1.y = rand() % GRID_SIZE;
    warrior2.x = rand() % GRID_SIZE;
    warrior2.y = rand() % GRID_SIZE;

    // Check if warriors are in the same cell
    if (warrior1.x == warrior2.x && warrior1.y == warrior2.y) {
      // Attack warrior2
      warrior2.health -= 20;
    }
  }

  // Print winner
  if (warrior1.health > warrior2.health) {
    printf("Warrior 1 wins!");
  } else {
    printf("Warrior 2 wins!");
  }

  return 0;
}
