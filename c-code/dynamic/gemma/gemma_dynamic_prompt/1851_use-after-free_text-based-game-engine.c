#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void free_game_object(void *object) {
  free(object);
}

int main() {
  int *game_object = malloc(10 * sizeof(int));
  game_object[0] = 10;
  game_object[1] = 20;
  game_object[2] = 30;

  free_game_object(game_object);

  // Use of the freed memory, causing a use after free vulnerability
  printf("%d", game_object[0]);

  return 0;
}
