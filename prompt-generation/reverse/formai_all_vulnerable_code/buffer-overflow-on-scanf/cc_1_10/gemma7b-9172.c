//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void bucket_sort(int **arr, int n) {
  int i, j, k, bucket_size, min, max;
  int **buckets = NULL;

  min = arr[0][0];
  max = arr[0][0];

  for (i = 0; i < n; i++) {
    min = arr[i][0] < min ? arr[i][0] : min;
    max = arr[i][0] > max ? arr[i][0] : max;
  }

  bucket_size = (max - min) / MAX_SIZE + 1;

  buckets = (int **)malloc(bucket_size * sizeof(int *));
  for (i = 0; i < bucket_size; i++) {
    buckets[i] = (int *)malloc(n * sizeof(int));
  }

  for (i = 0; i < n; i++) {
    buckets[arr[i][0] / MAX_SIZE][arr[i][0] % MAX_SIZE] = arr[i];
  }

  int **sorted_arr = (int **)malloc(n * sizeof(int *));
  for (i = 0; i < n; i++) {
    sorted_arr[i] = buckets[i][0];
  }

  free(buckets);
  free(sorted_arr);
}

int main() {
  int **arr = NULL;
  int n;

  printf("Enter the number of elements: ");
  scanf("%d", &n);

  arr = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    arr[i] = (int *)malloc(2 * sizeof(int));
  }

  printf("Enter the elements: ");
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &arr[i][0], &arr[i][1]);
  }

  bucket_sort(arr, n);

  printf("The sorted array is:\n");
  for (int i = 0; i < n; i++) {
    printf("%d %d\n", arr[i][0], arr[i][1]);
  }

  free(arr);

  return 0;
}