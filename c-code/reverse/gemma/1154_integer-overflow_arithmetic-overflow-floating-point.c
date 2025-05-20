#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int n = 1000000;
  int **arr = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    arr[i] = (int *)malloc(n * sizeof(int));
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      arr[i][j] = rand() % 1000;
    }
  }

  int radius = 50;
  int minPts = 20;
  dbscan(arr, n, radius, minPts);

  return 0;
}

void dbscan(int **arr, int n, int radius, int minPts) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int distance = abs(arr[i][0] - arr[j][0]) + abs(arr[i][1] - arr[j][1]) + abs(arr[i][2] - arr[j][2]);
      if (distance < radius && arr[i][3] < minPts) {
        arr[j][3]++;
      }
    }
  }
}
