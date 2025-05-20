//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 10

int map[GRID_SIZE][GRID_SIZE];

void generateMap() {
  for (int x = 0; x < GRID_SIZE; x++) {
    for (int y = 0; y < GRID_SIZE; y++) {
      map[x][y] = rand() % 2;
    }
  }
}

void printMap() {
  for (int x = 0; x < GRID_SIZE; x++) {
    for (int y = 0; y < GRID_SIZE; y++) {
      printf("%d ", map[x][y]);
    }
    printf("\n");
  }
}

int navigate(int startX, int startY, int endX, int endY) {
  int distance = abs(endX - startX) + abs(endY - startY);
  int pathFound = 0;

  while (distance > 0) {
    printf("Distance left: %d\n", distance);

    if (startX < endX && map[startX+1][startY] == 1) {
      printf("Moving right...\n");
      startX++;
      distance--;
    }
    else if (startX > endX && map[startX-1][startY] == 1) {
      printf("Moving left...\n");
      startX--;
      distance--;
    }
    else if (startY < endY && map[startX][startY+1] == 1) {
      printf("Moving down...\n");
      startY++;
      distance--;
    }
    else if (startY > endY && map[startX][startY-1] == 1) {
      printf("Moving up...\n");
      startY--;
      distance--;
    }
    else {
      printf("No path found!\n");
      pathFound = -1;
      break;
    }
  }

  if (pathFound != -1) {
    printf("Destination reached!\n");
  }

  return pathFound;
}

int main() {
  srand(time(NULL));
  generateMap();
  printMap();

  int startX, startY, endX, endY;

  printf("Enter start X: ");
  scanf("%d", &startX);

  printf("Enter start Y: ");
  scanf("%d", &startY);

  printf("Enter end X: ");
  scanf("%d", &endX);

  printf("Enter end Y: ");
  scanf("%d", &endY);

  navigate(startX, startY, endX, endY);

  return 0;
}