//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bucket_sort(int **arr, int n) {
  int i, j, k, min, max, buckets[n], count[n], pos[n];
  for (i = 0; i < n; i++) {
    buckets[i] = 0;
    count[i] = 0;
    pos[i] = 0;
  }
  min = arr[0][0];
  max = arr[0][0];
  for (i = 0; i < n; i++) {
    min = fmin(min, arr[i][0]);
    max = fmax(max, arr[i][0]);
  }
  for (i = 0; i < max - min + 1; i++) {
    buckets[i] = 0;
  }
  for (i = 0; i < n; i++) {
    buckets[arr[i][0] - min]++ ;
  }
  for (i = 0; i < max - min + 1; i++) {
    count[i] = buckets[i];
  }
  for (i = 0; i < n; i++) {
    pos[i] = count[arr[i][0] - min] - 1;
  }
  for (i = 0; i < n; i++) {
    arr[i][1] = pos[i] + 1;
  }
}

int main() {
  int n, i, j, arr[10][2], **arr_ptr = arr;
  scanf("Enter the number of elements: ", &n);
  arr_ptr = (int **)malloc(n * sizeof(int *) + 1);
  arr_ptr[0] = (int *)malloc(n * sizeof(int) * 2);
  for (i = 0; i < n; i++) {
    for (j = 0; j < 2; j++) {
      scanf("Enter the element: ", &arr[i][j]);
    }
  }
  bucket_sort(arr_ptr, n);
  printf("The sorted array is:\n");
  for (i = 0; i < n; i++) {
    printf("(%d, %d)\n", arr[i][0], arr[i][1]);
  }
  free(arr_ptr[0]);
  free(arr_ptr);
  return 0;
}