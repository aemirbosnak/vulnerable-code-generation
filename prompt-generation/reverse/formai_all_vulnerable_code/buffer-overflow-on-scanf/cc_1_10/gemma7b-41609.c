//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

void bucketSort(int **arr, int n) {
  int i, j, k, bucketSize, min, max, **bucket, **tempArr;

  min = arr[0][0];
  max = arr[0][0];
  for (i = 0; i < n; i++) {
    min = fmin(min, arr[i][0]);
    max = fmax(max, arr[i][0]);
  }

  bucketSize = (max - min) / n + 1;
  bucket = (int *)malloc(n * bucketSize * sizeof(int));
  tempArr = (int *)malloc(n * sizeof(int));

  for (i = 0; i < n; i++) {
    k = arr[i][0] - min;
    bucket[k] = 1;
  }

  for (i = 0; i < bucketSize; i++) {
    if (bucket[i] > 0) {
      for (j = 0; j < bucket[i]; j++) {
        tempArr[j] = i + min;
      }
      memcpy(arr, tempArr, n * sizeof(int));
    }
  }

  free(bucket);
  free(tempArr);
}

int main() {
  int n, i, j, **arr;

  printf("Enter the number of elements:");
  scanf("%d", &n);

  arr = (int **)malloc(n * sizeof(int *));
  for (i = 0; i < n; i++) {
    arr[i] = (int *)malloc(2 * sizeof(int));
  }

  printf("Enter the elements:");
  for (i = 0; i < n; i++) {
    scanf("%d %d", &arr[i][0], &arr[i][1]);
  }

  bucketSort(arr, n);

  printf("Sorted array:");
  for (i = 0; i < n; i++) {
    printf("%d %d ", arr[i][0], arr[i][1]);
  }

  free(arr);

  return 0;
}