//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void bucketSort(int **arr, int n) {
  int i, j, k, bucketSize, min, max, hash, count = 0;
   bucketSize = n / MAX_SIZE;
  min = arr[0][0];
  max = arr[0][1];
  for (i = 0; i < n; i++) {
    hash = arr[i][0] / bucketSize;
    count++;
    arr[i][2] = count;
  }

  for (i = 0; i < bucketSize; i++) {
    for (j = 0; j < count; j++) {
      if (arr[j][2] == i + 1) {
        for (k = 0; k < MAX_SIZE; k++) {
          arr[j][k] = arr[i][k];
        }
      }
    }
  }

  for (i = 0; i < n; i++) {
    printf("%d ", arr[i][0]);
  }
  printf("\n");

  for (i = 0; i < n; i++) {
    printf("%d ", arr[i][1]);
  }
  printf("\n");
}

int main() {
  int n, i;
  int **arr = NULL;

  printf("Enter the number of elements: ");
  scanf("%d", &n);

  arr = (int **)malloc(n * sizeof(int *) + MAX_SIZE * sizeof(int));

  for (i = 0; i < n; i++) {
    arr[i] = (int *)malloc(MAX_SIZE * sizeof(int));
  }

  bucketSort(arr, n);

  return 0;
}