//Code Llama-13B DATASET v1.0 Category: Procedurally Generated Maze ; Style: real-life
// Procedurally Generated Maze in C

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10
#define TILES 100

// Structures
typedef struct {
  int x;
  int y;
} Coord;

typedef struct {
  int up;
  int down;
  int left;
  int right;
} Connections;

// Functions
void generate_maze(Coord** tiles, Connections** connections, int width, int height);
void print_maze(Coord** tiles, Connections** connections, int width, int height);

int main() {
  srand(time(NULL));

  Coord** tiles = malloc(WIDTH * HEIGHT * sizeof(Coord*));
  Connections** connections = malloc(WIDTH * HEIGHT * sizeof(Connections*));

  generate_maze(tiles, connections, WIDTH, HEIGHT);
  print_maze(tiles, connections, WIDTH, HEIGHT);

  return 0;
}

void generate_maze(Coord** tiles, Connections** connections, int width, int height) {
  for (int i = 0; i < width * height; i++) {
    tiles[i] = malloc(sizeof(Coord));
    connections[i] = malloc(sizeof(Connections));
  }

  // Initialize tiles and connections
  for (int i = 0; i < width * height; i++) {
    tiles[i]->x = i % width;
    tiles[i]->y = i / width;

    connections[i]->up = 0;
    connections[i]->down = 0;
    connections[i]->left = 0;
    connections[i]->right = 0;
  }

  // Generate maze
  for (int i = 0; i < width * height; i++) {
    int x = tiles[i]->x;
    int y = tiles[i]->y;

    // Check if current tile is a dead end
    if (x == 0 || x == width - 1 || y == 0 || y == height - 1) {
      continue;
    }

    // Generate random number for direction
    int dir = rand() % 4;

    // Check if current tile is already connected to another tile
    if (connections[i]->up == 1 || connections[i]->down == 1 || connections[i]->left == 1 || connections[i]->right == 1) {
      continue;
    }

    // Connect current tile to another tile
    if (dir == 0) {
      int j = i - width;
      connections[i]->up = 1;
      connections[j]->down = 1;
    } else if (dir == 1) {
      int j = i + width;
      connections[i]->down = 1;
      connections[j]->up = 1;
    } else if (dir == 2) {
      int j = i - 1;
      connections[i]->left = 1;
      connections[j]->right = 1;
    } else {
      int j = i + 1;
      connections[i]->right = 1;
      connections[j]->left = 1;
    }
  }
}

void print_maze(Coord** tiles, Connections** connections, int width, int height) {
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      int i = y * width + x;

      // Check if current tile is a wall
      if (connections[i]->up == 1 || connections[i]->down == 1 || connections[i]->left == 1 || connections[i]->right == 1) {
        printf("#");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}