//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: innovative
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
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
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

typedef struct {
  int x;
  int y;
} point;

point stack[MAZE_SIZE * MAZE_SIZE];
int top = 0;

void push(point p) {
  stack[top++] = p;
}

point pop() {
  return stack[--top];
}

int is_valid(int x, int y) {
  return x >= 0 && x < MAZE_SIZE && y >= 0 && y < MAZE_SIZE && maze[x][y] == 0 && visited[x][y] == 0;
}

int find_path(int x, int y) {
  point p = {x, y};
  push(p);
  while (top > 0) {
    p = pop();
    if (p.x == MAZE_SIZE - 1 && p.y == MAZE_SIZE - 1) {
      return 1;
    }
    visited[p.x][p.y] = 1;
    if (is_valid(p.x - 1, p.y)) {
      push((point){p.x - 1, p.y});
    }
    if (is_valid(p.x + 1, p.y)) {
      push((point){p.x + 1, p.y});
    }
    if (is_valid(p.x, p.y - 1)) {
      push((point){p.x, p.y - 1});
    }
    if (is_valid(p.x, p.y + 1)) {
      push((point){p.x, p.y + 1});
    }
  }
  return 0;
}

int main() {
  int x, y;
  printf("Enter the starting point (x, y): ");
  scanf("%d %d", &x, &y);
  if (is_valid(x, y) && find_path(x, y)) {
    printf("Path found!\n");
  } else {
    printf("No path found!\n");
  }
  return 0;
}