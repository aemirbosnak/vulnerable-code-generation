//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void bucket_sort(int **arr, int n) {
  int i, j, k, bucket_size, *bucket, **sorted_arr;

  sorted_arr = (int **)malloc(n * sizeof(int *));
  for (i = 0; i < n; i++) {
    sorted_arr[i] = (int *)malloc(MAX * sizeof(int));
  }

  bucket_size = n;
  bucket = (int *)malloc(bucket_size * sizeof(int));
  for (i = 0; i < bucket_size; i++) {
    bucket[i] = 0;
  }

  for (i = 0; i < n; i++) {
    k = arr[i];
    bucket[k]++;
  }

  for (i = 1; i <= bucket_size; i++) {
    for (j = 0; bucket[j] > 0; j++) {
      sorted_arr[bucket[j]] = arr[i - 1];
      bucket[j]--;
    }
  }

  free(bucket);
  for (i = 0; i < n; i++) {
    free(sorted_arr[i]);
  }
  free(sorted_arr);
}

int main() {
  int n, i, *arr;

  printf("Enter the number of elements:");
  scanf("%d", &n);

  arr = (int *)malloc(n * sizeof(int));

  printf("Enter the elements:");
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  bucket_sort(&arr, n);

  printf("Sorted array:");
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  free(arr);

  return 0;
}