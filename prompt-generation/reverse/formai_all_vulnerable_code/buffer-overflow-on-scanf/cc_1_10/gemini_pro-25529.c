//GEMINI-pro DATASET v1.0 Category: Pathfinding algorithms ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

typedef struct {
  int x;
  int y;
} point;

typedef struct {
  point start;
  point end;
} path;

char map[MAX_WIDTH][MAX_HEIGHT];
int width, height;

int get_distance(point a, point b) {
  return abs(a.x - b.x) + abs(a.y - b.y);
}

int is_valid_point(point p) {
  return (p.x >= 0 && p.x < width && p.y >= 0 && p.y < height && map[p.x][p.y] != '#');
}

int is_path_valid(path p) {
  return (is_valid_point(p.start) && is_valid_point(p.end));
}

int find_path(path *p) {
  if (!is_path_valid(*p)) {
    return 0;
  }

  // Initialize the queue with the start point
  point queue[MAX_WIDTH * MAX_HEIGHT];
  int head = 0;
  int tail = 0;
  queue[tail++] = p->start;

  // Initialize the distance map
  int distance[MAX_WIDTH][MAX_HEIGHT];
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < height; j++) {
      distance[i][j] = -1;
    }
  }
  distance[p->start.x][p->start.y] = 0;

  // BFS
  while (head < tail) {
    point current = queue[head++];

    // Check if we have reached the end point
    if (current.x == p->end.x && current.y == p->end.y) {
      return distance[current.x][current.y];
    }

    // Add the neighbors to the queue
    point neighbors[] = {
      {current.x - 1, current.y},
      {current.x + 1, current.y},
      {current.x, current.y - 1},
      {current.x, current.y + 1},
    };
    for (int i = 0; i < 4; i++) {
      point neighbor = neighbors[i];
      if (is_valid_point(neighbor) && distance[neighbor.x][neighbor.y] == -1) {
        distance[neighbor.x][neighbor.y] = distance[current.x][current.y] + 1;
        queue[tail++] = neighbor;
      }
    }
  }

  // No path found
  return -1;
}

int main() {
  // Read the input
  scanf("%d %d", &width, &height);
  for (int i = 0; i < height; i++) {
    scanf("%s", map[i]);
  }

  // Find the path
  path p;
  scanf("%d %d %d %d", &p.start.x, &p.start.y, &p.end.x, &p.end.y);
  int distance = find_path(&p);

  // Print the output
  if (distance == -1) {
    printf("No path found\n");
  } else {
    printf("Path found with distance %d\n", distance);
  }

  return 0;
}