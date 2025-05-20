//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: statistical
#include <stdio.h>

// C Bucket Sort Implementation example program
int main() {
  // Create an array of 10 integers
  int arr[] = {3, 8, 4, 5, 9, 1, 7, 2, 6, 10};

  // Create an array to hold the buckets
  int buckets[10];

  // Create an array to hold the bucket size
  int bucket_sizes[10];

  // Set all bucket sizes to 0
  for (int i = 0; i < 10; i++) {
    bucket_sizes[i] = 0;
  }

  // Sort the array using Bucket Sort
  int n = sizeof(arr) / sizeof(arr[0]);
  int i, j, k, temp;
  for (i = 0; i < n; i++) {
    j = i;
    while (j < n && arr[j] <= arr[i]) {
      j++;
    }
    k = i;
    while (k > j && arr[k] <= arr[j]) {
      k--;
    }
    if (k < j) {
      temp = arr[j];
      arr[j] = arr[k];
      arr[k] = temp;
    }
    bucket_sizes[arr[i] % 10]++;
  }

  // Print the sorted array
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  // Print the bucket sizes
  for (i = 0; i < 10; i++) {
    printf("%d ", bucket_sizes[i]);
  }
  printf("\n");

  // Print the sorted array again
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}