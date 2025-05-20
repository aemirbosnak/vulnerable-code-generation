//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void bucket_sort(int **arr, int n) {
  int i, j, k, bucket_size, min, max, hash, count[MAX] = {0};

  min = arr[0][0];
  max = arr[0][0];
  for (i = 0; i < n; i++) {
    min = fmin(min, arr[i][0]);
    max = fmax(max, arr[i][0]);
  }

  bucket_size = (max - min) / MAX + 1;
  hash = min;

  for (i = 0; i < n; i++) {
    count[arr[i][0]]++;
  }

  for (j = 0; j < bucket_size; j++) {
    if (count[j] > 0) {
      for (k = 0; k < count[j]; k++) {
        arr[k][0] = hash;
      }
    }
    hash++;
  }
}

int main() {
  int n, i, **arr;

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

  return 0;
}