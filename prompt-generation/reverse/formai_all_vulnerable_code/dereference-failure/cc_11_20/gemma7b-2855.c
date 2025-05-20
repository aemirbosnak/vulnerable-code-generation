//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 20

void percolate(int **arr, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (arr[i][j] > 0) {
        int x = i;
        int y = j;
        int direction = rand() % 4;
        switch (direction) {
          case 0:
            if (x - 1 >= 0 && arr[x - 1][y] == 0) {
              arr[x - 1][y] = arr[x][y];
              arr[x][y] = 0;
            }
            break;
          case 1:
            if (x + 1 < size && arr[x + 1][y] == 0) {
              arr[x + 1][y] = arr[x][y];
              arr[x][y] = 0;
            }
            break;
          case 2:
            if (y - 1 >= 0 && arr[x][y - 1] == 0) {
              arr[x][y - 1] = arr[x][y];
              arr[x][y] = 0;
            }
            break;
          case 3:
            if (y + 1 < size && arr[x][y + 1] == 0) {
              arr[x][y + 1] = arr[x][y];
              arr[x][y] = 0;
            }
            break;
        }
      }
    }
  }
}

int main() {
  int **arr = (int **)malloc(MAX_SIZE * sizeof(int *));
  for (int i = 0; i < MAX_SIZE; i++) {
    arr[i] = (int *)malloc(MAX_SIZE * sizeof(int));
  }

  srand(time(NULL));

  for (int i = 0; i < MAX_SIZE; i++) {
    for (int j = 0; j < MAX_SIZE; j++) {
      arr[i][j] = rand() % 2;
    }
  }

  percolate(arr, MAX_SIZE);

  for (int i = 0; i < MAX_SIZE; i++) {
    for (int j = 0; j < MAX_SIZE; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }

  free(arr);

  return 0;
}