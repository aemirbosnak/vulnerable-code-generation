//Gemma-7B DATASET v1.0 Category: GPS Navigation Simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 10
#define MAP_HEIGHT 10

typedef struct Point {
  int x;
  int y;
} Point;

void print_map(Point current) {
  for (int y = 0; y < MAP_HEIGHT; y++) {
    for (int x = 0; x < MAP_WIDTH; x++) {
      if (x == current.x && y == current.y) {
        printf("X ");
      } else {
        printf(". ");
      }
    }
    printf("\n");
  }
}

int main() {
  Point current;
  current.x = 5;
  current.y = 5;

  print_map(current);

  time_t t = time(NULL);
  int delay = rand() % 1000;

  printf("Starting navigation...\n");

  while (time(NULL) - t < delay) {
    current.x++;
    current.y++;

    print_map(current);

    sleep(1);
  }

  printf("Destination reached!\n");

  return 0;
}