//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define SWAP(a, b) { int t = a; a = b; b = t; }

void bucketSort(int arr[], int n) {
  int i, j, k, min, max;
  
  // Find the minimum and maximum elements in the array
  min = arr[0];
  max = arr[0];
  for (i = 1; i < n; i++) {
    if (arr[i] < min)
      min = arr[i];
    else if (arr[i] > max)
      max = arr[i];
  }
  
  // Create an array of buckets
  int numBuckets = (max - min) / n + 1;
  int buckets[numBuckets];
  for (i = 0; i < numBuckets; i++)
    buckets[i] = 0;
  
  // Distribute the elements into the buckets
  for (i = 0; i < n; i++)
    buckets[arr[i] - min]++;
  
  // Sort the elements in each bucket
  for (i = 0; i < numBuckets; i++) {
    for (j = 0; j < buckets[i]; j++) {
      for (k = j + 1; k < buckets[i]; k++) {
        if (arr[k] < arr[j])
          SWAP(arr[k], arr[j]);
      }
    }
  }
  
  // Concatenate the buckets into the sorted array
  k = 0;
  for (i = 0; i < numBuckets; i++) {
    for (j = 0; j < buckets[i]; j++)
      arr[k++] = min + i;
  }
}

int main() {
  int arr[] = { 5, 3, 1, 7, 4, 1, 2, 8, 6 };
  int n = sizeof(arr) / sizeof(arr[0]);
  
  bucketSort(arr, n);
  
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
  
  return 0;
}