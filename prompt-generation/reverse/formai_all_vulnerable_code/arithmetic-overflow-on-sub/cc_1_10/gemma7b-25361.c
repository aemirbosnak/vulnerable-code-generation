//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bucket_sort(int **arr, int n, int k) {
  int i, j, bucket_size, **buckets = NULL;
  buckets = (int**)malloc(k * sizeof(int*));
  for (i = 0; i < k; i++) {
    buckets[i] = (int*)malloc(n * sizeof(int));
  }

  for (i = 0; i < n; i++) {
    buckets[*arr[i]]++;
  }

  for (i = 0; i < k; i++) {
    for (j = 0; buckets[i] > 0; j++) {
      buckets[i][j] = arr[i];
    }
  }

  free(buckets);
}

int main() {
  int n, k, i, **arr = NULL;
  clock_t start, end;

  printf("Enter the number of elements: ");
  scanf("%d", &n);

  printf("Enter the number of buckets: ");
  scanf("%d", &k);

  arr = (int**)malloc(n * sizeof(int));

  printf("Enter the elements: ");
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  start = clock();
  bucket_sort(arr, n, k);
  end = clock();

  printf("Time taken: %.2f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

  printf("Sorted array: ");
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  free(arr);

  return 0;
}