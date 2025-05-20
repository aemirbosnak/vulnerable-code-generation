//GEMINI-pro DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Cryptic
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
  int x, y;
} Point;

typedef struct {
  char c;
  int fg, bg;
} Tile;

typedef struct {
  int w, h;
  Tile *tiles;
} Map;

#define MAP_WIDTH  80
#define MAP_HEIGHT 25

int main() {
  // Seed the random number generator.
  srand(time(NULL));

  // Create the map.
  Map map = {MAP_WIDTH, MAP_HEIGHT, malloc(sizeof(Tile) * MAP_WIDTH * MAP_HEIGHT)};

  // Generate the map.
  for (int i = 0; i < MAP_WIDTH * MAP_HEIGHT; i++) {
    map.tiles[i].c = rand() % 26 + 'a';
    map.tiles[i].fg = rand() % 256;
    map.tiles[i].bg = rand() % 256;
  }

  // Place the player.
  Point player = {MAP_WIDTH / 2, MAP_HEIGHT / 2};

  // Main game loop.
  while (1) {
    // Draw the map.
    for (int y = 0; y < MAP_HEIGHT; y++) {
      for (int x = 0; x < MAP_WIDTH; x++) {
        printf("%c", map.tiles[y * MAP_WIDTH + x].c);
      }
      printf("\n");
    }

    // Get the player's input.
    char input = getchar();

    // Move the player.
    switch (input) {
      case 'w':
        player.y--;
        break;
      case 's':
        player.y++;
        break;
      case 'a':
        player.x--;
        break;
      case 'd':
        player.x++;
        break;
    }

    // Check if the player has won.
    if (player.x == MAP_WIDTH - 1 && player.y == MAP_HEIGHT - 1) {
      printf("You win!\n");
      break;
    }
  }

  // Free the map.
  free(map.tiles);

  return 0;
}