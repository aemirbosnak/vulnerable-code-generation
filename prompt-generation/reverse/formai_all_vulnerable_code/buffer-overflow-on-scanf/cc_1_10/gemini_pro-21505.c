//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum element in an array
int findMax(int arr[], int n) {
  int max = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
}

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
  // Create n empty buckets
  int buckets[n];
  for (int i = 0; i < n; i++) {
    buckets[i] = 0;
  }

  // Insert elements into their respective buckets
  int max = findMax(arr, n);
  for (int i = 0; i < n; i++) {
    int bucketIndex = arr[i] * n / (max + 1);
    buckets[bucketIndex]++;
  }

  // Sort each bucket individually using insertion sort
  for (int i = 0; i < n; i++) {
    int bucketIndex = i;
    int count = buckets[i];
    while (count--) {
      int j = i - 1;
      while (arr[j] > arr[j + 1] && j >= 0) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        j--;
      }
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

int main() {
  // Get the size of the array
  int n;
  printf("Enter the size of the array: ");
  scanf("%d", &n);

  // Get the elements of the array
  int arr[n];
  printf("Enter the elements of the array: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  // Sort the array using bucket sort
  bucketSort(arr, n);

  // Print the sorted array
  printf("Sorted array: ");
  printArray(arr, n);

  return 0;
}