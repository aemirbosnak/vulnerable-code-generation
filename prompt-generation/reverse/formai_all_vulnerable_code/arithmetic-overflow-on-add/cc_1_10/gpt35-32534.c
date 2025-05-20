//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: minimalist
#include <stdio.h>
#define ARRAY_SIZE 10
#define BUCKET_SIZE 5

void bucketSort(int *arr, int size, int range) {
  int i, j, k;
  int ret_arr[size];
  int bucket[BUCKET_SIZE];

  // Traverse through input array
  for (i = 0; i < size; i++) {
    for (j = 0; j < BUCKET_SIZE; j++) {
      bucket[j] = 0;
    }

    // Store values in respective bucket
    for (j = 0; j < size; j++) {
      if (arr[j] / range == i) {
        bucket[arr[j] % range]++;
      }
    }

    // Update original array with sorted values
    for (j = 0, k = 0; j < BUCKET_SIZE; j++) {
      k += bucket[j];
      bucket[j] = k;
    }
    for (j = size - 1; j >= 0; j--) {
      if (arr[j] / range == i) {
        ret_arr[--bucket[arr[j] % range]] = arr[j];
      }
    }
  }

  // Copy sorted array back to original array
  for (i = 0; i < size; i++) {
    arr[i] = ret_arr[i];
  }
}

void printArray(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  int arr[ARRAY_SIZE] = {534, 246, 933, 127, 277, 321, 454, 565, 220, 34};
  printf("Input Array: ");
  printArray(arr, ARRAY_SIZE);

  bucketSort(arr, ARRAY_SIZE, 100);

  printf("Sorted Array: ");
  printArray(arr, ARRAY_SIZE);

  return 0;
}