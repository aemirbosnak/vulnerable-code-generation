//Gemma-7B DATASET v1.0 Category: Sorting ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void sort(int **arr, int n) {
  if (n <= 1) {
    return;
  }
  int i, j, k, min, temp;

  for (i = 0; i < n - 1; i++) {
    min = i;
    for (j = i + 1; j < n; j++) {
      if (arr[j] < arr[min]) {
        min = j;
      }
    }
    temp = arr[min];
    arr[min] = arr[i];
    arr[i] = temp;
  }

  sort(arr, n - 1);
}

int main() {
  int n;
  scanf("%d", &n);

  int **arr = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    arr[i] = (int *)malloc(n * sizeof(int));
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &arr[i][j]);
    }
  }

  sort(arr, n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }

  free(arr);

  return 0;
}