#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 10

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Create two warriors
  int warrior1_x = rand() % GRID_SIZE;
  int warrior1_y = rand() % GRID_SIZE;
  int warrior2_x = rand() % GRID_SIZE;
  int warrior2_y = rand() % GRID_SIZE;

  // Move the warriors randomly
  warrior1_x = rand() % GRID_SIZE;
  warrior1_y = rand() % GRID_SIZE;
  warrior2_x = rand() % GRID_SIZE;
  warrior2_y = rand() % GRID_SIZE;

  // Check if the warriors are in the same cell
  if (warrior1_x == warrior2_x && warrior1_y == warrior2_y) {
    printf("Warriors are in the same cell.\n");
  } else {
    // Calculate the distance between the warriors
    int distance = abs(warrior1_x - warrior2_x) + abs(warrior1_y - warrior2_y);

    // Attack the warrior
    if (distance <= 2) {
      printf("Warrior 1 attacks warrior 2.\n");
    } else {
      printf("Warrior 1 is too far away to attack warrior 2.\n");
    }
  }

  return 0;
}
