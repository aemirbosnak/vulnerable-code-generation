//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAZE_SIZE 10

int maze[MAZE_SIZE][MAZE_SIZE] = {
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
  {1, 0, 1, 0, 1, 0, 0, 0, 0, 1},
  {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
  {1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
  {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
  {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
  {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

int visited[MAZE_SIZE][MAZE_SIZE] = {
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

int stack[MAZE_SIZE*MAZE_SIZE];
int top = 0;

void push(int x, int y) {
  stack[top++] = x;
  stack[top++] = y;
}

int pop(int *x, int *y) {
  if (top == 0) {
    return 0;
  }
  *x = stack[--top];
  *y = stack[--top];
  return 1;
}

int is_valid(int x, int y) {
  return x >= 0 && x < MAZE_SIZE && y >= 0 && y < MAZE_SIZE && maze[x][y] == 0;
}

int find_path(int x, int y) {
  push(x, y);
  visited[x][y] = 1;

  while (top > 0) {
    int x, y;
    pop(&x, &y);

    if (x == MAZE_SIZE-1 && y == MAZE_SIZE-1) {
      return 1;
    }

    if (is_valid(x+1, y)) {
      push(x+1, y);
      visited[x+1][y] = 1;
    }
    if (is_valid(x-1, y)) {
      push(x-1, y);
      visited[x-1][y] = 1;
    }
    if (is_valid(x, y+1)) {
      push(x, y+1);
      visited[x][y+1] = 1;
    }
    if (is_valid(x, y-1)) {
      push(x, y-1);
      visited[x][y-1] = 1;
    }
  }

  return 0;
}

int main() {
  int x, y;
  printf("Enter starting coordinates (x, y): ");
  scanf("%d %d", &x, &y);

  if (find_path(x, y)) {
    printf("Path found!\n");
  } else {
    printf("No path found.\n");
  }

  return 0;
}