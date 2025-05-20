#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
  int n, m, i, j, x, y, cost, min_cost = INT_MAX;
  scanf(" %d %d ", &n, &m);
  int **maze = (int **)malloc(n * sizeof(int *));
  for (i = 0; i < n; i++) {
    maze[i] = (int *)malloc(m * sizeof(int));
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      scanf(" %d ", &maze[i][j]);
    }
  }
  scanf(" %d ", &x);
  scanf(" %d ", &y);
  cost = maze[x][y];
  if (cost != -1) {
    min_cost = cost;
  }
  printf(" %d ", min_cost);
  return 0;
}
