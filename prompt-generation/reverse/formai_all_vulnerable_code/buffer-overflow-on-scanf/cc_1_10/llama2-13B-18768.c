//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ARRAY_SIZE 100

// Function to sort an array of integers using quicksort
int quicksort(int arr[], int low, int high) {
  int i, j, pivot, temp;

  // If the length of the array is 1 or less, return
  if (low >= high) return 0;

  // Partition the array into two subarrays
  pivot = arr[low];
  i = low + 1;
  j = high;

  // Find the first element greater than the pivot
  while (i <= j) {
    while (arr[i] <= pivot) i++;
    while (arr[j] > pivot) j--;

    // If i and j are equal, the pivot is the middle element
    if (i == j) {
      temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
      i++;
      j--;
    }
  }

  // Recursively sort the two subarrays
  if (i <= j) quicksort(arr, low, i - 1);
  if (i < j) quicksort(arr, i, j);

  return 1;
}

int main() {
  int arr[MAX_ARRAY_SIZE];
  int i, j, n;
  clock_t start, end;

  // Get the number of elements in the array
  printf("Enter the number of elements in the array: ");
  scanf("%d", &n);

  // Initialize the array with random elements
  for (i = 0; i < n; i++) {
    arr[i] = rand() % 100;
  }

  // Sort the array using quicksort
  quicksort(arr, 0, n - 1);

  // Print the sorted array
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  // Get the time taken for sorting
  clock_t now = clock();
  double time_taken = (double)(now - start) / CLOCKS_PER_SEC;
  printf("Time taken for sorting: %f seconds\n", time_taken);

  return 0;
}