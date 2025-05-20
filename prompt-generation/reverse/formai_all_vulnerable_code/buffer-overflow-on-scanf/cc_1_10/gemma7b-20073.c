//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 50
#define MAX_HEIGHT 20

void draw_map(int **map, int width, int height) {
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      switch (map[y][x]) {
        case 0:
          printf(" ");
          break;
        case 1:
          printf("#");
          break;
        case 2:
          printf("O");
          break;
      }
    }
    printf("\n");
  }
}

int main() {
  int **map = NULL;
  int width, height;

  printf("Enter map dimensions (width, height): ");
  scanf("%d %d", &width, &height);

  map = (int **)malloc(height * sizeof(int *) + height);
  for (int i = 0; i < height; i++) {
    map[i] = (int *)malloc(width * sizeof(int) + width);
  }

  // Create a map
  map[0][0] = 2;
  map[0][1] = 1;
  map[1][0] = 1;
  map[1][1] = 0;
  map[1][2] = 2;

  // Draw the map
  draw_map(map, width, height);

  free(map);

  return 0;
}