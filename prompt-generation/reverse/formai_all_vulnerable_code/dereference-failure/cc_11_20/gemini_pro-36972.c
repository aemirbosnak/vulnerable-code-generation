//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

#define BUCKETS 10

int main() {
  int n, i, j, k, l;
  int* arr;
  int max = 0;
  int** buckets;

  printf("Enter the number of elements: ");
  scanf("%d", &n);

  arr = (int*)malloc(n * sizeof(int));

  printf("Enter the elements of the array: ");
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
    if (arr[i] > max)
      max = arr[i];
  }

  buckets = (int**)malloc(BUCKETS * sizeof(int*));
  for (i = 0; i < BUCKETS; i++) {
    buckets[i] = (int*)malloc((max + 1) * sizeof(int));
    for (j = 0; j <= max; j++) {
      buckets[i][j] = 0;
    }
  }

  for (i = 0; i < n; i++) {
    buckets[arr[i] / BUCKETS][arr[i]]++;
  }

  l = 0;
  for (i = 0; i < BUCKETS; i++) {
    for (j = 0; j <= max; j++) {
      for (k = 0; k < buckets[i][j]; k++) {
        arr[l++] = j;
      }
    }
  }

  printf("Sorted array: ");
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  for (i = 0; i < BUCKETS; i++) {
    free(buckets[i]);
  }
  free(buckets);
  free(arr);

  return 0;
}