//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>

void bucketSort(int **arr, int n, int k) {
  int i, j, h, bucket[k], *p = *arr;

  for (i = 0; i < k; i++) {
    bucket[i] = 0;
  }

  for (i = 0; i < n; i++) {
    bucket[p[i]]++;
  }

  for (i = 1; i < k; i++) {
    bucket[i] += bucket[i - 1];
  }

  h = bucket[k - 1];

  for (i = n - 1; i >= 0; i--) {
    p[bucket[p[i]] - 1] = i;
    bucket[p[i]]--;
  }

  free(bucket);
}

int main() {
  int n, k, i, *arr;

  printf("Enter the number of elements:");
  scanf("%d", &n);

  printf("Enter the number of buckets:");
  scanf("%d", &k);

  arr = (int *)malloc(n * sizeof(int));

  printf("Enter the elements:");
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  bucketSort(&arr, n, k);

  printf("Sorted array:");
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  free(arr);

  return 0;
}