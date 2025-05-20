//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Function to sort an array using bucket sort
void bucketSort(int *arr, int n) {
  // Create an array of buckets
  int buckets[10];

  // Initialize all buckets to 0
  for (int i = 0; i < 10; i++) {
    buckets[i] = 0;
  }

  // Count the number of elements in each bucket
  for (int i = 0; i < n; i++) {
    buckets[arr[i]]++;
  }

  // Create an array to store the sorted elements
  int sortedArr[n];

  // Add the elements from the buckets to the sorted array
  int index = 0;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < buckets[i]; j++) {
      sortedArr[index++] = i;
    }
  }

  // Copy the sorted array back to the original array
  for (int i = 0; i < n; i++) {
    arr[i] = sortedArr[i];
  }
}

// Function to print an array
void printArray(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// Driver code
int main() {
  // Get the input array
  int n;
  printf("Enter the size of the array: ");
  scanf("%d", &n);

  int arr[n];
  printf("Enter the elements of the array: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  // Sort the array using bucket sort
  bucketSort(arr, n);

  // Print the sorted array
  printf("The sorted array is: ");
  printArray(arr, n);

  return 0;
}