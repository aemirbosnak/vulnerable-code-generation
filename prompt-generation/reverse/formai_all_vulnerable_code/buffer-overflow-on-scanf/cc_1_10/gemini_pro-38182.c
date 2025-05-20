//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// Function to sort the array using Bucket Sort
void bucketSort(int *arr, int n) {
  // Create n empty buckets
  int **buckets = malloc(sizeof(int *) * n);
  for (int i = 0; i < n; i++) {
    buckets[i] = malloc(sizeof(int));
    *buckets[i] = 0;
  }

  // Distribute the elements into the buckets
  for (int i = 0; i < n; i++) {
    // Calculate the index of the bucket to which the element belongs
    int bucketIndex = arr[i] / n;
    // Increment the count of the element in the bucket
    (*buckets[bucketIndex])++;
  }

  // Sort each bucket individually
  for (int i = 0; i < n; i++) {
    if (*buckets[i] > 0) {
      int *bucket = buckets[i];
      int bucketSize = *buckets[i];
      // Sort the bucket using any sorting algorithm
      // In this example, we are using Insertion Sort
      for (int j = 1; j < bucketSize; j++) {
        int key = bucket[j];
        int k = j - 1;
        while (k >= 0 && bucket[k] > key) {
          bucket[k + 1] = bucket[k];
          k--;
        }
        bucket[k + 1] = key;
      }
    }
  }

  // Concatenate the sorted buckets into the original array
  int k = 0;
  for (int i = 0; i < n; i++) {
    int *bucket = buckets[i];
    int bucketSize = *buckets[i];
    for (int j = 0; j < bucketSize; j++) {
      arr[k++] = *bucket;
      bucket++;
    }
    free(buckets[i]);
  }
  free(buckets);
}

// Function to print the array
void printArray(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  int n;
  printf("Enter the size of the array: ");
  scanf("%d", &n);

  int *arr = malloc(sizeof(int) * n);
  printf("Enter the elements of the array: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  bucketSort(arr, n);

  printf("Sorted array: ");
  printArray(arr, n);

  free(arr);

  return 0;
}