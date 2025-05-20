//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Function to sort an array using bucket sort
void bucketSort(int *arr, int n) {
  // Create n empty buckets
  int **buckets = malloc(sizeof(int *) * n);
  for (int i = 0; i < n; i++) {
    buckets[i] = malloc(sizeof(int));
    *buckets[i] = 0;
  }

  // Distribute the elements into the buckets
  for (int i = 0; i < n; i++) {
    int bucketIndex = arr[i] / n;
    (*buckets[bucketIndex])++;
  }

  // Sort each bucket
  for (int i = 0; i < n; i++) {
    int *bucket = buckets[i];
    int bucketSize = *bucket;

    // Create a new array to store the sorted elements
    int *sortedBucket = malloc(sizeof(int) * bucketSize);

    // Sort the bucket using any sorting algorithm (e.g., insertion sort)
    for (int j = 0; j < bucketSize - 1; j++) {
      for (int k = j + 1; k < bucketSize; k++) {
        if (sortedBucket[j] > sortedBucket[k]) {
          int temp = sortedBucket[j];
          sortedBucket[j] = sortedBucket[k];
          sortedBucket[k] = temp;
        }
      }
    }

    // Copy the sorted elements back into the bucket
    for (int j = 0; j < bucketSize; j++) {
      bucket[j] = sortedBucket[j];
    }

    // Free the memory allocated for the sorted bucket
    free(sortedBucket);
  }

  // Concatenate the sorted buckets into the original array
  int index = 0;
  for (int i = 0; i < n; i++) {
    int *bucket = buckets[i];
    int bucketSize = *bucket;

    for (int j = 0; j < bucketSize; j++) {
      arr[index++] = bucket[j];
    }

    // Free the memory allocated for the bucket
    free(bucket);
  }

  // Free the memory allocated for the buckets array
  free(buckets);
}

// Function to print an array
void printArray(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// Main function
int main() {
  // Get the size of the array
  int n;
  printf("Enter the size of the array: ");
  scanf("%d", &n);

  // Get the elements of the array
  int *arr = malloc(sizeof(int) * n);
  printf("Enter the elements of the array: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  // Print the original array
  printf("Original array: ");
  printArray(arr, n);

  // Sort the array using bucket sort
  bucketSort(arr, n);

  // Print the sorted array
  printf("Sorted array: ");
  printArray(arr, n);

  // Free the memory allocated for the array
  free(arr);

  return 0;
}