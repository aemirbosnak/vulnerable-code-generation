//GEMINI-pro DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

#define MAX_X 100
#define MAX_Y 100
#define MAX_Z 100
#define MAX_NODES 10000

typedef struct node {
  int x, y, z;
  struct node *parent;
  float g, h, f;
} node;

node *nodes[MAX_NODES];
int num_nodes = 0;

int grid[MAX_X][MAX_Y][MAX_Z];

void add_node(int x, int y, int z, node *parent) {
  node *n = malloc(sizeof(node));
  n->x = x;
  n->y = y;
  n->z = z;
  n->parent = parent;
  n->g = parent ? parent->g + 1 : 0;
  n->h = sqrtf((x - MAX_X / 2) * (x - MAX_X / 2) + (y - MAX_Y / 2) * (y - MAX_Y / 2) + (z - MAX_Z / 2) * (z - MAX_Z / 2));
  n->f = n->g + n->h;
  nodes[num_nodes++] = n;
}

int compare_nodes(const void *a, const void *b) {
  node *n1 = *(node **)a;
  node *n2 = *(node **)b;
  return n1->f - n2->f;
}

node *a_star(int start_x, int start_y, int start_z, int end_x, int end_y, int end_z) {
  add_node(start_x, start_y, start_z, NULL);

  while (num_nodes > 0) {
    qsort(nodes, num_nodes, sizeof(node *), compare_nodes);
    node *current = nodes[0];
    if (current->x == end_x && current->y == end_y && current->z == end_z) {
      return current;
    }

    for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
        for (int k = -1; k <= 1; k++) {
          if (i == 0 && j == 0 && k == 0) {
            continue;
          }
          int x = current->x + i;
          int y = current->y + j;
          int z = current->z + k;
          if (x < 0 || x >= MAX_X || y < 0 || y >= MAX_Y || z < 0 || z >= MAX_Z || grid[x][y][z] > 0) {
            continue;
          }
          add_node(x, y, z, current);
        }
      }
    }

    nodes[0] = nodes[num_nodes - 1];
    num_nodes--;
  }

  return NULL;
}

void print_path(node *n) {
  if (!n) {
    printf("No path found.\n");
    return;
  }

  printf("Path: ");
  while (n) {
    printf("(%d, %d, %d) ", n->x, n->y, n->z);
    n = n->parent;
  }
  printf("\n");
}

int main() {
  int start_x, start_y, start_z, end_x, end_y, end_z;
  printf("Enter start coordinates (x, y, z): ");
  scanf("%d %d %d", &start_x, &start_y, &start_z);
  printf("Enter end coordinates (x, y, z): ");
  scanf("%d %d %d", &end_x, &end_y, &end_z);

  node *path = a_star(start_x, start_y, start_z, end_x, end_y, end_z);
  print_path(path);

  return 0;
}