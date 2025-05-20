//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void bucket_sort(int **arr, int n) {
  int i, j, k, bucket_size, *buckets;

  buckets = (int *)malloc(n * sizeof(int));
  for (i = 0; i < n; i++) {
    buckets[i] = 0;
  }

  for (i = 0; i < n; i++) {
    buckets[*arr[i]]++;
  }

  for (i = 0; i < n; i++) {
    for (j = buckets[i]; j > 0; j--) {
      arr[k] = i;
      k++;
    }
  }

  free(buckets);
}

int main() {
  int i, n, *arr;

  printf("Enter the number of elements: ");
  scanf("%d", &n);

  arr = (int *)malloc(n * sizeof(int));

  printf("Enter the elements: ");
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  bucket_sort(arr, n);

  printf("Sorted array: ");
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  free(arr);

  return 0;
}