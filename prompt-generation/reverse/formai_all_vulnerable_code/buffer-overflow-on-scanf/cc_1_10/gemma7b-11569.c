//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void bucket_sort(int **arr, int n) {
  int i, j, k, bucket_size, min, max;

  min = arr[0][0];
  max = arr[0][0];

  for (i = 0; i < n; i++) {
    if (arr[i][0] < min) {
      min = arr[i][0];
    }
    if (arr[i][0] > max) {
      max = arr[i][0];
    }
  }

  bucket_size = (max - min) / MAX_SIZE + 1;

  int **buckets = (int **)malloc(bucket_size * sizeof(int *));
  for (i = 0; i < bucket_size; i++) {
    buckets[i] = (int *)malloc(n * sizeof(int));
  }

  for (i = 0; i < n; i++) {
    buckets[arr[i][0]]++;
  }

  for (i = 0; i < bucket_size; i++) {
    for (j = 0; j < buckets[i]; j++) {
      arr[j][0] = i;
    }
  }

  free(buckets);
}

int main() {
  int n, i, j, **arr;

  printf("Enter the number of elements: ");
  scanf("%d", &n);

  arr = (int **)malloc(n * sizeof(int *));
  for (i = 0; i < n; i++) {
    arr[i] = (int *)malloc(2 * sizeof(int));
  }

  printf("Enter the elements: ");
  for (i = 0; i < n; i++) {
    scanf("%d %d", &arr[i][0], &arr[i][1]);
  }

  bucket_sort(arr, n);

  printf("Sorted elements: ");
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i][0]);
  }

  free(arr);

  return 0;
}