//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAZE_WIDTH 10
#define MAZE_HEIGHT 10

int maze[MAZE_HEIGHT][MAZE_WIDTH] = {
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

int visited[MAZE_HEIGHT][MAZE_WIDTH];

struct position {
  int x;
  int y;
};

struct queue {
  struct position* positions;
  int front;
  int rear;
  int size;
};

void enqueue(struct queue* q, struct position pos) {
  if (q->rear == q->size - 1) {
    printf("Queue is full");
  } else {
    q->positions[++q->rear] = pos;
  }
}

struct position dequeue(struct queue* q) {
  if (q->front == q->rear) {
    printf("Queue is empty");
  } else {
    return q->positions[++q->front];
  }
}

int is_valid(int x, int y) {
  return x >= 0 && x < MAZE_HEIGHT && y >= 0 && y < MAZE_WIDTH && !visited[x][y] && !maze[x][y];
}

void print_maze(int** maze, int height, int width) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      printf("%d ", maze[i][j]);
    }
    printf("\n");
  }
}

int find_path(int** maze, int height, int width, int start_x, int start_y, int end_x, int end_y) {
  struct queue q;
  q.front = q.rear = -1;
  q.size = height * width;
  q.positions = malloc(q.size * sizeof(struct position));

  struct position start = {start_x, start_y};
  enqueue(&q, start);

  while (q.front != q.rear) {
    struct position current = dequeue(&q);

    if (current.x == end_x && current.y == end_y) {
      return 1;
    }

    visited[current.x][current.y] = 1;

    if (is_valid(current.x - 1, current.y)) {
      struct position next = {current.x - 1, current.y};
      enqueue(&q, next);
    }

    if (is_valid(current.x + 1, current.y)) {
      struct position next = {current.x + 1, current.y};
      enqueue(&q, next);
    }

    if (is_valid(current.x, current.y - 1)) {
      struct position next = {current.x, current.y - 1};
      enqueue(&q, next);
    }

    if (is_valid(current.x, current.y + 1)) {
      struct position next = {current.x, current.y + 1};
      enqueue(&q, next);
    }
  }

  return 0;
}

int main() {
  int start_x, start_y, end_x, end_y;

  printf("Enter the starting coordinates (x, y): ");
  scanf("%d %d", &start_x, &start_y);

  printf("Enter the ending coordinates (x, y): ");
  scanf("%d %d", &end_x, &end_y);

  if (find_path(maze, MAZE_HEIGHT, MAZE_WIDTH, start_x, start_y, end_x, end_y)) {
    printf("Path found!\n");
  } else {
    printf("No path found.\n");
  }

  return 0;
}