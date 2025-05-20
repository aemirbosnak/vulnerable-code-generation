//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// Function to sort an array of integers using bucket sort
void bucketSort(int arr[], int n, int max) {
  // Create n empty buckets
  int buckets[n];
  for (int i = 0; i < n; i++) {
    buckets[i] = 0;
  }

  // Distribute elements into buckets
  for (int i = 0; i < n; i++) {
    int bucketIndex = arr[i] * n / max;
    buckets[bucketIndex]++;
  }

  // Sort elements in each bucket
  for (int i = 0; i < n; i++) {
    while (buckets[i] > 0) {
      int index = i * n / max;
      arr[index] = i;
      buckets[i]--;
      index++;
    }
  }
}

// Function to print an array
void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// Main function
int main() {
  // Get the input array and its size
  int n;
  printf("Enter the size of the array: ");
  scanf("%d", &n);
  int arr[n];
  printf("Enter the elements of the array: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  // Find the maximum element in the array
  int max = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }

  // Sort the array using bucket sort
  bucketSort(arr, n, max);

  // Print the sorted array
  printf("Sorted array: ");
  printArray(arr, n);

  return 0;
}