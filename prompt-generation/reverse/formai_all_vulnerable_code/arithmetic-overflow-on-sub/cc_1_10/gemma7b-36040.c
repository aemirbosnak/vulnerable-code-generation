//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void bucket_sort(int **arr, int n) {
  int i, j, k, bucket_size, min, max;
  int *bucket = NULL;

  min = arr[0][0];
  max = arr[0][0];

  for (i = 0; i < n; i++) {
    for (j = 0; j < MAX_SIZE; j++) {
      if (arr[i][j] < min) {
        min = arr[i][j];
      }
      if (arr[i][j] > max) {
        max = arr[i][j];
      }
    }
  }

  bucket_size = (max - min) / MAX_SIZE + 1;
  bucket = (int *)malloc(bucket_size * MAX_SIZE * sizeof(int));

  for (i = 0; i < n; i++) {
    for (j = 0; j < MAX_SIZE; j++) {
      bucket[arr[i][j]]++;
    }
  }

  for (i = 0; i < bucket_size; i++) {
    for (j = 0; j < MAX_SIZE; j++) {
      if (bucket[j] > 0) {
        for (k = 0; k < bucket[j]; k++) {
          arr[k][j] = min + j;
        }
      }
    }
  }

  free(bucket);
}

int main() {
  int **arr = NULL;
  int n, i, j;

  scanf("Enter the number of elements: ", &n);

  arr = (int **)malloc(n * MAX_SIZE * sizeof(int));

  for (i = 0; i < n; i++) {
    for (j = 0; j < MAX_SIZE; j++) {
      arr[i][j] = -1;
    }
  }

  bucket_sort(arr, n);

  for (i = 0; i < n; i++) {
    for (j = 0; j < MAX_SIZE; j++) {
      if (arr[i][j] != -1) {
        printf("Element: (%d, %d) Value: %d\n", arr[i][j], arr[i][j], arr[i][j]);
      }
    }
  }

  free(arr);

  return 0;
}