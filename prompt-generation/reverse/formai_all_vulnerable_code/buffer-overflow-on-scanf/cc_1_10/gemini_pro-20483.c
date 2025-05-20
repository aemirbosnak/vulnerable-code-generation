//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: genious
#include <stdio.h>
#include <stdlib.h>

// Define the number of buckets
#define NUM_BUCKETS 10

// Define the maximum value in the input array
#define MAX_VALUE 100

// Create a bucket sort function
void bucketSort(int *arr, int size) {
  // Create an array of buckets
  int buckets[NUM_BUCKETS][MAX_VALUE];

  // Initialize the buckets
  for (int i = 0; i < NUM_BUCKETS; i++) {
    for (int j = 0; j < MAX_VALUE; j++) {
      buckets[i][j] = 0;
    }
  }

  // Distribute the elements into the buckets
  for (int i = 0; i < size; i++) {
    int bucketIndex = arr[i] / NUM_BUCKETS;
    int valueIndex = arr[i] % NUM_BUCKETS;
    buckets[bucketIndex][valueIndex]++;
  }

  // Sort the elements in each bucket
  for (int i = 0; i < NUM_BUCKETS; i++) {
    for (int j = 0; j < MAX_VALUE; j++) {
      for (int k = 0; k < buckets[i][j]; k++) {
        printf("%d ", i * NUM_BUCKETS + j);
      }
    }
  }
}

// Main function
int main() {
  // Get the size of the input array
  int size;
  printf("Enter the size of the input array: ");
  scanf("%d", &size);

  // Get the elements of the input array
  int arr[size];
  printf("Enter the elements of the input array: ");
  for (int i = 0; i < size; i++) {
    scanf("%d", &arr[i]);
  }

  // Sort the input array using bucket sort
  bucketSort(arr, size);

  return 0;
}