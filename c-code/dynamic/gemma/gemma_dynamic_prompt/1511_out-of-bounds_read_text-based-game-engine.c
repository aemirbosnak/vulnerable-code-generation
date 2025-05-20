#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int user_input;
  char *game_data = malloc(1024);

  // Out-of-bounds read vulnerability
  printf("Enter a memory address: ");
  scanf("%d", &user_input);
  game_data[user_input] = 'A';

  free(game_data);
  return 0;
}
