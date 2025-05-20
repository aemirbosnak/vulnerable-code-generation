#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <limits.h>

int main() {
  int x_max = INT_MAX / 2;
  int y_max = INT_MAX / 2;
  int cost_max = INT_MAX / 2;

  int x_start = 0;
  int y_start = 0;
  int x_end = x_max - 1;
  int y_end = y_max - 1;

  int **distance = (int **)malloc(sizeof(int *) * y_max);
  for (int i = 0; i < y_max; i++) {
    distance[i] = (int *)malloc(sizeof(int) * x_max);
    for (int j = 0; j < x_max; j++) {
      distance[i][j] = cost_max;
    }
  }

  distance[y_start][x_start] = 0;

  // Dijkstra's algorithm implementation

  // ...

  // Print the shortest path

  for (int i = 0; i < y_max; i++) {
    for (int j = 0; j < x_max; j++) {
      printf("%d ", distance[i][j]);
    }
    printf("\n");
  }

  return 0;
}
