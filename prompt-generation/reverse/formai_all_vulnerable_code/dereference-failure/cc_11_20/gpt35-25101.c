//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node {
  int x;
  int y;
  int dist;
  int total_dist;
  struct node *parent;
} node;

int euclidean_dist(int x1, int y1, int x2, int y2) {
  int x = x2 - x1;
  int y = y2 - y1;
  return sqrt((x * x) + (y * y));
}

void pathfind(int start_x, int start_y, int end_x, int end_y, int **grid, int width, int height) {
  node *open_list[width * height];
  node *closed_list[width * height];
  int num_open = 0;
  int num_closed = 0;

  node *start_node = malloc(sizeof(node));
  start_node->x = start_x;
  start_node->y = start_y;
  start_node->dist = 0;
  start_node->total_dist = euclidean_dist(start_x, start_y, end_x, end_y);
  start_node->parent = NULL;
  open_list[num_open++] = start_node;

  while (num_open > 0) {
    node *curr_node = open_list[0];

    for (int i = 0; i < num_open - 1; ++i) {
      open_list[i] = open_list[i+1];
    }
    num_open--;

    if (curr_node->x == end_x && curr_node->y == end_y) {
      node *node_path = curr_node;
      printf("Found Path. Going from (%d, %d) to (%d, %d)\n", start_x, start_y, end_x, end_y);
      while (node_path != NULL) {
        printf("(%d, %d)\n", node_path->x, node_path->y);
        node_path = node_path->parent;
      }
      return;
    }

    int x = curr_node->x;
    int y = curr_node->y;
    int curr_dist = curr_node->dist;

    for (int i = -1; i <= 1; ++i) {
      for (int j = -1; j <= 1; ++j) {
        if (i == 0 && j == 0) {
          continue;
        }

        int new_x = x + i;
        int new_y = y + j;

        if (new_x < 0 || new_y < 0 || new_x >= width || new_y >= height) {
          continue;
        }

        int new_dist;
        if (i == 0 || j == 0) {
          new_dist = curr_dist + 1;
        } else {
          new_dist = curr_dist + 2;
        }

        if (grid[new_x][new_y] == 1) {
          continue;
        }

        int found_in_open = 0;
        for (int k = 0; k < num_open; ++k) {
          if (open_list[k]->x == new_x && open_list[k]->y == new_y) {
            node *old_node = open_list[k];
            if (new_dist < old_node->dist) {
              old_node->dist = new_dist;
              old_node->parent = curr_node;
              old_node->total_dist = new_dist + euclidean_dist(new_x, new_y, end_x, end_y);
            }
            found_in_open = 1;
            break;
          }
        }

        if (found_in_open) {
          continue;
        }

        int found_in_closed = 0;
        for (int k = 0; k < num_closed; ++k) {
          if (closed_list[k]->x == new_x && closed_list[k]->y == new_y) {
            found_in_closed = 1;
            break;
          }
        }

        if (found_in_closed) {
          continue;
        }

        node *new_node = malloc(sizeof(node));
        new_node->x = new_x;
        new_node->y = new_y;
        new_node->dist = new_dist;
        new_node->parent = curr_node;
        new_node->total_dist = new_dist + euclidean_dist(new_x, new_y, end_x, end_y);

        open_list[num_open++] = new_node;
      }
    }

    closed_list[num_closed++] = curr_node;

    for (int i = 0; i < num_open-1; ++i) {
      int min_total_dist = open_list[i]->total_dist;
      node *min_node = open_list[i];
      for (int j = i+1; j < num_open; ++j) {
        if (open_list[j]->total_dist < min_total_dist) {
          min_total_dist = open_list[j]->total_dist;
          min_node = open_list[j];
        }
      }
      if (min_total_dist < open_list[i]->total_dist) {
        open_list[i] = min_node;
        open_list[num_open-1] = min_total_dist;
      }
    }
  }
}

int main() {
  int width = 10;
  int height = 10;

  int **grid = malloc(width * sizeof(int *));
  for (int i = 0; i < width; ++i) {
    grid[i] = malloc(height * sizeof(int));
  }

  for (int i = 0; i < width; ++i) {
    for (int j = 0; j < height; ++j) {
      grid[i][j] = 0;
    }
  }

  grid[2][3] = 1;
  grid[2][4] = 1;
  grid[2][5] = 1;
  grid[3][5] = 1;
  grid[4][5] = 1;
  grid[4][4] = 1;
  grid[4][3] = 1;

  pathfind(0, 0, 9, 9, grid, width, height);

  return 0;
}