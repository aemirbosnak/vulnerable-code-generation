//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// Function to sort an array using bucket sort
void bucketSort(int arr[], int n) {
  // Create n empty buckets
  int buckets[n];
  for (int i = 0; i < n; i++) {
    buckets[i] = 0;
  }

  // Insert each element of the array into a bucket
  for (int i = 0; i < n; i++) {
    int bucketIndex = arr[i] / n;
    buckets[bucketIndex]++;
  }

  // Sort each bucket
  for (int i = 0; i < n; i++) {
    int count = buckets[i];
    while (count > 0) {
      for (int j = 0; j < n; j++) {
        if (arr[j] / n == i) {
          printf("%d ", arr[j]);
          count--;
        }
      }
    }
  }

  printf("\n");
}

// Driver code to test the bucket sort function
int main() {
  int arr[] = {38, 27, 43, 3, 9, 82, 10};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("Unsorted array: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  printf("\n");

  bucketSort(arr, n);

  printf("Sorted array: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  printf("\n");

  return 0;
}